/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "bison.yy" /* yacc.c:339  */

#include <stdio.h>
#include <string.h>

#include "src/pretty_printer.h"  

extern "C" int yylex();

void yyerror(char *s) 
{
  printf ("%s\n", s);
}

Printer *pp = new Printer("./graph.gv");

#line 82 "bison.tab.cc" /* yacc.c:339  */

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

/* In a future release of Bison, this section will be replaced
   by #include "bison.tab.hh".  */
#ifndef YY_YY_BISON_TAB_HH_INCLUDED
# define YY_YY_BISON_TAB_HH_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    END = 0,
    CLASS = 258,
    VAR = 259,
    EXTENDS = 260,
    PUBLIC = 261,
    PRIVATE = 262,
    STATICVOIDMAIN = 263,
    STRING = 264,
    INT = 265,
    BOOLEAN = 266,
    IF = 267,
    ELSE = 268,
    WHILE = 269,
    SYSTEMOUTPRINTLN = 270,
    LENGTH = 271,
    TRUE = 272,
    FALSE = 273,
    NEW = 274,
    THIS = 275,
    RETURN = 276,
    DIGIT = 277,
    LETER = 278,
    COMMENT = 279,
    L_BRACKET = 280,
    R_BRACKET = 281,
    L_ROUND = 282,
    R_ROUND = 283,
    L_SQUARE = 284,
    R_SQUARE = 285,
    SEMICOLON = 286,
    MINUS = 287,
    PLUS = 288,
    PERCENT = 289,
    DIVIDE = 290,
    EQUALS = 291,
    COMMA = 292,
    DOT = 293,
    STAR = 294,
    LESS = 295,
    BANG = 296,
    AND = 297,
    OR = 298,
    INTEGER = 299,
    BOOL_VAL = 300,
    ID = 301
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 18 "bison.yy" /* yacc.c:355  */

	int intVal;
	char* nameId;
  Program *program;
  MainClass *mainClass;
  TrueExpr* mytrue;
  FalseExpr *myfalse;
  ClassDecl *myClass;
  VarDecl *variable;
  VarDeclList *variables;
  Expr *expression;
  ClassDeclList *classSeq;
  StatementList *statementSeq;
  Statements *statements;
  Statement *mystatement;
  ExprList *expressions;
  Id *myId;
  MethodModifier* myModifier;
  MethodDecl *myMethod;
  MethodDeclList *methods;
  Type *myType;
  ArgDeclList *args;
  BasicType *basicType;

#line 195 "bison.tab.cc" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_BISON_TAB_HH_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 226 "bison.tab.cc" /* yacc.c:358  */

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   478

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  168

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

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
      45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   128,   128,   129,   132,   138,   139,   142,   143,   144,
     145,   146,   147,   148,   149,   152,   153,   156,   159,   160,
     163,   165,   167,   169,   173,   174,   175,   178,   179,   182,
     183,   184,   185,   188,   189,   192,   193,   194,   195,   196,
     197,   200,   201,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   226
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "END", "error", "$undefined", "CLASS", "VAR", "EXTENDS", "PUBLIC",
  "PRIVATE", "STATICVOIDMAIN", "STRING", "INT", "BOOLEAN", "IF", "ELSE",
  "WHILE", "SYSTEMOUTPRINTLN", "LENGTH", "TRUE", "FALSE", "NEW", "THIS",
  "RETURN", "DIGIT", "LETER", "COMMENT", "L_BRACKET", "R_BRACKET",
  "L_ROUND", "R_ROUND", "L_SQUARE", "R_SQUARE", "SEMICOLON", "MINUS",
  "PLUS", "PERCENT", "DIVIDE", "EQUALS", "COMMA", "DOT", "STAR", "LESS",
  "BANG", "AND", "OR", "INTEGER", "BOOL_VAL", "ID", "$accept", "goal",
  "main_class", "class_s", "class", "var_s", "var", "method_s", "method",
  "arg_s", "modifier", "type", "statement_s", "statement", "exp_s", "exp",
  "id", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301
};
# endif

#define YYPACT_NINF -69

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-69)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      15,   -11,    34,    19,   -69,    22,   -69,   -69,   -11,   175,
     -69,    43,     8,   -69,   -69,    65,   -11,    20,    60,    54,
     -69,   -69,    62,   -69,   -69,    98,   -69,    52,   -69,    -8,
     -11,   -69,    80,   105,    63,   -69,   -69,    55,   -69,   -69,
     -11,    64,    70,   -69,   119,   112,   -69,   -69,    86,   -69,
      77,   -69,   114,   -69,    -8,   -11,   -69,    49,   -11,   106,
     108,    -8,   -69,   127,   146,   -11,   134,   110,   123,   135,
     200,   134,   158,    -4,   -69,   157,   -69,   162,   157,   200,
     200,   200,   -69,   -69,    -6,   -69,   200,   200,   -69,   282,
     -69,   170,   200,   185,   200,   -69,   200,   200,   138,   219,
     235,   251,   137,   154,   267,   -69,   200,   163,   200,   200,
     200,   -10,   200,   200,   200,   200,   -69,   297,   200,   312,
     327,   342,   -69,   134,   134,   159,   200,   173,   -69,   357,
     -69,   216,   324,    12,   -69,   164,   165,   125,   438,   426,
     172,   372,   176,   179,   -69,   196,   -69,   -69,   387,   -69,
     -69,   194,   -69,   181,   -69,   200,   134,   -69,   -69,   104,
     414,   -69,   402,   -69,   -69,   200,   -69,   414
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,    63,     0,     1,     2,     0,     0,
       6,     0,     0,     3,     5,     0,     0,     0,     0,     0,
      27,    28,    31,    30,     7,     0,    16,     0,    19,     0,
       0,    32,     0,     0,     0,     8,    15,     0,     9,    18,
       0,     0,     0,    11,     0,     0,    29,    10,     0,    17,
       0,    12,     0,    13,    24,     0,    14,     0,     0,     0,
       0,     0,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    34,    32,    25,     0,     0,     0,
       0,     0,    55,    56,     0,    58,     0,     0,    54,     0,
      57,     0,     0,     0,     0,    33,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    61,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    35,     0,     0,     0,
       0,     0,     4,     0,     0,     0,     0,     0,    62,     0,
      23,    46,    45,    48,    51,     0,    47,    44,    43,    49,
       0,     0,     0,     0,    39,     0,    37,    38,     0,    60,
      50,     0,    21,     0,    22,     0,     0,    59,    52,     0,
      42,    20,     0,    36,    53,     0,    40,    41
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -69,   -69,   -69,   -69,   214,   -19,   -24,   103,    90,   -69,
     -69,   -17,   171,   -68,   -69,   -12,    -1
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     9,    10,    25,    26,    27,    28,    57,
      29,    30,    73,    74,   159,    89,    90
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       5,    36,    22,    23,   102,    95,   134,    12,    67,    95,
      68,    69,    40,    16,    44,    19,    31,    94,     1,     7,
      36,    71,     8,    95,    31,    95,    20,    21,    31,    41,
      22,    23,    31,    17,     6,     4,     4,    58,     4,    48,
       4,   106,     4,    31,    65,    72,    24,    11,    36,    15,
     111,   112,   113,    31,    59,   145,   146,    62,    20,    21,
      31,    20,    21,    75,    76,    78,     4,    99,   100,   101,
      78,    75,    78,    18,   104,   105,    78,    60,    38,    33,
     117,    47,   119,   103,   120,   121,    61,    32,   163,    42,
      78,    34,    78,    46,   129,    49,   131,   132,   133,    50,
     136,   137,   138,   139,    20,    21,   141,    55,    22,    23,
     135,    20,    21,    54,   148,    22,    23,    39,    20,    21,
      20,    21,    78,    78,    35,    20,    21,    39,    37,    22,
      23,    43,   164,    64,    63,    39,    45,    79,    53,   160,
      56,   165,    39,   162,     4,    51,    67,    52,    68,    69,
      80,     4,    66,   167,   106,    78,    22,    23,    67,    71,
      68,    69,    81,   111,   122,     4,   126,    70,    22,    23,
      67,    71,    68,    69,    67,    13,    68,    69,     8,    92,
       4,   127,    67,    71,    68,    69,    96,    71,    98,   130,
     147,   151,     4,    97,   106,    71,   116,    67,   152,    68,
      69,   149,   154,   111,     4,   113,   118,   161,     4,   156,
      71,    82,    83,    84,    85,   155,     4,    82,    83,    84,
      85,    86,   158,    14,     0,     0,     0,    86,     0,     0,
       0,     4,     0,     0,     0,    87,     0,    77,    88,     0,
       4,    87,    91,    93,    88,   106,     4,   123,   106,   109,
     110,   108,   109,   110,   111,   112,   113,   111,   112,   113,
       0,   114,   115,   124,   106,     0,     0,   108,   109,   110,
       0,     0,     0,   111,   112,   113,     0,   114,   115,   125,
     106,     0,     0,   108,   109,   110,     0,     0,     0,   111,
     112,   113,     0,   114,   115,   128,   106,     0,     0,   108,
     109,   110,     0,     0,     0,   111,   112,   113,     0,   114,
     115,   106,     0,   107,   108,   109,   110,     0,     0,     0,
     111,   112,   113,     0,   114,   115,   106,     0,   140,   108,
     109,   110,     0,     0,     0,   111,   112,   113,     0,   114,
     115,   106,     0,   142,   108,   109,   110,     0,     0,     0,
     111,   112,   113,   106,   114,   115,   106,   143,   110,   108,
     109,   110,   111,   112,   113,   111,   112,   113,     0,   114,
     115,   106,     0,   144,   108,   109,   110,     0,     0,     0,
     111,   112,   113,     0,   114,   115,   106,   150,     0,   108,
     109,   110,     0,     0,     0,   111,   112,   113,     0,   114,
     115,   106,     0,   153,   108,   109,   110,     0,     0,     0,
     111,   112,   113,     0,   114,   115,   106,   157,     0,   108,
     109,   110,     0,     0,     0,   111,   112,   113,     0,   114,
     115,   106,     0,   166,   108,   109,   110,     0,     0,     0,
     111,   112,   113,   106,   114,   115,   108,   109,   110,     0,
       0,     0,   111,   112,   113,   106,   114,   115,   108,   109,
     110,     0,     0,     0,   111,   112,   113,   106,   114,     0,
     108,   109,   110,     0,     0,     0,   111,   112,   113
};

static const yytype_int16 yycheck[] =
{
       1,    25,    10,    11,    10,    73,    16,     8,    12,    77,
      14,    15,    29,     5,    33,    16,    17,    21,     3,     0,
      44,    25,     3,    91,    25,    93,     6,     7,    29,    30,
      10,    11,    33,    25,     0,    46,    46,    54,    46,    40,
      46,    29,    46,    44,    61,    64,    26,    25,    72,     6,
      38,    39,    40,    54,    55,   123,   124,    58,     6,     7,
      61,     6,     7,    64,    65,    66,    46,    79,    80,    81,
      71,    72,    73,     8,    86,    87,    77,    28,    26,    25,
      92,    26,    94,    84,    96,    97,    37,    27,   156,     9,
      91,    29,    93,    30,   106,    31,   108,   109,   110,    29,
     112,   113,   114,   115,     6,     7,   118,    30,    10,    11,
     111,     6,     7,    27,   126,    10,    11,    27,     6,     7,
       6,     7,   123,   124,    26,     6,     7,    37,    25,    10,
      11,    26,    28,    25,    28,    45,    33,    27,    26,   151,
      26,    37,    52,   155,    46,    26,    12,    44,    14,    15,
      27,    46,    25,   165,    29,   156,    10,    11,    12,    25,
      14,    15,    27,    38,    26,    46,    29,    21,    10,    11,
      12,    25,    14,    15,    12,     0,    14,    15,     3,    21,
      46,    27,    12,    25,    14,    15,    29,    25,    26,    26,
      31,    27,    46,    36,    29,    25,    26,    12,    26,    14,
      15,    28,    26,    38,    46,    40,    21,    26,    46,    13,
      25,    17,    18,    19,    20,    36,    46,    17,    18,    19,
      20,    27,    28,     9,    -1,    -1,    -1,    27,    -1,    -1,
      -1,    46,    -1,    -1,    -1,    41,    -1,    66,    44,    -1,
      46,    41,    71,    72,    44,    29,    46,    28,    29,    33,
      34,    32,    33,    34,    38,    39,    40,    38,    39,    40,
      -1,    42,    43,    28,    29,    -1,    -1,    32,    33,    34,
      -1,    -1,    -1,    38,    39,    40,    -1,    42,    43,    28,
      29,    -1,    -1,    32,    33,    34,    -1,    -1,    -1,    38,
      39,    40,    -1,    42,    43,    28,    29,    -1,    -1,    32,
      33,    34,    -1,    -1,    -1,    38,    39,    40,    -1,    42,
      43,    29,    -1,    31,    32,    33,    34,    -1,    -1,    -1,
      38,    39,    40,    -1,    42,    43,    29,    -1,    31,    32,
      33,    34,    -1,    -1,    -1,    38,    39,    40,    -1,    42,
      43,    29,    -1,    31,    32,    33,    34,    -1,    -1,    -1,
      38,    39,    40,    29,    42,    43,    29,    30,    34,    32,
      33,    34,    38,    39,    40,    38,    39,    40,    -1,    42,
      43,    29,    -1,    31,    32,    33,    34,    -1,    -1,    -1,
      38,    39,    40,    -1,    42,    43,    29,    30,    -1,    32,
      33,    34,    -1,    -1,    -1,    38,    39,    40,    -1,    42,
      43,    29,    -1,    31,    32,    33,    34,    -1,    -1,    -1,
      38,    39,    40,    -1,    42,    43,    29,    30,    -1,    32,
      33,    34,    -1,    -1,    -1,    38,    39,    40,    -1,    42,
      43,    29,    -1,    31,    32,    33,    34,    -1,    -1,    -1,
      38,    39,    40,    29,    42,    43,    32,    33,    34,    -1,
      -1,    -1,    38,    39,    40,    29,    42,    43,    32,    33,
      34,    -1,    -1,    -1,    38,    39,    40,    29,    42,    -1,
      32,    33,    34,    -1,    -1,    -1,    38,    39,    40
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    48,    49,    46,    63,     0,     0,     3,    50,
      51,    25,    63,     0,    51,     6,     5,    25,     8,    63,
       6,     7,    10,    11,    26,    52,    53,    54,    55,    57,
      58,    63,    27,    25,    29,    26,    53,    54,    26,    55,
      58,    63,     9,    26,    52,    54,    30,    26,    63,    31,
      29,    26,    54,    26,    27,    30,    26,    56,    58,    63,
      28,    37,    63,    28,    25,    58,    25,    12,    14,    15,
      21,    25,    52,    59,    60,    63,    63,    59,    63,    27,
      27,    27,    17,    18,    19,    20,    27,    41,    44,    62,
      63,    59,    21,    59,    21,    60,    29,    36,    26,    62,
      62,    62,    10,    63,    62,    62,    29,    31,    32,    33,
      34,    38,    39,    40,    42,    43,    26,    62,    21,    62,
      62,    62,    26,    28,    28,    28,    29,    27,    28,    62,
      26,    62,    62,    62,    16,    63,    62,    62,    62,    62,
      31,    62,    31,    30,    31,    60,    60,    31,    62,    28,
      30,    27,    26,    31,    26,    36,    13,    30,    28,    61,
      62,    26,    62,    60,    28,    37,    31,    62
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    48,    49,    50,    50,    51,    51,    51,
      51,    51,    51,    51,    51,    52,    52,    53,    54,    54,
      55,    55,    55,    55,    56,    56,    56,    57,    57,    58,
      58,    58,    58,    59,    59,    60,    60,    60,    60,    60,
      60,    61,    61,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    63
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     3,    15,     2,     1,     4,     5,     5,
       6,     6,     7,     7,     8,     2,     1,     3,     2,     1,
      13,    12,    12,    11,     0,     4,     2,     1,     1,     3,
       1,     1,     1,     2,     1,     3,     7,     5,     5,     4,
       7,     3,     1,     3,     3,     3,     3,     3,     3,     3,
       4,     3,     5,     6,     1,     1,     1,     1,     1,     5,
       4,     2,     3,     1
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 128 "bison.yy" /* yacc.c:1646  */
    {(yyval.program) = new Program((MainClass *)((yyvsp[-1].mainClass))); (yyval.program)->accept(pp);}
#line 1565 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 3:
#line 129 "bison.yy" /* yacc.c:1646  */
    {(yyval.program) = new Program((MainClass *)((yyvsp[-2].mainClass)), (ClassDeclList *)((yyvsp[-1].classSeq))); (yyval.program)->accept(pp);}
#line 1571 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 4:
#line 135 "bison.yy" /* yacc.c:1646  */
    {(yyval.mainClass) = new MainClass((Id *)((yyvsp[-13].myId)), (Id *)((yyvsp[-5].myId)), (StatementList *)((yyvsp[-2].statementSeq)));}
#line 1577 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 5:
#line 138 "bison.yy" /* yacc.c:1646  */
    {(yyval.classSeq) = new ClassDeclList((ClassDeclList *)((yyvsp[-1].classSeq)), (ClassDecl *)((yyvsp[0].myClass)));}
#line 1583 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 6:
#line 139 "bison.yy" /* yacc.c:1646  */
    {(yyval.classSeq) = new ClassDeclList((ClassDecl *)((yyvsp[0].myClass)));}
#line 1589 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 7:
#line 142 "bison.yy" /* yacc.c:1646  */
    {(yyval.myClass) = new ClassDecl((Id *)((yyvsp[-2].myId)), nullptr);}
#line 1595 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 8:
#line 143 "bison.yy" /* yacc.c:1646  */
    {(yyval.myClass) = new ClassDecl((Id *)((yyvsp[-3].myId)), nullptr, (VarDeclList *)((yyvsp[-1].variables)));}
#line 1601 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 9:
#line 144 "bison.yy" /* yacc.c:1646  */
    {(yyval.myClass) = new ClassDecl((Id *)((yyvsp[-3].myId)), nullptr, (MethodDeclList *)((yyvsp[-1].methods)));}
#line 1607 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 10:
#line 145 "bison.yy" /* yacc.c:1646  */
    {(yyval.myClass) = new ClassDecl((Id *)((yyvsp[-4].myId)), nullptr, (VarDeclList *)((yyvsp[-2].variables)), (MethodDeclList *)((yyvsp[-1].methods)));}
#line 1613 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 11:
#line 146 "bison.yy" /* yacc.c:1646  */
    {(yyval.myClass) = new ClassDecl((Id *)((yyvsp[-4].myId)), (Id *)((yyvsp[-2].myId))); printf("class ext (%s)\n", (yyvsp[-4].myId) );}
#line 1619 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 12:
#line 147 "bison.yy" /* yacc.c:1646  */
    {(yyval.myClass) = new ClassDecl((Id *)((yyvsp[-5].myId)), (Id *)((yyvsp[-3].myId)), (VarDeclList *)((yyvsp[-1].variables)));}
#line 1625 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 13:
#line 148 "bison.yy" /* yacc.c:1646  */
    {(yyval.myClass) = new ClassDecl((Id *)((yyvsp[-5].myId)), (Id *)((yyvsp[-3].myId)), (MethodDeclList *)((yyvsp[-1].methods)));}
#line 1631 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 14:
#line 149 "bison.yy" /* yacc.c:1646  */
    {(yyval.myClass) = new ClassDecl((Id *)((yyvsp[-6].myId)), (Id *)((yyvsp[-4].myId)), (VarDeclList *)((yyvsp[-2].variables)), (MethodDeclList *)((yyvsp[-1].methods)));}
#line 1637 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 15:
#line 152 "bison.yy" /* yacc.c:1646  */
    {(yyval.variables) = new VarDeclList((VarDeclList *)((yyvsp[-1].variables)), (VarDecl *)((yyvsp[0].variable))); }
#line 1643 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 16:
#line 153 "bison.yy" /* yacc.c:1646  */
    {(yyval.variables) = new VarDeclList((VarDecl *)((yyvsp[0].variable)));}
#line 1649 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 17:
#line 156 "bison.yy" /* yacc.c:1646  */
    {(yyval.variable) = new VarDecl((Type *)((yyvsp[-2].myType)), (Id *)((yyvsp[-1].myId)));}
#line 1655 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 18:
#line 159 "bison.yy" /* yacc.c:1646  */
    {(yyval.methods) = new MethodDeclList((MethodDeclList *)((yyvsp[-1].methods)), (MethodDecl *)((yyvsp[0].myMethod)));}
#line 1661 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 19:
#line 160 "bison.yy" /* yacc.c:1646  */
    {(yyval.methods) = new MethodDeclList((MethodDecl *)((yyvsp[0].myMethod)));}
#line 1667 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 20:
#line 164 "bison.yy" /* yacc.c:1646  */
    {(yyval.myMethod) = new MethodDecl((MethodModifier *)((yyvsp[-12].myModifier)), (Type *)((yyvsp[-11].myType)), (Id *)((yyvsp[-10].myId)), (ArgDeclList *)((yyvsp[-8].args)), (VarDeclList *)((yyvsp[-5].variables)), (StatementList *)((yyvsp[-4].statementSeq)), (Expr *)((yyvsp[-2].expression)));}
#line 1673 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 21:
#line 166 "bison.yy" /* yacc.c:1646  */
    {(yyval.myMethod) = new MethodDecl((MethodModifier *)((yyvsp[-11].myModifier)),(Type *)((yyvsp[-10].myType)), (Id *)((yyvsp[-9].myId)), (ArgDeclList *)((yyvsp[-7].args)), (VarDeclList *)((yyvsp[-4].variables)), nullptr, (Expr *)((yyvsp[-2].expression)));}
#line 1679 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 22:
#line 168 "bison.yy" /* yacc.c:1646  */
    {(yyval.myMethod) = new MethodDecl((MethodModifier *)((yyvsp[-11].myModifier)),(Type *)((yyvsp[-10].myType)), (Id *)((yyvsp[-9].myId)), (ArgDeclList *)((yyvsp[-7].args)), nullptr, (StatementList *)((yyvsp[-4].statementSeq)), (Expr *)((yyvsp[-2].expression)));}
#line 1685 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 23:
#line 170 "bison.yy" /* yacc.c:1646  */
    {(yyval.myMethod) = new MethodDecl((MethodModifier *)((yyvsp[-10].myModifier)),(Type *)((yyvsp[-9].myType)), (Id *)((yyvsp[-8].myId)), (ArgDeclList *)((yyvsp[-6].args)), nullptr, nullptr, (Expr *)((yyvsp[-2].expression)));}
#line 1691 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 24:
#line 173 "bison.yy" /* yacc.c:1646  */
    {(yyval.args) = new ArgDeclList();}
#line 1697 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 25:
#line 174 "bison.yy" /* yacc.c:1646  */
    {(yyval.args) = new ArgDeclList((ArgDeclList *)((yyvsp[-3].args)), (Type *)((yyvsp[-1].myType)), (Id *)((yyvsp[0].myId)));}
#line 1703 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 26:
#line 175 "bison.yy" /* yacc.c:1646  */
    {(yyval.args) = new ArgDeclList((Type *)((yyvsp[-1].myType)), (Id *)((yyvsp[0].myId)));}
#line 1709 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 27:
#line 178 "bison.yy" /* yacc.c:1646  */
    {(yyval.myModifier) = new MethodModifier("PUBLIC");}
#line 1715 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 28:
#line 179 "bison.yy" /* yacc.c:1646  */
    {(yyval.myModifier) = new MethodModifier("PRIVATE");}
#line 1721 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 29:
#line 182 "bison.yy" /* yacc.c:1646  */
    {(yyval.myType) = new BasicType(INT_ARRAY_);}
#line 1727 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 30:
#line 183 "bison.yy" /* yacc.c:1646  */
    {(yyval.myType) = new BasicType(BOOL_);}
#line 1733 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 31:
#line 184 "bison.yy" /* yacc.c:1646  */
    {(yyval.myType) = new BasicType(INT_);}
#line 1739 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 32:
#line 185 "bison.yy" /* yacc.c:1646  */
    {(yyval.myType) = new ClassType((Id *)((yyvsp[0].myId)));}
#line 1745 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 33:
#line 188 "bison.yy" /* yacc.c:1646  */
    {(yyval.statementSeq) = new StatementList((StatementList *)((yyvsp[-1].statementSeq)), (Statement *)((yyvsp[0].mystatement)));}
#line 1751 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 34:
#line 189 "bison.yy" /* yacc.c:1646  */
    {(yyval.statementSeq) = new StatementList((Statement *)((yyvsp[0].mystatement)));}
#line 1757 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 35:
#line 192 "bison.yy" /* yacc.c:1646  */
    {(yyval.mystatement) = new Statements((StatementList *)((yyvsp[-1].statementSeq)));}
#line 1763 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 36:
#line 193 "bison.yy" /* yacc.c:1646  */
    {(yyval.mystatement) = new IfStatement((Expr *)((yyvsp[-4].expression)), (Statement *)((yyvsp[-2].mystatement)), (Statement *)((yyvsp[0].mystatement)));}
#line 1769 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 37:
#line 194 "bison.yy" /* yacc.c:1646  */
    {(yyval.mystatement) = new WhileStatement((Expr *)((yyvsp[-2].expression)), (Statement *)((yyvsp[0].mystatement)));}
#line 1775 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 38:
#line 195 "bison.yy" /* yacc.c:1646  */
    {(yyval.mystatement) = new PrintLineStatement((Expr *)((yyvsp[-2].expression)));}
#line 1781 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 39:
#line 196 "bison.yy" /* yacc.c:1646  */
    {(yyval.mystatement) = new AssignStatement((Id *)((yyvsp[-3].myId)), (Expr *)((yyvsp[-1].expression)));}
#line 1787 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 40:
#line 197 "bison.yy" /* yacc.c:1646  */
    {(yyval.mystatement) = new RandomAccessAssignStatement((Id *)((yyvsp[-6].myId)), (Expr *)((yyvsp[-4].expression)), (Expr *)((yyvsp[-1].expression)));}
#line 1793 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 41:
#line 200 "bison.yy" /* yacc.c:1646  */
    {(yyval.expressions) = new ExprList((ExprList *)((yyvsp[-2].expressions)), (Expr *)((yyvsp[0].expression)));}
#line 1799 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 42:
#line 201 "bison.yy" /* yacc.c:1646  */
    {(yyval.expressions) = new ExprList((Expr *)((yyvsp[0].expression)));}
#line 1805 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 43:
#line 204 "bison.yy" /* yacc.c:1646  */
    {(yyval.expression) = new BinaryExpr((Expr *)((yyvsp[-2].expression)), AND_T, (Expr *)((yyvsp[0].expression)));}
#line 1811 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 44:
#line 205 "bison.yy" /* yacc.c:1646  */
    {(yyval.expression) = new BinaryExpr((Expr *)((yyvsp[-2].expression)), LESS_T, (Expr *)((yyvsp[0].expression)));}
#line 1817 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 45:
#line 206 "bison.yy" /* yacc.c:1646  */
    {(yyval.expression) = new BinaryExpr((Expr *)((yyvsp[-2].expression)), PLUS_T, (Expr *)((yyvsp[0].expression)));}
#line 1823 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 46:
#line 207 "bison.yy" /* yacc.c:1646  */
    {(yyval.expression) = new BinaryExpr((Expr *)((yyvsp[-2].expression)), MINUS_T, (Expr *)((yyvsp[0].expression)));}
#line 1829 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 47:
#line 208 "bison.yy" /* yacc.c:1646  */
    {(yyval.expression) = new BinaryExpr((Expr *)((yyvsp[-2].expression)), TIMES_T, (Expr *)((yyvsp[0].expression)));}
#line 1835 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 48:
#line 209 "bison.yy" /* yacc.c:1646  */
    {(yyval.expression) = new BinaryExpr((Expr *)((yyvsp[-2].expression)), MOD_T, (Expr *)((yyvsp[0].expression)));}
#line 1841 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 49:
#line 210 "bison.yy" /* yacc.c:1646  */
    {(yyval.expression) = new BinaryExpr((Expr *)((yyvsp[-2].expression)), OR_T, (Expr *)((yyvsp[0].expression)));}
#line 1847 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 50:
#line 211 "bison.yy" /* yacc.c:1646  */
    {(yyval.expression) = new RandomAccessExpr((Expr *)((yyvsp[-3].expression)), (Expr *)((yyvsp[-1].expression)));}
#line 1853 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 51:
#line 212 "bison.yy" /* yacc.c:1646  */
    {(yyval.expression) = new LengthExpr((Expr *)((yyvsp[-2].expression)));}
#line 1859 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 52:
#line 213 "bison.yy" /* yacc.c:1646  */
    {(yyval.expression) = new CallMethodExpr((Expr *)((yyvsp[-4].expression)), (Id *)((yyvsp[-2].myId)), nullptr);}
#line 1865 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 53:
#line 214 "bison.yy" /* yacc.c:1646  */
    {(yyval.expression) = new CallMethodExpr((Expr *)((yyvsp[-5].expression)), (Id *)((yyvsp[-3].myId)), (ExprList *)((yyvsp[-1].expressions)));}
#line 1871 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 54:
#line 215 "bison.yy" /* yacc.c:1646  */
    {(yyval.expression) = new IntegerExpr(yylval.intVal);}
#line 1877 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 55:
#line 216 "bison.yy" /* yacc.c:1646  */
    {(yyval.expression) = new TrueExpr();}
#line 1883 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 56:
#line 217 "bison.yy" /* yacc.c:1646  */
    {(yyval.expression) = new FalseExpr();}
#line 1889 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 57:
#line 218 "bison.yy" /* yacc.c:1646  */
    {(yyval.expression) = (yyvsp[0].myId);}
#line 1895 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 58:
#line 219 "bison.yy" /* yacc.c:1646  */
    {(yyval.expression) = new ThisExpr();}
#line 1901 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 59:
#line 220 "bison.yy" /* yacc.c:1646  */
    {(yyval.expression) = new NewIntArrayExpr((Expr *)((yyvsp[-1].expression)));}
#line 1907 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 60:
#line 221 "bison.yy" /* yacc.c:1646  */
    {(yyval.expression) = new NewObjectExpr((Id *)((yyvsp[-2].myId)));}
#line 1913 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 61:
#line 222 "bison.yy" /* yacc.c:1646  */
    {(yyval.expression) = new NotExpr((Expr *)((yyvsp[0].expression)));}
#line 1919 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 62:
#line 223 "bison.yy" /* yacc.c:1646  */
    {(yyval.expression) = (yyvsp[-1].expression);}
#line 1925 "bison.tab.cc" /* yacc.c:1646  */
    break;

  case 63:
#line 226 "bison.yy" /* yacc.c:1646  */
    {(yyval.myId) = new Id(std::string(yylval.nameId));}
#line 1931 "bison.tab.cc" /* yacc.c:1646  */
    break;


#line 1935 "bison.tab.cc" /* yacc.c:1646  */
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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
#line 227 "bison.yy" /* yacc.c:1906  */


int main (void) {
  yyparse();
  delete pp;
}
