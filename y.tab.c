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
#line 4 "compiler_hw3.y" /* yacc.c:339  */

    #include "compiler_hw_common.h" //Extern variables that communicate with lex
    #include "mySymbolTable.h"
    #include "myCodeGen.h"
    #include "mySwitch.h"
    //#define YYDEBUG 1
    //int yydebug = 1;
    char* free_cat(char*a,char*b){
        int n=strlen(a)+strlen(b)+1;
        char* ret=malloc(n);
        strcpy(ret,a);
        strcat(ret,b);
        free(a);
        free(b);
        return ret;
    }
    char* cdup(char c){
        static char temp[2];
        temp[1]=0;
        temp[0]=c;
        return strdup(temp);
    }
    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;
    int reduce_line=1;

    int yylex_destroy ();
    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", reduce_line, s);
        g_has_error=true;
    }

    /* Used to generate code */
    /* As printf; the usage: CODEGEN("%d - %s\n", 100, "Hello world"); */
    /* We do not enforce the use of this macro */

    /* Global variables */
    bool g_has_error = false;

#line 108 "y.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    VAR = 258,
    NEWLINE = 259,
    INT = 260,
    FLOAT = 261,
    BOOL = 262,
    STRING = 263,
    INC = 264,
    DEC = 265,
    GEQ = 266,
    LOR = 267,
    LAND = 268,
    EQL = 269,
    ADD_ASSIGN = 270,
    SUB_ASSIGN = 271,
    QUO_ASSIGN = 272,
    MUL_ASSIGN = 273,
    REM_ASSIGN = 274,
    IF = 275,
    ELSE = 276,
    FOR = 277,
    SWITCH = 278,
    CASE = 279,
    DEFAULT = 280,
    PRINTLN = 281,
    PACKAGE = 282,
    FUNC = 283,
    PRINT = 284,
    RETURN = 285,
    INT_LIT = 286,
    FLOAT_LIT = 287,
    STRING_LIT = 288,
    BOOL_LIT = 289,
    IDENT = 290
  };
#endif
/* Tokens.  */
#define VAR 258
#define NEWLINE 259
#define INT 260
#define FLOAT 261
#define BOOL 262
#define STRING 263
#define INC 264
#define DEC 265
#define GEQ 266
#define LOR 267
#define LAND 268
#define EQL 269
#define ADD_ASSIGN 270
#define SUB_ASSIGN 271
#define QUO_ASSIGN 272
#define MUL_ASSIGN 273
#define REM_ASSIGN 274
#define IF 275
#define ELSE 276
#define FOR 277
#define SWITCH 278
#define CASE 279
#define DEFAULT 280
#define PRINTLN 281
#define PACKAGE 282
#define FUNC 283
#define PRINT 284
#define RETURN 285
#define INT_LIT 286
#define FLOAT_LIT 287
#define STRING_LIT 288
#define BOOL_LIT 289
#define IDENT 290

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 52 "compiler_hw3.y" /* yacc.c:355  */

    char* str_lit;
    int int_lit;
    float float_lit;
    bool bool_lit;
    char* func_sig;
    char* name;
    unsigned char type;
    int label;
    struct forloop_node for_labels;
    struct case_node case_data;
    struct switch_node switch_data;
    /* ... */

#line 233 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 250 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   196

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  189

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   290

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    50,    38,     2,     2,    49,     2,     2,
      40,    41,    47,    45,    39,    46,     2,    48,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    43,     2,
       2,    42,    44,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,     2,    37,     2,     2,     2,     2,
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
      35
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    97,    97,   102,   107,   112,   117,   123,   124,   127,
     131,   134,   135,   138,   139,   142,   148,   154,   164,   170,
     171,   174,   175,   178,   181,   186,   189,   194,   197,   200,
     205,   208,   213,   216,   220,   228,   234,   243,   248,   251,
     256,   265,   273,   283,   292,   298,   305,   314,   317,   318,
     325,   330,   334,   346,   358,   361,   364,   367,   370,   374,
     379,   382,   396,   399,   402,   405,   410,   421,   432,   443,
     454,   462,   467,   470,   476,   479,   485,   488,   497,   500,
     509,   518,   521,   529,   537,   540,   548,   556,   562,   565,
     568,   576,   581,   584,   589,   594,   604,   607,   610,   613,
     618,   621
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VAR", "NEWLINE", "INT", "FLOAT", "BOOL",
  "STRING", "INC", "DEC", "GEQ", "LOR", "LAND", "EQL", "ADD_ASSIGN",
  "SUB_ASSIGN", "QUO_ASSIGN", "MUL_ASSIGN", "REM_ASSIGN", "IF", "ELSE",
  "FOR", "SWITCH", "CASE", "DEFAULT", "PRINTLN", "PACKAGE", "FUNC",
  "PRINT", "RETURN", "INT_LIT", "FLOAT_LIT", "STRING_LIT", "BOOL_LIT",
  "IDENT", "'{'", "'}'", "'\"'", "','", "'('", "')'", "'='", "':'", "'>'",
  "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "$accept", "newline", "for",
  "ident", "Program", "package", "methods", "method", "lines", "newlines",
  "int_lit", "float_lit", "bool_lit", "string_lit", "parastart", "paras",
  "paradecstart", "paradecs", "exprable_type", "nonvoid_type", "type",
  "paradec", "funchead", "funcbody", "blockbody", "dec_assign", "forbody",
  "ifbody", "casebody", "defaultbody", "switchhalfblock", "line",
  "equation", "lor_expr", "land_expr", "equ_expr", "cmp_expr", "expr",
  "term", "fac", "case_lit", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   123,   125,    34,    44,
      40,    41,    61,    58,    62,    43,    45,    42,    47,    37,
      33
};
# endif

#define YYPACT_NINF -92

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-92)))

#define YYTABLE_NINF -38

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      13,   -92,    13,    21,    16,   -92,   -92,    42,    52,   -92,
      47,   -92,    13,    44,    13,   -92,    52,    56,    57,   -92,
      20,    51,    55,   -92,    94,   -92,   -92,   -92,   -92,   -92,
     -92,    20,    56,    60,    58,    61,    33,   -92,    33,    64,
      65,   116,   -92,   -92,   -92,   154,    33,    33,    33,    33,
      33,   -92,    59,   -92,   -92,   -92,    70,    13,    13,    -5,
      13,   -92,    95,    96,    97,     0,   -16,   -13,   -92,   -92,
     -92,   -92,    82,    33,    33,    68,    95,    -3,   116,   116,
      77,   -92,    95,   -92,   -92,    33,    33,    33,    33,    33,
      33,   116,    11,   -92,   -92,   -92,    95,   -92,    94,    76,
      79,   -15,    75,   -92,    13,    13,    94,    33,    33,    33,
      33,    33,    33,    33,    33,    33,    33,    71,    85,    12,
      25,    13,    91,    28,    92,    35,    98,    95,    95,    95,
      95,    95,   100,    99,    95,   -92,    95,   -92,   106,    94,
      94,   -92,   104,   102,   -92,   101,   110,   -92,    96,    97,
       0,   -16,   -16,   -13,   -13,   -92,   -92,   -92,   111,    33,
     -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,
      33,   -92,   115,   118,   -92,   -92,    94,    94,   -92,    95,
      95,   -92,   -92,   120,   121,    13,    13,   -92,   -92
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      14,     2,    14,     0,     0,    13,     1,     0,    10,     6,
       0,     5,     8,     0,    14,    35,    10,    24,     0,     7,
       0,     0,    23,    26,    64,    27,    28,    29,    31,    30,
      34,    33,     0,     0,     0,     0,     0,     3,     0,     0,
       0,    63,    15,    16,    17,     4,     0,     0,     0,     0,
       0,    96,     0,    97,    98,    99,     0,    14,    14,     0,
      12,    48,    72,    74,    76,    78,    81,    84,    88,    32,
      36,    25,     0,     0,     0,     4,    41,     0,     0,     0,
       0,    62,    61,    52,    53,     0,     0,     0,     0,     0,
      20,     0,     0,    89,    90,    91,    40,     9,    64,     0,
       0,     0,     0,    60,    14,    14,    64,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    50,    39,     0,
       0,    14,     0,     0,     0,     0,     0,    66,    67,    69,
      68,    70,     0,    19,    22,    71,    65,    92,     0,    64,
      64,   100,     0,     0,    43,     0,     0,    11,    73,    75,
      77,    80,    79,    82,    83,    85,    86,    87,     0,     0,
      49,    94,    93,    44,    55,    54,    57,    56,    18,    95,
       0,    47,     0,     0,   101,    42,    64,    64,    51,    38,
      21,    59,    58,     0,     0,    14,    14,    45,    46
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -92,    -6,   -92,   -92,   -92,   -92,   137,   -92,   -91,    -2,
     -92,   -92,   -92,   -77,   -92,   -92,   -92,   -92,    87,   129,
     -92,   133,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,
     -92,   -92,   -92,   -28,    67,    69,    66,   -69,   -38,   -44,
     -92
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    50,    51,     3,     8,    11,    12,    52,     4,
      53,    54,    55,    81,   132,   133,    21,    22,    29,    30,
      70,    23,    13,    14,    56,   160,    57,    58,   104,   105,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
     143
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       5,   122,   124,    93,    94,    95,    16,   138,    76,   107,
      77,   110,    18,    82,   135,   147,   141,     1,    92,   101,
     102,     6,    96,   107,   107,    25,    26,    27,    28,   112,
     113,   142,   103,   121,   114,   115,   116,   107,    34,    35,
     107,   151,   152,     7,   111,   119,   120,   107,   172,   173,
     123,   125,   137,   161,   106,    99,   100,   127,   128,   129,
     130,   131,   134,   136,    42,    43,   162,    44,    75,   165,
     155,   156,   157,    46,   153,   154,   167,     9,    47,    48,
      10,   178,    15,    49,    17,   183,   184,    25,    26,    27,
     117,    20,    31,    24,    32,    72,    97,    33,    73,    34,
      35,    74,   145,   146,    78,    79,    98,   107,    90,   108,
     126,   109,   139,   158,    36,   140,    37,    38,   144,   163,
      39,    34,    35,    40,    41,    42,    43,   159,    44,    45,
     -37,   179,   164,   166,    46,   174,   168,   176,   170,    47,
      48,   169,   180,   171,    49,   175,   177,    42,    43,    80,
      44,    75,   181,    19,    80,   182,    46,   185,   186,   118,
      69,    47,    48,    83,    84,    71,    49,     0,     0,    85,
      86,    87,    88,    89,   148,   150,     0,   149,     0,     0,
       0,     0,     0,   187,   188,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    90,     0,    91
};

static const yytype_int16 yycheck[] =
{
       2,    78,    79,    47,    48,    49,    12,    98,    36,    12,
      38,    11,    14,    41,    91,   106,    31,     4,    46,    24,
      25,     0,    50,    12,    12,     5,     6,     7,     8,    45,
      46,    46,    37,    36,    47,    48,    49,    12,     5,     6,
      12,   110,   111,    27,    44,    73,    74,    12,   139,   140,
      78,    79,    41,    41,    60,    57,    58,    85,    86,    87,
      88,    89,    90,    91,    31,    32,    41,    34,    35,    41,
     114,   115,   116,    40,   112,   113,    41,    35,    45,    46,
      28,   158,    35,    50,    40,   176,   177,     5,     6,     7,
       8,    35,    41,    36,    39,    35,    37,     3,    40,     5,
       6,    40,   104,   105,    40,    40,    36,    12,    40,    13,
      33,    14,    36,    42,    20,    36,    22,    23,    43,   121,
      26,     5,     6,    29,    30,    31,    32,    42,    34,    35,
      36,   159,    41,    41,    40,    31,    38,    36,    39,    45,
      46,    41,   170,    37,    50,    43,    36,    31,    32,    38,
      34,    35,    37,    16,    38,    37,    40,    37,    37,    72,
      31,    45,    46,     9,    10,    32,    50,    -1,    -1,    15,
      16,    17,    18,    19,   107,   109,    -1,   108,    -1,    -1,
      -1,    -1,    -1,   185,   186,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    -1,    42
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    52,    55,    60,    60,     0,    27,    56,    35,
      28,    57,    58,    73,    74,    35,    52,    40,    60,    57,
      35,    67,    68,    72,    36,     5,     6,     7,     8,    69,
      70,    41,    39,     3,     5,     6,    20,    22,    23,    26,
      29,    30,    31,    32,    34,    35,    40,    45,    46,    50,
      53,    54,    59,    61,    62,    63,    75,    77,    78,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    70,
      71,    72,    35,    40,    40,    35,    84,    84,    40,    40,
      38,    64,    84,     9,    10,    15,    16,    17,    18,    19,
      40,    42,    84,    90,    90,    90,    84,    37,    36,    60,
      60,    24,    25,    37,    79,    80,    52,    12,    13,    14,
      11,    44,    45,    46,    47,    48,    49,     8,    69,    84,
      84,    36,    64,    84,    64,    84,    33,    84,    84,    84,
      84,    84,    65,    66,    84,    64,    84,    41,    59,    36,
      36,    31,    46,    91,    43,    60,    60,    59,    85,    86,
      87,    88,    88,    89,    89,    90,    90,    90,    42,    42,
      76,    41,    41,    60,    41,    41,    41,    41,    38,    41,
      39,    37,    59,    59,    31,    43,    36,    36,    64,    84,
      84,    37,    37,    59,    59,    37,    37,    60,    60
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    54,    55,    56,    57,    57,    58,
      58,    59,    59,    60,    60,    61,    62,    63,    64,    65,
      65,    66,    66,    67,    67,    68,    68,    69,    69,    69,
      70,    70,    71,    71,    72,    73,    74,    75,    76,    76,
      77,    78,    79,    80,    81,    81,    81,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    83,    83,    83,    83,    83,
      83,    83,    83,    84,    84,    85,    85,    86,    86,    87,
      87,    87,    88,    88,    88,    89,    89,    89,    89,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      91,    91
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     2,     3,     1,     5,
       0,     3,     1,     2,     0,     1,     1,     1,     3,     1,
       0,     3,     1,     1,     0,     3,     1,     1,     1,     1,
       1,     1,     1,     0,     2,     2,     5,     0,     2,     0,
       2,     2,     3,     2,     4,     7,     7,     4,     1,     4,
       3,     5,     2,     2,     4,     4,     4,     4,     5,     5,
       2,     2,     2,     1,     0,     3,     3,     3,     3,     3,
       3,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     1,     2,
       2,     2,     3,     4,     4,     4,     1,     1,     1,     1,
       1,     2
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
#line 97 "compiler_hw3.y" /* yacc.c:1646  */
    {
        reduce_line++;
    }
#line 1468 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 102 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.label)=label_cnt++;
        LABELGEN((yyval.label));
    }
#line 1477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 107 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.type)=myload((yyvsp[0].name));
    }
#line 1485 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 112 "compiler_hw3.y" /* yacc.c:1646  */
    {

    }
#line 1493 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 117 "compiler_hw3.y" /* yacc.c:1646  */
    {
        code_begin();
    }
#line 1501 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 127 "compiler_hw3.y" /* yacc.c:1646  */
    {
        dump_symbol();
        method_end();
    }
#line 1510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 142 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.type)=type_i;
        CODEGEN("ldc %d\n",(yyvsp[0].int_lit));
    }
#line 1519 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 148 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.type)=type_f;
        CODEGEN("ldc %f\n",(yyvsp[0].float_lit));
    }
#line 1528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 154 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.type)=type_b;
        if((yyvsp[0].bool_lit)){
            CODEGEN("iconst_1\n");
        }else{
            CODEGEN("iconst_0\n");
        }
    }
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 164 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.type)=type_s;
        CODEGEN("ldc \"%s\"\n",(yyvsp[-1].str_lit));
    }
#line 1550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 178 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.func_sig)=(yyvsp[0].func_sig);
    }
#line 1558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 181 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.func_sig)=strdup("");
    }
#line 1566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 186 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.func_sig)=free_cat((yyvsp[-2].func_sig),(yyvsp[0].func_sig));
    }
#line 1574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 189 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.func_sig)=(yyvsp[0].func_sig);
    }
#line 1582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 194 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.type)=type_i;
    }
#line 1590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 197 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.type)=type_f;
    }
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 200 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.type)=type_b;
    }
#line 1606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 205 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.type)=(yyvsp[0].type);
    }
#line 1614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 208 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.type)=type_s;
    }
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 213 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.type)=(yyvsp[0].type);
    }
#line 1630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 216 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.type)=type_void;
    }
#line 1638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 220 "compiler_hw3.y" /* yacc.c:1646  */
    {
        reduce_line++;
        insert_symbol((yyvsp[-1].name),(yyvsp[0].type));
        reduce_line--;
        (yyval.func_sig)=cdup(get_type((yyvsp[0].type)));
    }
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 228 "compiler_hw3.y" /* yacc.c:1646  */
    {
        create_symbol();
        (yyval.name)=(yyvsp[0].name);
    }
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 234 "compiler_hw3.y" /* yacc.c:1646  */
    {
        if(strcmp((yyvsp[-4].name),"main")==0&&strcmp((yyvsp[-2].func_sig),"")==0&&(yyvsp[0].type)==type_void){
            main_method_begin((yyvsp[-4].name),(yyvsp[-2].func_sig),(yyvsp[0].type));
        }else{
            method_begin((yyvsp[-4].name),(yyvsp[-2].func_sig),(yyvsp[0].type));
        }
    }
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 243 "compiler_hw3.y" /* yacc.c:1646  */
    {
        create_symbol();
    }
#line 1678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 248 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.type)=(yyvsp[0].type);
    }
#line 1686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 251 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.type)=type_void;
    }
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 256 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.for_labels).again=(yyvsp[-1].label);
        (yyval.for_labels).out=label_cnt++;
        CODEGEN("ifeq Label%d\n",(yyval.for_labels).out);
        check_bool_condition((yyvsp[0].type));
        create_symbol();
    }
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 265 "compiler_hw3.y" /* yacc.c:1646  */
    {
        check_bool_condition((yyvsp[0].type));
        (yyval.label)=label_cnt++;
        CODEGEN("ifeq Label%d\n",(yyval.label));
        create_symbol();
    }
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 273 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.case_data).key=(yyvsp[-1].int_lit);
        (yyval.case_data).label=label_cnt++;
        (yyval.case_data).isdefault=false;
        (yyval.case_data).next=NULL;
        LABELGEN((yyval.case_data).label);
        create_symbol();
    }
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 283 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.case_data).label=label_cnt++;
        (yyval.case_data).isdefault=true;
        (yyval.case_data).next=NULL;
        LABELGEN((yyval.case_data).label);
        create_symbol();
    }
#line 1742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 292 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.switch_data).enter_label=label_cnt++;
        (yyval.switch_data).exit_label=label_cnt++;
        (yyval.switch_data).first=NULL;
        CODEGEN("goto Label%d\n",(yyval.switch_data).enter_label);
    }
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 298 "compiler_hw3.y" /* yacc.c:1646  */
    {
        struct case_node* newnode=casedup((yyvsp[-5].case_data));
        newnode->next=(yyval.switch_data).first;
        (yyval.switch_data).first=newnode;
        CODEGEN("goto Label%d\n",(yyvsp[-6].switch_data).exit_label);
        dump_symbol();
    }
#line 1765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 305 "compiler_hw3.y" /* yacc.c:1646  */
    {
        struct case_node* newnode=casedup((yyvsp[-5].case_data));
        newnode->next=(yyval.switch_data).first;
        (yyval.switch_data).first=newnode;
        CODEGEN("goto Label%d\n",(yyvsp[-6].switch_data).exit_label);
        dump_symbol();
    }
#line 1777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 314 "compiler_hw3.y" /* yacc.c:1646  */
    {
        dump_symbol();
    }
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 318 "compiler_hw3.y" /* yacc.c:1646  */
    {
        insert_symbol((yyvsp[-2].name),(yyvsp[-1].type));
        if((yyvsp[0].type)!=type_void){
            check_match("ASSIGN",(yyvsp[-1].type),(yyvsp[0].type));
            mystore((yyvsp[-2].name));
        }
    }
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 325 "compiler_hw3.y" /* yacc.c:1646  */
    {
        insert_symbol((yyvsp[-1].name),type_s);
        CODEGEN("ldc \"\"\n");
        mystore((yyvsp[-1].name));
    }
#line 1807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 330 "compiler_hw3.y" /* yacc.c:1646  */
    {
        insert_symbol((yyvsp[-3].name),type_s);
        mystore((yyvsp[-3].name));
    }
#line 1816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 334 "compiler_hw3.y" /* yacc.c:1646  */
    {
        unsigned char tp=myload((yyvsp[-1].name));
        check_type_define("INC",tp,type_i|type_f);
        if(tp==type_f){
            CODEGEN("ldc 1.0\n");
            CODEGEN("fadd\n");
        }else{
            CODEGEN("iconst_1\n");
            CODEGEN("iadd\n");
        } 
        mystore((yyvsp[-1].name));
    }
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 346 "compiler_hw3.y" /* yacc.c:1646  */
    {
        unsigned char tp=myload((yyvsp[-1].name));
        check_type_define("DEC",tp,type_i|type_f);
        if(tp==type_f){
            CODEGEN("ldc 1.0\n");
            CODEGEN("fsub\n");
        }else{
            CODEGEN("iconst_1\n");
            CODEGEN("isub\n");
        } 
        mystore((yyvsp[-1].name));
    }
#line 1850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 358 "compiler_hw3.y" /* yacc.c:1646  */
    {
        println_post((yyvsp[-1].type));
    }
#line 1858 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 361 "compiler_hw3.y" /* yacc.c:1646  */
    {
        println_post((yyvsp[-1].type));
    }
#line 1866 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 364 "compiler_hw3.y" /* yacc.c:1646  */
    {
        print_post((yyvsp[-1].type));
    }
#line 1874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 367 "compiler_hw3.y" /* yacc.c:1646  */
    {
        print_post((yyvsp[-1].type));
    }
#line 1882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 370 "compiler_hw3.y" /* yacc.c:1646  */
    {
        LABELGEN((yyvsp[-4].label));
        dump_symbol();
    }
#line 1891 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 374 "compiler_hw3.y" /* yacc.c:1646  */
    {
        CODEGEN("goto Label%d\n",(yyvsp[-4].for_labels).again);
        LABELGEN((yyvsp[-4].for_labels).out);
        dump_symbol();
    }
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 379 "compiler_hw3.y" /* yacc.c:1646  */
    {
        my_lookupswitch((yyvsp[-1].switch_data));
    }
#line 1909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 382 "compiler_hw3.y" /* yacc.c:1646  */
    {
        switch((yyvsp[0].type)){
        case type_i:
            CODEGEN("ireturn\n");
            break;
        case type_f:
            CODEGEN("freturn\n");
            break;
        case type_b:
            CODEGEN("breturn\n");
            break;
        }
        
    }
#line 1928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 396 "compiler_hw3.y" /* yacc.c:1646  */
    {
        CODEGEN("sreturn\n");
    }
#line 1936 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 399 "compiler_hw3.y" /* yacc.c:1646  */
    {
        CODEGEN("return\n");
    }
#line 1944 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 405 "compiler_hw3.y" /* yacc.c:1646  */
    {
        unsigned char tp=ident_type((yyvsp[-2].name));
        check_match("ASSIGN",tp,(yyvsp[0].type));
        mystore((yyvsp[-2].name));
    }
#line 1954 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 410 "compiler_hw3.y" /* yacc.c:1646  */
    {
        unsigned char tp=myload((yyvsp[-2].name));
        check_match("ADD",tp,(yyvsp[0].type));
        CODEGEN("swap\n");
        if(tp==type_f){
            CODEGEN("fadd\n");
        }else{
            CODEGEN("iadd\n");
        } 
        mystore((yyvsp[-2].name));
    }
#line 1970 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 421 "compiler_hw3.y" /* yacc.c:1646  */
    {
        unsigned char tp=myload((yyvsp[-2].name));
        check_match("SUB",tp,(yyvsp[0].type));
        CODEGEN("swap\n");
        if(tp==type_f){
            CODEGEN("fsub\n");
        }else{
            CODEGEN("isub\n");
        } 
        mystore((yyvsp[-2].name));
    }
#line 1986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 432 "compiler_hw3.y" /* yacc.c:1646  */
    {
        unsigned char tp=myload((yyvsp[-2].name));
        check_match("MUL",tp,(yyvsp[0].type));
        CODEGEN("swap\n");
        if(tp==type_f){
            CODEGEN("fmul\n");
        }else{
            CODEGEN("imul\n");
        } 
        mystore((yyvsp[-2].name));
    }
#line 2002 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 443 "compiler_hw3.y" /* yacc.c:1646  */
    {
        unsigned char tp=myload((yyvsp[-2].name));
        check_match("QUO",tp,(yyvsp[0].type));
        CODEGEN("swap\n");
        if(tp==type_f){
            CODEGEN("fdiv\n");
        }else{
            CODEGEN("idiv\n");
        } 
        mystore((yyvsp[-2].name));
    }
#line 2018 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 454 "compiler_hw3.y" /* yacc.c:1646  */
    {
        unsigned char tp=myload((yyvsp[-2].name));
        check_type_define("REM",tp,type_i);
        check_type_define("REM",(yyvsp[0].type),type_i);
        CODEGEN("swap\n");
        CODEGEN("irem\n");
        mystore((yyvsp[-2].name));
    }
#line 2031 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 462 "compiler_hw3.y" /* yacc.c:1646  */
    {
        unsigned char tp=ident_type((yyvsp[-2].name));
        check_match("ASSIGN",tp,(yyvsp[0].type));
        mystore((yyvsp[-2].name));
    }
#line 2041 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 470 "compiler_hw3.y" /* yacc.c:1646  */
    {
        check_type_define("LOR",(yyvsp[-2].type),type_b);
        check_type_define("LOR",(yyvsp[0].type),type_b);
        (yyval.type)=type_b;
        CODEGEN("ior\n");
    }
#line 2052 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 479 "compiler_hw3.y" /* yacc.c:1646  */
    {
        check_type_define("LAND",(yyvsp[-2].type),type_b);
        check_type_define("LAND",(yyvsp[0].type),type_b);
        (yyval.type)=type_b;
        CODEGEN("iand\n");
    }
#line 2063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 488 "compiler_hw3.y" /* yacc.c:1646  */
    {
        check_match("EQL",(yyvsp[-2].type),(yyvsp[0].type));
        (yyval.type)=type_b;
        if((yyvsp[-2].type)==type_f){
            my_fcmp("eq");
        }else{
            my_icmp("eq");
        }
    }
#line 2077 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 500 "compiler_hw3.y" /* yacc.c:1646  */
    {
        check_match("GTR",(yyvsp[-2].type),(yyvsp[0].type));
        (yyval.type)=type_b;
        if((yyvsp[-2].type)==type_f){
            my_fcmp("gt");
        }else{
            my_icmp("gt");
        }
    }
#line 2091 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 509 "compiler_hw3.y" /* yacc.c:1646  */
    {
        check_match("GEQ",(yyvsp[-2].type),(yyvsp[0].type));
        (yyval.type)=type_b;
        if((yyvsp[-2].type)==type_f){
            my_fcmp("ge");
        }else{
            my_icmp("ge");
        }
    }
#line 2105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 521 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.type)=check_match("ADD",(yyvsp[-2].type),(yyvsp[0].type));
        if((yyvsp[-2].type)==type_f){
            CODEGEN("fadd\n");
        }else{
            CODEGEN("iadd\n");
        }
    }
#line 2118 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 529 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.type)=check_match("SUB",(yyvsp[-2].type),(yyvsp[0].type));
        if((yyvsp[-2].type)==type_f){
            CODEGEN("fsub\n");
        }else{
            CODEGEN("isub\n");
        }
    }
#line 2131 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 540 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.type)=check_match("MUL",(yyvsp[-2].type),(yyvsp[0].type));
        if((yyvsp[-2].type)==type_f){
            CODEGEN("fmul\n");
        }else{
            CODEGEN("imul\n");
        }
    }
#line 2144 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 548 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.type)=check_match("QUO",(yyvsp[-2].type),(yyvsp[0].type));
        if((yyvsp[-2].type)==type_f){
            CODEGEN("fdiv\n");
        }else{
            CODEGEN("idiv\n");
        }
    }
#line 2157 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 556 "compiler_hw3.y" /* yacc.c:1646  */
    {
        check_type_define("REM",(yyvsp[-2].type),type_i);
        check_type_define("REM",(yyvsp[0].type),type_i);
        (yyval.type)=type_i;
        CODEGEN("irem\n");
    }
#line 2168 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 565 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.type)=check_type_define("POS",(yyvsp[0].type),type_i|type_f)?(yyvsp[0].type):type_error;
    }
#line 2176 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 568 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.type)=check_type_define("NEG",(yyvsp[0].type),type_i|type_f)?(yyvsp[0].type):type_error;
        if((yyvsp[0].type)==type_f){
            CODEGEN("fneg\n");
        }else{
            CODEGEN("ineg\n");
        }
    }
#line 2189 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 576 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.type)=check_type_define("NOT",(yyvsp[0].type),type_b)?type_b:type_error;
        CODEGEN("iconst_1\n");
        CODEGEN("ixor\n");
    }
#line 2199 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 581 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.type)=(yyvsp[-1].type);
    }
#line 2207 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 584 "compiler_hw3.y" /* yacc.c:1646  */
    {
        check_type_define("i2f",(yyvsp[-1].type),type_i);
        CODEGEN("i2f\n");
        (yyval.type)=type_f;
    }
#line 2217 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 589 "compiler_hw3.y" /* yacc.c:1646  */
    {
        check_type_define("f2i",(yyvsp[-1].type),type_f);
        CODEGEN("f2i\n");
        (yyval.type)=type_i;
    }
#line 2227 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 594 "compiler_hw3.y" /* yacc.c:1646  */
    {
        int i=func_find((yyvsp[-3].name));
        if(i!=-1){
            (yyval.type)=func_table[i].type;
            CODEGEN("invokestatic Main/%s(%s)%c\n",(yyvsp[-3].name),func_table[i].func_sig,get_type((yyval.type)));
        }else{
            printf("error:%d: undefined: %s\n",reduce_line,(yyvsp[-3].name));
            g_has_error=true;
        }
    }
#line 2242 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 604 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.type)=(yyvsp[0].type);
    }
#line 2250 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 607 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.type)=(yyvsp[0].type);
    }
#line 2258 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 610 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.type)=(yyvsp[0].type);
    }
#line 2266 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 613 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.type)=(yyvsp[0].type);
    }
#line 2274 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 618 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.int_lit)=(yyvsp[0].int_lit);
    }
#line 2282 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 621 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.int_lit)=-(yyvsp[0].int_lit);
    }
#line 2290 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2294 "y.tab.c" /* yacc.c:1646  */
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
#line 626 "compiler_hw3.y" /* yacc.c:1906  */


/* C code section */
int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }
    if (!yyin) {
        printf("file `%s` doesn't exists or cannot be opened\n", argv[1]);
        exit(1);
    }

    /* Codegen output init */
    char *bytecode_filename = "hw3.j";
    fout = fopen(bytecode_filename, "w");
    

    /* Symbol table init */
    // Add your code

    yylineno = 0;
    yyparse();

    /* Symbol table dump */
    // Add your code

	printf("Total lines: %d\n", reduce_line-1);
    fclose(fout);
    fclose(yyin);

    if (g_has_error) {
        remove(bytecode_filename);
    }
    yylex_destroy();
    return 0;
}
