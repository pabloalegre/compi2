/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "pascual1.y"

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
FILE *f;

extern nErrores;
char* tabular(int n){
	char* cad="";
	int i;

	cad= (char*)malloc(sizeof(char)*(n));
	for (i=0; i<n; i++) strcat(cad,"\t");
	return cad;
}




/* Line 268 of yacc.c  */
#line 104 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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

/* Line 293 of yacc.c  */
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



/* Line 293 of yacc.c  */
#line 236 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 248 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   183

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNRULES -- Number of states.  */
#define YYNSTATES  170

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      48,    49,    41,    39,    47,    40,     2,    42,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    44,
      51,    50,    52,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    45,     2,    46,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    43
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     5,     6,    16,    17,    18,    22,
      26,    28,    31,    34,    36,    38,    40,    47,    49,    51,
      53,    55,    59,    61,    65,    66,    69,    70,    71,    72,
      81,    82,    87,    88,    92,    96,    98,    99,   102,   104,
     106,   107,   112,   115,   116,   118,   120,   122,   124,   126,
     128,   134,   136,   140,   146,   150,   152,   157,   165,   166,
     172,   173,   181,   182,   185,   186,   191,   192,   196,   200,
     204,   206,   208,   212,   214,   216,   218,   220,   222,   224,
     226,   230,   232,   234,   236,   238,   242,   244,   246,   248,
     250,   253,   256,   260,   265,   270,   275,   277,   279,   281,
     283,   285
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      54,     0,    -1,    -1,    -1,    -1,     3,    12,    44,    55,
      58,    56,    67,    57,    78,    -1,    -1,    -1,    59,    60,
      44,    -1,    60,    44,    61,    -1,    61,    -1,    63,    65,
      -1,    63,    66,    -1,    13,    -1,    14,    -1,    15,    -1,
      37,    45,    97,    46,    38,    64,    -1,    13,    -1,    14,
      -1,    15,    -1,    12,    -1,    65,    47,    12,    -1,    12,
      -1,    66,    47,    12,    -1,    -1,    67,    68,    -1,    -1,
      -1,    -1,    72,    44,    69,    58,    70,    67,    71,    78,
      -1,    -1,     4,    12,    73,    74,    -1,    -1,    48,    75,
      49,    -1,    75,    44,    76,    -1,    76,    -1,    -1,    77,
      62,    -1,    35,    -1,    36,    -1,    -1,    19,    79,    80,
      20,    -1,    80,    81,    -1,    -1,    82,    -1,    84,    -1,
      86,    -1,    89,    -1,    87,    -1,    92,    -1,    17,    48,
      83,    49,    44,    -1,    12,    -1,    83,    47,    12,    -1,
      16,    48,    85,    49,    44,    -1,    85,    47,    97,    -1,
      97,    -1,    12,    18,    97,    44,    -1,    12,    45,    97,
      46,    18,    97,    44,    -1,    -1,    24,    97,    88,    80,
      25,    -1,    -1,    31,    97,    90,    32,    80,    91,    34,
      -1,    -1,    33,    80,    -1,    -1,    12,    95,    93,    44,
      -1,    -1,    12,    94,    44,    -1,    48,    96,    49,    -1,
      96,    47,    97,    -1,    97,    -1,    99,    -1,    97,    98,
      99,    -1,    50,    -1,    51,    -1,    52,    -1,    26,    -1,
      27,    -1,    28,    -1,   101,    -1,    99,   100,   101,    -1,
      39,    -1,    40,    -1,    22,    -1,   103,    -1,   101,   102,
     103,    -1,    41,    -1,    30,    -1,    29,    -1,    21,    -1,
      40,   103,    -1,    23,   103,    -1,    48,    97,    49,    -1,
      10,    48,    97,    49,    -1,    11,    48,    97,    49,    -1,
      12,    45,    97,    46,    -1,    12,    -1,     5,    -1,     6,
      -1,     7,    -1,     8,    -1,     9,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    79,    79,    86,    90,    78,   103,   105,   105,   115,
     116,   120,   126,   136,   141,   146,   151,   174,   175,   176,
     180,   204,   232,   259,   293,   294,   298,   299,   300,   298,
     310,   309,   325,   328,   335,   340,   344,   348,   355,   359,
     366,   366,   377,   378,   383,   384,   385,   386,   387,   388,
     392,   397,   412,   430,   435,   436,   440,   475,   543,   541,
     556,   554,   566,   568,   575,   573,   631,   630,   662,   669,
     673,   680,   684,   705,   706,   707,   708,   709,   710,   714,
     718,   778,   782,   786,   793,   797,   875,   879,   883,   887,
     894,   907,   915,   919,   927,   938,   960,   976,   982,   986,
     990,   994
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tPROGRAMA", "tACCION", "tCONSTENTERA",
  "tCONSTCHAR", "tCONSTCAD", "tTRUE", "tFALSE", "tENTACAR", "tCARAENT",
  "tIDENTIFICADOR", "tENTERO", "tCARACTER", "tBOOLEANO", "tESCRIBIR",
  "tLEER", "tOPAS", "tPRINCIPIO", "tFIN", "tAND", "tOR", "tNOT", "tMQ",
  "tFMQ", "tMEI", "tMAI", "tNI", "tMOD", "tDIV", "tSI", "tENT", "tSI_NO",
  "tFSI", "tVAL", "tREF", "tVECTOR", "tDE", "'+'", "'-'", "'*'", "'/'",
  "MENOSU", "';'", "'['", "']'", "','", "'('", "')'", "'='", "'<'", "'>'",
  "$accept", "programa", "$@1", "$@2", "$@3", "declaracion_variables",
  "$@4", "lista_declaraciones", "declaracion", "declaracion_parametros",
  "tipo_variables", "tipo_variables2", "identificadores",
  "identificadores_parametros", "declaracion_acciones",
  "declaracion_accion", "$@5", "$@6", "$@7", "cabecera_accion", "$@8",
  "parametros_formales", "lista_parametros", "parametros",
  "clase_parametros", "bloque_instrucciones", "$@9", "lista_instrucciones",
  "instruccion", "leer", "lista_asignables", "escribir",
  "lista_escribibles", "asignacion", "mientras_que", "$@10", "seleccion",
  "$@11", "resto_seleccion", "invocacion_accion", "$@12", "$@13",
  "argumentos", "lista_expresiones", "expresion", "operador_relacional",
  "expresion_simple", "operador_aditivo", "termino",
  "operador_multiplicativo", "factor", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,    43,
      45,    42,    47,   294,    59,    91,    93,    44,    40,    41,
      61,    60,    62
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    55,    56,    57,    54,    58,    59,    58,    60,
      60,    61,    62,    63,    63,    63,    63,    64,    64,    64,
      65,    65,    66,    66,    67,    67,    69,    70,    71,    68,
      73,    72,    74,    74,    75,    75,    75,    76,    77,    77,
      79,    78,    80,    80,    81,    81,    81,    81,    81,    81,
      82,    83,    83,    84,    85,    85,    86,    86,    88,    87,
      90,    89,    91,    91,    93,    92,    94,    92,    95,    96,
      96,    97,    97,    98,    98,    98,    98,    98,    98,    99,
      99,   100,   100,   100,   101,   101,   102,   102,   102,   102,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     0,     9,     0,     0,     3,     3,
       1,     2,     2,     1,     1,     1,     6,     1,     1,     1,
       1,     3,     1,     3,     0,     2,     0,     0,     0,     8,
       0,     4,     0,     3,     3,     1,     0,     2,     1,     1,
       0,     4,     2,     0,     1,     1,     1,     1,     1,     1,
       5,     1,     3,     5,     3,     1,     4,     7,     0,     5,
       0,     7,     0,     2,     0,     4,     0,     3,     3,     3,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       2,     2,     3,     4,     4,     4,     1,     1,     1,     1,
       1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     2,     7,     3,     0,    24,
      13,    14,    15,     0,     0,    10,     0,     4,     0,     8,
      20,    11,     0,     0,    25,     0,    97,    98,    99,   100,
     101,     0,     0,    96,     0,     0,     0,     0,    71,    79,
      84,     9,     0,    30,    40,     5,    26,     0,     0,     0,
      91,    90,     0,    76,    77,    78,     0,    73,    74,    75,
       0,    83,    81,    82,     0,    89,    88,    87,    86,     0,
      21,    32,    43,     7,     0,     0,     0,    92,     0,    72,
      80,    85,    36,    31,     0,    27,    93,    94,    95,    17,
      18,    19,    16,    38,    39,     0,    35,     0,    66,     0,
       0,    41,     0,     0,    42,    44,    45,    46,    48,    47,
      49,    24,     0,    33,    37,     0,     0,     0,     0,     0,
      64,     0,     0,    58,    60,    28,    34,    22,    12,     0,
       0,     0,    70,    67,     0,     0,    55,    51,     0,    43,
       0,     0,     0,    56,     0,     0,    68,    65,     0,     0,
       0,     0,     0,    43,    29,    23,     0,    69,    54,    53,
      52,    50,    59,    62,     0,    43,     0,    57,    63,    61
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     6,     9,    23,     7,     8,    14,    15,   114,
      16,    92,    21,   128,    17,    24,    73,   111,   141,    25,
      71,    83,    95,    96,    97,    45,    72,    84,   104,   105,
     138,   106,   135,   107,   108,   139,   109,   140,   166,   110,
     134,   119,   120,   131,    37,    60,    38,    64,    39,    69,
      40
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -124
static const yytype_int16 yypact[] =
{
       6,    26,    58,    15,  -124,  -124,    16,  -124,    11,  -124,
    -124,  -124,  -124,    17,    24,  -124,    57,    79,    -4,    11,
    -124,    32,    72,    73,  -124,    49,  -124,  -124,  -124,  -124,
    -124,    52,    59,    66,    -4,    -4,    -4,    -5,    21,   103,
    -124,  -124,   111,  -124,  -124,  -124,  -124,    -4,    -4,    -4,
    -124,  -124,     1,  -124,  -124,  -124,    96,  -124,  -124,  -124,
      -4,  -124,  -124,  -124,    -4,  -124,  -124,  -124,  -124,    -4,
    -124,    92,  -124,    16,     5,    37,    44,  -124,    63,    21,
     103,  -124,   -18,  -124,   129,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,   -10,  -124,    11,    -8,    94,
      99,  -124,    -4,    -4,  -124,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,   -18,  -124,  -124,   136,    -4,    -4,    -4,   113,
    -124,    -4,   149,    87,    87,    79,  -124,  -124,   115,    47,
      75,    61,    87,  -124,   121,    69,    87,  -124,    70,  -124,
     135,    73,   156,  -124,   151,    -4,  -124,  -124,    -4,   127,
     160,   130,   139,  -124,  -124,  -124,    -4,    87,    87,  -124,
    -124,  -124,  -124,   119,    78,  -124,   141,  -124,   142,  -124
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -124,  -124,  -124,  -124,  -124,   104,  -124,  -124,   157,  -124,
      81,  -124,  -124,  -124,    68,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,  -124,    71,  -124,    39,  -124,  -123,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,  -124,  -124,   -36,  -124,   122,  -124,   117,  -124,
     -20
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -7
static const yytype_int16 yytable[] =
{
      52,    26,    27,    28,    29,    30,    31,    32,    33,     1,
     116,    74,    75,    76,    50,    51,   152,    93,    94,    34,
      -6,    53,    54,    55,    10,    11,    12,    53,    54,    55,
     163,    53,    54,    55,   112,    -6,    35,   117,     3,   113,
     118,    56,   168,    61,    36,    57,    58,    59,    13,    81,
      77,    57,    58,    59,    86,    57,    58,    59,     4,     5,
      62,    63,    18,    53,    54,    55,   123,   124,    19,    20,
      53,    54,    55,    53,    54,    55,    89,    90,    91,    42,
     129,   130,   132,    22,    43,   136,    87,    57,    58,    59,
      88,   143,    44,    46,    57,    58,    59,    57,    58,    59,
      47,    53,    54,    55,    53,    54,    55,    48,   145,   157,
     146,    49,   158,    53,    54,    55,   148,   150,   149,   151,
     164,   144,   167,    70,    65,    57,    58,    59,    57,    58,
      59,    98,    66,    67,    78,    99,   100,    57,    58,    59,
      82,    98,   121,   102,    68,    99,   100,   122,   127,   101,
     103,    98,   165,   102,    98,    99,   100,   133,    99,   100,
     103,   137,   142,   102,   162,   147,   102,   153,   155,   156,
     103,   159,   160,   103,   161,   169,    41,    85,   115,   125,
     154,    80,    79,   126
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-124))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_uint8 yycheck[] =
{
      36,     5,     6,     7,     8,     9,    10,    11,    12,     3,
      18,    47,    48,    49,    34,    35,   139,    35,    36,    23,
       4,    26,    27,    28,    13,    14,    15,    26,    27,    28,
     153,    26,    27,    28,    44,    19,    40,    45,    12,    49,
      48,    46,   165,    22,    48,    50,    51,    52,    37,    69,
      49,    50,    51,    52,    49,    50,    51,    52,     0,    44,
      39,    40,    45,    26,    27,    28,   102,   103,    44,    12,
      26,    27,    28,    26,    27,    28,    13,    14,    15,    47,
     116,   117,   118,     4,    12,   121,    49,    50,    51,    52,
      46,    44,    19,    44,    50,    51,    52,    50,    51,    52,
      48,    26,    27,    28,    26,    27,    28,    48,    47,   145,
      49,    45,   148,    26,    27,    28,    47,    47,    49,    49,
     156,    46,    44,    12,    21,    50,    51,    52,    50,    51,
      52,    12,    29,    30,    38,    16,    17,    50,    51,    52,
      48,    12,    48,    24,    41,    16,    17,    48,    12,    20,
      31,    12,    33,    24,    12,    16,    17,    44,    16,    17,
      31,    12,    47,    24,    25,    44,    24,    32,    12,    18,
      31,    44,    12,    31,    44,    34,    19,    73,    97,   111,
     141,    64,    60,   112
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    54,    12,     0,    44,    55,    58,    59,    56,
      13,    14,    15,    37,    60,    61,    63,    67,    45,    44,
      12,    65,     4,    57,    68,    72,     5,     6,     7,     8,
       9,    10,    11,    12,    23,    40,    48,    97,    99,   101,
     103,    61,    47,    12,    19,    78,    44,    48,    48,    45,
     103,   103,    97,    26,    27,    28,    46,    50,    51,    52,
      98,    22,    39,    40,   100,    21,    29,    30,    41,   102,
      12,    73,    79,    69,    97,    97,    97,    49,    38,    99,
     101,   103,    48,    74,    80,    58,    49,    49,    46,    13,
      14,    15,    64,    35,    36,    75,    76,    77,    12,    16,
      17,    20,    24,    31,    81,    82,    84,    86,    87,    89,
      92,    70,    44,    49,    62,    63,    18,    45,    48,    94,
      95,    48,    48,    97,    97,    67,    76,    12,    66,    97,
      97,    96,    97,    44,    93,    85,    97,    12,    83,    88,
      90,    71,    47,    44,    46,    47,    49,    44,    47,    49,
      47,    49,    80,    32,    78,    12,    18,    97,    97,    44,
      12,    44,    25,    80,    97,    33,    91,    44,    80,    34
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1806 of yacc.c  */
#line 79 "pascual1.y"
    {
	  introducir_programa(tabsim,(yyvsp[(2) - (3)].identificador).nombre,0);
	  fprintf(f,"<Programa name=%c%s%c>\n",34,(yyvsp[(2) - (3)].identificador).nombre,34);
      nivel = 0;
      inicializar_tabla (tabsim);
    }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 86 "pascual1.y"
    {
		fprintf(f,"%s<declaracion_acciones>\n",tabular(1));
	}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 90 "pascual1.y"
    {
		fprintf(f,"%s</declaracion_acciones>\n",tabular(1));
	}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 94 "pascual1.y"
    {
      eliminar_variables (tabsim, nivel);
      eliminar_acciones (tabsim, nivel);
      --nivel;
	  fprintf(f,"</Programa>\n");
    }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 105 "pascual1.y"
    {
		fprintf(f,"%s<declaracion_variables>\n",tabular(nivel+1));
	}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 109 "pascual1.y"
    {
		fprintf(f,"%s</declaracion_variables>\n",tabular(nivel+1));
	}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 127 "pascual1.y"
    {
		(yyval.listaParametros)=(yyvsp[(2) - (2)].listaParametros);
	}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 137 "pascual1.y"
    {
		(yyval.variable).tipo=ENTERO;
		(yyval.variable).tpContenido=DESCONOCIDO; 
	 }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 142 "pascual1.y"
    {
		(yyval.variable).tipo=CHAR; 
		(yyval.variable).tpContenido=DESCONOCIDO; 
	}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 147 "pascual1.y"
    {
		(yyval.variable).tipo=BOOLEANO; 
		(yyval.variable).tpContenido==DESCONOCIDO; 
	}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 152 "pascual1.y"
    {
		(yyval.variable).tipo=VECTOR;
		if (( (yyvsp[(3) - (6)].variable).tipo != ENTERO ) || ( (yyvsp[(3) - (6)].variable).constante = 0 ))
			{
				error_semantico("El indice debe ser constante.");
			}	
		else{
			if ((yyvsp[(3) - (6)].variable).valor <= 0){
				error_semantico("ERROR: el rango debe ser mayor de 1");
			    fprintf(f,"hola");
			}
		    else{
			
				(yyval.variable).dim1=(yyvsp[(3) - (6)].variable).valor;
			}
		}
		(yyval.variable).tpContenido = (yyvsp[(6) - (6)].tipo);
	}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 174 "pascual1.y"
    {(yyval.tipo)=ENTERO;}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 175 "pascual1.y"
    {(yyval.tipo)=CHAR;}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 176 "pascual1.y"
    {(yyval.tipo)=BOOLEANO;}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 181 "pascual1.y"
    {
		(yyval.variable)=(yyvsp[(0) - (1)].variable);  
		if (((yyvsp[(1) - (1)].identificador).simbolo == NULL) || ((yyvsp[(1) - (1)].identificador).simbolo->nivel!=nivel)){ /*No existe y lo metemos*/
			(yyvsp[(1) - (1)].identificador).simbolo=introducir_variable(tabsim, (yyvsp[(1) - (1)].identificador).nombre,(yyvsp[(0) - (1)].variable).tipo,nivel,0);
			(yyvsp[(1) - (1)].identificador).simbolo->tipo=VARIABLE;
			fprintf(f,"%s<var nombre = %c%s%c    tipo = %c",tabular(nivel+2),34,(yyvsp[(1) - (1)].identificador).nombre,34,34);
			
			if ((yyvsp[(1) - (1)].identificador).simbolo->variable==ENTERO) fprintf(f,"entero%c/>\n",34);					/*ENTERO*/
			else if ((yyvsp[(1) - (1)].identificador).simbolo->variable==CHAR) fprintf(f,"caracter%c/>\n",34);			/*CHAR*/
			else if ((yyvsp[(1) - (1)].identificador).simbolo->variable==BOOLEANO) fprintf(f,"booleano%c/>\n",34);		/*BOOLEANO*/
			else if ((yyvsp[(1) - (1)].identificador).simbolo->variable==VECTOR){											/*VECTOR*/
				(yyvsp[(1) - (1)].identificador).simbolo->dim1=(yyvsp[(0) - (1)].variable).dim1;
				(yyvsp[(1) - (1)].identificador).simbolo->tpContenido=(yyvsp[(0) - (1)].variable).tpContenido;
				fprintf(f,"vector%c",34);
				if ((yyvsp[(1) - (1)].identificador).simbolo->tpContenido==ENTERO) fprintf(f,"    %cvalores=entero%c",34,34);
				else if ((yyvsp[(1) - (1)].identificador).simbolo->tpContenido==CHAR) fprintf(f,"    %cvalores=caracter%c",34,34);
				else if ((yyvsp[(1) - (1)].identificador).simbolo->tpContenido==BOOLEANO) fprintf(f,"    %cvalores=booleano%c",34,34);
				fprintf(f,"    sup=%c%d%c/>\n",34,(yyvsp[(1) - (1)].identificador).simbolo->dim1,34);
			}

		}
		else error_semantico("Identificador duplicado.");
	 }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 205 "pascual1.y"
    {
		(yyval.variable)=(yyvsp[(0) - (3)].variable);
		if (((yyvsp[(3) - (3)].identificador).simbolo==NULL) || ((yyvsp[(3) - (3)].identificador).simbolo->nivel!=nivel)){
			(yyvsp[(3) - (3)].identificador).simbolo=introducir_variable(tabsim,(yyvsp[(3) - (3)].identificador).nombre,(yyvsp[(1) - (3)].variable).tipo,nivel,0);
			(yyvsp[(3) - (3)].identificador).simbolo->tipo=VARIABLE;
			fprintf(f,"%s<var nombre = %c%s%c    tipo = %c",tabular(nivel+2),34,(yyvsp[(3) - (3)].identificador).nombre,34,34);
			
			if ((yyvsp[(3) - (3)].identificador).simbolo->variable==ENTERO) fprintf(f,"entero%c/>\n",34);
			else if ((yyvsp[(3) - (3)].identificador).simbolo->variable==CHAR) fprintf(f,"caracter%c/>\n",34);
			else if ((yyvsp[(3) - (3)].identificador).simbolo->variable==BOOLEANO) fprintf(f,"booleano%c/>\n",34);
			if ((yyvsp[(3) - (3)].identificador).simbolo->variable==VECTOR){
				(yyvsp[(3) - (3)].identificador).simbolo->dim1=(yyvsp[(0) - (3)].variable).dim1;
				(yyvsp[(3) - (3)].identificador).simbolo->tpContenido=(yyvsp[(1) - (3)].variable).tpContenido;
				fprintf(f,"vector%c",34);
				if ((yyvsp[(3) - (3)].identificador).simbolo->tpContenido==ENTERO) fprintf(f,"    %cvalores=entero%c",34,34);
				else if ((yyvsp[(3) - (3)].identificador).simbolo->tpContenido==CHAR) fprintf(f,"    %cvalores=caracter%c",34,34);
				else if ((yyvsp[(3) - (3)].identificador).simbolo->tpContenido==BOOLEANO) fprintf(f,"    %cvalores=booleano%c",34,34);
				fprintf(f,"    sup=%c%d%c/>\n",34,(yyvsp[(3) - (3)].identificador).simbolo->dim1,34);
			}
		}
	}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 233 "pascual1.y"
    {
		if (((yyvsp[(1) - (1)].identificador).simbolo==NULL) || ((yyvsp[(1) - (1)].identificador).simbolo->nivel!=nivel)){
			(yyvsp[(1) - (1)].identificador).simbolo=introducir_parametro(tabsim,(yyvsp[(1) - (1)].identificador).nombre,(yyvsp[(0) - (1)].variable).tipo,(yyvsp[(-1) - (1)].tpPar),nivel,0);
			fprintf(f,"%s<parametro nombre=%c%s%c     tipo=",tabular(nivel+2),34,(yyvsp[(1) - (1)].identificador).nombre,34);
			(yyvsp[(1) - (1)].identificador).simbolo->tipo=PARAMETRO;
			if ((yyvsp[(1) - (1)].identificador).simbolo->variable==ENTERO) fprintf(f,"%centero%c",34,34);
			else if ((yyvsp[(1) - (1)].identificador).simbolo->variable==CHAR) fprintf(f,"%ccaracter%c",34,34);
			else if ((yyvsp[(1) - (1)].identificador).simbolo->variable==BOOLEANO) fprintf(f,"%cbooleano%c",34,34);
			else if ((yyvsp[(1) - (1)].identificador).simbolo->variable==VECTOR){ 
				(yyvsp[(1) - (1)].identificador).simbolo->tpContenido=(yyvsp[(0) - (1)].variable).tpContenido;
				(yyvsp[(1) - (1)].identificador).simbolo->dim1=(yyvsp[(0) - (1)].variable).dim1;
				fprintf(f,"%cvector%c",34,34);
				if ((yyvsp[(1) - (1)].identificador).simbolo->tpContenido==ENTERO) fprintf(f,"    %cvalores=entero%c",34,34);
				else if ((yyvsp[(1) - (1)].identificador).simbolo->tpContenido==CHAR) fprintf(f,"    %cvalores=caracter%c",34,34);
				else if ((yyvsp[(1) - (1)].identificador).simbolo->tpContenido==BOOLEANO) fprintf(f,"    %cvalores=booleano%c",34,34);
				fprintf(f,"    sup=%c%d%c",34,(yyvsp[(1) - (1)].identificador).simbolo->dim1,34);
			}
			if ((yyvsp[(1) - (1)].identificador).simbolo->parametro==VAL) fprintf(f,"    paso=%cval%c />\n",34,34);
			else if ((yyvsp[(1) - (1)].identificador).simbolo->parametro==REF) fprintf(f,"    paso=%cref%c />\n",34,34);
			crear_unitaria_copiando(&(yyval.listaParametros),(yyvsp[(1) - (1)].identificador).simbolo,sizeof(SIMBOLO));
		}
		else{
			error_semantico("Identificador duplicado.");
			crear_vacia(&(yyval.listaParametros)); 
		}
	}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 260 "pascual1.y"
    {
		if (((yyvsp[(3) - (3)].identificador).simbolo==NULL) || ((yyvsp[(3) - (3)].identificador).simbolo->nivel!=nivel)){
			(yyvsp[(3) - (3)].identificador).simbolo=introducir_parametro(tabsim,(yyvsp[(3) - (3)].identificador).nombre,(yyvsp[(0) - (3)].variable).tipo,(yyvsp[(-1) - (3)].tpPar),nivel,0);
			(yyvsp[(3) - (3)].identificador).simbolo->tipo=VARIABLE;
			fprintf(f,"%s<parametro nombre=%c%s%c     tipo=",tabular(nivel+2),34,(yyvsp[(3) - (3)].identificador).nombre,34);
			if ((yyvsp[(3) - (3)].identificador).simbolo->variable==ENTERO) fprintf(f,"%centero%c",34,34);
			else if ((yyvsp[(3) - (3)].identificador).simbolo->variable==CHAR) fprintf(f,"%ccaracter%c",34,34);
			else if ((yyvsp[(3) - (3)].identificador).simbolo->variable==BOOLEANO) fprintf(f,"%cbooleano%c",34,34);
			else if ((yyvsp[(3) - (3)].identificador).simbolo->variable==VECTOR){ 
				(yyvsp[(3) - (3)].identificador).simbolo->tpContenido=(yyvsp[(0) - (3)].variable).tpContenido;
				(yyvsp[(3) - (3)].identificador).simbolo->dim1=(yyvsp[(0) - (3)].variable).dim1;
				fprintf(f,"%cvector%c",34,34);
				if ((yyvsp[(3) - (3)].identificador).simbolo->tpContenido==ENTERO) fprintf(f,"    %cvalores=entero%c",34,34);
				else if ((yyvsp[(3) - (3)].identificador).simbolo->tpContenido==CHAR) fprintf(f,"    %cvalores=caracter%c",34,34);
				else if ((yyvsp[(3) - (3)].identificador).simbolo->tpContenido==BOOLEANO) fprintf(f,"    %cvalores=booleano%c",34,34);
				fprintf(f,"    sup=%c%d%c",34,(yyvsp[(3) - (3)].identificador).simbolo->dim1,34);
			}
			if ((yyvsp[(3) - (3)].identificador).simbolo->parametro==VAL) fprintf(f,"    paso=%cval%c />\n",34,34);
			else if ((yyvsp[(3) - (3)].identificador).simbolo->parametro==REF) fprintf(f,"    paso=%cref%c />\n",34,34);
			SIMBOLO *s=(yyvsp[(3) - (3)].identificador).simbolo;
			anadir_derecha(s,&(yyvsp[(1) - (3)].listaParametros));
			(yyval.listaParametros)=(yyvsp[(1) - (3)].listaParametros);
		}
		else{
			error_semantico("Identificador duplicado.");
			crear_vacia(&(yyval.listaParametros)); 
		}
	}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 293 "pascual1.y"
    {fprintf(f," no hay acciones dentro\n ");}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 298 "pascual1.y"
    {fprintf(f,"principio\n");}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 299 "pascual1.y"
    {fprintf(f,"variables\n");}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 300 "pascual1.y"
    {fprintf(f,"acciones\n");}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 302 "pascual1.y"
    {
		fprintf(f,"%s</accion>\n",tabular(nivel+2));
		fprintf(f,"fin bloque inst de la accion");
	 }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 310 "pascual1.y"
    {
		if(((yyvsp[(2) - (2)].identificador).simbolo==NULL) || ((yyvsp[(2) - (2)].identificador).simbolo->nivel!=nivel)){
			(yyvsp[(2) - (2)].identificador).simbolo=introducir_accion(tabsim, (yyvsp[(2) - (2)].identificador).nombre,nivel,0);		
			fprintf(f,"%s<accion nombre = %c%s%c>\n",tabular(nivel+2),34,(yyvsp[(2) - (2)].identificador).simbolo->nombre,34);
		} 
		else error_semantico("El identificador ya existe.");
		nivel++;
	 }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 319 "pascual1.y"
    {
		(yyvsp[(2) - (4)].identificador).simbolo->parametros=(yyvsp[(4) - (4)].listaParametros);  
	 }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 325 "pascual1.y"
    {
		crear_vacia(&(yyval.listaParametros));
	}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 329 "pascual1.y"
    {
		(yyval.listaParametros)=(yyvsp[(2) - (3)].listaParametros);
	}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 336 "pascual1.y"
    {
		concatenar( &(yyvsp[(1) - (3)].listaParametros),(yyvsp[(3) - (3)].listaParametros));  
		(yyval.listaParametros)=(yyvsp[(1) - (3)].listaParametros);
	 }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 341 "pascual1.y"
    {
		(yyval.listaParametros)=(yyvsp[(1) - (1)].listaParametros);
	}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 344 "pascual1.y"
    {crear_vacia(&(yyval.listaParametros));}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 349 "pascual1.y"
    {
		(yyval.listaParametros)=(yyvsp[(2) - (2)].listaParametros);
	 }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 356 "pascual1.y"
    {
		(yyval.tpPar)=VAL;
	 }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 360 "pascual1.y"
    {	
		(yyval.tpPar)=REF;
	 }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 366 "pascual1.y"
    {fprintf(f,"despues de principio\n");}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 367 "pascual1.y"
    {  fprintf(f,"ojo principio arras");
	 	eliminar_variables(tabsim,nivel);
		ocultar_parametros(tabsim,nivel);
		eliminar_parametros_ocultos(tabsim,nivel);
		eliminar_acciones(tabsim,nivel+1);
		nivel--;
	 }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 377 "pascual1.y"
    {fprintf(f," hay instrucciones");}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 378 "pascual1.y"
    {fprintf(f,"no hay instrucciones");}
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 398 "pascual1.y"
    {
		if ((yyvsp[(1) - (1)].identificador).simbolo==NULL){ //Si no lo conocemos
			error_semantico("Identificador no declarado.");     
			(yyvsp[(1) - (1)].identificador).simbolo=introducir_variable(tabsim,(yyvsp[(1) - (1)].identificador).nombre,DESCONOCIDO,nivel,0); 	//Marcamos como desconocido
		}
		else{ 
			if (((yyvsp[(1) - (1)].identificador).simbolo->tipo!=VARIABLE) && ((yyvsp[(1) - (1)].identificador).simbolo->tipo!=PARAMETRO)) 		//Si no es ni variable ni parametro
				error_semantico("El identificador no es ni variable ni parametro.");
			else{
				if (((yyvsp[(1) - (1)].identificador).simbolo->variable!=ENTERO) && ((yyvsp[(1) - (1)].identificador).simbolo->variable!=CHAR)) //Añadir BOOLEANO??       <-----------------------
					error_semantico("El identificador no se puede leer");
			}
		}
	 }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 413 "pascual1.y"
    { //Igual que la anterior produccion pero cambiando los $numero
		if ((yyvsp[(3) - (3)].identificador).simbolo==NULL){
			error_semantico("Identificador no declarado.");
			(yyvsp[(3) - (3)].identificador).simbolo=introducir_variable(tabsim,(yyvsp[(3) - (3)].identificador).nombre,DESCONOCIDO,nivel,0);
		}
		else{
			if (((yyvsp[(3) - (3)].identificador).simbolo->tipo!=VARIABLE) && ((yyvsp[(3) - (3)].identificador).simbolo->tipo!=PARAMETRO))
				error_semantico("El identificador no es ni variable ni parametro.");
			else{
				if (((yyvsp[(3) - (3)].identificador).simbolo->variable!=ENTERO) && ((yyvsp[(3) - (3)].identificador).simbolo->variable!=CHAR))
					error_semantico("Tipos incompatibles.");
			}
		}
	}
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 441 "pascual1.y"
    {
		if ((yyvsp[(1) - (4)].identificador).simbolo == NULL)								//No conocemos el identificador
		{
			error_semantico("Identificador desconocido.");
		}
		else
		{
			if ((yyvsp[(1) - (4)].identificador).simbolo->nivel>nivel)                    //Si esta en otro nivel
			{
				error_semantico("Identificador desconocido.");
			}
			else{
				if (((yyvsp[(1) - (4)].identificador).simbolo->tipo != VARIABLE) && ((yyvsp[(1) - (4)].identificador).simbolo->tipo != PARAMETRO)) //Si no es var o par ( intentan colarnos una accion o programa)
				{
					error_semantico("El identificador debe ser una variable o un parametro.");
				}
				else
				{
					if (((yyvsp[(1) - (4)].identificador).simbolo->tipo == PARAMETRO) && ((yyvsp[(1) - (4)].identificador).simbolo->parametro == VAL)) //Parametro de entrada por valor
					{
						error_semantico("No se puede asignar valor a un parametro de entrada.");
					}
					else
					{	
						if (((yyvsp[(1) - (4)].identificador).simbolo->variable != DESCONOCIDO) && ((yyvsp[(3) - (4)].variable).tipo != DESCONOCIDO) && ((yyvsp[(1) - (4)].identificador).simbolo->variable != (yyvsp[(3) - (4)].variable).tipo))
						{
							error_semantico ("Tipos incompatibles.");
						}
					}
				}
			}
		}
			
	 }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 476 "pascual1.y"
    { fprintf(f,"q pasaaaaaaaaaaaaa");
		if ((yyvsp[(1) - (7)].identificador).simbolo == NULL)								//No conocemos el identificador
		{
			error_semantico("Identificador desconocido.");
		}
		else
		{
			if (((yyvsp[(1) - (7)].identificador).simbolo->tipo != VARIABLE) && ((yyvsp[(1) - (7)].identificador).simbolo->tipo != PARAMETRO)) //Si no es var o par ( intentan colarnos una accion o programa)
			{
				error_semantico("El identificador debe ser una variable o un parametro.");
			}
			else  //Si es una variable o un parametro
			{
				if (((yyvsp[(1) - (7)].identificador).simbolo->tipo==PARAMETRO) && ((yyvsp[(1) - (7)].identificador).simbolo->parametro==VAL))      
				{
					error_semantico("No se puede asignar valor a un parametro de entrada.");
				}
				else  //Una vez comprobado el identificador, pasamor al indice.
				{
					if ((yyvsp[(3) - (7)].variable).tipo != ENTERO)
					{
						error_semantico("El indice debe ser un entero. 1,2,3...");
					}
					else if ((yyvsp[(1) - (7)].identificador).simbolo->variable == VECTOR) //si tenemos un entero, comprobamos que tIdentificador es un VECTOR.
					{
						if ((yyvsp[(3) - (7)].variable).calculable == 1) //Si podemos calcularla
						{
							if ((yyvsp[(3) - (7)].variable).valor < 0)   //limite inferior
							{
								error_semantico("Underflow.");
							}
							else if ((yyvsp[(3) - (7)].variable).valor > (yyvsp[(1) - (7)].identificador).simbolo->dim1) 
							{
								error_semantico("Overflow.");
							}
							else
							{
								if ((yyvsp[(6) - (7)].variable).tipo != DESCONOCIDO)
								{
									if (((yyvsp[(6) - (7)].variable).tipo == VECTOR) )
									{
										if ((yyvsp[(1) - (7)].identificador).simbolo->tpContenido != (yyvsp[(6) - (7)].variable).tpContenido)
										{
											error_semantico("Tipos incompatibles.");
										}
									}
									else
									{
										if ((yyvsp[(1) - (7)].identificador).simbolo->tpContenido != (yyvsp[(6) - (7)].variable).tipo)
										{
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
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 543 "pascual1.y"
    {
		if (((yyvsp[(2) - (2)].variable).tipo != DESCONOCIDO) && ((yyvsp[(2) - (2)].variable).tipo != BOOLEANO))
		{
			error_semantico("La condicion o las condiciones deben ser booleanas.");
		}
	}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 556 "pascual1.y"
    {
		if (((yyvsp[(2) - (2)].variable).tipo != DESCONOCIDO) && ((yyvsp[(2) - (2)].variable).tipo != BOOLEANO)) 
			error_semantico("La condicion o las condiciones deben ser booleanas.");
	}
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 575 "pascual1.y"
    {
		if ((yyvsp[(1) - (2)].identificador).simbolo==NULL) 								//----------------------Comprobaciones tipicas----------------------
		{
			error_semantico("Accion no declarada.");
		}
		else
		{
			if ((yyvsp[(1) - (2)].identificador).simbolo->tipo!=ACCION) 
			{
				error_semantico("No es una accion.");
			}
			else
			{
				if ((yyvsp[(1) - (2)].identificador).simbolo->nivel<(nivel-1)) 
				{
					error_semantico("Accion no declarada."); //------------------------------------------------------------------
				}
				else
				{
					if (longitud_lista((yyvsp[(1) - (2)].identificador).simbolo->parametros) != longitud_lista((yyvsp[(2) - (2)].listaParametros)))  //Los dos son listaParametros
						{
							error_semantico("Numero de parametros de la accion incorrectos.");
						}
					else                                                              //Todo aparentemente correcto
					{
						int i;
						SIMBOLO *s;
						VARIABLES *v;
						
						for(i=0; i < longitud_lista((yyvsp[(1) - (2)].identificador).simbolo->parametros) ; i++) //Tenemos que ir comprobando todos los elementos de la lista
						{
							s=(SIMBOLO *) observar((yyvsp[(1) - (2)].identificador).simbolo->parametros,i); //Recordatorio: observar devuelve el elemnto deseado de la lista (simbolo o variable)
							v=(VARIABLES *) observar((yyvsp[(2) - (2)].listaParametros),i);
							
							if ((s->variable != v->tipo) && (s->variable != DESCONOCIDO) && (v->tipo != DESCONOCIDO))
								{        //Comprobamos que las variables correscponden con lo que tienen que ser
									error_semantico("Argumento y parametro no corresponden.");
								}
							else
							{
								if ((s->variable == VECTOR) && (v->tipo == VECTOR))
								{
									if (s->dim1!=v->dim1)
									{
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
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 631 "pascual1.y"
    {
		if ((yyvsp[(1) - (1)].identificador).simbolo == NULL)  //Identificador NULL
		{	
			error_semantico("Identificador no declarado.");
		}
		else
		{
			if ((yyvsp[(1) - (1)].identificador).simbolo->tipo != ACCION)  //No permitimos acciones como parametros
			{
				error_semantico("El identificador no es una accion");
			}
			else
			{
				if ( (yyvsp[(1) - (1)].identificador).simbolo->nivel < (nivel-1) ) //Comprobamos el nivel 
				{
					error_semantico("Accion no declarada.");
				}
				else
				{
					if ( longitud_lista((yyvsp[(1) - (1)].identificador).simbolo->parametros) > 0 ) //Si tiene parametros es erroneo
					{
						error_semantico("Numero de parametros no corresponden.");
					}
				}
			}
		}		
	}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 663 "pascual1.y"
    {
		(yyval.listaParametros)=(yyvsp[(2) - (3)].listaParametros);
	}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 670 "pascual1.y"
    {
		anadir_derecha_copiando( (ELEMENTO)&(yyvsp[(3) - (3)].variable), &(yyval.listaParametros), sizeof(VARIABLES) );
	 }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 674 "pascual1.y"
    {
		crear_unitaria_copiando( &(yyval.listaParametros), (ELEMENTO)&(yyvsp[(1) - (1)].variable), sizeof(VARIABLES) );
	}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 681 "pascual1.y"
    {
		(yyval.variable)=(yyvsp[(1) - (1)].variable);
	}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 685 "pascual1.y"
    {
		if (((yyvsp[(1) - (3)].variable).tipo != DESCONOCIDO) && ((yyvsp[(3) - (3)].variable).tipo != DESCONOCIDO) && ((yyvsp[(1) - (3)].variable).tipo != (yyvsp[(3) - (3)].variable).tipo)){
			error_semantico("Los operadores deben ser del mismo tipo.");
			(yyval.variable).tipo=DESCONOCIDO;
		}
		else { //Si no son ENTERO o CHAR
			if ((((yyvsp[(1) - (3)].variable).tipo != DESCONOCIDO) && ((yyvsp[(1) - (3)].variable).tipo != ENTERO) && ((yyvsp[(1) - (3)].variable).tipo != CHAR)) || 
				(((yyvsp[(3) - (3)].variable).tipo != DESCONOCIDO) && ((yyvsp[(3) - (3)].variable).tipo != ENTERO)) && ((yyvsp[(3) - (3)].variable).tipo != CHAR)){
					error_semantico("Los operadores deben ser enteros o caracteres.");
					(yyval.variable).tipo=DESCONOCIDO;
			}
			else{ //Es BOOLEANO
				(yyval.variable).tipo=BOOLEANO;
				(yyval.variable).exprSimple=0;
			}
		}
	}
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 715 "pascual1.y"
    { 
		(yyval.variable)=(yyvsp[(1) - (1)].variable);
	 }
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 719 "pascual1.y"
    {
		if ((yyvsp[(2) - (3)].operador) == 0) {  // +
			if ((((yyvsp[(1) - (3)].variable).tipo != ENTERO) || ((yyvsp[(3) - (3)].variable).tipo != ENTERO)) && ((yyvsp[(1) - (3)].variable).tipo != DESCONOCIDO) && ((yyvsp[(3) - (3)].variable).tipo != DESCONOCIDO)){
				error_semantico("Los operadores deben ser enteros.");
				(yyval.variable).tipo=DESCONOCIDO;
			}
			else{
				if ((((double) (yyvsp[(1) - (3)].variable).valor + (double)(yyvsp[(3) - (3)].variable).valor) < -2147483647) || (((double) (yyvsp[(1) - (3)].variable).valor + (double)(yyvsp[(3) - (3)].variable).valor) > 2147483647)){
					(yyval.variable).tipo=DESCONOCIDO;
					error_semantico("Overflow.");
				}
				else{
					(yyval.variable).tipo=ENTERO;	
					if (((yyvsp[(1) - (3)].variable).calculable == 1) && ((yyvsp[(3) - (3)].variable).calculable == 1)){
						(yyval.variable).valor=(yyvsp[(1) - (3)].variable).valor+(yyvsp[(3) - (3)].variable).valor;
						(yyval.variable).calculable=1;
					}
					else (yyval.variable).calculable=0;
					(yyval.variable).constante=0;
					(yyval.variable).exprSimple=0;
				}
			}
		} 
		else if ((yyvsp[(2) - (3)].operador) == 1){  // -
			if (((yyvsp[(1) - (3)].variable).tipo != ENTERO) || ((yyvsp[(3) - (3)].variable).tipo != ENTERO)){
				error_semantico("Los operadores deben ser enteros.");
				(yyval.variable).tipo=DESCONOCIDO;
			}
			else{
				if ((((double) (yyvsp[(1) - (3)].variable).valor - (double)(yyvsp[(3) - (3)].variable).valor) < -2147483647) || (((double) (yyvsp[(1) - (3)].variable).valor - (double)(yyvsp[(3) - (3)].variable).valor) > 2147483647)){
					(yyval.variable).tipo=DESCONOCIDO;
					error_semantico("Overflow.");
				}
				else{
					(yyval.variable).tipo=ENTERO;	
					if (((yyvsp[(1) - (3)].variable).calculable == 1) && ((yyvsp[(3) - (3)].variable).calculable == 1)){
						(yyval.variable).valor=(yyvsp[(1) - (3)].variable).valor-(yyvsp[(3) - (3)].variable).valor;
						(yyval.variable).calculable=1;
					}
					else (yyval.variable).calculable=0;
					(yyval.variable).constante=0;
					(yyval.variable).exprSimple=0;
				}
			}
		}
		else{		//$2= OR
			if (((yyvsp[(1) - (3)].variable).tipo != BOOLEANO) || ((yyvsp[(3) - (3)].variable).tipo != BOOLEANO)){
				error_semantico("Los operadores deben ser booleanos.");
				(yyval.variable).tipo=DESCONOCIDO;
			}
			else {
				(yyval.variable).tipo=BOOLEANO;
				(yyval.variable).exprSimple=0;
			} 
		}
	}
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 779 "pascual1.y"
    {
		(yyval.operador)=0;
	 }
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 783 "pascual1.y"
    {
		(yyval.operador)=1;
	 }
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 787 "pascual1.y"
    {
		(yyval.operador)=2;
	 }
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 794 "pascual1.y"
    {
		(yyval.variable)=(yyvsp[(1) - (1)].variable);
	 }
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 798 "pascual1.y"
    {
		if ((yyvsp[(2) - (3)].operador)==0) {
			if (((yyvsp[(1) - (3)].variable).tipo!=ENTERO) || ((yyvsp[(3) - (3)].variable).tipo!=ENTERO)){
				error_semantico("Los operadores deben ser enteros.");
				(yyval.variable).tipo=DESCONOCIDO;
			}
			else{
				if ((((double) (yyvsp[(1) - (3)].variable).valor*(double)(yyvsp[(3) - (3)].variable).valor)<-2147483647) || (((double) (yyvsp[(1) - (3)].variable).valor*(double)(yyvsp[(3) - (3)].variable).valor)>2147483647)){
					(yyval.variable).tipo=DESCONOCIDO;
					error_semantico("Overflow.");
				}
				else{
					(yyval.variable).tipo=ENTERO;	
					if (((yyvsp[(1) - (3)].variable).calculable==1) && ((yyvsp[(3) - (3)].variable).calculable==1)){
						(yyval.variable).valor=(yyvsp[(1) - (3)].variable).valor*(yyvsp[(3) - (3)].variable).valor;
						(yyval.variable).calculable=1;
					}
					else (yyval.variable).calculable=0;
					(yyval.variable).constante=0;
					(yyval.variable).exprSimple=0;
				}
			}
		}
		else if ((yyvsp[(2) - (3)].operador)==1){
			if (((yyvsp[(1) - (3)].variable).tipo!=ENTERO) || ((yyvsp[(3) - (3)].variable).tipo!=ENTERO)){
				error_semantico("Los operadores deben ser enteros.");
				(yyval.variable).tipo=DESCONOCIDO;
			}
			else{
				(yyval.variable).tipo=ENTERO;
				if (((yyvsp[(1) - (3)].variable).calculable==1) && ((yyvsp[(3) - (3)].variable).calculable==1)){
					if ((yyvsp[(3) - (3)].variable).valor!=0){
						(yyval.variable).valor=(yyvsp[(1) - (3)].variable).valor/(yyvsp[(3) - (3)].variable).valor;
						(yyval.variable).calculable=1;
					}
					else{ 
						error_semantico("Division por cero.");
						(yyval.variable).tipo=DESCONOCIDO;
						(yyval.variable).calculable=0;
					}
				}
				else (yyval.variable).calculable=0;
				(yyval.variable).constante=0;
				(yyval.variable).exprSimple=0;
				
			}
		}
		else if ((yyvsp[(2) - (3)].operador)==2){
			if (((yyvsp[(1) - (3)].variable).tipo!=ENTERO) || ((yyvsp[(3) - (3)].variable).tipo!=ENTERO)){
				error_semantico("Los operadores deben ser enteros.");
				(yyval.variable).tipo=DESCONOCIDO;
			}
			else{
				(yyval.variable).tipo=ENTERO;
				if (((yyvsp[(1) - (3)].variable).calculable==1) && ((yyvsp[(3) - (3)].variable).calculable==1)){
					(yyval.variable).valor=(yyvsp[(1) - (3)].variable).valor%(yyvsp[(3) - (3)].variable).valor;
					(yyval.variable).calculable=1;
				}
				else (yyval.variable).calculable=0;
				(yyval.variable).constante=0;
				(yyval.variable).exprSimple=0;
			}
		}
		else{   // $2==3
			if (((yyvsp[(1) - (3)].variable).tipo!=BOOLEANO) || ((yyvsp[(3) - (3)].variable).tipo!=BOOLEANO)){
				error_semantico("Los operadores deben ser booleanos.");
				(yyval.variable).tipo=DESCONOCIDO;
			}
			else {
				(yyval.variable).tipo=BOOLEANO;
				(yyval.variable).exprSimple=0;
			}
		}
	 }
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 876 "pascual1.y"
    {
		(yyval.operador)=0;
	 }
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 880 "pascual1.y"
    {
		(yyval.operador)=1;
	 }
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 884 "pascual1.y"
    {
		(yyval.operador)=2;
	 }
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 888 "pascual1.y"
    {
		(yyval.operador)=3;
	 }
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 895 "pascual1.y"
    {
		if (((yyvsp[(2) - (2)].variable).tipo!=ENTERO) && ((yyvsp[(2) - (2)].variable).tipo!=DESCONOCIDO)){ 
			(yyval.variable).tipo=DESCONOCIDO;
			error_semantico("Tipos incompatibles.");
		}
		else{
			(yyval.variable).constante=(yyvsp[(2) - (2)].variable).constante;
			(yyval.variable).tipo=ENTERO;
			(yyval.variable).valor=-(yyvsp[(2) - (2)].variable).valor;
			(yyval.variable).calculable=(yyvsp[(2) - (2)].variable).calculable;
		}
	}
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 908 "pascual1.y"
    {
		if ((yyvsp[(2) - (2)].variable).tipo!=BOOLEANO){ 
			(yyval.variable).tipo=DESCONOCIDO;
			error_semantico("Tipos incompatibles.");
		}
		else  (yyval.variable).tipo=BOOLEANO;
	}
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 916 "pascual1.y"
    {
		(yyval.variable)=(yyvsp[(2) - (3)].variable);
	}
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 920 "pascual1.y"
    {
		if ((yyvsp[(3) - (4)].variable).tipo!=ENTERO){
			error_semantico("Casteo de entero a caracter debe recibir un entero.");
			(yyval.variable).tipo=DESCONOCIDO;
		}
		else (yyval.variable).tipo=CHAR;
	}
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 928 "pascual1.y"
    {
		if ((yyvsp[(3) - (4)].variable).tipo!=CHAR){
			error_semantico("Casteo de caracter a entero debe recibir un caracter.");
			(yyval.variable).tipo=DESCONOCIDO;
		}
		else{ 
			(yyval.variable).tipo=ENTERO;
			(yyval.variable).constante=0;
		}
	}
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 939 "pascual1.y"
    { 
		(yyval.variable).exprSimple=1;
		if ((yyvsp[(1) - (4)].identificador).simbolo==NULL){ 
			error_semantico("Identificador desconocido.");
			(yyval.variable).tipo=DESCONOCIDO;
			(yyvsp[(1) - (4)].identificador).simbolo=introducir_variable(tabsim, (yyvsp[(1) - (4)].identificador).nombre,DESCONOCIDO,nivel,0);
		}
		else if (((yyvsp[(3) - (4)].variable).tipo!=DESCONOCIDO) && ((yyvsp[(3) - (4)].variable).tipo!=ENTERO)) error_semantico("Indice incorrecto.");
		else { 			
			if ((yyvsp[(1) - (4)].identificador).simbolo->tpContenido==ENTERO) (yyval.variable).calculable=1;
			else (yyval.variable).calculable=0;
			if (((yyvsp[(3) - (4)].variable).valor<0) && ((yyvsp[(3) - (4)].variable).calculable==1)) error_semantico("Underflow.");
			else if(((yyvsp[(3) - (4)].variable).valor>=(yyvsp[(1) - (4)].identificador).simbolo->dim1) && ((yyvsp[(3) - (4)].variable).calculable==1)) error_semantico("Overflow.");
			else{
				(yyval.variable).tipo=(yyvsp[(1) - (4)].identificador).simbolo->tpContenido;
				(yyval.variable).constante=1;
				(yyval.variable).parametros=(yyvsp[(1) - (4)].identificador).simbolo->parametro;

			}
		}
	}
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 961 "pascual1.y"
    {
		(yyval.variable).calculable=0;
		(yyval.variable).constante=0;
		(yyval.variable).exprSimple=1;
		if ((yyvsp[(1) - (1)].identificador).simbolo==NULL){ 
			error_semantico("Identificador desconocido.");
			(yyvsp[(1) - (1)].identificador).simbolo=introducir_variable(tabsim,(yyvsp[(1) - (1)].identificador).nombre,DESCONOCIDO,nivel,0);
		}
		else{
			(yyval.variable).tipo=(yyvsp[(1) - (1)].identificador).simbolo->variable;
			(yyval.variable).tpContenido=(yyvsp[(1) - (1)].identificador).simbolo->tpContenido;
			(yyval.variable).dim1=(yyvsp[(1) - (1)].identificador).simbolo->dim1;
		}
		
	}
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 977 "pascual1.y"
    {
		(yyval.variable).tipo=ENTERO;
		(yyval.variable).constante=1;
		(yyval.variable).calculable=1;
	}
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 983 "pascual1.y"
    {
		(yyval.variable).tipo=CHAR;
	}
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 987 "pascual1.y"
    {	
		(yyval.variable).tipo=CADENA ;
	}
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 991 "pascual1.y"
    {
		(yyval.variable).tipo=BOOLEANO;
	}
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 995 "pascual1.y"
    {
		(yyval.variable).tipo=BOOLEANO;
	}
    break;



/* Line 1806 of yacc.c  */
#line 2786 "y.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 1000 "pascual1.y"


/**********************************************************************/
main(int argc, char *argv[])
/**********************************************************************/
{
    extern FILE *yyin;
    char namein[100], nameout[100];

    strcpy (namein, argv[1]);
    strcat (namein, ".pc");
    yyin = fopen (namein, "r");
	f=fopen("fich.xml", "w");
    if (yyin == NULL) {
       fprintf (stderr, "Fichero %s no existe.\n", namein);
       exit (1);
    }
    yyparse ();
    fclose (yyin);
   
}


