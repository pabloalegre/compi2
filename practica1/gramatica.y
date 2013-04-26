%start programa
%token tPROGRAMA tACCION tCONSTENTERA tCONSTCHAR tCONSTCAD tTRUE tFALSE tENTACAR tCARAENT tIDENTIFICADOR 
%token tENTERO tCARACTER tBOOLEANO tESCRIBIR tLEER tOPAS tPRINCIPIO tFIN tAND tOR 
%token tNOT tMQ tFMQ tMEI tMAI tNI tMOD tDIV tSI tENT 
%token tSI_NO tFSI tVAL tREF 
%%
programa : tPROGRAMA tIDENTIFICADOR ';' declaracion_variables declaracion_acciones bloque_instrucciones ;
declaracion_variables : | lista_declaraciones ';' ;
lista_declaraciones : declaracion lista_declaraciones' ;
declaracion : tipo_variables identificadores ;
tipo_variables : tENTERO | tCARACTER | tBOOLEANO ;
identificadores : tIDENTIFICADOR identificadores' ;
declaracion_acciones : | declaracion_accion declaracion_acciones' ;
declaracion_accion : cabecera_accion ';' declaracion_variables declaracion_acciones bloque_instrucciones ;
cabecera_accion : tACCION tIDENTIFICADOR parametros_formales ;
parametros_formales : | '(' lista_parametros ')' ;
lista_parametros : | parametros lista_parametros' ;
parametros : clase_parametros declaracion ;
clase_parametros : tVAL | tREF ;
bloque_instrucciones : tPRINCIPIO lista_instrucciones tFIN ; /*AQUI*/
lista_instrucciones : | instruccion lista_instrucciones ;
instruccion : leer | escribir | asignacion | seleccion | mientras_que | invocacion_accion ;
leer : tLEER '(' lista_asignables ')' ';' ;
lista_asignables : tIDENTIFICADOR lista_asignables' ;
escribir : tESCRIBIR '(' lista_escribibles ')' ';' ;
lista_escribibles : expresion lista_escribibles' ;
asignacion : tIDENTIFICADOR tOPAS expresion ';' ;
mientras_que : tMQ expresion lista_instrucciones tFMQ ;
seleccion : tSI expresion tENT lista_instrucciones resto_seleccion tFSI ;
resto_seleccion : | tSI_NO lista_instrucciones ;
invocacion_accion : tIDENTIFICADOR argumentos ';' | tIDENTIFICADOR ';' ;
argumentos : '(' lista_expresiones ')' ;
lista_expresiones : expresion lista_expresiones' ;
expresion : expresion_simple expresion' ;
operador_relacional : '=' | '<' | '>' | tMEI | tMAI | tNI ;
expresion_simple : termino expresion_simple' ;
operador_aditivo : '+' | '-' | tOR ;
termino : factor termino' ;
operador_multiplicativo : '*' | tDIV | tMOD | tAND ;
factor : '-' factor | tNOT factor | '(' expresion ')' | tENTACAR '(' expresion ')' | tCARAENT '(' expresion ')' | tIDENTIFICADOR | tCONSTENTERA | tCONSTCHAR | tCONSTCAD | tTRUE | tFALSE ;
lista_declaraciones' : ';' declaracion lista_declaraciones' | ; /*AQUI*/
identificadores' : ',' tIDENTIFICADOR identificadores' | ;
declaracion_acciones' : declaracion_accion declaracion_acciones' | ;
lista_parametros' : ';' parametros lista_parametros' | ;
lista_asignables' : ',' tIDENTIFICADOR lista_asignables' | ;
lista_escribibles' : ',' expresion lista_escribibles' | ;
lista_expresiones' : ',' expresion lista_expresiones' | ;
expresion' : operador_relacional expresion_simple expresion' | ;
expresion_simple' : operador_aditivo termino expresion_simple' | ;
termino' : operador_multiplicativo factor termino' | ;

%%
