/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     tPROGRAMA = 258,
     tACCION = 259,
     tCONSTENTERA = 260,
     tCONSTCHAR = 261,
     tCONSTCAD = 262,
     tTRUE = 263,
     tFALSE = 264,
     tENTACAR = 265,
     tCARAENT = 266,
     tIDENTIFICADOR = 267,
     tENTERO = 268,
     tCARACTER = 269,
     tBOOLEANO = 270,
     tESCRIBIR = 271,
     tLEER = 272,
     tOPAS = 273,
     tPRINCIPIO = 274,
     tFIN = 275,
     tAND = 276,
     tOR = 277,
     tNOT = 278,
     tMQ = 279,
     tFMQ = 280,
     tMEI = 281,
     tMAI = 282,
     tNI = 283,
     tMOD = 284,
     tDIV = 285,
     tSI = 286,
     tENT = 287,
     tSI_NO = 288,
     tFSI = 289,
     tVAL = 290,
     tREF = 291,
     tVECTOR = 292,
     tDE = 293,
     MENOSU = 294
   };
#endif
/* Tokens.  */
#define tPROGRAMA 258
#define tACCION 259
#define tCONSTENTERA 260
#define tCONSTCHAR 261
#define tCONSTCAD 262
#define tTRUE 263
#define tFALSE 264
#define tENTACAR 265
#define tCARAENT 266
#define tIDENTIFICADOR 267
#define tENTERO 268
#define tCARACTER 269
#define tBOOLEANO 270
#define tESCRIBIR 271
#define tLEER 272
#define tOPAS 273
#define tPRINCIPIO 274
#define tFIN 275
#define tAND 276
#define tOR 277
#define tNOT 278
#define tMQ 279
#define tFMQ 280
#define tMEI 281
#define tMAI 282
#define tNI 283
#define tMOD 284
#define tDIV 285
#define tSI 286
#define tENT 287
#define tSI_NO 288
#define tFSI 289
#define tVAL 290
#define tREF 291
#define tVECTOR 292
#define tDE 293
#define MENOSU 294




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 33 "pascual1.y"

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



/* Line 2068 of yacc.c  */
#line 146 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


