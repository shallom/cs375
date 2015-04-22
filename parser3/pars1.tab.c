/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "pars1.y" /* yacc.c:339  */
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


#line 128 "pars1.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 298 "pars1.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   259

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  107
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  241

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   316

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    82,    82,    87,    88,    90,    93,    94,    95,    96,
      98,   101,   104,   105,   109,   110,   114,   115,   119,   120,
     124,   125,   129,   130,   134,   135,   139,   140,   144,   147,
     151,   155,   156,   160,   162,   165,   168,   171,   174,   177,
     178,   183,   184,   188,   191,   195,   196,   200,   204,   205,
     209,   213,   214,   218,   219,   223,   227,   228,   229,   230,
     234,   238,   240,   245,   247,   250,   254,   255,   257,   260,
     264,   265,   266,   270,   271,   275,   276,   277,   278,   279,
     280,   281,   282,   286,   287,   288,   289,   293,   294,   295,
     299,   300,   301,   302,   303,   304,   308,   309,   310,   311,
     312,   313,   314,   315,   319,   320,   321,   322
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
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
  "statement", "stmtlist", "idlist", "argslist", "lblock", "cblock",
  "tblock", "vblock", "block", "paramlist", "paramgroup", "llist", "clist",
  "tspecs", "tgroup", "varspecs", "vargroup", "endpart", "endif",
  "assignment", "var", "mergebracks", "mergelist", "fieldlist", "type",
  "simpletype", "simplelist", "expr", "simpexpr", "unaryexpr", "term",
  "factor", "factorlist", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
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

#define YYPACT_NINF -183

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-183)))

#define YYTABLE_NINF -99

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -42,    18,    22,     1,  -183,    27,    16,    19,    27,    23,
    -183,   105,    34,    50,    55,    54,    60,    99,    27,    78,
    -183,  -183,  -183,  -183,    47,  -183,    85,    69,   128,   128,
      34,    69,   106,   128,  -183,    34,   128,   -14,  -183,    -3,
    -183,   114,   109,    93,   129,   112,   137,   129,   127,   111,
     142,   145,     2,   148,  -183,   128,   128,  -183,    34,   143,
    -183,  -183,    69,    69,   149,   185,    11,  -183,   157,   150,
     146,   -14,   -31,  -183,   126,   158,   125,   152,    34,  -183,
    -183,  -183,   182,   128,   188,  -183,     7,   167,    54,   110,
     184,    37,  -183,    99,    37,  -183,    27,   183,   186,   187,
    -183,   128,  -183,  -183,  -183,   128,   128,   128,   128,   128,
     128,   128,    69,    69,    69,    69,    69,    69,    69,    69,
     128,  -183,  -183,   128,   128,    34,    34,   128,    34,   -14,
    -183,  -183,   189,    27,    27,    27,   190,  -183,   210,  -183,
    -183,     2,  -183,   191,   211,    27,   192,    27,  -183,  -183,
    -183,  -183,  -183,   206,   128,   194,   196,  -183,  -183,  -183,
    -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,
    -183,  -183,   195,   193,   197,   180,  -183,  -183,  -183,  -183,
      50,   199,    66,   200,   218,   202,   203,   227,  -183,   204,
      41,   208,   198,  -183,  -183,  -183,   128,    34,    34,    34,
    -183,  -183,   233,     7,  -183,   234,    72,     2,  -183,  -183,
    -183,   214,   209,    37,  -183,  -183,  -183,  -183,  -183,    74,
    -183,    84,     7,  -183,   215,    41,   201,   216,     7,  -183,
       7,  -183,  -183,  -183,  -183,    37,    27,  -183,  -183,  -183,
    -183
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,    17,     0,     0,     0,
      16,     0,    13,     0,     0,     0,     0,     0,     0,     0,
      21,    23,    25,    27,    56,   102,    96,     0,     0,   107,
      13,     0,     0,     0,   103,    13,     0,     0,     4,    97,
      58,     0,     0,     0,    32,    42,     0,    32,     0,     0,
       0,     0,     0,     0,     2,     0,     0,    60,    13,    56,
      96,   100,     0,     0,     0,    82,    86,    89,    95,   104,
       0,     0,     0,    12,     0,    15,     0,     0,    13,    52,
      30,    59,     0,     0,     0,    22,     0,     0,     0,     0,
       0,     0,    24,    46,     0,    26,    49,     0,    19,     0,
       3,     0,    87,    88,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   101,     6,     0,     0,    13,    13,     0,    13,     0,
      57,    55,     0,     0,     0,     0,     0,    31,     0,    41,
      20,     0,    70,     0,     0,     0,     0,    65,    47,    66,
      45,    50,    48,     5,     0,    61,     0,    75,    78,    76,
      79,    80,    77,    81,    83,    84,    85,    90,    91,    94,
      92,    93,   105,     0,     0,    54,    14,     9,     8,    51,
      44,     0,     0,     0,     0,     0,     0,     0,    67,     0,
       0,     0,     0,    18,    62,    98,   107,    13,    13,    13,
       7,    43,     0,     0,    39,     0,     0,     0,    28,    72,
      71,    74,     0,     0,    69,   106,    11,    10,    53,     0,
      40,     0,     0,    33,     0,     0,     0,    63,     0,    35,
       0,    37,    34,    29,    73,     0,    65,    36,    38,    68,
      64
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -183,  -183,    -7,   117,    -5,   -45,  -183,   155,   205,   207,
     -48,   212,  -142,   159,    65,   153,  -183,   154,  -183,   -69,
    -183,   220,  -183,  -183,    98,    21,   -88,  -182,    29,    -1,
      97,  -183,   -29,   -11,    56
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    75,    76,   136,    97,    19,    20,    21,    22,
      23,    87,   137,    46,    43,    49,    50,    52,    53,    80,
     200,    38,    39,    40,    57,   192,   148,   149,   212,    98,
      65,    66,    67,    68,    70
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       7,    41,   122,    10,    95,    37,   151,   123,   211,     1,
       6,    99,    78,    51,    81,    82,    61,   112,   113,    41,
      41,     3,     4,    71,    41,   124,    79,    64,    69,     5,
       6,   114,    74,   102,   103,    77,    12,    24,    25,    26,
     142,     8,   143,   211,   142,    14,   143,    41,     9,    11,
     133,   100,    16,    42,   144,    27,   156,   134,    44,    45,
     179,   220,    28,    47,    29,   145,   135,    41,    30,   145,
     146,   129,    59,    25,    60,    55,    31,    56,    32,    33,
     232,    34,   131,   164,   165,   166,   237,    35,   238,   147,
      27,    51,   203,   186,    36,   204,    54,    28,   222,    29,
     228,   223,    48,   229,   167,   168,   169,   170,   171,   193,
     230,    73,    58,   231,    41,    41,    34,    41,   175,   172,
      84,   178,   173,   174,    83,   227,   177,    12,   181,   182,
     183,    59,    25,    60,    62,    63,    14,    88,    91,    12,
     189,    13,   191,    16,    12,    12,    13,   239,    14,    27,
      17,    15,    18,    14,    14,    16,    28,    86,    29,   224,
      16,    16,    17,    89,    18,   115,   116,    17,    93,    18,
      18,   101,    94,    56,    96,    34,   117,   121,   104,   118,
     119,   125,   120,   127,   126,   130,    41,    41,    41,   128,
     216,   217,   218,   132,   138,    69,   105,   106,   107,   108,
     109,   110,   157,   158,   159,   160,   161,   162,   163,   111,
     141,   154,   153,   185,   188,   180,   -98,   184,   155,   199,
     196,   206,   190,   187,    56,   195,   202,   205,   207,   208,
     197,   191,   209,   210,   198,   213,   219,   221,   214,   225,
     226,   233,   236,   176,   140,   201,   150,   139,    85,   235,
     152,    72,   215,   194,   234,     0,    92,   240,     0,    90
};

static const yytype_int16 yycheck[] =
{
       5,    12,    71,     8,    52,    12,    94,    38,   190,    51,
       3,    56,    26,    18,    17,    18,    27,     6,     7,    30,
      31,     3,     0,    30,    35,    56,    40,    28,    29,    28,
       3,    20,    33,    62,    63,    36,    34,     3,     4,     5,
       3,    25,     5,   225,     3,    43,     5,    58,    29,    26,
      43,    58,    50,     3,    17,    21,   101,    50,     3,     5,
     129,   203,    28,     3,    30,    28,    59,    78,    34,    28,
      33,    78,     3,     4,     5,    28,    42,    30,    44,    45,
     222,    47,    83,   112,   113,   114,   228,    53,   230,    52,
      21,    96,    26,   141,    60,    29,    18,    28,    26,    30,
      26,    29,     3,    29,   115,   116,   117,   118,   119,   154,
      26,     5,    27,    29,   125,   126,    47,   128,   125,   120,
      11,   128,   123,   124,    10,   213,   127,    34,   133,   134,
     135,     3,     4,     5,     6,     7,    43,    25,    11,    34,
     145,    36,   147,    50,    34,    34,    36,   235,    43,    21,
      57,    46,    59,    43,    43,    50,    28,    28,    30,   207,
      50,    50,    57,    26,    59,     8,     9,    57,    26,    59,
      59,    28,    27,    30,    26,    47,    19,    31,    29,    22,
      23,    55,    32,    58,    26,     3,   197,   198,   199,    37,
     197,   198,   199,     5,    27,   196,    11,    12,    13,    14,
      15,    16,   105,   106,   107,   108,   109,   110,   111,    24,
      26,    25,    29,     3,     3,    26,    10,    27,    31,    39,
      25,     3,    30,    32,    30,    29,    27,    27,    26,    26,
      37,   236,     5,    29,    37,    27,     3,     3,    40,    25,
      31,    26,    26,   126,    89,   180,    93,    88,    43,    48,
      96,    31,   196,   155,   225,    -1,    49,   236,    -1,    47
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    51,    63,     3,     0,    28,     3,    66,    25,    29,
      66,    26,    34,    36,    43,    46,    50,    57,    59,    68,
      69,    70,    71,    72,     3,     4,     5,    21,    28,    30,
      34,    42,    44,    45,    47,    53,    60,    64,    83,    84,
      85,    95,     3,    76,     3,     5,    75,     3,     3,    77,
      78,    66,    79,    80,    18,    28,    30,    86,    27,     3,
       5,    95,     6,     7,    91,    92,    93,    94,    95,    91,
      96,    64,    83,     5,    91,    64,    65,    91,    26,    40,
      81,    17,    18,    10,    11,    70,    28,    73,    25,    26,
      73,    11,    71,    26,    27,    72,    26,    67,    91,    67,
      64,    28,    94,    94,    29,    11,    12,    13,    14,    15,
      16,    24,     6,     7,    20,     8,     9,    19,    22,    23,
      32,    31,    81,    38,    56,    55,    26,    58,    37,    64,
       3,    91,     5,    43,    50,    59,    66,    74,    27,    75,
      69,    26,     3,     5,    17,    28,    33,    52,    88,    89,
      77,    88,    79,    29,    25,    31,    67,    92,    92,    92,
      92,    92,    92,    92,    94,    94,    94,    95,    95,    95,
      95,    95,    91,    91,    91,    64,    65,    91,    64,    81,
      26,    66,    66,    66,    27,     3,    72,    32,     3,    66,
      30,    66,    87,    67,    86,    29,    25,    37,    37,    39,
      82,    76,    27,    26,    29,    27,     3,    26,    26,     5,
      29,    89,    90,    27,    40,    96,    64,    64,    64,     3,
      74,     3,    26,    29,    72,    25,    31,    88,    26,    29,
      26,    29,    74,    26,    90,    48,    26,    74,    74,    88,
      87
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    65,    65,    66,    66,    67,    67,
      68,    68,    69,    69,    70,    70,    71,    71,    72,    72,
      72,    73,    73,    74,    74,    74,    74,    74,    74,    74,
      74,    75,    75,    76,    76,    77,    77,    78,    79,    79,
      80,    81,    81,    82,    82,    83,    84,    84,    84,    84,
      85,    86,    86,    87,    87,    87,    88,    88,    88,    88,
      89,    89,    89,    90,    90,    91,    91,    91,    91,    91,
      91,    91,    91,    92,    92,    92,    92,    93,    93,    93,
      94,    94,    94,    94,    94,    94,    95,    95,    95,    95,
      95,    95,    95,    95,    96,    96,    96,    96
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     8,     3,     1,     4,     3,     5,     4,     4,
       6,     6,     2,     0,     3,     1,     3,     1,     3,     1,
       4,     1,     3,     1,     3,     1,     3,     1,     6,     8,
       3,     2,     0,     4,     5,     5,     6,     5,     6,     3,
       4,     3,     1,     5,     4,     3,     2,     3,     3,     2,
       3,     3,     1,     2,     0,     3,     1,     3,     1,     2,
       2,     3,     4,     3,     5,     0,     1,     2,     6,     3,
       1,     3,     3,     3,     1,     3,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     3,     1,     2,     2,     1,
       3,     3,     3,     3,     3,     1,     1,     1,     4,     3,
       2,     3,     1,     1,     1,     3,     5,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
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

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
      yychar = yylex ();
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 83 "pars1.y" /* yacc.c:1646  */
    { parseresult = makeprogram((yyvsp[-6]), (yyvsp[-4]), (yyvsp[-1])); }
#line 1545 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 87 "pars1.y" /* yacc.c:1646  */
    { (yyval) = dolabel((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1551 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 88 "pars1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1557 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 91 "pars1.y" /* yacc.c:1646  */
    { (yyval) = makefuncall((yyvsp[-2]), (yyvsp[-3]), (yyvsp[-1])); }
#line 1563 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 93 "pars1.y" /* yacc.c:1646  */
    { (yyval) = makepnb((yyvsp[-2]), cons((yyvsp[-1]), (yyvsp[0]))); }
#line 1569 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 94 "pars1.y" /* yacc.c:1646  */
    { (yyval) = makeif((yyvsp[-4]), (yyvsp[-3]), (yyvsp[-1]), (yyvsp[0])); }
#line 1575 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 95 "pars1.y" /* yacc.c:1646  */
    { (yyval) = makewhile((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1581 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 96 "pars1.y" /* yacc.c:1646  */
    { (yyval) = makerepeat((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1587 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 99 "pars1.y" /* yacc.c:1646  */
    { (yyval) = makefor(1, (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1593 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 102 "pars1.y" /* yacc.c:1646  */
    { (yyval) = makefor(-1, (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1599 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 104 "pars1.y" /* yacc.c:1646  */
    { (yyval) = dogoto((yyvsp[-1]), (yyvsp[0])); }
#line 1605 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 105 "pars1.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 1611 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 109 "pars1.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[-2]), (yyvsp[0])); }
#line 1617 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 110 "pars1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1623 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 114 "pars1.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[-2]), (yyvsp[0])); }
#line 1629 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 115 "pars1.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[0]), NULL); }
#line 1635 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 119 "pars1.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[-2]), (yyvsp[0])); }
#line 1641 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 120 "pars1.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[0]), NULL); }
#line 1647 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 124 "pars1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1653 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 125 "pars1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1659 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 129 "pars1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1665 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 130 "pars1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1671 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 134 "pars1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1677 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 135 "pars1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1683 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 139 "pars1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1689 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 140 "pars1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1695 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 145 "pars1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-5]); }
#line 1701 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 149 "pars1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-7]); }
#line 1707 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 151 "pars1.y" /* yacc.c:1646  */
    { (yyval) = makepnb((yyvsp[-2]), cons((yyvsp[-1]), (yyvsp[0]))); }
#line 1713 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 155 "pars1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 1719 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 156 "pars1.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 1725 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 160 "pars1.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[-3]), (yyvsp[-1])); }
#line 1731 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 163 "pars1.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[-4]), (yyvsp[-2])); }
#line 1737 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 166 "pars1.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[-3]), (yyvsp[-1])); }
#line 1743 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 169 "pars1.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[-4]), (yyvsp[-2])); }
#line 1749 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 172 "pars1.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[-3]), (yyvsp[-1])); }
#line 1755 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 175 "pars1.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[-4]), (yyvsp[-2])); }
#line 1761 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 177 "pars1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 1767 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 179 "pars1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-2]); }
#line 1773 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 183 "pars1.y" /* yacc.c:1646  */
    { instlabel((yyvsp[-2])); /* $$ = cons($1, $3); */ }
#line 1779 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 184 "pars1.y" /* yacc.c:1646  */
    { instlabel((yyvsp[0])); }
#line 1785 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 189 "pars1.y" /* yacc.c:1646  */
    { instconst((yyvsp[-4]), (yyvsp[-2])); }
#line 1791 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 191 "pars1.y" /* yacc.c:1646  */
    { instconst((yyvsp[-3]), (yyvsp[-1])); }
#line 1797 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 195 "pars1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1803 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 196 "pars1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 1809 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 200 "pars1.y" /* yacc.c:1646  */
    { insttype((yyvsp[-2]), (yyvsp[0])); }
#line 1815 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 204 "pars1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1821 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 205 "pars1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 1827 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 209 "pars1.y" /* yacc.c:1646  */
    { instvars((yyvsp[-2]), (yyvsp[0])); }
#line 1833 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 213 "pars1.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[-1]), (yyvsp[0])); }
#line 1839 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 214 "pars1.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 1845 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 218 "pars1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1851 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 219 "pars1.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 1857 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 223 "pars1.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 1863 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 227 "pars1.y" /* yacc.c:1646  */
    { (yyval) = findid((yyvsp[0])); }
#line 1869 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 228 "pars1.y" /* yacc.c:1646  */
    { (yyval) = reducedot((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1875 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 230 "pars1.y" /* yacc.c:1646  */
    { (yyval) = dopoint((yyvsp[-1]), (yyvsp[0])); }
#line 1881 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 234 "pars1.y" /* yacc.c:1646  */
    { (yyval) = arrayref((yyvsp[-1]), NULL, (yyvsp[0]), NULL); }
#line 1887 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 238 "pars1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 1893 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 241 "pars1.y" /* yacc.c:1646  */
    { (yyval) = nconc((yyvsp[-2]), (yyvsp[0])); }
#line 1899 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 245 "pars1.y" /* yacc.c:1646  */
    { instfields((yyvsp[-2]), (yyvsp[0])); }
#line 1905 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 248 "pars1.y" /* yacc.c:1646  */
    { instfields((yyvsp[-4]), (yyvsp[-2])); (yyval) = nconc((yyvsp[-4]), (yyvsp[0])); }
#line 1911 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 250 "pars1.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 1917 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 254 "pars1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1923 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 255 "pars1.y" /* yacc.c:1646  */
    { (yyval) = instpoint((yyvsp[-1]), (yyvsp[0])); }
#line 1929 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 258 "pars1.y" /* yacc.c:1646  */
    { (yyval) = instarray((yyvsp[-3]), (yyvsp[0])); }
#line 1935 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 260 "pars1.y" /* yacc.c:1646  */
    { (yyval) = instrec((yyvsp[-2]), (yyvsp[-1])); }
#line 1941 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 264 "pars1.y" /* yacc.c:1646  */
    { (yyval) = findtype((yyvsp[0])); }
#line 1947 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 265 "pars1.y" /* yacc.c:1646  */
    { (yyval) = instenum((yyvsp[-1])); }
#line 1953 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 266 "pars1.y" /* yacc.c:1646  */
    { (yyval) = instdotdot((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1959 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 270 "pars1.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[0]), (yyvsp[-2])); }
#line 1965 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 271 "pars1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1971 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 275 "pars1.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 1977 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 276 "pars1.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 1983 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 277 "pars1.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 1989 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 278 "pars1.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 1995 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 279 "pars1.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 2001 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 280 "pars1.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 2007 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 281 "pars1.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 2013 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 282 "pars1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2019 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 286 "pars1.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 2025 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 287 "pars1.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 2031 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 288 "pars1.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 2037 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 289 "pars1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2043 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 293 "pars1.y" /* yacc.c:1646  */
    { (yyval) = unaryop((yyvsp[-1]), (yyvsp[0])); }
#line 2049 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 294 "pars1.y" /* yacc.c:1646  */
    { (yyval) = unaryop((yyvsp[-1]), (yyvsp[0])); }
#line 2055 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 295 "pars1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2061 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 299 "pars1.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 2067 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 300 "pars1.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 2073 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 301 "pars1.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 2079 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 302 "pars1.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 2085 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 303 "pars1.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 2091 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 304 "pars1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2097 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 308 "pars1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2103 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 309 "pars1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2109 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 310 "pars1.y" /* yacc.c:1646  */
    { (yyval) = makefuncall((yyvsp[-2]), (yyvsp[-3]), (yyvsp[-1])); }
#line 2115 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 311 "pars1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 2121 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 312 "pars1.y" /* yacc.c:1646  */
    { (yyval) = unaryop((yyvsp[-1]), (yyvsp[0])); }
#line 2127 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 313 "pars1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 2133 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 314 "pars1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2139 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 315 "pars1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2145 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 319 "pars1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2151 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 320 "pars1.y" /* yacc.c:1646  */
    { (yyval) = instdotdot((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 2157 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 321 "pars1.y" /* yacc.c:1646  */
    { (yyval) = instdotdot((yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2])); }
#line 2163 "pars1.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 322 "pars1.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 2169 "pars1.tab.c" /* yacc.c:1646  */
    break;


#line 2173 "pars1.tab.c" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 327 "pars1.y" /* yacc.c:1906  */


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
#define DB_FINDTYPE    1


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

  /* If rhs represents nil, convert rhs to
     an INTEGER NUMBERTOK with ->whichval = 0. */
  if (rhs->whichval == (NIL - RESERVED_BIAS)) {
    rhs->tokentype = NUMBERTOK;
    rhs->datatype = INTEGER;
    rhs->whichval = 0;
  }

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
          printf("BOTH REAL\n");
          op->datatype = REAL;
        } else if ((lhs->datatype == REAL) && (rhs->datatype == INTEGER)) {
          printf("REAL AND INTEGER\n");
          op->datatype = REAL;
          rhs->datatype = REAL;
          rhs->realval = (double) rhs->intval;
        } else if ((lhs->datatype == INTEGER) && (rhs->datatype == REAL) && (lhs->whichval != AREFOP)) {
          printf("INTEGER AND REAL\n");

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

// assumes fn is always a write() or writeln() function
// does not do cross-conversions (e.g., send in writelnf() to convert to writelni())
// identifier datatypes?
TOKEN write_fxn_args_type_check(TOKEN fn, TOKEN args) {

  if (args->datatype == STRINGTYPE) {
    return fn;
  }

  TOKEN out = NULL;

  SYMBOL fn_sym = searchst(fn->stringval);
  if (!fn_sym) {
    printf(" Error: function \"%s\" is not defined.\n", fn->stringval);
    return out;
  }

  int fn_arg_type = fn_sym->datatype->link->basicdt;
  int args_type = args->datatype;
  printf("ARGS SYMTYPE\n");
  printsymbol(args->symtype);
  // if (args->symtype) {
  //   args_type = args->symtype->basicdt;
  // }

  if (args_type == STRINGTYPE) {
    out = fn;
  }
  else {

    int replace_index = 5;
    if (strcmp(fn->stringval, "writeln") == 0) {
      replace_index = 7;
    }

    if (strcmp(fn->stringval, "write") == 0) {

      if (args_type == INTEGER) {
        fn->stringval[replace_index] = 'i';
        fn->stringval[replace_index + 1] = '\0';
        out = fn;
      }
      else if (args_type == REAL) {
        fn->stringval[replace_index] = 'f';
        fn->stringval[replace_index + 1] = '\0';
        out = fn;       
      }

    }
    else if (strcmp(fn->stringval, "writeln") == 0) {

      if (args_type == INTEGER) {
        fn->stringval[replace_index] = 'i';
        fn->stringval[replace_index + 1] = '\0';
        out = fn;
      }
      else if (args_type == REAL) {
        fn->stringval[replace_index] = 'f';
        fn->stringval[replace_index + 1] = '\0';
        out = fn;
      }

    }
  }

  return out;
}


/* makefuncall makes a FUNCALL operator and links it to the fn and args.
   tok is a (now) unused token that is recycled. */
TOKEN makefuncall(TOKEN tok, TOKEN fn, TOKEN args){
    tok = (TOKEN) talloc();
  if (strcmp(fn->stringval, "new") != 0) {
    // tok = (TOKEN) talloc();
    // tok->operands = fn;
    // tok->whichval = FUNCALLOP;
    // tok->datatype = fn->datatype;
    // fn->link = args;
    tok = makeop(FUNCALLOP);    // 24
    // if (!funcall_tok) {
    //   printf(" Failed to allocate TOKEN, makefuncall().\n");  // according to the Prof, print message and coredump
    //   return NULL;
    // }

    SYMBOL this_fxn = searchst(fn->stringval);
    // if (!this_fxn) {
    //   printf(" Failed to find function with name \"%s\" in symbol table.\n", fn->stringval);
    //   return NULL;
    // }
    
    tok->datatype = this_fxn->datatype->basicdt;

    if (strcmp(fn->stringval, "writeln") == 0) {
      printf("FOUND WRITE AND WRITELN\n");
      fn = write_fxn_args_type_check(fn, args);
      // if (!fn) {
      //   return NULL;
      // }
    }

    /* (+ i j) => +->operands = i and i->link = j; (tok fn args) */
    tok->operands = fn;
    fn->link = args;

  }
  else {
    tok = makeop(ASSIGNOP);
    TOKEN funcall = makeop(FUNCALLOP);

    SYMBOL this_type = searchst(args->stringval);

    tok->operands = args;
    args->link = funcall;
    funcall->operands = fn;
    fn->link = makeintc(this_type->datatype->datatype->datatype->size);
    return tok;

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
  TOKEN gotoTok = makeop(GOTOOP);
  gotoTok->operands = makeintc(label);
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
  // tok->symtype = searchst(tok->stringval);
  
  if (DEBUG & DB_FINDTYPE) {
    printf("In findtype()\n");
    dbugprinttok(tok);
  }
  
  SYMBOL sym, typ;
//  sym = searchins(tok->stringval);
  sym = searchst(tok->stringval);

  typ = sym->datatype;
  int kind = sym->kind;

  /* Arg represents symbol of basic datatype (INTEGER, REAL, STRINGTYPE, BOOLETYPE, POINTER) */
  if (kind == BASICTYPE) {
    tok->datatype = sym->basicdt;
    tok->symtype = sym;
  }
  else {
    tok->symtype = typ;
  }

  if (DEBUG & DB_FINDTYPE) {
    printf(" Finished findtype().\n");
    dbugprinttok(tok);
  }

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
      // printf("CURRENT_SIZE %d\n", arrsym->size);
      // printf("CURRENT SIZE %d\n", high-low+1);

    }
    else {
      arrsym->datatype = typetok->symtype;
      // printf("ARRAY SYM SIZE %d\n", arrsym->size);

      arrsym->size = (high - low + 1) * prev_sym->size;
      // printf("PREVIOUS SIZE %d\n", prev_sym->size);
      // printf("CURRENT SIZE %d\n", high-low+1);
      dbugprinttok(curr_bound);
      // printf("TYPESYM SIZE %d\n", typesym->size);
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
    printf(" Finished instpoint().\n");
    dbugprinttok(tok);
    printf(" ");
    dbprsymbol(tok->symtype);
    printf(" ");
    dbprsymbol(tok->symtype->datatype);
    printf("\n");
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
  // printf("INTVAL MAKEGOTO %d\n", label_tok->operands->intval);
  TOKEN goto_tok = makegoto(label_tok->operands->intval);
  TOKEN while_progn_tok = makepnb(talloc(), label_tok); // operand label_tok to while_progn_tok
  // TOKEN do_progn_tok = makepnb(talloc(), statement);    // operand statement to do_progn_tok
  TOKEN ifop_tok = makeif(makeop(IFOP), expr, statement, NULL);

  label_tok->link = ifop_tok;

  /* Handle elimination of nested progns */
  // if (do_progn_tok->whichval != PROGNOP) {
  //   do_progn_tok->operands = statement;
  //   statement->link = goto_tok;
  // }
  // else {  // do_progn_tok == statement
    TOKEN current = (TOKEN) get_last_link(statement->operands);
    current->link = goto_tok;
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

/* Gets and returns the last TOKEN (in)directly
   connected via ->operands to TOKEN tok. */
TOKEN get_last_operand(TOKEN tok) {
  if (!tok) {
    return NULL;
  }

  TOKEN curr = tok;
  TOKEN curr_operand = curr->operands;
  while (curr_operand) {
    curr = curr_operand;
    curr_operand = curr_operand->operands;
  }

  return curr;  
}

TOKEN get_offset(TOKEN var, TOKEN field) {
  
  TOKEN offset = makeintc(-1);

  TOKEN root_name = get_last_operand(var);
  TOKEN last_offset = get_last_link(var->operands);

  if (var->whichval != AREFOP) {
    SYMBOL found = NULL;

    SYMBOL varsym = searchst(root_name->stringval);
    if (varsym) {
      SYMBOL temp = varsym;
      while (temp) {
        if (temp->datatype && temp->datatype->kind == BASICTYPE) {
          break;
        }
        temp = temp->datatype;
      }
      while (temp && !found) {
        if (strcmp(temp->namestring, field->stringval) == 0) {
          found = temp;
        }
        else {
          temp = temp->link;
        }
      }
      if (found) {
        offset->whichval = found->offset;
        return offset;
      }
    }

  }
  else {
    SYMBOL found = NULL;

    SYMBOL varsym = searchst(root_name->stringval);
    if (varsym) {
      SYMBOL temp = varsym;
      while (temp) {
        if (temp->datatype && temp->datatype->kind == BASICTYPE) {
          break;
        }
        temp = temp->datatype;
      }
      while (temp && !found) {
        if (temp->offset == last_offset->whichval) {
          found = temp;
        }
        else {
          temp = temp->link;
        }
      }
      if (found) {
        SYMBOL found_cpy = found;
        SYMBOL blah = searchst(found->datatype->namestring);
        found = NULL;
        while (blah) {
          if (blah->datatype && blah->datatype->kind == BASICTYPE) {
            break;
          }
          blah = blah->datatype;
        }
        while (blah && !found) {
          
          if (strcmp(blah->namestring, field->stringval) == 0) {
            found = blah;
          }
          else {
            blah = blah->link;
          }
        }
        if (found) {
          offset->whichval = last_offset->whichval + found->offset;
        }       
      }
    }   
  }

  return offset;
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
  SYMBOL sym = symalloc();
  sym->basicdt = var->datatype;
  aref->symtype = sym;
  // aref->datatype = var->datatype;
  if (DEBUG & DB_MAKEAREF) {
    printf("makearef().\n");
    dbugprinttok(aref);
  } 
  
  return aref;
}


/* reducedot handles a record reference.
   dot is a (now) unused token that is recycled. */
TOKEN reducedot(TOKEN var, TOKEN dot, TOKEN field) {
  if (DEBUG & DB_REDUCEDOT) {
    printf("reducedot\n");
    dbugprinttok(var);
    dbugprinttok(dot);
    dbugprinttok(field);
  }

  TOKEN aref;
  TOKEN offset = get_offset(var, field);

  if (var->whichval == AREFOP) {

    if (offset->whichval >= 0) {
      var->operands->link = offset;
    }
    aref = var;

  }
  else {
    // printf("MAKING AN AREF\n");
    aref = makearef(var, offset, NULL);
  }

  /* Change aref's datatype to REAL to avoid incorrect
     fixes/floats in binop(). NULL out the dummy link. */
  if (offset->link && offset->link->datatype == REAL &&
    offset->link->realval == -DBL_MAX) {

    aref->datatype = REAL;
    offset->link = NULL;
  }
  // aref->datatype = var->datatype;
  // SYMBOL field_sym = var->symtype;
  field->datatype = var->datatype;

  if (DEBUG & DB_REDUCEDOT) {
    printf("reducedot\n");
    dbugprinttok(aref);
    dbugprinttok(field);
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
  tok->datatype = var->datatype;
  tok->operands = var;
  // tok->symtype = var->symtype;
  if (DEBUG & DB_DOPOINT) {
    printf("dopoint\n");
    dbugprinttok(tok);
  }

  return tok;  
}

int get_internal_label_num(int external_label_num) {
  int i;
  for (i = 0; i < 100; i++) {
    if (labels[i] == external_label_num) {
      printf("LABEL NUMBER %d-%d\n", i, external_label_num);
      return i;
    }
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
