%{
/**********************************************************************
 * fichero: pascual.y
 *          Analizador sint'actico de Pascual
 *          2011-03-21
 *             jfabra - Cambios en la gram'atica
 **********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "errores.h"
#include "listas.h"
#include "tabla.h"

TABLA_SIMBOLOS tabsim;
int nivel;
%}

%token tPROGRAMA tACCION 
%token tCONSTENTERA tCONSTCHAR tCONSTCAD tTRUE tFALSE tENTACAR tCARAENT
%token tIDENTIFICADOR tENTERO tCARACTER tBOOLEANO
%token tESCRIBIR tLEER tOPAS tPRINCIPIO tFIN
%token tAND tOR tNOT 
%token tMQ tFMQ
%token tMEI tMAI tNI tMOD tDIV
%token tSI tENT tSI_NO tFSI
%token tVAL tREF
%left '+' '-'
%left '*' '/' tDIV tMOD
%left tNOT
%nonassoc MENOSU

%union {
  int constante;
  char *cadena;
}

%start programa
%%

programa: 
    tPROGRAMA tIDENTIFICADOR ';'
    {
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
|    lista_declaraciones ';'
;

lista_declaraciones:
     lista_declaraciones ';' declaracion
|    declaracion
;

declaracion:
     tipo_variables identificadores 
;

tipo_variables:
     tENTERO
|    tCARACTER
|    tBOOLEANO
;

identificadores:
     tIDENTIFICADOR
|    identificadores ',' tIDENTIFICADOR
;

declaracion_acciones:
|    declaracion_accion 
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
     parametros_formales
;

parametros_formales:
|    '(' lista_parametros ')'
;

lista_parametros:
     lista_parametros ';' parametros
|    parametros
|
;

parametros:
     clase_parametros declaracion
;

clase_parametros:
     tVAL
|    tREF
;

bloque_instrucciones:
     tPRINCIPIO lista_instrucciones tFIN 
;

lista_instrucciones:
|    instruccion
|    lista_instrucciones instruccion
;

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
|    lista_asignables ',' tIDENTIFICADOR
;        
        
escribir:
     tESCRIBIR 
     '(' lista_escribibles ')' ';'
;

lista_escribibles:
    lista_escribibles ',' expresion
|   expresion
;

asignacion:
     tIDENTIFICADOR tOPAS expresion ';'
;


mientras_que:
    tMQ 
    expresion 
    lista_instrucciones 
    tFMQ
;
            
seleccion:
    tSI 
    expresion 
    tENT 
    lista_instrucciones 
    resto_seleccion
    tFSI
;

resto_seleccion:
|
    tSI_NO 
    lista_instrucciones
;

invocacion_accion:
     tIDENTIFICADOR 
     argumentos
     ';'
|    tIDENTIFICADOR
     ';'
;
                            
argumentos:
    '(' lista_expresiones ')'                
;

lista_expresiones:
     lista_expresiones ',' expresion
|    expresion
;

expresion:
     expresion_simple
|    expresion operador_relacional expresion_simple
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
|    expresion_simple operador_aditivo termino
;

operador_aditivo:
     '+'
|    '-'
|    tOR
;
        
termino:
     factor
|    termino operador_multiplicativo factor
;

operador_multiplicativo:
     '*'
|    tDIV
|    tMOD
|    tAND
;

factor:
     '-' factor %prec MENOSU
|    tNOT factor
|    '(' expresion ')'
|    tENTACAR '(' expresion ')'
|    tCARAENT '(' expresion ')'
|    tIDENTIFICADOR
|    tCONSTENTERA
|    tCONSTCHAR
|    tCONSTCAD
|    tTRUE
|    tFALSE
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

