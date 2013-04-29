%{
/**********************************************************************
 * fichero: pascual.y
 *          Analizador sint'actico de Pascual
 *          2011-03-21
 *             jfabra - Cambios en la gram'atica
 * 577511 Pablo Alegre Lara
 **********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "errores.h"
#include "listas.h"
#include "tabla.h" 

TABLA_SIMBOLOS tabsim;
int nivel;
FILE *f;

extern nErrores;

char* tabular(int n){
	char* cad="";
	int i;
	cad= (char*)malloc(sizeof(char)*(n));
	for (i=0; i<n; i++) strcat(cad,"\t");
	return cad;
}


%}

%union{
	char *cadena;
	int constante; 
	int operador; 	
	CLASE_PARAMETRO tpPar;		
	TIPO_VARIABLE tipo;
	TIPO_SIMBOLO tipo_sim;
	SIMBOLO *simbolo;
	struct{
		char *nombre;
		SIMBOLO *simbolo;
	} identificador;
	VARIABLES variable;
	LISTA listaParametros;
}


%token tPROGRAMA tACCION 
%token tCONSTENTERA tCONSTCHAR tCONSTCAD tTRUE tFALSE tENTACAR tCARAENT
%token tIDENTIFICADOR tENTERO tCARACTER tBOOLEANO
%token tESCRIBIR tLEER tOPAS tPRINCIPIO tFIN
%token tAND tOR tNOT 
%token tMQ tFMQ
%token tMEI tMAI tNI tMOD tDIV
%token tSI tENT tSI_NO tFSI
%token tVAL tREF
%token tVECTOR tDE
%left '+' '-'
%left '*' '/' tDIV tMOD
%left tNOT
%nonassoc MENOSU


%type<identificador> tIDENTIFICADOR;
%type<variable> expresion tipo_variables expresion_simple identificadores factor termino;
%type<tipo>  tipo_variables2;
%type <listaParametros> parametros_formales lista_parametros parametros declaracion_parametros 
						identificadores_parametros lista_expresiones argumentos;
%type<tpPar> clase_parametros;
%type<operador> operador_multiplicativo operador_aditivo;

%start programa
%%

programa: 
	tPROGRAMA tIDENTIFICADOR ';'
    {
	  introducir_programa(tabsim,$2.nombre,0);
      nivel = 0;
      inicializar_tabla (tabsim);
    }
    declaracion_variables 
    declaracion_acciones
    bloque_instrucciones
    {
      eliminar_variables (tabsim, nivel);
      eliminar_acciones (tabsim, nivel);
      --nivel;
    }
;


declaracion_variables: 
|   lista_declaraciones ';'
;

lista_declaraciones: 
     lista_declaraciones ';' declaracion
|    declaracion
;

declaracion: 
     tipo_variables identificadores 
;

/*===================================================*/
/*===================================================*/
declaracion_parametros:
	tipo_variables identificadores_parametros
	{
		$$=$2;
	}
;
/*===================================================*/
/*===================================================*/

/*===================================================*/
tipo_variables: 
     tENTERO
	 {
		$$.tipo=ENTERO;
		$$.tpContenido=DESCONOCIDO; 
	 }
|    tCARACTER
	{
		$$.tipo=CHAR; 
		$$.tpContenido=DESCONOCIDO; 
	}
|    tBOOLEANO
	{
		$$.tipo=BOOLEANO; 
		$$.tpContenido==DESCONOCIDO; 
	} 
|	tVECTOR '[' expresion ']' tDE tipo_variables2
	{
		$$.tipo=VECTOR;
		if (( $3.tipo != ENTERO ) || ( $3.constante = 0 )){
				error_semantico("El indice debe ser constante.");
		}	
		else{
			if ($3.valor <= 0){
				error_semantico("ERROR: el rango debe ser mayor de 1");
			}
		    else{
				$$.dimension=$3.valor;
			}
		}
		$$.tpContenido = $6;
	}
;

tipo_variables2:									
	tENTERO {$$=ENTERO;}
|	tCARACTER {$$=CHAR;}
|	tBOOLEANO {$$=BOOLEANO;}
;
/*===================================================*/
identificadores:  
     tIDENTIFICADOR
	 {
		$$=$<variable>0;  
		if (($1.simbolo == NULL) || ($1.simbolo->nivel != nivel)){ /*No existe y lo metemos*/
			$1.simbolo=introducir_variable(tabsim, $1.nombre,$<variable>0.tipo,nivel,0);
			$1.simbolo->tipo=VARIABLE;
			if ($1.simbolo->variable==VECTOR){
				$1.simbolo->dimension=$<variable>0.dimension;
				$1.simbolo->tpContenido=$<variable>0.tpContenido;
			}
		}
		else error_semantico("Identificador duplicado.");
	 }
|    identificadores ',' tIDENTIFICADOR
	{
		$$=$<variable>0;
		if (($3.simbolo == NULL) || ($3.simbolo->nivel != nivel)){
			$3.simbolo=introducir_variable(tabsim,$3.nombre,$1.tipo,nivel,0);
			$3.simbolo->tipo=VARIABLE;
			if ($3.simbolo->variable == VECTOR){
				$3.simbolo->dimension=$<variable>0.dimension;
				$3.simbolo->tpContenido=$1.tpContenido;
			}
		}
	}
;
/*===================================================*/
/* Necesario para distingir entre introducir_parametro
   o introducir_variable*/
/*===================================================*/
identificadores_parametros:
	tIDENTIFICADOR
	{
		if (($1.simbolo==NULL) || ($1.simbolo->nivel!=nivel)){
			$1.simbolo=introducir_parametro(tabsim,$1.nombre,$<variable>0.tipo,$<tpPar>-1,nivel,0);
			$1.simbolo->tipo=PARAMETRO;
			if ($1.simbolo->variable==VECTOR){ 
				$1.simbolo->tpContenido=$<variable>0.tpContenido;
				$1.simbolo->dimension=$<variable>0.dimension;
			}
			crear_unitaria_copiando(&$$,$1.simbolo,sizeof(SIMBOLO));
		}
		else{
			error_semantico("Identificador duplicado.");
			crear_vacia(&$$); 
		}
	}
|	identificadores_parametros ',' tIDENTIFICADOR
	{
		if (($3.simbolo == NULL) || ($3.simbolo->nivel != nivel)){
			$3.simbolo=introducir_parametro(tabsim,$3.nombre,$<variable>0.tipo,$<tpPar>-1,nivel,0);
			$3.simbolo->tipo=VARIABLE;
			if ($3.simbolo->variable==VECTOR){ 
				$3.simbolo->tpContenido=$<variable>0.tpContenido;
				$3.simbolo->dimension=$<variable>0.dimension;
			}
			SIMBOLO *s=$3.simbolo;
			anadir_derecha(s,&$1);
			$$=$1;
		}
		else{
			error_semantico("Identificador duplicado.");
			crear_vacia(&$$); 
		}
	}
;
/*===================================================*/
/*===================================================*/


declaracion_acciones:
|    declaracion_acciones  declaracion_accion
;

declaracion_accion:
     cabecera_accion ';'
     declaracion_variables 
     declaracion_acciones       
     bloque_instrucciones
;

cabecera_accion:
     tACCION tIDENTIFICADOR 
	 {
		if(($2.simbolo == NULL) || ($2.simbolo->nivel != nivel)){
			$2.simbolo=introducir_accion(tabsim, $2.nombre,nivel,0);		
		} 
		else error_semantico("El identificador ya existe.");
		nivel++;
	 }
     parametros_formales
	 {
		$2.simbolo->parametros=$4;  
	 }	 
;

parametros_formales: 
	{
		crear_vacia(&$$);
	}
|    '(' lista_parametros ')'
	{
		$$=$2;
	}
;

lista_parametros:
     lista_parametros ';' parametros
	 {
		concatenar( &$1,$3);  
		$$=$1;
	 }
|    parametros
	{
		$$=$1;
	}
|	{crear_vacia(&$$);}
;

parametros:
     clase_parametros declaracion_parametros
	 {
		$$=$2;
	 }
;

clase_parametros:
     tVAL
	 {
		$$=VAL;
	 }
|    tREF
	 {	
		$$=REF;
	 }
;

bloque_instrucciones:
     tPRINCIPIO lista_instrucciones tFIN 
	 { 
	 	eliminar_variables(tabsim,nivel);
		ocultar_parametros(tabsim,nivel);
		eliminar_parametros_ocultos(tabsim,nivel);
		eliminar_acciones(tabsim,nivel+1);
		nivel--;
	 }
;
/*----------------------------------------------------------*/
lista_instrucciones:
     lista_instrucciones instruccion  
| 
;
/*----------------------------------------------------------*/

instruccion:
     leer
|    escribir
|    asignacion
|    seleccion
|    mientras_que
|    invocacion_accion
;

leer:
     tLEER 
     '(' lista_asignables ')' ';'
;

lista_asignables:
     tIDENTIFICADOR
	 {
		if ($1.simbolo == NULL){ //Si no lo conocemos
			error_semantico("Identificador no declarado.");     
			$1.simbolo=introducir_variable(tabsim,$1.nombre,DESCONOCIDO,nivel,0); 	//Marcamos como desconocido
		}
		else{ 
			if (($1.simbolo->tipo!=VARIABLE) && ($1.simbolo->tipo!=PARAMETRO)){ 		//Si no es ni variable ni parametro
				error_semantico("El identificador no es ni variable ni parametro.");
			}
			else{
				if (($1.simbolo->variable!=ENTERO) && ($1.simbolo->variable!=CHAR)){ 
					error_semantico("El identificador no se puede leer");
				}
			}
		}
	 } 
|    lista_asignables ',' tIDENTIFICADOR
	{ //Igual que la anterior produccion pero cambiando los $numero
		if ($3.simbolo==NULL){
			error_semantico("Identificador no declarado.");
			$3.simbolo=introducir_variable(tabsim,$3.nombre,DESCONOCIDO,nivel,0);
		}
		else{
			if (($3.simbolo->tipo!=VARIABLE) && ($3.simbolo->tipo!=PARAMETRO)){
				error_semantico("El identificador no es ni variable ni parametro.");
			}
			else{
				if (($3.simbolo->variable!=ENTERO) && ($3.simbolo->variable!=CHAR)){
					error_semantico("Tipos incompatibles.");
				}
			}
		}
	}
;        
        
escribir:
     tESCRIBIR 
     '(' lista_escribibles ')' ';'
;

lista_escribibles:
    lista_escribibles ',' expresion
|   expresion
;
/*-------------Modificada-------------------------------*/  //PENDIENTE   <------------------
asignacion:
     tIDENTIFICADOR tOPAS expresion ';'
	 {
		if ($1.simbolo == NULL){								//No conocemos el identificador
			error_semantico("Identificador desconocido.");
		}
		else{
			if ($1.simbolo->nivel>nivel){                    //Si esta en otro nivel
				error_semantico("Identificador desconocido.");
			}
			else{
				if (($1.simbolo->tipo != VARIABLE) && ($1.simbolo->tipo != PARAMETRO)){ //Si no es var o par ( intentan colarnos una accion o programa)
					error_semantico("El identificador debe ser una variable o un parametro.");
				}
				else{
					if (($1.simbolo->tipo == PARAMETRO) && ($1.simbolo->parametro == VAL)){ //Parametro de entrada por valor
						error_semantico("No se puede asignar valor a un parametro de entrada.");
					}
					else{	
						if (($1.simbolo->variable != DESCONOCIDO) && ($3.tipo != DESCONOCIDO) && ($1.simbolo->variable != $3.tipo)){
							error_semantico ("Tipos incompatibles.");
						}
					}
				}
			}
		}
	 }
|	 tIDENTIFICADOR '[' expresion ']' tOPAS expresion ';'/* Añadida para tratar la asignacion de vectores*/
	{
		if ($1.simbolo == NULL){								//No conocemos el identificador
			error_semantico("Identificador desconocido.");
		}
		else{
			if (($1.simbolo->tipo != VARIABLE) && ($1.simbolo->tipo != PARAMETRO)){ //Si no es var o par ( intentan colarnos una accion o programa)
				error_semantico("El identificador debe ser una variable o un parametro.");
			}
			else{  //Si es una variable o un parametro
				if (($1.simbolo->tipo==PARAMETRO) && ($1.simbolo->parametro==VAL)){
					error_semantico("No se puede asignar valor a un parametro de entrada.");
				}
				else  //Una vez comprobado el identificador, pasamor al indice.
				{
					if ($3.tipo != ENTERO){
						error_semantico("El indice debe ser un entero. 1,2,3...");
					}
					else if ($1.simbolo->variable == VECTOR){ //si tenemos un entero, comprobamos que tIdentificador es un VECTOR.
						if ($3.calculable == 1){ //Si podemos calcularla
							if ($3.valor < 0){   //limite inferior
								error_semantico("Underflow.");
							}
							else if ($3.valor > $1.simbolo->dimension){
								error_semantico("Overflow.");
							}
							else{
								if ($6.tipo != DESCONOCIDO){
									if (($6.tipo == VECTOR)){
										if ($1.simbolo->tpContenido != $6.tpContenido){
											error_semantico("Tipos incompatibles.");
										}
									}
									else{
										if ($1.simbolo->tpContenido != $6.tipo){
											error_semantico("Tipos incompatibles.");
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
;
/*------------------------------------------------------*/

mientras_que:
    tMQ 
    expresion 
	{
		if (($2.tipo != DESCONOCIDO) && ($2.tipo != BOOLEANO)){
			error_semantico("La condicion o las condiciones deben ser booleanas.");
		}
	}
    lista_instrucciones 
    tFMQ
;
            
seleccion:
    tSI 
    expresion 
	{
		if (($2.tipo != DESCONOCIDO) && ($2.tipo != BOOLEANO)){
			error_semantico("La condicion o las condiciones deben ser booleanas.");
		}
	}
    tENT 
    lista_instrucciones 
    resto_seleccion
    tFSI
;

resto_seleccion:  //Tratamiento de los si no ´s
|
    tSI_NO 
    lista_instrucciones
;

invocacion_accion:
     tIDENTIFICADOR 
     argumentos
	 {
		if ($1.simbolo == NULL){ 								//----------------------Comprobaciones tipicas----------------------
			error_semantico("Accion no declarada.");
		}
		else{
			if ($1.simbolo->tipo != ACCION){
				error_semantico("No es una accion.");
			}
			else{
				if ($1.simbolo->nivel < (nivel-1)){
					error_semantico("Accion no declarada."); //------------------------------------------------------------------
				}
				else{
					if (longitud_lista($1.simbolo->parametros) != longitud_lista($2)){  //Los dos son listaParametros

							error_semantico("Numero de parametros de la accion incorrectos.");
						}
					else{
						int i;
						SIMBOLO *s;
						VARIABLES *v;
						
						for(i=0; i < longitud_lista($1.simbolo->parametros) ; i++){ //Tenemos que ir comprobando todos los elementos de la lista
							s=(SIMBOLO *) observar($1.simbolo->parametros,i); //Recordatorio: observar devuelve el elemnto deseado de la lista (simbolo o variable)
							v=(VARIABLES *) observar($2,i);
							
							if ((s->variable != v->tipo) && (s->variable != DESCONOCIDO) && (v->tipo != DESCONOCIDO)){        
									//Comprobamos que las variables correscponden con lo que tienen que ser
									error_semantico("Argumento y parametro no corresponden.");
								}
							else{
								if ((s->variable == VECTOR) && (v->tipo == VECTOR)){
									if (s->dimension!=v->dimension){
										error_semantico("Dimensiones de los vectores no corresponden.");
									}		
								}
							}
						}
					}
				} 
			}
		}
	 }	 
     ';'
|    tIDENTIFICADOR
	{
		if ($1.simbolo == NULL){  //Identificador NULL
			error_semantico("Identificador no declarado.");
		}
		else{
			if ($1.simbolo->tipo != ACCION){ //No permitimos acciones como parametros
				error_semantico("El identificador no es una accion");
			}
			else{
				if ( $1.simbolo->nivel < (nivel-1) ){ //Comprobamos el nivel 
					error_semantico("Accion no declarada.");
				}
				else{
					if ( longitud_lista($1.simbolo->parametros) > 0 ){ //Si tiene parametros es erroneo
						error_semantico("Numero de parametros no corresponden.");
					}
				}
			}
		}		
	}
     ';'
;
                            
argumentos:      //subimos la lista de argumentos
     '(' lista_expresiones ')'    
	{
		$$=$2;
	}
;

lista_expresiones:
     lista_expresiones ',' expresion
	 {
		anadir_derecha_copiando( (ELEMENTO)&$3, &$$, sizeof(VARIABLES) );
	 }
|    expresion
	{
		crear_unitaria_copiando( &$$, (ELEMENTO)&$1, sizeof(VARIABLES) );
	}
;

expresion:
    expresion_simple
	{
		$$=$1;
	}
|   expresion operador_relacional expresion_simple     
	{
		if (($1.tipo != DESCONOCIDO) && ($3.tipo != DESCONOCIDO) && ($1.tipo != $3.tipo)){
			error_semantico("Los operadores deben ser del mismo tipo.");
			$$.tipo=DESCONOCIDO;
		}
		else { //Si no son ENTERO o CHAR
			if ((($1.tipo != DESCONOCIDO) && ($1.tipo != ENTERO) && ($1.tipo != CHAR)) || 
				(($3.tipo != DESCONOCIDO) && ($3.tipo != ENTERO)) && ($3.tipo != CHAR)){
					error_semantico("Los operadores deben ser enteros o caracteres.");
					$$.tipo=DESCONOCIDO;
			}
			else{ //Es BOOLEANO
				$$.tipo=BOOLEANO;
				$$.exprSimple=0;
			}
		}
	}
;
        
operador_relacional:
     '='
|    '<'
|    '>'
|    tMEI
|    tMAI
|    tNI
;

expresion_simple:
     termino
	 { 
		$$=$1;
	 }
|    expresion_simple operador_aditivo termino
	{
		if ($2 == 0) {  // +
			if ((($1.tipo != ENTERO) || ($3.tipo != ENTERO)) && ($1.tipo != DESCONOCIDO) && ($3.tipo != DESCONOCIDO)){
				error_semantico("Los operadores deben ser enteros.");
				$$.tipo=DESCONOCIDO;
			}
			else{
				if ((((double) $1.valor + (double)$3.valor) < -2147483647) || (((double) $1.valor + (double)$3.valor) > 2147483647)){
					$$.tipo=DESCONOCIDO;
					error_semantico("Overflow.");
				}
				else{
					$$.tipo=ENTERO;	
					if (($1.calculable == 1) && ($3.calculable == 1)){
						$$.valor=$1.valor+$3.valor;
						$$.calculable=1;
					}
					else $$.calculable=0;
					$$.constante=0;
					$$.exprSimple=0;
				}
			}
		} 
		else if ($2 == 1){  // -
			if (($1.tipo != ENTERO) || ($3.tipo != ENTERO)){
				error_semantico("Los operadores deben ser enteros.");
				$$.tipo=DESCONOCIDO;
			}
			else{
				if ((((double) $1.valor - (double)$3.valor) < -2147483647) || (((double) $1.valor - (double)$3.valor) > 2147483647)){
					$$.tipo=DESCONOCIDO;
					error_semantico("Overflow.");
				}
				else{
					$$.tipo=ENTERO;	
					if (($1.calculable == 1) && ($3.calculable == 1)){
						$$.valor=$1.valor-$3.valor;
						$$.calculable=1;
					}
					else $$.calculable=0;
					$$.constante=0;
					$$.exprSimple=0;
				}
			}
		}
		else{		//$2= OR
			if (($1.tipo != BOOLEANO) || ($3.tipo != BOOLEANO)){
				error_semantico("Los operadores deben ser booleanos.");
				$$.tipo=DESCONOCIDO;
			}
			else {
				$$.tipo=BOOLEANO;
				$$.exprSimple=0;
			} 
		}
	}
;

operador_aditivo:   
     '+' 
	 {
		$$=0;
	 }
|    '-'
	 {
		$$=1;
	 }
|    tOR
	 {
		$$=2;
	 }
;
       
termino:
     factor
	 {
		$$=$1;
	 }
|    termino operador_multiplicativo factor
	 {
		if ($2==0) {
			if (($1.tipo!=ENTERO) || ($3.tipo!=ENTERO)){
				error_semantico("Los operadores deben ser enteros.");
				$$.tipo=DESCONOCIDO;
			}
			else{
				if ((((double) $1.valor*(double)$3.valor)<-2147483647) || (((double) $1.valor*(double)$3.valor)>2147483647)){
					$$.tipo=DESCONOCIDO;
					error_semantico("Overflow.");
				}
				else{
					$$.tipo=ENTERO;	
					if (($1.calculable==1) && ($3.calculable==1)){
						$$.valor=$1.valor*$3.valor;
						$$.calculable=1;
					}
					else $$.calculable=0;
					$$.constante=0;
					$$.exprSimple=0;
				}
			}
		}
		else if ($2==1){
			if (($1.tipo!=ENTERO) || ($3.tipo!=ENTERO)){
				error_semantico("Los operadores deben ser enteros.");
				$$.tipo=DESCONOCIDO;
			}
			else{
				$$.tipo=ENTERO;
				if (($1.calculable==1) && ($3.calculable==1)){
					if ($3.valor!=0){
						$$.valor=$1.valor/$3.valor;
						$$.calculable=1;
					}
					else{ 
						error_semantico("Division por cero.");
						$$.tipo=DESCONOCIDO;
						$$.calculable=0;
					}
				}
				else $$.calculable=0;
				$$.constante=0;
				$$.exprSimple=0;
				
			}
		}
		else if ($2==2){
			if (($1.tipo!=ENTERO) || ($3.tipo!=ENTERO)){
				error_semantico("Los operadores deben ser enteros.");
				$$.tipo=DESCONOCIDO;
			}
			else{
				$$.tipo=ENTERO;
				if (($1.calculable==1) && ($3.calculable==1)){
					$$.valor=$1.valor%$3.valor;
					$$.calculable=1;
				}
				else $$.calculable=0;
				$$.constante=0;
				$$.exprSimple=0;
			}
		}
		else{   // $2==3
			if (($1.tipo!=BOOLEANO) || ($3.tipo!=BOOLEANO)){
				error_semantico("Los operadores deben ser booleanos.");
				$$.tipo=DESCONOCIDO;
			}
			else {
				$$.tipo=BOOLEANO;
				$$.exprSimple=0;
			}
		}
	 }
;

operador_multiplicativo:
     '*'
	 {
		$$=0;
	 }
|    tDIV
	 {
		$$=1;
	 }
|    tMOD
	 {
		$$=2;
	 }
|    tAND
	 {
		$$=3;
	 }
;

factor:
     '-' factor %prec MENOSU
	{
		if (($2.tipo!=ENTERO) && ($2.tipo!=DESCONOCIDO)){ 
			$$.tipo=DESCONOCIDO;
			error_semantico("Tipos incompatibles.");
		}
		else{
			$$.constante=$2.constante;
			$$.tipo=ENTERO;
			$$.valor=-$2.valor;
			$$.calculable=$2.calculable;
		}
	}
|    tNOT factor
	{
		if ($2.tipo!=BOOLEANO){ 
			$$.tipo=DESCONOCIDO;
			error_semantico("Tipos incompatibles.");
		}
		else  $$.tipo=BOOLEANO;
	}
|    '(' expresion ')'
	{
		$$=$2;
	}
|    tENTACAR '(' expresion ')'
	{
		if ($3.tipo!=ENTERO){
			error_semantico("Casteo de entero a caracter debe recibir un entero.");
			$$.tipo=DESCONOCIDO;
		}
		else $$.tipo=CHAR;
	}
|    tCARAENT '(' expresion ')'
	{
		if ($3.tipo!=CHAR){
			error_semantico("Casteo de caracter a entero debe recibir un caracter.");
			$$.tipo=DESCONOCIDO;
		}
		else{ 
			$$.tipo=ENTERO;
			$$.constante=0;
		}
	}
|	 tIDENTIFICADOR '[' expresion ']' 
	{ 
		$$.exprSimple=1;
		if ($1.simbolo==NULL){ 
			error_semantico("Identificador desconocido.");
			$$.tipo=DESCONOCIDO;
			$1.simbolo=introducir_variable(tabsim, $1.nombre,DESCONOCIDO,nivel,0);
		}
		else if (($3.tipo!=DESCONOCIDO) && ($3.tipo!=ENTERO)) error_semantico("Indice incorrecto.");
		else { 			
			if ($1.simbolo->tpContenido==ENTERO) $$.calculable=1;
			else $$.calculable=0;
			if (($3.valor<0) && ($3.calculable==1)) error_semantico("Underflow.");
			else if(($3.valor>=$1.simbolo->dimension) && ($3.calculable==1)) error_semantico("Overflow.");
			else{
				$$.tipo=$1.simbolo->tpContenido;
				$$.constante=1;
				$$.parametros=$1.simbolo->parametro;
			}
		}
	}
|    tIDENTIFICADOR
	{
		$$.calculable=0;
		$$.constante=0;
		$$.exprSimple=1;
		if ($1.simbolo == NULL){ 
			error_semantico("Identificador desconocido.");
			$1.simbolo=introducir_variable(tabsim,$1.nombre,DESCONOCIDO,nivel,0);
		}
		else{
			$$.tipo=$1.simbolo->variable;
			$$.tpContenido=$1.simbolo->tpContenido;
			$$.dimension=$1.simbolo->dimension;
		}
		
	}
|    tCONSTENTERA
	{
		$$.tipo=ENTERO;
		$$.constante=1;
		$$.calculable=1;
	}
|    tCONSTCHAR
	{
		$$.tipo=CHAR;
	}
|    tCONSTCAD
	{	
		$$.tipo=CADENA ;
	}
|    tTRUE
	{
		$$.tipo=BOOLEANO;
	}
|    tFALSE
	{
		$$.tipo=BOOLEANO;
	}
;

%%

/**********************************************************************/
main(int argc, char *argv[])
/**********************************************************************/
{
    extern FILE *yyin;
    char namein[100], nameout[100];

    strcpy (namein, argv[1]);
    strcat (namein, ".pc");
    yyin = fopen (namein, "r");
    if (yyin == NULL) {
       fprintf (stderr, "Fichero %s no existe.\n", namein);
       exit (1);
    }
    yyparse ();
    fclose (yyin);
   
}