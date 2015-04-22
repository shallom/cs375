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
#line 1 "pars1.y"
     /* pars1.y    Pascal Parser      Gordon S. Novak Jr.  ; 30 Jul 13   */

/* Copyright (c) 2013 Gordon S. Novak Jr. and
   The University of Texas at Austin. */

/* 14 Feb 01; 01 Oct 04; 02 Mar 07; 27 Feb 08; 24 Jul 09; 02 Aug 12 */

/*
; This program is free software; you can redistribute it and/or modify
; it under the terms of the GNU General Public License as published by
; the Free Software Foundation; either version 2 of the License, or
; (at your option) any later version.

; This program is distributed in the hope that it will be useful,
; but WITHOUT ANY WARRANTY; without even the implied warranty of
; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
; GNU General Public License for more details.

; You should have received a copy of the GNU General Public License
; along with this program; if not, see <http://www.gnu.org/licenses/>.
  */


/* NOTE:   Copy your lexan.l lexical analyzer to this directory.      */

       /* To use:
                     make pars1y              has 1 shift/reduce conflict
                     pars1y                   execute the parser
                     i:=j .
                     ^D                       control-D to end input

                     pars1y                   execute the parser
                     begin i:=j; if i+j then x:=a+b*c else x:=a*b+c; k:=i end.
                     ^D

                     pars1y                   execute the parser
                     if x+y then if y+z then i:=j else k:=2.
                     ^D

           You may copy pars1.y to be parse.y and extend it for your
           assignment.  Then use   make parser   as above.
        */

        /* Yacc reports 1 shift/reduce conflict, due to the ELSE part of
           the IF statement, but Yacc's default resolves it in the right way.*/

#include <stdio.h>
#include <ctype.h>
#include "token.h"
#include "lexan.h"
#include "symtab.h"
#include "parse.h"
#include <float.h>

        /* define the type of the Yacc stack element to be TOKEN */

#define YYSTYPE TOKEN

TOKEN parseresult;



/* Line 268 of yacc.c  */
#line 134 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
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
     IDENTIFIER = 258,
     STRING = 259,
     NUMBER = 260,
     PLUS = 261,
     MINUS = 262,
     TIMES = 263,
     DIVIDE = 264,
     ASSIGN = 265,
     EQ = 266,
     NE = 267,
     LT = 268,
     LE = 269,
     GE = 270,
     GT = 271,
     POINT = 272,
     DOT = 273,
     AND = 274,
     OR = 275,
     NOT = 276,
     DIV = 277,
     MOD = 278,
     IN = 279,
     COMMA = 280,
     SEMICOLON = 281,
     COLON = 282,
     LPAREN = 283,
     RPAREN = 284,
     LBRACKET = 285,
     RBRACKET = 286,
     DOTDOT = 287,
     ARRAY = 288,
     BEGINBEGIN = 289,
     CASE = 290,
     CONST = 291,
     DO = 292,
     DOWNTO = 293,
     ELSE = 294,
     END = 295,
     FILEFILE = 296,
     FOR = 297,
     FUNCTION = 298,
     GOTO = 299,
     IF = 300,
     LABEL = 301,
     NIL = 302,
     OF = 303,
     PACKED = 304,
     PROCEDURE = 305,
     PROGRAM = 306,
     RECORD = 307,
     REPEAT = 308,
     SET = 309,
     THEN = 310,
     TO = 311,
     TYPE = 312,
     UNTIL = 313,
     VAR = 314,
     WHILE = 315,
     WITH = 316
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define STRING 259
#define NUMBER 260
#define PLUS 261
#define MINUS 262
#define TIMES 263
#define DIVIDE 264
#define ASSIGN 265
#define EQ 266
#define NE 267
#define LT 268
#define LE 269
#define GE 270
#define GT 271
#define POINT 272
#define DOT 273
#define AND 274
#define OR 275
#define NOT 276
#define DIV 277
#define MOD 278
#define IN 279
#define COMMA 280
#define SEMICOLON 281
#define COLON 282
#define LPAREN 283
#define RPAREN 284
#define LBRACKET 285
#define RBRACKET 286
#define DOTDOT 287
#define ARRAY 288
#define BEGINBEGIN 289
#define CASE 290
#define CONST 291
#define DO 292
#define DOWNTO 293
#define ELSE 294
#define END 295
#define FILEFILE 296
#define FOR 297
#define FUNCTION 298
#define GOTO 299
#define IF 300
#define LABEL 301
#define NIL 302
#define OF 303
#define PACKED 304
#define PROCEDURE 305
#define PROGRAM 306
#define RECORD 307
#define REPEAT 308
#define SET 309
#define THEN 310
#define TO 311
#define TYPE 312
#define UNTIL 313
#define VAR 314
#define WHILE 315
#define WITH 316




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 298 "y.tab.c"

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
#define YYLAST   185

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNRULES -- Number of states.  */
#define YYNSTATES  182

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   316

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    13,    15,    18,    21,    24,    27,    31,
      34,    37,    41,    44,    48,    52,    56,    59,    63,    65,
      67,    71,    75,    79,    81,    83,    86,    90,    93,    97,
     101,   104,   107,   111,   115,   124,   130,   134,   138,   140,
     142,   144,   148,   150,   153,   156,   160,   165,   169,   171,
     175,   181,   183,   185,   187,   189,   193,   198,   201,   206,
     211,   218,   222,   224,   227,   228,   232,   236,   240,   244,
     248,   252,   256,   260,   262,   266,   270,   274,   276,   279,
     282,   284,   288,   290,   294,   296,   298,   300,   302
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      63,     0,    -1,    51,     3,    28,     3,    29,    26,    64,
      90,    18,    -1,    80,    -1,    76,    64,    -1,    65,    64,
      -1,    67,    64,    -1,    46,    66,    -1,     5,    25,    66,
      -1,     5,    26,    -1,    57,    68,    -1,    69,    26,    68,
      -1,    69,    26,    -1,     3,    11,    70,    -1,    52,    72,
      40,    -1,    28,    71,    29,    -1,    17,     3,    -1,     3,
      25,    71,    -1,     3,    -1,    73,    -1,    73,    26,    72,
      -1,    74,    27,    75,    -1,     3,    25,    74,    -1,     3,
      -1,     3,    -1,    36,    77,    -1,    78,    26,    77,    -1,
      78,    26,    -1,     3,    11,     5,    -1,     3,    11,     5,
      -1,    59,    81,    -1,    82,    26,    -1,    82,    26,    81,
      -1,    84,    27,    85,    -1,    84,    27,    33,    30,    83,
      31,    48,     3,    -1,     5,    32,     5,    25,     3,    -1,
       5,    32,     5,    -1,     3,    25,    84,    -1,     3,    -1,
       3,    -1,     3,    -1,    86,    18,     3,    -1,    87,    -1,
      86,    17,    -1,     3,    88,    -1,    30,    89,    31,    -1,
      30,    89,    31,    88,    -1,    97,    25,    89,    -1,    97,
      -1,    34,    90,    94,    -1,    45,    97,    55,    90,    95,
      -1,    93,    -1,    92,    -1,    96,    -1,    91,    -1,     5,
      27,    90,    -1,    60,    97,    37,    90,    -1,    44,     5,
      -1,    53,    90,    58,    79,    -1,     3,    28,    97,    29,
      -1,    42,    96,    56,     3,    37,    90,    -1,    26,    90,
      94,    -1,    40,    -1,    39,    90,    -1,    -1,   101,    10,
      97,    -1,    98,    11,    98,    -1,    98,    13,    98,    -1,
      98,    16,    98,    -1,    98,    12,    98,    -1,    98,    14,
      98,    -1,    98,    15,    98,    -1,    98,    24,    98,    -1,
      98,    -1,    98,     6,   100,    -1,    98,     7,   100,    -1,
      98,    20,   100,    -1,    99,    -1,     6,   100,    -1,     7,
     100,    -1,   100,    -1,   100,     8,   101,    -1,   101,    -1,
      28,    97,    29,    -1,    86,    -1,     5,    -1,     4,    -1,
      92,    -1,    47,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    81,    81,    84,    85,    86,    87,    90,    93,    94,
      98,   101,   102,   105,   108,   109,   110,   113,   114,   117,
     118,   121,   123,   124,   126,   129,   131,   132,   135,   137,
     139,   142,   143,   146,   147,   150,   152,   154,   155,   157,
     160,   161,   162,   163,   165,   168,   169,   171,   172,   174,
     177,   178,   179,   180,   181,   182,   183,   184,   186,   189,
     191,   193,   194,   196,   197,   199,   202,   203,   204,   205,
     206,   207,   208,   209,   212,   213,   214,   215,   218,   219,
     220,   222,   223,   226,   227,   228,   229,   230,   231
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "STRING", "NUMBER", "PLUS",
  "MINUS", "TIMES", "DIVIDE", "ASSIGN", "EQ", "NE", "LT", "LE", "GE", "GT",
  "POINT", "DOT", "AND", "OR", "NOT", "DIV", "MOD", "IN", "COMMA",
  "SEMICOLON", "COLON", "LPAREN", "RPAREN", "LBRACKET", "RBRACKET",
  "DOTDOT", "ARRAY", "BEGINBEGIN", "CASE", "CONST", "DO", "DOWNTO", "ELSE",
  "END", "FILEFILE", "FOR", "FUNCTION", "GOTO", "IF", "LABEL", "NIL", "OF",
  "PACKED", "PROCEDURE", "PROGRAM", "RECORD", "REPEAT", "SET", "THEN",
  "TO", "TYPE", "UNTIL", "VAR", "WHILE", "WITH", "$accept", "program",
  "prebegin", "labels", "label", "types", "typelist", "typeItem", "type",
  "idlist", "recordSet", "recordLine", "recordNames", "recordType",
  "constants", "constant", "constinst", "equalsNum", "variables", "varSet",
  "varLine", "btwbrackets", "varNames", "varType", "var", "mergebracks",
  "mergelist", "argslist", "statement", "repeatuntil", "funcCall",
  "forLoop", "endpart", "endif", "assignment", "expr", "simpexpr",
  "unaryexpr", "term", "factor", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    64,    64,    64,    64,    65,    66,    66,
      67,    68,    68,    69,    70,    70,    70,    71,    71,    72,
      72,    73,    74,    74,    75,    76,    77,    77,    78,    79,
      80,    81,    81,    82,    82,    83,    83,    84,    84,    85,
      86,    86,    86,    86,    87,    88,    88,    89,    89,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    91,    92,
      93,    94,    94,    95,    95,    96,    97,    97,    97,    97,
      97,    97,    97,    97,    98,    98,    98,    98,    99,    99,
      99,   100,   100,   101,   101,   101,   101,   101,   101
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     9,     1,     2,     2,     2,     2,     3,     2,
       2,     3,     2,     3,     3,     3,     2,     3,     1,     1,
       3,     3,     3,     1,     1,     2,     3,     2,     3,     3,
       2,     2,     3,     3,     8,     5,     3,     3,     1,     1,
       1,     3,     1,     2,     2,     3,     4,     3,     1,     3,
       5,     1,     1,     1,     1,     3,     4,     2,     4,     4,
       6,     3,     1,     2,     0,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     3,     1,     2,     2,
       1,     3,     1,     3,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     3,     0,    25,
       0,     0,     7,     0,    10,     0,    38,    30,     0,     0,
      40,    86,    85,     0,     0,     0,     0,     0,    88,     0,
       0,    84,    42,     0,    54,    52,    51,    53,     0,     5,
       6,     4,     0,    27,     0,     9,     0,    12,     0,    31,
       0,     0,     0,    44,     0,    85,     0,     0,    87,     0,
      73,    77,    80,    82,     0,     0,    57,     0,     0,     0,
      43,     0,     2,     0,    28,    26,     8,     0,     0,     0,
      13,    11,    37,    32,    39,     0,    33,     0,     0,    48,
      55,    78,    79,    83,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    62,    49,     0,     0,
       0,     0,    41,    65,    16,    18,     0,    23,     0,    19,
       0,     0,    59,    45,     0,    74,    75,    66,    69,    67,
      70,    71,    68,    76,    72,    81,     0,     0,    64,     0,
      58,    56,     0,    15,     0,    14,     0,     0,     0,     0,
      46,    47,    61,     0,     0,    50,     0,    17,    22,    20,
      24,    21,     0,     0,    60,    63,    29,    36,     0,     0,
      34,    35
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    13,    14,    22,    15,    24,    25,    90,   126,
     128,   129,   130,   171,    16,    19,    20,   150,    17,    27,
      28,   159,    29,    96,    41,    42,    63,    98,    43,    44,
      68,    46,   117,   165,    47,    99,    70,    71,    72,    73
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -50
static const yytype_int16 yypact[] =
{
     -47,     9,    19,    -5,   -50,    22,     1,    20,    24,    45,
      48,    56,    59,     5,    24,    24,    24,   -50,    64,   -50,
      50,     2,   -50,    66,   -50,    52,    39,   -50,    58,    65,
     -15,   -50,    73,    38,     5,    33,    74,    38,   -50,     5,
      38,    54,   -50,    75,   -50,    81,   -50,   -50,    94,   -50,
     -50,   -50,   105,    45,    48,   -50,   -12,    56,    59,    59,
      -1,    38,    38,   -50,     5,   -50,    33,    33,   -50,    89,
      83,   -50,   112,   -50,    -6,    68,   -50,    70,    63,    85,
     -50,   120,   -50,    38,   -50,   -50,   -50,   123,   124,   125,
     -50,   -50,   -50,   -50,   -50,    99,   -50,   103,   102,   109,
     -50,   112,   112,   -50,    33,    33,    38,    38,    38,    38,
      38,    38,    33,    38,    33,     5,   -50,   -50,   132,     5,
     133,     5,   -50,   -50,   -50,   113,   108,   114,   100,   115,
     116,   137,   -50,   117,    38,   112,   112,    67,    67,    67,
      67,    67,    67,   112,    67,   -50,    -6,   107,   106,   135,
     -50,   -50,   124,   -50,   125,   -50,   125,   145,   126,   118,
     -50,   -50,   -50,     5,     5,   -50,   147,   -50,   -50,   -50,
     -50,   -50,   150,   111,   -50,   -50,   -50,   131,   154,   157,
     -50,   -50
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -50,   -50,    53,   -50,   110,   -50,   104,   -50,   -50,    10,
       7,   -50,    11,   -50,   -50,   119,   -50,   -50,   -50,   121,
     -50,   -50,   127,   -50,   -50,   -50,    34,    32,   -33,   -50,
     -10,   -50,    23,   -50,   136,   -26,     6,   -50,   -49,   -13
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -88
static const yytype_int16 yytable[] =
{
      48,    74,    94,    45,     1,    87,    78,    69,    30,    31,
      32,    77,     3,    61,    79,    62,    88,   101,   102,     4,
     115,    48,    48,     5,    45,     6,    48,    54,    55,    45,
       7,   100,    95,    33,   116,    97,    30,    31,    65,    34,
      89,    30,    31,    65,    66,    67,     8,    35,    18,    36,
      37,    48,    38,    21,    45,   135,   136,   123,    39,    23,
       9,    33,    26,   143,    58,    40,    33,    49,    50,    51,
      10,    80,    81,   104,   105,    52,    53,    56,    57,    76,
      38,    11,   146,    12,    59,    38,   148,   112,   151,   104,
     105,   -87,    60,    82,   106,   107,   108,   109,   110,   111,
      64,   145,    48,   112,    83,    45,    48,   113,    48,    45,
      84,    45,   137,   138,   139,   140,   141,   142,   103,   144,
     114,   120,   121,   122,   118,   119,   124,   125,   127,   131,
     174,   175,   132,   133,   134,   147,   149,   153,   152,   154,
     155,   156,   158,   157,   163,   164,   166,    62,   170,   173,
      48,    48,   176,    45,    45,   177,   179,   180,   172,   178,
     181,    91,   167,   169,    86,   168,   161,   160,     0,   162,
       0,    75,    85,     0,     0,     0,     0,     0,     0,     0,
      93,     0,     0,     0,     0,    92
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-50))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      13,    34,     3,    13,    51,    17,    39,    33,     3,     4,
       5,    37,     3,    28,    40,    30,    28,    66,    67,     0,
      26,    34,    35,    28,    34,     3,    39,    25,    26,    39,
      29,    64,    33,    28,    40,    61,     3,     4,     5,    34,
      52,     3,     4,     5,     6,     7,    26,    42,     3,    44,
      45,    64,    47,     5,    64,   104,   105,    83,    53,     3,
      36,    28,     3,   112,    25,    60,    28,    14,    15,    16,
      46,    17,    18,     6,     7,    11,    26,    11,    26,     5,
      47,    57,   115,    59,    26,    47,   119,    20,   121,     6,
       7,    10,    27,    18,    11,    12,    13,    14,    15,    16,
      27,   114,   115,    20,    10,   115,   119,    24,   121,   119,
       5,   121,   106,   107,   108,   109,   110,   111,    29,   113,
       8,    58,    37,     3,    56,    55,     3,     3,     3,    30,
     163,   164,    29,    31,    25,     3,     3,    29,    25,    25,
      40,    26,     5,    27,    37,    39,    11,    30,     3,    31,
     163,   164,     5,   163,   164,     5,    25,     3,    32,    48,
       3,    57,   152,   156,    54,   154,   134,   133,    -1,   146,
      -1,    35,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    -1,    -1,    -1,    -1,    58
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    51,    63,     3,     0,    28,     3,    29,    26,    36,
      46,    57,    59,    64,    65,    67,    76,    80,     3,    77,
      78,     5,    66,     3,    68,    69,     3,    81,    82,    84,
       3,     4,     5,    28,    34,    42,    44,    45,    47,    53,
      60,    86,    87,    90,    91,    92,    93,    96,   101,    64,
      64,    64,    11,    26,    25,    26,    11,    26,    25,    26,
      27,    28,    30,    88,    27,     5,     6,     7,    92,    97,
      98,    99,   100,   101,    90,    96,     5,    97,    90,    97,
      17,    18,    18,    10,     5,    77,    66,    17,    28,    52,
      70,    68,    84,    81,     3,    33,    85,    97,    89,    97,
      90,   100,   100,    29,     6,     7,    11,    12,    13,    14,
      15,    16,    20,    24,     8,    26,    40,    94,    56,    55,
      58,    37,     3,    97,     3,     3,    71,     3,    72,    73,
      74,    30,    29,    31,    25,   100,   100,    98,    98,    98,
      98,    98,    98,   100,    98,   101,    90,     3,    90,     3,
      79,    90,    25,    29,    25,    40,    26,    27,     5,    83,
      88,    89,    94,    37,    39,    95,    11,    71,    74,    72,
       3,    75,    32,    31,    90,    90,     5,     5,    48,    25,
       3,     3
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
#line 81 "pars1.y"
    { parseresult = makeprogram((yyvsp[(2) - (9)]), (yyvsp[(4) - (9)]), (yyvsp[(8) - (9)])); }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 84 "pars1.y"
    { (yyval) = NULL;  }
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 85 "pars1.y"
    { (yyval) = NULL;  }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 86 "pars1.y"
    { (yyval) = NULL;  }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 87 "pars1.y"
    { (yyval) = NULL;  }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 90 "pars1.y"
    { (yyval) = NULL; }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 93 "pars1.y"
    { instlabel((yyvsp[(1) - (3)])); }
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 94 "pars1.y"
    { instlabel((yyvsp[(1) - (2)])); }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 98 "pars1.y"
    { (yyval) = NULL; }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 101 "pars1.y"
    { (yyval) = NULL; }
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 102 "pars1.y"
    { (yyval) = NULL; }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 105 "pars1.y"
    { insttype((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 108 "pars1.y"
    { (yyval) = instrec((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)])); }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 109 "pars1.y"
    { (yyval) = instenum((yyvsp[(2) - (3)])); }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 110 "pars1.y"
    { (yyval) = instpoint((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 113 "pars1.y"
    { (yyval) = cons((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 114 "pars1.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 117 "pars1.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 118 "pars1.y"
    { (yyval) = cons((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 121 "pars1.y"
    { instfields((yyvsp[(1) - (3)]), findtype((yyvsp[(3) - (3)])));}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 123 "pars1.y"
    { (yyval) = cons((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 124 "pars1.y"
    {  (yyval) = ((yyvsp[(1) - (1)])); }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 126 "pars1.y"
    {  (yyval) = ((yyvsp[(1) - (1)]));  }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 129 "pars1.y"
    { (yyval) = NULL; }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 131 "pars1.y"
    { (yyval) = NULL; }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 132 "pars1.y"
    { (yyval) = NULL; }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 135 "pars1.y"
    { instconst((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 137 "pars1.y"
    { (yyval) = binop((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));  }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 139 "pars1.y"
    { (yyval) = NULL; }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 142 "pars1.y"
    { (yyval) = NULL; }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 143 "pars1.y"
    { (yyval) = NULL; }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 146 "pars1.y"
    { instvars((yyvsp[(1) - (3)]), findtype((yyvsp[(3) - (3)]))); }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 148 "pars1.y"
    { instvars((yyvsp[(1) - (8)]), instarray((yyvsp[(5) - (8)]), findtype((yyvsp[(8) - (8)])))); }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 151 "pars1.y"
    { (yyval) = cons(findtype((yyvsp[(5) - (5)])), instdotdot((yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]), (yyvsp[(3) - (5)]))); }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 152 "pars1.y"
    { (yyval) = instdotdot((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 154 "pars1.y"
    { (yyval) = cons((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 155 "pars1.y"
    { (yyval) = ((yyvsp[(1) - (1)])); }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 157 "pars1.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 160 "pars1.y"
    { (yyval) = findid((yyvsp[(1) - (1)])); }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 161 "pars1.y"
    { (yyval) = reducedot((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 163 "pars1.y"
    { (yyval) = dopoint((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 165 "pars1.y"
    { (yyval) = arrayref((yyvsp[(1) - (2)]), NULL, (yyvsp[(2) - (2)]), NULL); }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 168 "pars1.y"
    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 169 "pars1.y"
    { (yyval) = nconc((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)])); }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 171 "pars1.y"
    { (yyval) = cons((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 172 "pars1.y"
    { (yyval) = cons((yyvsp[(1) - (1)]), NULL); }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 174 "pars1.y"
    {  (yyval) = makeprogn((yyvsp[(1) - (3)]),nconc((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])));  }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 177 "pars1.y"
    { (yyval) = makeif((yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]), (yyvsp[(4) - (5)]), (yyvsp[(5) - (5)])); }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 178 "pars1.y"
    { (yyval) = (yyvsp[(1) - (1)]);  }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 179 "pars1.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 180 "pars1.y"
    { (yyval) = (yyvsp[(1) - (1)]);  }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 181 "pars1.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 182 "pars1.y"
    { (yyval) = dolabel((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 183 "pars1.y"
    { (yyval) = makewhile((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)])); }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 184 "pars1.y"
    { (yyval) = dogoto((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 186 "pars1.y"
    { (yyval) = makerepeat((TOKEN) talloc(), (yyvsp[(2) - (4)]), (TOKEN) talloc(), (yyvsp[(4) - (4)])); }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 189 "pars1.y"
    { (yyval) = makefuncall((TOKEN) talloc(), findid((yyvsp[(1) - (4)])), (yyvsp[(3) - (4)])); }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 191 "pars1.y"
    { (yyval) = makefor(1, (TOKEN) talloc(), (yyvsp[(2) - (6)]), findid((yyvsp[(4) - (6)])), NULL, NULL, (yyvsp[(6) - (6)])); }
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 193 "pars1.y"
    { (yyval) = cons((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 194 "pars1.y"
    { (yyval) = NULL; }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 196 "pars1.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 197 "pars1.y"
    { (yyval) = NULL; }
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 199 "pars1.y"
    { (yyval) = binop((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 202 "pars1.y"
    { (yyval) = binop((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 203 "pars1.y"
    { (yyval) = binop((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 204 "pars1.y"
    { (yyval) = binop((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 205 "pars1.y"
    { (yyval) = binop((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 206 "pars1.y"
    { (yyval) = binop((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 207 "pars1.y"
    { (yyval) = binop((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 208 "pars1.y"
    { (yyval) = binop((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 209 "pars1.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 212 "pars1.y"
    { (yyval) = binop((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 213 "pars1.y"
    { (yyval) = binop((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 214 "pars1.y"
    { (yyval) = binop((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 215 "pars1.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 218 "pars1.y"
    { (yyval) = unaryop((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 219 "pars1.y"
    { (yyval) = unaryop((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 220 "pars1.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 222 "pars1.y"
    { (yyval) = binop((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 223 "pars1.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 226 "pars1.y"
    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 227 "pars1.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 228 "pars1.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 229 "pars1.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 230 "pars1.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 231 "pars1.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;



/* Line 1806 of yacc.c  */
#line 2292 "y.tab.c"
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
#line 236 "pars1.y"


/* You should add your own debugging flags below, and add debugging
   printouts to your programs.

   You will want to change DEBUG to turn off printouts once things
   are working.
  */

#define DEBUG          1             /* set bits here for debugging, 0 = off  */
#define DB_CONS        1             /* bit to trace cons */
#define DB_NCONC       1             /* bit to trace nconc */
#define DB_COPYTOK     1             /* bit to trace copytok */
#define DB_BINOP       1             /* bit to trace binop */
#define DB_MAKEFOR     1             /* bit to trace makefor */
#define DB_MAKEFUNCALL 1             /* bit to trace makefuncall */
#define DB_MAKEGOTO    1             /* bit to trace makegoto */
#define DB_MAKEIF      1             /* bit to trace makeif */
#define DB_MAKEINTC    1             /* bit to trace makeintc */
#define DB_MAKELABEL   1             /* bit to trace makelabel */
#define DB_MAKEOP      1             /* bit to trace makeop */
#define DB_MAKEPROGN   1             /* bit to trace makeprogn */
#define DB_MAKEPROGRAM 1             /* bit to trace makeprogram */
#define DB_PARSERES    1             /* bit to trace parseresult */
#define DB_UNARYOP     1             /* bit to trace unaryop */
#define DB_MAKEREPEAT  1             /* bit to trace makerepeat */
#define DB_INSTVARS    1             /* bit to trace makerepeat */
#define DB_INSTTYPE    1             /* bit to trace makerepeat */
#define DB_INSTREC     1            
#define DB_INSTFIELDS  1            
#define DB_MAKESUBRNG  1
#define DB_INSTPOINT   1
#define DB_INSTARRAY   1
#define DB_INSTDOTDOT  1
#define DB_INSTARRAY   1
#define DB_DOPOINT     1
#define DB_REDUCEDOT   1
#define DB_MAKEAREF    1
#define DB_DOLABEL     1
#define DB_ARRAYREF    1
#define DB_MAKEPLUS    1
#define DB_ADDINT      1
#define DB_MAKEPNB     1
#define DB_MAKEWHILE   1
#define DB_DOGOTO      1


 int labelnumber = 0;  /* sequential counter for internal label numbers */
 int labels[100];
   /*  Note: you should add to the above values and insert debugging
       printouts in your routines similar to those that are shown here.     */

TOKEN cons(TOKEN item, TOKEN list)           /* add item to front of list */
  { item->link = list;
    if (DEBUG & DB_CONS)
       { printf("cons\n");
         dbugprinttok(item);
         dbugprinttok(list);
       };
    return item;
  }

/* nconc concatenates two token lists, destructively, by making the last link
   of lista point to listb.
   (nconc '(a b) '(c d e))  =  (a b c d e)  */
/* nconc is useful for putting together two fieldlist groups to
   make them into a single list in a record declaration. */
TOKEN nconc(TOKEN lista, TOKEN listb) 
    { 
      TOKEN current = lista;
      while(current->link != NULL) {
        current = current->link;
      }
      current->link = listb;
    if (DEBUG & DB_NCONC)
       { printf("nconc\n");
         dbugprinttok(lista);
         dbugprinttok(listb);
       };
    return lista;
  }


/* makeplus makes a + operator.
   tok (if not NULL) is a (now) unused token that is recycled. */
TOKEN makeplus(TOKEN lhs, TOKEN rhs, TOKEN tok) {

  if (DEBUG & DB_MAKEPLUS) {
    printf("In makeplus()\n");
    dbugprinttok(lhs);
    dbugprinttok(rhs);
    dbugprinttok(tok);    
  }

  TOKEN out = makeop(PLUSOP);
  if (lhs && rhs) {
    out->operands = lhs;
    lhs->link = rhs;
    rhs->link = NULL;
  }
  
  if (DEBUG & DB_MAKEPLUS) {
    printf(" Finished makeplus().\n");
    dbugprinttok(out);
  }

  return out;
}

/* addint adds integer off to expression exp, possibly using tok */
TOKEN addint(TOKEN exp, TOKEN off, TOKEN tok) {
  if (!exp || !off) {
    return NULL;
  }

  int a = exp->intval;
  int b = off->intval;
  
  if (DEBUG & DB_ADDINT) {
    printf("In addint()\n Adding %d to %d\n", b, a);
    dbugprinttok(exp);
    dbugprinttok(off);
    dbugprinttok(tok);
  }

  exp->intval = a + b;
  
  if (DEBUG & DB_ADDINT) {
    printf(" New value of exp: %d\n", exp->intval);
    dbugprinttok(exp);
  }
  
  return exp;
}

/* unaryop links a unary operator op to one operand, lhs */
TOKEN unaryop(TOKEN op, TOKEN lhs) {
    op->operands = lhs;          /* link operands to operator       */
    lhs->link = NULL;
    if (DEBUG & DB_UNARYOP)
       { printf("unaryop\n");
         dbugprinttok(op);
         dbugprinttok(lhs);
       };
    return op;
}

int isReal(TOKEN tok) {
  // printf("IS REAL: \n");
  SYMBOL sym = searchst(tok->stringval);
  // dbugprinttok(tok);
  if (sym->basicdt == REAL) {
    // printf("TRUE\n");
    return 1;
  }
    // printf("FALSE\n");

  return 0;
}

int isInteger(TOKEN tok) {
  // printf("IS INTEGER: \n");
  // dbugprinttok(tok);
  SYMBOL sym = searchst(tok->stringval);
  if (sym->basicdt == INTEGER) {
    // printf("TRUE\n");
    return 1;
  }
    // printf("FALSE\n");
    return 0;
}

int isIdentifier(TOKEN tok) {
  if (tok->tokentype == IDENTIFIERTOK) {
    return 1;
  }
  return 0;
}

TOKEN binop(TOKEN op, TOKEN lhs, TOKEN rhs)        /* reduce binary operator */
  { op->operands = lhs;          /* link operands to operator       */
    lhs->link = rhs;             /* link second operand to first    */
    rhs->link = NULL;            /* terminate operand list          */

    if (isIdentifier(lhs)) {
      if (isIdentifier(rhs)) {
        if (isReal(lhs) && isReal(rhs)) {
          op->datatype = REAL;
        } else if (isReal(lhs) && isInteger(rhs)) {
          op->datatype = REAL;
          TOKEN float_tok = makeop(FLOATOP);
          float_tok->operands = rhs;
          lhs->link = float_tok;
        } else if (isInteger(lhs) && isReal(rhs)) {
          if (op->whichval == ASSIGNOP) {
            TOKEN fix_tok = makeop(FIXOP);
            fix_tok->operands =rhs;
            lhs->link = fix_tok;
          }
          else {
            op->datatype = REAL;
            TOKEN float_tok = makeop(FLOATOP);
            float_tok->operands = lhs;
            float_tok->link = rhs;            
          }

        }
      }
      else {
        if (isReal(lhs) && (rhs->datatype == REAL)) {
          op->datatype = REAL;
        } else if (isReal(lhs) && (rhs->datatype == INTEGER)) {
          op->datatype = REAL;
          rhs->datatype = REAL;
          rhs->realval = (double) rhs->intval;
        } else if (isInteger(lhs) && (rhs->datatype == REAL)) {
          if (op->whichval == ASSIGNOP) {
            if (rhs->tokentype == OPERATOR || rhs->tokentype == IDENTIFIERTOK) {
              TOKEN fix_tok = makeop(FIXOP);
              fix_tok->operands =rhs;
              lhs->link = fix_tok;           
            } else if (rhs->tokentype == NUMBERTOK) {
              rhs->datatype = INTEGER;
              rhs->intval = (int) rhs->realval;
            }

          }else {
            op->datatype = REAL;
            TOKEN float_tok = makeop(FLOATOP);
            float_tok->operands = lhs;
            float_tok->link = rhs;
          }

        }
      }
    }
    else {
      if (isIdentifier(rhs)) {
        if ((lhs->datatype == REAL) && isReal(rhs)) {
          op->datatype = REAL;
        } else if ((lhs->datatype == REAL) && isInteger(rhs)) {
          op->datatype = REAL;
          TOKEN float_tok = makeop(FLOATOP);
          float_tok->operands = rhs;
          lhs->link = float_tok;
        } else if ((lhs->datatype == INTEGER) && isReal(rhs)) {
          op->datatype = REAL;
          lhs->datatype = REAL;
          lhs->realval = (double) lhs->intval;
        }
      }
      else {
        if ((lhs->datatype == REAL) && (rhs->datatype == REAL)) {
          op->datatype = REAL;
        } else if ((lhs->datatype == REAL) && (rhs->datatype == INTEGER)) {
          op->datatype = REAL;
          rhs->datatype = REAL;
          rhs->realval = (double) rhs->intval;
        } else if ((lhs->datatype == INTEGER) && (rhs->datatype == REAL)) {
          op->datatype = REAL;
          lhs->datatype = REAL;
          lhs->realval = (double) lhs->intval;
        }        
      }
    }

    if (DEBUG & DB_BINOP)
       { printf("binop\n");
         dbugprinttok(op);
         dbugprinttok(lhs);
         dbugprinttok(rhs);
       };
    return op;
  }

/* arrayref processes an array reference a[i]
   subs is a list of subscript expressions.
   tok and tokb are (now) unused tokens that are recycled. */
TOKEN arrayref(TOKEN arr, TOKEN tok, TOKEN subs, TOKEN tokb) {
  if (DEBUG & DB_ARRAYREF) {
    printf("In arrayref()\n");
    dbugprinttok(arr); 
    dbugprinttok(tok);
    dbugprinttok(subs);
    dbugprinttok(tokb);
  }

  TOKEN array_ref = NULL;
  SYMBOL arr_varsym, typesym, temp;
  SYMBOL arrsyms[10];

  arr_varsym = searchst(arr->stringval);

  if (!arr_varsym) {
    printf(" Error: array \"%s\" not found in symbol table, arrayref().\n", arr->stringval);
    return NULL;
  }

  temp = arr_varsym->datatype;

  int counter = 0;
  int num_arr_dims = 0; // not being used for anything

  while (temp && temp->kind != TYPESYM) {
    arrsyms[counter] = temp;
    num_arr_dims++;
    counter++;
    temp = temp->datatype;
  }

  typesym = temp;

  if (subs->link == NULL && subs->tokentype == NUMBERTOK) {
    int total_size = (subs->whichval - 1) * typesym->size;
    array_ref = makearef(arr, makeintc(total_size), NULL);
    array_ref->datatype = arr_varsym->basicdt;
    return array_ref;
  }
  // else if tokentype is IDENTIFIER?

  counter = 0;
  TOKEN curr_sub = subs;

  while (curr_sub) {

    if (counter == 0) {
      SYMBOL curr_sym = arrsyms[counter];
      int curr_size = curr_sym->size / (curr_sym->highbound - curr_sym->lowbound + 1);

      // TOKEN mul_op = maketimes(makeintc(curr_size), curr_sub, NULL);

      TOKEN mul_op = makeop(TIMESOP);
      TOKEN pos_typesym_size = makeintc(curr_size);
      TOKEN neg_typesym_size = makeintc(curr_size * -1);

      mul_op->operands = pos_typesym_size;
      pos_typesym_size->link = curr_sub;

      neg_typesym_size->link = mul_op;

      TOKEN plus_op = makeplus(neg_typesym_size, mul_op, NULL);

      array_ref = makearef(arr, plus_op, NULL);
      array_ref->datatype = arr_varsym->basicdt;

    }
    else {

      if (curr_sub->tokentype == NUMBERTOK) {   // only integers for now
        array_ref->operands->link->operands = addint(array_ref->operands->link->operands, 
          makeintc(curr_sub->whichval * typesym->size), NULL);
      }
      else {

        SYMBOL curr_sym = arrsyms[counter];
        int curr_size = curr_sym->size / (curr_sym->highbound - curr_sym->lowbound + 1);

        TOKEN mul_op = makeop(TIMESOP);
        TOKEN pos_typesym_size = makeintc(curr_size);
        TOKEN neg_typesym_size = makeintc(curr_size * -1);

        mul_op->operands = pos_typesym_size;
        pos_typesym_size->link = curr_sub;

        array_ref->operands->link->operands = addint(array_ref->operands->link->operands,
          neg_typesym_size, NULL);

        TOKEN add_to = array_ref->operands->link->operands->link;
        TOKEN plus_op = makeplus(add_to, mul_op, NULL);
        array_ref->operands->link->operands->link = plus_op;

      }
    }

    TOKEN unlink = curr_sub;
    curr_sub = curr_sub->link;
    unlink->link = NULL;
    counter++;
  }

  if (DEBUG & DB_ARRAYREF) {
    printf(" Finished arrayref().\n");
    dbugprinttok(array_ref);
  } 
  
  return array_ref;
}

/* makerepeat makes structures for a repeat statement.
   tok and tokb are (now) unused tokens that are recycled. */
TOKEN makerepeat(TOKEN tok, TOKEN statements, TOKEN tokb, TOKEN expr) {
  int num_to_go_to = labelnumber;
  TOKEN labeltok = makelabel();
  tok = makeprogn(tok, labeltok);

  TOKEN progn_statements = makeprogn(tokb, statements);
  labeltok->link = progn_statements;
  TOKEN go_to_tok = makegoto(num_to_go_to);
  TOKEN empty_progn = makeprogn((TOKEN) talloc(), NULL);
  empty_progn->link = go_to_tok;

  TOKEN if_token = talloc();
  if_token = makeif(if_token, expr, empty_progn, go_to_tok);
  progn_statements->link = if_token;
 if (DEBUG & DB_MAKEREPEAT)
    { printf("makerepeat\n");
      dbugprinttok(tok);
      dbugprinttok(labeltok);
      dbugprinttok(progn_statements);
      dbugprinttok(if_token);
      dbugprinttok(expr);
      dbugprinttok(empty_progn);
      dbugprinttok(go_to_tok);
    };
 return tok;  
}

TOKEN makeif(TOKEN tok, TOKEN exp, TOKEN thenpart, TOKEN elsepart)
  {  tok->tokentype = OPERATOR;  /* Make it look like an operator   */
     tok->whichval = IFOP;
     if (elsepart != NULL) elsepart->link = NULL;
     thenpart->link = elsepart;
     exp->link = thenpart;
     tok->operands = exp;
     if (DEBUG & DB_MAKEIF)
        { printf("makeif\n");
          dbugprinttok(tok);
          dbugprinttok(exp);
          dbugprinttok(thenpart);
          dbugprinttok(elsepart);
        };
     return tok;
   }

/* copytok makes a new token that is a copy of origtok */
TOKEN copytok(TOKEN origtok) {
  TOKEN copy = talloc();
  copy->tokentype = origtok->tokentype;
  copy->datatype = origtok->datatype;
  copy->symtype = origtok->symtype;
  copy->symentry = origtok->symentry;
  copy->link = origtok->link;
  copy->whichval = origtok->whichval;
  copy->intval = origtok->intval;
  copy->realval = origtok->realval;
  if (DEBUG & DB_COPYTOK) {
    printf("copytok\n");
    dbugprinttok(copy);
  }
  return copy;
}

/* makeintc makes a new token with num as its value */
TOKEN makeintc(int num) {
  TOKEN intMade = talloc();
  intMade->tokentype = NUMBERTOK;
  intMade->datatype = INTEGER;
  intMade->intval = num;
  if (DEBUG & DB_MAKEINTC) {
    dbugprinttok(intMade);
  }
  return intMade;
}

/* makeprogram makes the tree structures for the top-level program */
TOKEN makeprogram(TOKEN name, TOKEN args, TOKEN statements) {
  TOKEN program = talloc();
  TOKEN nameToArgs = talloc();
  program->tokentype = OPERATOR;
  program->whichval = PROGRAMOP;
  program->operands = name;
  // args->tokentype = IDENTIFIER;
  // name->tokentype = IDENTIFIER;
  nameToArgs = makeprogn(nameToArgs, args);
  name->link = nameToArgs;
  nameToArgs->link = statements;
  if (DEBUG & DB_MAKEPROGRAM)
  { printf("makeprogram\n");
    dbugprinttok(program);
    dbugprinttok(name);
    dbugprinttok(nameToArgs);
    dbugprinttok(args);
  };
  return program;
}

/* makeprogn makes a PROGN operator and links it to the list of statements.
   tok is a (now) unused token that is recycled. */
TOKEN makeprogn(TOKEN tok, TOKEN statements)
  {  tok->tokentype = OPERATOR;
     tok->whichval = PROGNOP;
     tok->operands = statements;
     if (DEBUG & DB_MAKEPROGN)
       { printf("makeprogn\n");
         dbugprinttok(tok);
         dbugprinttok(statements);
       };
     return tok;
   }

/* makefuncall makes a FUNCALL operator and links it to the fn and args.
   tok is a (now) unused token that is recycled. */
TOKEN makefuncall(TOKEN tok, TOKEN fn, TOKEN args){
  if (strcmp(fn->stringval, "new") != 0) {
    tok->operands = fn;
    tok->whichval = FUNCALLOP;
    tok->datatype = fn->datatype;
    fn->link = args;
  }
  else {
    TOKEN funcall_tok;
    funcall_tok = makeop(ASSIGNOP);
    TOKEN funcall = makeop(FUNCALLOP);

    SYMBOL this_type = searchst(args->stringval);

    funcall_tok->operands = args;
    args->link = funcall;
    funcall->operands = fn;
    fn->link = makeintc(this_type->datatype->datatype->datatype->size);
    return funcall_tok;

  }
  if (DEBUG & DB_MAKEPROGN)
  { printf("makefuncall\n");
    dbugprinttok(tok);
    dbugprinttok(fn);
    dbugprinttok(args);
  };
  return tok;
}

/* makefor makes structures for a for statement.
   sign is 1 for normal loop, -1 for downto.
   asg is an assignment statement, e.g. (:= i 1)
   endexpr is the end expression
   tok, tokb and tokc are (now) unused tokens that are recycled. */
TOKEN makefor(int sign, TOKEN tok, TOKEN asg, TOKEN tokb, TOKEN endexpr,
              TOKEN tokc, TOKEN statement) {
  tok = makeprogn(tok, asg);
  tok->operands = asg;
  TOKEN label = makelabel();
  asg->link = label;

  TOKEN compare_op;
  TOKEN inc_or_dec_op;
  // Increment for loop
  if (sign == 1) {
    compare_op = makeop(LEOP);
    inc_or_dec_op = makeop(PLUSOP);
  }
  // Decrementing For Loop
  else if (sign == -1) {
    compare_op = makeop(GEOP);
    inc_or_dec_op = makeop(MINUSOP);
  }

  TOKEN ifStatement =  talloc();
  TOKEN statementProgn = talloc();
  statementProgn = makeprogn(statementProgn, statement);

  ifStatement = makeif(ifStatement, compare_op, statementProgn, NULL);
  TOKEN varA = copytok(asg->operands);

  ifStatement->operands = compare_op;
  compare_op->operands = varA;
  varA->link = tokb;
  
  TOKEN assign = makeop(ASSIGNOP);
  TOKEN secondVarA = copytok(varA);
  assign->operands = secondVarA;
  secondVarA->link = inc_or_dec_op;
  TOKEN thirdVarA = copytok(varA);
  inc_or_dec_op->operands = thirdVarA;
  thirdVarA->link = makeintc(1);

  statement->link = assign;
  assign->link = makegoto(labelnumber - 1);
  label->link = ifStatement;

  if (DEBUG & DB_MAKEFOR) {
    printf("makefor\n");
    dbugprinttok(tok);
    dbugprinttok(asg);
    dbugprinttok(tokb);
    dbugprinttok(endexpr);
    dbugprinttok(tokc);
    dbugprinttok(compare_op);
    dbugprinttok(inc_or_dec_op);
    dbugprinttok(varA);
    dbugprinttok(secondVarA);
    dbugprinttok(thirdVarA);
  }
  return tok;
}

/* makegoto makes a GOTO operator to go to the specified label.
   The label number is put into a number token. */
TOKEN makegoto(int label) {
  TOKEN gotoTok = talloc();
  gotoTok->tokentype = OPERATOR;
  gotoTok->whichval = GOTOOP;
  gotoTok->operands = makeintc(labelnumber - 1);
  if (DEBUG & DB_MAKEGOTO) {
    printf("makegoto\n");
    dbugprinttok(gotoTok);
  }
  return gotoTok;
}

/* makelabel makes a new label, using labelnumber++ */
TOKEN makelabel() {
  TOKEN newLabel = talloc();
  newLabel->tokentype = OPERATOR;
  newLabel->whichval = LABELOP;
  newLabel->operands = makeintc(labelnumber);
  labelnumber++;
  if (DEBUG & DB_MAKELABEL) {
    printf("makelabel\n");
    dbugprinttok(newLabel);
  }
  return newLabel;
}

/* makeop makes a new operator token with operator number opnum.
   Example:  makeop(FLOATOP)  */
TOKEN makeop(int opnum){
  TOKEN makeopTok = talloc();
  makeopTok->tokentype = OPERATOR;
  makeopTok->whichval = opnum;
  if (DEBUG & DB_MAKEOP) {
    printf("makeop\n");
    dbugprinttok(makeopTok);
  }
  return makeopTok;


}
/* findid finds an identifier in the symbol table, sets up symbol table
   pointers, changes a constant to its number equivalent */
TOKEN findid(TOKEN tok) { /* the ID token */
  SYMBOL sym, typ;

  sym = searchst(tok->stringval);
  tok->symentry = sym;
  typ = sym->datatype;
  tok->symtype = typ;
  tok->datatype = typ->basicdt;

  if (sym->kind == CONSTSYM)
  {
    if (sym->basicdt == REAL) {
      tok->tokentype = NUMBERTOK;
      tok->datatype = REAL;
      tok->realval = sym->constval.realnum;
    }
    else if (sym->basicdt == INTEGER) {
      tok->tokentype = NUMBERTOK;
      tok->datatype = INTEGER;
      tok->intval = sym->constval.intnum;
    }
  }
  return tok;

}

/* findtype looks up a type name in the symbol table, puts the pointer
   to its type into tok->symtype, returns tok. */
TOKEN findtype(TOKEN tok) {
  tok->symtype = searchst(tok->stringval);
  
  // if(sym->basicdt == INTEGER) {
  //   printf("FOUND TYPE TO BE INTEGER\n");
  //   tok->symtype = searchst("integer");
  // }
  // else if(type == REAL) {
  //   printf("FOUND TYPE TO BE REAL\n");
  //   tok->symtype = searchst("real");
  // }
  // else if(type == BOOLETYPE) {
  //   printf("FOUND TYPE TO BE BOOLEAN\n");
  //   tok->symtype = searchst("boolean");
  // }
  // else{
  //   printf("FOUND TYPE TO BE STRING\n");
  //   tok->symtype = searchst(tok->stringval);
  // }
  // printf("FIND TYPE\n");
  // dbugprinttok(tok);
  return tok;
}

/* instdotdot installs a .. subrange in the symbol table.
   dottok is a (now) unused token that is recycled. */
TOKEN instdotdot(TOKEN lowtok, TOKEN dottok, TOKEN hightok){
  TOKEN output = makesubrange(dottok, lowtok->intval, hightok->intval);
  if (DEBUG && DB_INSTDOTDOT) {
    printf("instdotdot\n");
    dbugprinttok(lowtok);
    dbugprinttok(dottok);
    dbugprinttok(hightok);
  }

  return output;
}

/* instarray installs an array declaration into the symbol table.
   bounds points to a SUBRANGE symbol table entry.
   The symbol table pointer is returned in token typetok. */
TOKEN instarray(TOKEN bounds, TOKEN typetok) {


  TOKEN curr_bound = bounds;
  SYMBOL prev_sym = NULL;

  SYMBOL typesym = searchst(typetok->stringval);
  int low, high;

  while (curr_bound) {
    if (DEBUG && DB_INSTARRAY) {
      printf("current bound\n");
      dbugprinttok(curr_bound);
    }
    SYMBOL arrsym = symalloc();
    arrsym->kind = ARRAYSYM;

    if (typesym) {
      arrsym->datatype = typesym;
    }


    low = curr_bound->symtype->lowbound;
    high = curr_bound->symtype->highbound;

    if (!prev_sym) {
      arrsym->size = (high - low + 1) * typesym->size;
      printf("CURRENT_SIZE %d\n", arrsym->size);
      printf("CURRENT SIZE %d\n", high-low+1);

    }
    else {
      arrsym->datatype = typetok->symtype;
      printf("ARRAY SYM SIZE %d\n", arrsym->size);

      arrsym->size = (high - low + 1) * prev_sym->size;
      printf("PREVIOUS SIZE %d\n", prev_sym->size);
      printf("CURRENT SIZE %d\n", high-low+1);
      dbugprinttok(curr_bound);
      printf("TYPESYM SIZE %d\n", typesym->size);
    }

    typetok->symtype = arrsym;
    prev_sym = arrsym;

    arrsym->lowbound = low;
    arrsym->highbound = high;

    curr_bound = curr_bound->link;
  }

  if (DEBUG && DB_INSTARRAY) {
    printf("instdotdot\n");
    dbugprinttok(bounds);
    dbugprinttok(typetok);
  } 
  return typetok;

}

/* instfields will install type in a list idlist of field name tokens:
   re, im: real    put the pointer to REAL in the RE, IM tokens.
   typetok is a token whose symtype is a symbol table pointer.
   Note that nconc() can be used to combine these lists after instrec() */
TOKEN instfields(TOKEN idlist, TOKEN typetok) {

  int next = 0;
  int offset = 0;

  SYMBOL recsym, typesym;

  TOKEN temp = idlist;

  while (temp) {
    typesym = searchst(typetok->stringval);
    recsym = makesym(temp->stringval);
    recsym->datatype = typesym;

    // offset = next; next = next + n;
    offset = next;
    next = next + typesym->size;

    recsym->offset = offset;
    recsym->size = typesym->size;
    recsym->datatype = typesym;

    if (typesym->kind == BASICTYPE) {
      recsym->basicdt = typesym->basicdt;
    }

    temp->symtype = recsym;

    temp = temp->link;
  }

  if (DEBUG && DB_INSTFIELDS) {
    printf("instfields\n");
    dbugprinttok(idlist);
    dbugprinttok(typetok);
    dbugprinttok(temp);
  }
  return idlist;
}


/* instrec will install a record definition.  Each token in the linked list
   argstok has a pointer its type.  rectok is just a trash token to be
   used to return the result in its symtype */
TOKEN instrec(TOKEN rectok, TOKEN argstok) {
  int total_size, offset;

  SYMBOL recsym = symalloc();
  recsym->kind = RECORDSYM;
  rectok->symtype = recsym;
  recsym->datatype = argstok->symtype;
  offset = wordaddress(argstok->symtype->size, 8);  // TODO: test this w/ something size 8
  total_size = offset;

  TOKEN curr = argstok;
  TOKEN next = argstok->link;
  while (next) {

    curr->symtype->link = next->symtype;
    offset = wordaddress(next->symtype->size, 8);   
    next->symtype->offset = total_size;
    total_size += offset;

    curr = next;
    next = next->link;
  }

  recsym->size = total_size;


  if (DEBUG && DB_INSTREC) {
    printf("instrec\n");
    dbugprinttok(rectok);
    dbugprinttok(argstok);
  }
  return rectok;
}

void  instconst(TOKEN idtok, TOKEN consttok) {
    SYMBOL sym, typesym;
    int align = alignsize(typesym);

    sym = insertsym(idtok->stringval);
    sym->kind = CONSTSYM;
    sym->size = typesym->size;
    sym->datatype = typesym;
    sym->basicdt = consttok->datatype;
    if(sym->basicdt == REAL) //real
    {
        sym->constval.realnum = consttok->realval;
    }
    if(sym->basicdt == INTEGER) //int
    {
        sym->constval.intnum = consttok->intval;
    }
    
}

/* instpoint will install a pointer type in symbol table */
TOKEN instpoint(TOKEN tok, TOKEN typename) {
  SYMBOL ptrsym, sym;
  ptrsym = symalloc();
  ptrsym->kind = POINTERSYM;
  ptrsym->basicdt = POINTER;
  ptrsym->size = basicsizes[POINTER];
  tok->symtype = ptrsym;
  sym = searchins(typename->stringval);
  sym->kind = TYPESYM;
  ptrsym->datatype = sym;

  if (DEBUG & DB_INSTPOINT) {
    printf("instpoint\n");
    dbugprinttok(tok);
    dbugprinttok(typename);
  }
  tok->datatype = POINTER;

  return tok;

}

/* insttype will install a type name in symbol table.
   typetok is a token containing symbol table pointers. */
void  insttype(TOKEN typename, TOKEN typetok) {

    SYMBOL sym, typesym;
    typesym = typetok->symtype;

    sym = searchins(typename->stringval);
    sym->kind = TYPESYM;
    sym->size = typesym->size;
    sym->datatype = typesym;
    sym->basicdt = typesym->basicdt;
    if (DEBUG && DB_INSTTYPE) {
      printf("insttype\n");
      dbugprinttok(typename);
      dbugprinttok(typetok);
    }
}

/* instlabel installs a user label into the label table */
void  instlabel (TOKEN num) {
   labels[labelnumber++] = num->intval;
}

/* instenum installs an enumerated subrange in the symbol table,
   e.g., type color = (red, white, blue)
   by calling makesubrange and returning the token it returns. */
TOKEN instenum(TOKEN idlist) {
  int whole_size = 0;
  TOKEN temp = idlist;
  while(temp) {
    instconst(temp, makeintc(whole_size));
    whole_size ++;
    temp = temp->link;
  }
  TOKEN subrange = makesubrange(idlist, 0, whole_size - 1); 
  return subrange;
}

/* makesubrange makes a SUBRANGE symbol table entry, puts the pointer to it
into tok, and returns tok. */
TOKEN makesubrange(TOKEN tok, int low, int high) {
  // if (low > high) {
  //   printf(" Error: low bound cannot be greater than high bound\n\n");
  //   return NULL;
  // }

  TOKEN out = copytok(tok);
  SYMBOL subrange = symalloc();
  subrange->kind = SUBRANGE;
  subrange->basicdt = INTEGER;
  subrange->lowbound = low;
  subrange->highbound = high;
  subrange->size = basicsizes[INTEGER];
  out->symtype = subrange;
  
  if (DEBUG & DB_MAKESUBRNG) {
    printf("makesubrng\n");
    dbugprinttok(tok);
    dbugprinttok(out);
    printf(" low bound: %d\n high bound: %d\n\n", low, high);
  }

  return out;
}

/* instvars will install variables in symbol table.
   typetok is a token containing symbol table pointer for type. */
void instvars(TOKEN idlist, TOKEN typetok)
  {  

    SYMBOL sym, typesym; int align;
     typesym = typetok->symtype;
     align = alignsize(typesym);
      if (DEBUG && DB_INSTVARS) {
        printf("instvars\n");
        dbugprinttok(typetok);
      }
     while ( idlist != NULL )   /* for each id */
       {  sym = insertsym(idlist->stringval);
          sym->kind = VARSYM;
          sym->offset = wordaddress(blockoffs[blocknumber], align);
          sym->size = typesym->size;
          blockoffs[blocknumber] =
                         sym->offset + sym->size;
          sym->datatype = typesym;
          sym->basicdt = typesym->basicdt;

          if (DEBUG && DB_INSTVARS) {

            dbugprinttok(idlist);
            dbugprinttok(typetok);
          }
          idlist = idlist->link;
        };
    if (DEBUG && DB_INSTVARS)
      printstlevel(1);
  }

/* makearef makes an array reference operation.
   off is be an integer constant token
   tok (if not NULL) is a (now) unused token that is recycled. */
TOKEN makearef(TOKEN var, TOKEN off, TOKEN tok) {
  if (DEBUG & DB_MAKEAREF) {
    printf("makearef\n");
    dbugprinttok(var);
    dbugprinttok(off);
    dbugprinttok(tok);
  }

  TOKEN aref = makeop(AREFOP);
  aref->operands = var;
  var->link = off;

  if (DEBUG & DB_MAKEAREF) {
    printf("makearef().\n");
    dbugprinttok(aref);
  } 
  
  return aref;
}

/* makepnb is like makeprogn, except that if statements is already a progn,
   it just returns statements.  This is optional. */
TOKEN makepnb(TOKEN tok, TOKEN statements) {

  // if (statements->whichval == PROGNOP && ELIM_NESTED_PROGN) {
  //   if (DEBUG & DB_MAKEPNB) {
  //     printf("In makepnb()\n\n");
  //     dbugprint2args(tok, statements);
  //     printf(" Finished makepnb().\n");
  //     dbugprint1tok(statements);
  //   }
  //   return statements;
  // }
  if (DEBUG & DB_MAKEPNB) {
    printf("In makepnb(); transferring to makeprogn()...\n");
  }
  return (makeprogn(tok, statements));
}

/* makewhile makes structures for a while statement.
   tok and tokb are (now) unused tokens that are recycled. */
TOKEN makewhile(TOKEN tok, TOKEN expr, TOKEN tokb, TOKEN statement) {

  if (DEBUG & DB_MAKEWHILE) {
    printf("In makewhile()\n");
    dbugprinttok(tok);
    dbugprinttok(expr);
    dbugprinttok(tokb);
    dbugprinttok(statement);
  }

  if (expr->operands->link && expr->operands->link->whichval == (NIL - RESERVED_BIAS)) {
    expr->operands->link->tokentype = NUMBERTOK;
    expr->operands->link->datatype = INTEGER;
    expr->operands->link->whichval = 0;
  }

  TOKEN label_tok = makelabel();
  TOKEN goto_tok = makegoto(label_tok->operands->intval);
  TOKEN while_progn_tok = makepnb(talloc(), label_tok); // operand label_tok to while_progn_tok
  TOKEN do_progn_tok = makepnb(talloc(), statement);    // operand statement to do_progn_tok
  TOKEN ifop_tok = makeif(makeop(IFOP), expr, do_progn_tok, NULL);

  if (!label_tok || !goto_tok || !while_progn_tok ||
    !do_progn_tok ||!ifop_tok) {
    printf(" Failed to alloc TOKEN(s), makewhile().\n");
    return NULL;
  }

  label_tok->link = ifop_tok;

  /* Handle elimination of nested progns */
  if (do_progn_tok->whichval != PROGNOP) {
    do_progn_tok->operands = statement;
    statement->link = goto_tok;
  }
  // else {  // do_progn_tok == statement
  //   get_last_link(do_progn_tok->operands)->link = goto_tok;
  // }

  if (DEBUG & DB_MAKEWHILE) {
    printf(" Finished makewhile().\n");
    dbugprinttok(while_progn_tok);
  }

  return while_progn_tok;
}

/* Gets and returns the last TOKEN (in)directly
   connected via ->link to TOKEN tok. Mostly used 
   to handle elimination of nested progns. */
TOKEN get_last_link(TOKEN tok) {
  if (!tok) {
    return NULL;
  }

  TOKEN curr = tok;
  TOKEN curr_link = curr->link;
  while (curr_link) {
    curr = curr_link;
    curr_link = curr_link->link;
  }

  return curr;
}

/* dogoto is the action for a goto statement.
   tok is a (now) unused token that is recycled. */
TOKEN dogoto(TOKEN tok, TOKEN labeltok) {

  // THIS METHOD SHOULD ONLY BE CALLED FOR A USER LABEL

  if (DEBUG & DB_DOGOTO) {
    printf("In dogoto()\n");
    dbugprinttok(tok);
    dbugprinttok(labeltok);    
  }

  // if (labeltok->intval < 0) {
  //   printf(" Warning: label number is negative, dogoto().\n");
  // }

  int internal_label_num = get_internal_label_num(labeltok->intval);
  // if (internal_label_num == -1) {
  //   printf(" Error: could not find internal label number corresponding to user label number %d\n", labeltok->intval);
  //   return NULL;
  // }
  
  if (DEBUG & DB_DOGOTO) {
    printf(" Finished dogoto().\n");
    printf("  Found internal label number %d corresponding to user label number %d\n", internal_label_num, labeltok->intval);
    printf("  Transferring to makegoto()...\n\n");
  }

  return (makegoto(internal_label_num));
}

/* reducedot handles a record reference.
   dot is a (now) unused token that is recycled. */
TOKEN reducedot(TOKEN var, TOKEN dot, TOKEN field) {
  if (DEBUG & DB_REDUCEDOT) {
    printf("reducedotn");
    dbugprinttok(var);
    dbugprinttok(dot);
    dbugprinttok(field);
  }

  TOKEN aref;
  TOKEN offset = (TOKEN) talloc();// get_offset(var, field);

  if (var->whichval == AREFOP) {
    /* Avoid adding multiple copies to the tree. */

    if (offset->whichval >= 0) {
      var->operands->link = offset;
    }
    aref = var;
  }
  else {
    aref = makearef(var, offset, NULL);
  }

  /* Change aref's datatype to REAL to avoid incorrect
     fixes/floats in binop(). NULL out the dummy link. */
  if (offset->link && offset->link->datatype == REAL &&
    offset->link->realval == -DBL_MAX) {

    aref->datatype = REAL;
    offset->link = NULL;
  }
  
  if (DEBUG & DB_REDUCEDOT) {
    printf("reducedot\n");
    dbugprinttok(aref);
    // ppexpr(aref);
    // printf("\n");
  }

  return aref;
}

/* dopoint handles a ^ operator.
   tok is a (now) unused token that is recycled. */
TOKEN dopoint(TOKEN var, TOKEN tok) {
  if (DEBUG & DB_DOPOINT) {
    printf("dopoint\n");
    dbugprinttok(var);
    dbugprinttok(tok);   
  }

  tok->operands = var;

  if (DEBUG & DB_DOPOINT) {
    printf("dopoint\n");
    dbugprinttok(tok);
  }

  return tok;  
}

int get_internal_label_num(int external_label_num) {
  int i;
  for (i = 0; i < 100; i++) {
    if (labels[i] == external_label_num)
      return i;
  }
  return -1;
}
/* dolabel is the action for a label of the form   <number>: <statement>
   tok is a (now) unused token that is recycled. */
TOKEN dolabel(TOKEN labeltok, TOKEN tok, TOKEN statement) {

  if (DEBUG & DB_DOLABEL) {
    printf("dolabel()\n");
    dbugprinttok(labeltok);
    dbugprinttok(tok);
    dbugprinttok(statement);   
  }
  
  int internal_label_num = get_internal_label_num(labeltok->intval);
  if (internal_label_num == -1) {
    printf(" Error: label %d not found in label table\n", labeltok->intval);
    return NULL;
  }

  TOKEN do_progn_tok = makeop(PROGNOP);
  TOKEN label_tok = makeop(LABELOP);
//  TOKEN do_progn_tok = makeprogn(makeop(PROGNOP), makeop(LABELOP)); // second arg will never be progn, so skip makepnb()
  TOKEN label_num_tok = makeintc(internal_label_num);

  if (!do_progn_tok || !label_tok || !label_num_tok) {
    printf(" Failed to alloc label TOKEN(s), dolabel().\n");
    return NULL;
  }

  do_progn_tok->operands = label_tok;
  label_tok->operands = label_num_tok;
  label_tok->link = statement;

  if (DEBUG & DB_DOLABEL) {
    printf(" Finished dolabel().\n");
    dbugprinttok(do_progn_tok);
  }

  return do_progn_tok;
}

int wordaddress(int n, int wordsize)
  { return ((n + wordsize - 1) / wordsize) * wordsize; }
 
yyerror(s)
  char * s;
  { 
  fputs(s,stderr); putc('\n',stderr);
  }

main()
  { int res;
    initsyms();
    res = yyparse();
    printst();
    printf("yyparse result = %8d\n", res);
    if (DEBUG & DB_PARSERES) dbugprinttok(parseresult);
    ppexpr(parseresult);           /* Pretty-print the result tree */
  }

