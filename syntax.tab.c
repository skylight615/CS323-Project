/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "syntax.y"

    #include "lex.yy.c"
    void yyerror(const char*);
    struct Node *cldArray[10];
    int yydebug = 1;
    int isCorrect=1;
    int instruct = 0;

#line 79 "syntax.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_SYNTAX_TAB_H_INCLUDED
# define YY_YY_SYNTAX_TAB_H_INCLUDED
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
    INT = 258,
    FLOAT = 259,
    CHAR = 260,
    TYPE = 261,
    STRUCT = 262,
    IF = 263,
    ELSE = 264,
    WHILE = 265,
    RETURN = 266,
    ID = 267,
    DOT = 268,
    SEMI = 269,
    COMMA = 270,
    INCLUDE = 271,
    FILEIN = 272,
    DEFINEIN = 273,
    ASSIGN = 274,
    LT = 275,
    LE = 276,
    GT = 277,
    GE = 278,
    NE = 279,
    EQ = 280,
    PLUS = 281,
    MINUS = 282,
    MUL = 283,
    DIV = 284,
    AND = 285,
    OR = 286,
    NOT = 287,
    LP = 288,
    RP = 289,
    LB = 290,
    RB = 291,
    ERROR = 292,
    NEG = 293,
    LC = 294,
    RC = 295,
    LOWER_ELSE = 296,
    REDUCE = 297,
    SHIFT = 298
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef struct Node * YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SYNTAX_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  19
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   375

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  162

#define YYUNDEFTOK  2
#define YYMAXUTOK   298


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    34,    34,    35,    38,    39,    41,    42,    43,    45,
      46,    47,    48,    49,    51,    53,    55,    57,    61,    62,
      63,    65,    66,    68,    69,    70,    71,    74,    75,    78,
      79,    81,    82,    84,    87,    88,    89,    91,    92,    93,
      95,    98,    99,   101,   104,   106,   107,   109,   110,   111,
     112,   114,   115,   118,   119,   120,   123,   126,   127,   129,
     130,   133,   134,   136,   137,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   157,   158,   159,   160,   162,   163,   164,   165,   166,
     167,   168,   169,   171,   172
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "CHAR", "TYPE", "STRUCT",
  "IF", "ELSE", "WHILE", "RETURN", "ID", "DOT", "SEMI", "COMMA", "INCLUDE",
  "FILEIN", "DEFINEIN", "ASSIGN", "LT", "LE", "GT", "GE", "NE", "EQ",
  "PLUS", "MINUS", "MUL", "DIV", "AND", "OR", "NOT", "LP", "RP", "LB",
  "RB", "ERROR", "NEG", "LC", "RC", "LOWER_ELSE", "REDUCE", "SHIFT",
  "$accept", "Program", "HeadList", "Head", "TransPara", "IdList",
  "ExtDefList", "ExtDef", "ExtDecList", "Specifier", "StructSpecifier",
  "VarDec", "FunDec", "VarList", "ParamDec", "CompSt", "StmtList", "Stmt",
  "DefList", "Def", "DecList", "Dec", "Exp", "Args", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298
};
# endif

#define YYPACT_NINF (-52)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     357,   -52,    -1,    58,     9,    64,    75,    56,   -52,    75,
      26,   -52,    21,   -52,   -52,   -52,   -52,   139,    81,   -52,
     -52,   -52,   -52,   -52,    38,   -52,   -52,    69,    52,    39,
      75,   -52,   -52,   -52,   -52,    76,   -52,   -52,   -52,   -52,
      57,    81,    81,    81,   -52,   288,    28,   -52,    -7,    86,
      75,   -52,    -7,     2,    75,    85,    31,    65,    66,    66,
     103,    84,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,   -52,   -52,    -7,
      32,    91,   -52,   -52,    71,     4,   -15,     5,    94,   -52,
     -52,   -52,    76,   -52,   -52,   -52,   250,    60,   -52,   -52,
     -52,   288,   330,   330,   330,   330,   330,   330,   170,   170,
      66,    66,   325,   307,   269,   288,    77,   -52,   -52,    75,
     -52,    78,   106,    81,   -52,    79,     4,   134,    81,   -52,
     -52,    -7,   -52,    81,   -52,   -52,   -52,   -52,    81,    81,
     165,   -52,   -52,   -52,   -52,   288,   -52,   -52,   196,   227,
     -52,   -52,     4,     4,     4,     4,   -52,   108,   -52,   -52,
       4,   -52
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,    29,     0,     0,     0,     0,    21,     4,     2,    21,
       0,    30,    33,     8,     6,     7,    14,     0,     0,     1,
       3,     5,    22,    26,    34,    24,    36,     0,    27,     0,
      57,     9,    10,    11,    12,    20,    13,    89,    90,    91,
      88,     0,     0,     0,    92,    15,     0,    23,     0,     0,
      57,    25,     0,     0,    57,    18,     0,     0,    81,    82,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    39,    38,     0,
       0,    42,    34,    28,     0,    45,    63,     0,    61,    32,
      31,    58,    20,    17,    16,    85,    94,     0,    80,    79,
      87,    65,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    66,    67,     0,    68,    43,    40,    37,     0,
      35,     0,     0,     0,    48,     0,    45,     0,     0,    60,
      59,     0,    19,     0,    84,    83,    86,    41,     0,     0,
       0,    44,    46,    56,    47,    64,    62,    93,     0,     0,
      50,    49,     0,     0,     0,     0,    52,    51,    55,    54,
       0,    53
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -52,   -52,   129,   -52,   -52,    49,    67,   -52,    97,   -28,
     -52,   -51,   -52,    27,   -52,   120,    24,    82,   -37,   -52,
      36,   -52,   -18,    19
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,     7,    18,    56,     8,     9,    27,    10,
      11,    28,    29,    80,    81,   124,   125,   126,    53,    54,
      87,    88,   127,    97
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      45,    86,    52,    89,   128,    82,   129,    37,    38,    39,
      16,    12,   121,    85,   122,   123,    40,    91,    79,   130,
      49,    17,    52,    58,    59,    60,    52,    23,   116,    77,
      26,    41,    93,   117,     1,     2,    42,    43,    24,    96,
      25,    44,    90,    50,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,    13,
      30,   134,    78,    26,    19,    94,   118,    48,    37,    38,
      39,    46,     3,    20,     4,    14,    22,    40,    50,    61,
      86,     1,     2,    47,    37,    38,    39,    49,    55,    84,
      57,    79,    41,    40,   135,    15,   100,    42,    43,    95,
      92,    75,    44,    76,    98,   140,   119,   120,    41,   131,
     145,   138,    49,    42,    43,    96,    61,   160,    44,   141,
     148,   149,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,   143,    21,    99,    75,   139,
      76,   132,    31,    32,    33,    83,   137,    61,   144,    51,
     142,    34,   147,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,   150,   146,     0,    75,
       0,    76,    35,     0,     0,     0,    36,     0,    61,   151,
       0,     0,     0,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,   152,    71,    72,
      75,     0,    76,     0,     0,    75,     0,    76,     0,    61,
       0,     0,     0,     0,     0,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,   154,     0,
     153,    75,     0,    76,   156,   157,   158,   159,     0,     0,
      61,     0,   161,     0,     0,     0,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,     0,
       0,   155,    75,    61,    76,   133,     0,     0,     0,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    61,     0,     0,    75,     0,    76,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    61,     0,     0,    75,   136,    76,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      61,     0,     0,    75,     0,    76,     0,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    61,     0,
       0,     0,    75,    61,    76,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,     0,    69,    70,    71,    72,
      75,     0,    76,     1,     2,    75,     0,    76,     0,     0,
       0,     0,     0,     3,     0,     4
};

static const yytype_int16 yycheck[] =
{
      18,    52,    30,     1,    19,    12,     1,     3,     4,     5,
       1,    12,     8,    50,    10,    11,    12,    54,    46,    14,
      35,    12,    50,    41,    42,    43,    54,     1,    79,     1,
      37,    27,     1,     1,     6,     7,    32,    33,    12,    57,
      14,    37,    40,    39,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,     1,
      39,     1,    34,    37,     0,    34,    34,    15,     3,     4,
       5,    33,    16,     6,    18,    17,     9,    12,    39,    13,
     131,     6,     7,    14,     3,     4,     5,    35,    12,     3,
      33,   119,    27,    12,    34,    37,    12,    32,    33,    34,
      15,    35,    37,    37,     1,   123,    15,    36,    27,    15,
     128,    33,    35,    32,    33,   133,    13,     9,    37,    40,
     138,   139,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,     1,     7,    34,    35,    33,
      37,    92,     3,     4,     5,    48,   119,    13,    14,    29,
     126,    12,   133,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,     1,   131,    -1,    35,
      -1,    37,    33,    -1,    -1,    -1,    37,    -1,    13,    14,
      -1,    -1,    -1,    13,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,     1,    28,    29,
      35,    -1,    37,    -1,    -1,    35,    -1,    37,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,     1,    -1,
      34,    35,    -1,    37,   152,   153,   154,   155,    -1,    -1,
      13,    -1,   160,    -1,    -1,    -1,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    -1,
      -1,    34,    35,    13,    37,    15,    -1,    -1,    -1,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    13,    -1,    -1,    35,    -1,    37,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    13,    -1,    -1,    35,    36,    37,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      13,    -1,    -1,    35,    -1,    37,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    13,    -1,
      -1,    -1,    35,    13,    37,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    26,    27,    28,    29,
      35,    -1,    37,     6,     7,    35,    -1,    37,    -1,    -1,
      -1,    -1,    -1,    16,    -1,    18
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,     7,    16,    18,    45,    46,    47,    50,    51,
      53,    54,    12,     1,    17,    37,     1,    12,    48,     0,
      50,    46,    50,     1,    12,    14,    37,    52,    55,    56,
      39,     3,     4,     5,    12,    33,    37,     3,     4,     5,
      12,    27,    32,    33,    37,    66,    33,    14,    15,    35,
      39,    59,    53,    62,    63,    12,    49,    33,    66,    66,
      66,    13,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    35,    37,     1,    34,    53,
      57,    58,    12,    52,     3,    62,    55,    64,    65,     1,
      40,    62,    15,     1,    34,    34,    66,    67,     1,    34,
      12,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    55,     1,    34,    15,
      36,     8,    10,    11,    59,    60,    61,    66,    19,     1,
      14,    15,    49,    15,     1,    34,    36,    57,    33,    33,
      66,    40,    60,     1,    14,    66,    64,    67,    66,    66,
       1,    14,     1,    34,     1,    34,    61,    61,    61,    61,
       9,    61
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    45,    46,    46,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    48,    48,    49,    49,
      49,    50,    50,    51,    51,    51,    51,    52,    52,    53,
      53,    54,    54,    54,    55,    55,    55,    56,    56,    56,
      56,    57,    57,    58,    59,    60,    60,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    62,    62,    63,
      63,    64,    64,    65,    65,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    67,    67
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     2,     2,     2,     3,
       3,     3,     3,     3,     2,     3,     4,     4,     1,     3,
       0,     0,     2,     3,     2,     3,     2,     1,     3,     1,
       1,     5,     5,     2,     1,     4,     1,     4,     3,     3,
       4,     3,     1,     2,     4,     0,     2,     2,     1,     3,
       3,     5,     5,     7,     5,     5,     2,     0,     2,     3,
       3,     1,     3,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     4,     4,     3,     4,     3,     1,     1,
       1,     1,     1,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
#line 34 "syntax.y"
                    {cldArray[0] = yyvsp[0]; yyval=createNode("Program", 1, cldArray); if(isCorrect==1)dfs(yyval,0);}
#line 1500 "syntax.tab.c"
    break;

  case 3:
#line 35 "syntax.y"
                          {cldArray[0] = yyvsp[-1]; cldArray[1] = yyvsp[0];yyval=createNode("Program", 2, cldArray); 
        if(isCorrect==1)dfs(yyval,0);}
#line 1507 "syntax.tab.c"
    break;

  case 4:
#line 38 "syntax.y"
                 {yyval = createNode("Empty", 0, cldArray);}
#line 1513 "syntax.tab.c"
    break;

  case 5:
#line 39 "syntax.y"
                    {cldArray[0] = yyvsp[-1]; cldArray[1] = yyvsp[0]; yyval=createNode("HeadList", 2, cldArray);}
#line 1519 "syntax.tab.c"
    break;

  case 6:
#line 41 "syntax.y"
                     {cldArray[0] = yyvsp[-1]; cldArray[1] = yyvsp[0]; yyval=createNode("Head", 2, cldArray);}
#line 1525 "syntax.tab.c"
    break;

  case 7:
#line 42 "syntax.y"
                    {cldArray[0] = yyvsp[-1]; cldArray[1] = yyvsp[0]; yyval=createNode("Head", 2, cldArray); isCorrect=0;}
#line 1531 "syntax.tab.c"
    break;

  case 8:
#line 43 "syntax.y"
                    {cldArray[0] = yyvsp[-1]; cldArray[1] = yyvsp[0]; yyval=createNode("Head", 2, cldArray);
        isCorrect=0;char* text = "Not a head file";printf("%d: %s\n",yyvsp[0]->line,text);}
#line 1538 "syntax.tab.c"
    break;

  case 9:
#line 45 "syntax.y"
                      {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Head", 3, cldArray);}
#line 1544 "syntax.tab.c"
    break;

  case 10:
#line 46 "syntax.y"
                        {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Head", 3, cldArray);}
#line 1550 "syntax.tab.c"
    break;

  case 11:
#line 47 "syntax.y"
                       {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Head", 3, cldArray);}
#line 1556 "syntax.tab.c"
    break;

  case 12:
#line 48 "syntax.y"
                     {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Head", 3, cldArray);}
#line 1562 "syntax.tab.c"
    break;

  case 13:
#line 49 "syntax.y"
                        {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Head", 3, cldArray);
         isCorrect=0;}
#line 1569 "syntax.tab.c"
    break;

  case 14:
#line 51 "syntax.y"
                     {cldArray[0] = yyvsp[-1]; cldArray[1] = yyvsp[0]; yyval=createNode("Head", 2, cldArray);
        isCorrect=0;char* text = "Not a head macro";printf("%d: %s\n",yyvsp[-1]->line,text);}
#line 1576 "syntax.tab.c"
    break;

  case 15:
#line 53 "syntax.y"
                             {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Head", 3, cldArray);}
#line 1582 "syntax.tab.c"
    break;

  case 16:
#line 55 "syntax.y"
                           {cldArray[0] = yyvsp[-3]; cldArray[1] = yyvsp[-2]; cldArray[2]=yyvsp[-1];cldArray[3]=yyvsp[0];
     yyval=createNode("TransPara", 4, cldArray);}
#line 1589 "syntax.tab.c"
    break;

  case 17:
#line 57 "syntax.y"
                         {cldArray[0] = yyvsp[-3]; cldArray[1] = yyvsp[-2]; cldArray[2]=yyvsp[-1];cldArray[3]=yyvsp[0];
         yyval=createNode("TransPara", 4, cldArray);
        isCorrect=0;char* text = "Missing closing parenthesis ')'";printf("%d: %s\n",yyvsp[-2]->line,text);}
#line 1597 "syntax.tab.c"
    break;

  case 18:
#line 61 "syntax.y"
           {cldArray[0] = yyvsp[0]; yyval=createNode("IdList", 1, cldArray);}
#line 1603 "syntax.tab.c"
    break;

  case 19:
#line 62 "syntax.y"
                      {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Head", 3, cldArray);}
#line 1609 "syntax.tab.c"
    break;

  case 20:
#line 63 "syntax.y"
             {yyval = createNode("Empty", 0, cldArray);}
#line 1615 "syntax.tab.c"
    break;

  case 21:
#line 65 "syntax.y"
                   {yyval = createNode("Empty", 0, cldArray);}
#line 1621 "syntax.tab.c"
    break;

  case 22:
#line 66 "syntax.y"
                        {cldArray[0] = yyvsp[-1]; cldArray[1] = yyvsp[0]; yyval=createNode("ExtDefList", 2, cldArray);}
#line 1627 "syntax.tab.c"
    break;

  case 23:
#line 68 "syntax.y"
                                  {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("ExtDef", 3, cldArray);}
#line 1633 "syntax.tab.c"
    break;

  case 24:
#line 69 "syntax.y"
                     {cldArray[0] = yyvsp[-1]; cldArray[1] = yyvsp[0]; yyval=createNode("ExtDef", 2, cldArray);}
#line 1639 "syntax.tab.c"
    break;

  case 25:
#line 70 "syntax.y"
                              {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("ExtDef", 3, cldArray);}
#line 1645 "syntax.tab.c"
    break;

  case 26:
#line 71 "syntax.y"
                      {cldArray[0] = yyvsp[-1]; cldArray[1] = yyvsp[0]; yyval=createNode("ExtDef", 2, cldArray);
        isCorrect=0;char* text = "Missing semicolon ';'";printf("%d: %s\n",yyvsp[0]->line,text);}
#line 1652 "syntax.tab.c"
    break;

  case 27:
#line 74 "syntax.y"
                   {cldArray[0] = yyvsp[0]; yyval=createNode("ExtDecList", 1, cldArray);}
#line 1658 "syntax.tab.c"
    break;

  case 28:
#line 75 "syntax.y"
                              {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("ExtDecList", 3, cldArray);}
#line 1664 "syntax.tab.c"
    break;

  case 29:
#line 78 "syntax.y"
                {cldArray[0] = yyvsp[0]; yyval=createNode("Specifier", 1, cldArray);}
#line 1670 "syntax.tab.c"
    break;

  case 30:
#line 79 "syntax.y"
                      {cldArray[0] = yyvsp[0]; yyval=createNode("Specifier", 1, cldArray);}
#line 1676 "syntax.tab.c"
    break;

  case 31:
#line 81 "syntax.y"
                                         {cldArray[0] = yyvsp[-4]; cldArray[1] = yyvsp[-3]; cldArray[2]=yyvsp[-2]; cldArray[3]=yyvsp[-1]; cldArray[4]=yyvsp[0]; yyval=createNode("StructSpecifier", 5, cldArray);}
#line 1682 "syntax.tab.c"
    break;

  case 32:
#line 82 "syntax.y"
                                 {cldArray[0] = yyvsp[-4]; cldArray[1] = yyvsp[-3]; cldArray[2]=yyvsp[-2]; cldArray[3]=yyvsp[-1]; cldArray[4]=yyvsp[0]; yyval=createNode("StructSpecifier", 5, cldArray);
        isCorrect=0;char* text = "Missing closing brace '}'";printf("%d: %s\n",yylineno,text);}
#line 1689 "syntax.tab.c"
    break;

  case 33:
#line 84 "syntax.y"
                {cldArray[0] = yyvsp[-1]; cldArray[1] = yyvsp[0]; yyval=createNode("StructSpecifier", 2, cldArray);}
#line 1695 "syntax.tab.c"
    break;

  case 34:
#line 87 "syntax.y"
           {cldArray[0] = yyvsp[0]; yyval=createNode("VarDec", 1, cldArray);}
#line 1701 "syntax.tab.c"
    break;

  case 35:
#line 88 "syntax.y"
                       {cldArray[0] = yyvsp[-3]; cldArray[1] = yyvsp[-2]; cldArray[2]=yyvsp[-1]; cldArray[3]=yyvsp[0]; yyval=createNode("VarDec", 4, cldArray);}
#line 1707 "syntax.tab.c"
    break;

  case 36:
#line 89 "syntax.y"
            {cldArray[0]=yyvsp[0]; yyval=createNode("Exp", 1, cldArray); isCorrect=0;}
#line 1713 "syntax.tab.c"
    break;

  case 37:
#line 91 "syntax.y"
                         {cldArray[0] = yyvsp[-3]; cldArray[1] = yyvsp[-2]; cldArray[2]=yyvsp[-1]; cldArray[3]=yyvsp[0]; yyval=createNode("FunDec", 4, cldArray);}
#line 1719 "syntax.tab.c"
    break;

  case 38:
#line 92 "syntax.y"
               {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("FunDec", 3, cldArray);}
#line 1725 "syntax.tab.c"
    break;

  case 39:
#line 93 "syntax.y"
                  {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=createLeaf("RP",NULL,0);yyval=createNode("FunDec", 3, cldArray);
        isCorrect=0;char* text = "Missing closing parenthesis ')'";printf("%d: %s\n",yyvsp[-1]->line,text);}
#line 1732 "syntax.tab.c"
    break;

  case 40:
#line 95 "syntax.y"
                          {cldArray[0] = yyvsp[-3]; cldArray[1] = yyvsp[-2]; cldArray[2]=yyvsp[-1]; cldArray[3]=yyvsp[0]; yyval=createNode("FunDec", 4, cldArray);
        isCorrect=0;char* text = "Missing closing parenthesis ')'";printf("%d: %s\n",yyvsp[-2]->line,text);}
#line 1739 "syntax.tab.c"
    break;

  case 41:
#line 98 "syntax.y"
                                {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("VarList", 3, cldArray);}
#line 1745 "syntax.tab.c"
    break;

  case 42:
#line 99 "syntax.y"
               {cldArray[0] = yyvsp[0]; yyval=createNode("VarList", 1, cldArray);}
#line 1751 "syntax.tab.c"
    break;

  case 43:
#line 101 "syntax.y"
                           {cldArray[0] = yyvsp[-1]; cldArray[1] = yyvsp[0]; yyval=createNode("ParamDec", 2, cldArray);}
#line 1757 "syntax.tab.c"
    break;

  case 44:
#line 104 "syntax.y"
                               {cldArray[0] = yyvsp[-3]; cldArray[1] = yyvsp[-2]; cldArray[2]=yyvsp[-1]; cldArray[3]=yyvsp[0]; yyval=createNode("CompSt", 4, cldArray);}
#line 1763 "syntax.tab.c"
    break;

  case 45:
#line 106 "syntax.y"
                 {yyval = createNode("Empty", 0, cldArray);}
#line 1769 "syntax.tab.c"
    break;

  case 46:
#line 107 "syntax.y"
                    {cldArray[0] = yyvsp[-1]; cldArray[1] = yyvsp[0]; yyval=createNode("StmtList", 2, cldArray);}
#line 1775 "syntax.tab.c"
    break;

  case 47:
#line 109 "syntax.y"
               {cldArray[0] = yyvsp[-1]; cldArray[1] = yyvsp[0]; yyval=createNode("Stmt", 2, cldArray);}
#line 1781 "syntax.tab.c"
    break;

  case 48:
#line 110 "syntax.y"
             {cldArray[0] = yyvsp[0]; yyval=createNode("Stmt", 1, cldArray);}
#line 1787 "syntax.tab.c"
    break;

  case 49:
#line 111 "syntax.y"
                      {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Stmt", 3, cldArray);}
#line 1793 "syntax.tab.c"
    break;

  case 50:
#line 112 "syntax.y"
                       {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Stmt", 3, cldArray);
        isCorrect=0;char* text = "Missing semicolon ';'";printf("%d: %s\n",yyvsp[-1]->line,text);}
#line 1800 "syntax.tab.c"
    break;

  case 51:
#line 114 "syntax.y"
                                        {cldArray[0] = yyvsp[-4]; cldArray[1] = yyvsp[-3]; cldArray[2]=yyvsp[-2]; cldArray[3]=yyvsp[-1]; cldArray[4]=yyvsp[0]; yyval=createNode("Stmt", 5, cldArray);}
#line 1806 "syntax.tab.c"
    break;

  case 52:
#line 115 "syntax.y"
                                           {cldArray[0] = yyvsp[-4]; cldArray[1] = yyvsp[-3]; cldArray[2]=yyvsp[-2]; cldArray[3]=yyvsp[-1]; cldArray[4]=yyvsp[0]; yyval=createNode("Stmt", 5, cldArray);
        isCorrect=0;char* text = "Missing closing parenthesis ')'";printf("%d: %s\n",yyvsp[-3]->line,text);}
#line 1813 "syntax.tab.c"
    break;

  case 53:
#line 118 "syntax.y"
                                  {cldArray[0] = yyvsp[-6]; cldArray[1] = yyvsp[-5]; cldArray[2]=yyvsp[-4]; cldArray[3]=yyvsp[-3]; cldArray[4]=yyvsp[-2]; cldArray[5]=yyvsp[-1]; cldArray[6]=yyvsp[0];yyval=createNode("Stmt", 7, cldArray);}
#line 1819 "syntax.tab.c"
    break;

  case 54:
#line 119 "syntax.y"
                           {cldArray[0] = yyvsp[-4]; cldArray[1] = yyvsp[-3]; cldArray[2]=yyvsp[-2]; cldArray[3]=yyvsp[-1]; cldArray[4]=yyvsp[0]; yyval=createNode("Stmt", 5, cldArray);}
#line 1825 "syntax.tab.c"
    break;

  case 55:
#line 120 "syntax.y"
                              {cldArray[0] = yyvsp[-4]; cldArray[1] = yyvsp[-3]; cldArray[2]=yyvsp[-2]; cldArray[3]=yyvsp[-1]; cldArray[4]=yyvsp[0]; yyval=createNode("Stmt", 5, cldArray);
        isCorrect=0;char* text = "Missing closing parenthesis ')'";printf("%d: %s\n",yyvsp[-3]->line,text);}
#line 1832 "syntax.tab.c"
    break;

  case 56:
#line 123 "syntax.y"
                {cldArray[0] = yyvsp[-1]; cldArray[1] = yyvsp[0]; yyval=createNode("Stmt", 2, cldArray); isCorrect=0;char* text = "Missing semicolon ';'";printf("%d: %s\n",yyvsp[-1]->line,text);}
#line 1838 "syntax.tab.c"
    break;

  case 57:
#line 126 "syntax.y"
                {yyval = createNode("Empty", 0, cldArray);}
#line 1844 "syntax.tab.c"
    break;

  case 58:
#line 127 "syntax.y"
                  {cldArray[0] = yyvsp[-1]; cldArray[1] = yyvsp[0]; yyval=createNode("DefList", 2, cldArray);}
#line 1850 "syntax.tab.c"
    break;

  case 59:
#line 129 "syntax.y"
                            {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Def", 3, cldArray);}
#line 1856 "syntax.tab.c"
    break;

  case 60:
#line 130 "syntax.y"
                              {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Def", 3, cldArray);
        isCorrect=0;char* text = "Missing semicolon ';'";printf("%d: %s\n",yyvsp[-1]->line,text);}
#line 1863 "syntax.tab.c"
    break;

  case 61:
#line 133 "syntax.y"
             {cldArray[0] = yyvsp[0]; yyval=createNode("DecList", 1, cldArray);}
#line 1869 "syntax.tab.c"
    break;

  case 62:
#line 134 "syntax.y"
                        {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("DecList", 3, cldArray);}
#line 1875 "syntax.tab.c"
    break;

  case 63:
#line 136 "syntax.y"
            {cldArray[0] = yyvsp[0]; yyval=createNode("Dec", 1, cldArray);}
#line 1881 "syntax.tab.c"
    break;

  case 64:
#line 137 "syntax.y"
                        {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Dec", 3, cldArray);}
#line 1887 "syntax.tab.c"
    break;

  case 65:
#line 140 "syntax.y"
                    {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Exp", 3, cldArray);}
#line 1893 "syntax.tab.c"
    break;

  case 66:
#line 141 "syntax.y"
                  {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Exp", 3, cldArray);}
#line 1899 "syntax.tab.c"
    break;

  case 67:
#line 142 "syntax.y"
                 {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Exp", 3, cldArray);}
#line 1905 "syntax.tab.c"
    break;

  case 68:
#line 143 "syntax.y"
                    {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Exp", 3, cldArray); isCorrect=0;}
#line 1911 "syntax.tab.c"
    break;

  case 69:
#line 144 "syntax.y"
                 {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Exp", 3, cldArray);}
#line 1917 "syntax.tab.c"
    break;

  case 70:
#line 145 "syntax.y"
                 {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Exp", 3, cldArray);}
#line 1923 "syntax.tab.c"
    break;

  case 71:
#line 146 "syntax.y"
                 {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Exp", 3, cldArray);}
#line 1929 "syntax.tab.c"
    break;

  case 72:
#line 147 "syntax.y"
                 {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Exp", 3, cldArray);}
#line 1935 "syntax.tab.c"
    break;

  case 73:
#line 148 "syntax.y"
                 {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Exp", 3, cldArray);}
#line 1941 "syntax.tab.c"
    break;

  case 74:
#line 149 "syntax.y"
                 {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Exp", 3, cldArray);}
#line 1947 "syntax.tab.c"
    break;

  case 75:
#line 150 "syntax.y"
                   {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Exp", 3, cldArray);}
#line 1953 "syntax.tab.c"
    break;

  case 76:
#line 151 "syntax.y"
                    {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Exp", 3, cldArray);}
#line 1959 "syntax.tab.c"
    break;

  case 77:
#line 152 "syntax.y"
                  {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Exp", 3, cldArray);}
#line 1965 "syntax.tab.c"
    break;

  case 78:
#line 153 "syntax.y"
                  {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Exp", 3, cldArray);}
#line 1971 "syntax.tab.c"
    break;

  case 79:
#line 154 "syntax.y"
                {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Exp", 3, cldArray);}
#line 1977 "syntax.tab.c"
    break;

  case 80:
#line 155 "syntax.y"
                   {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Exp", 3, cldArray);
        isCorrect=0;char* text = "Missing closing parenthesis ')'";printf("%d: %s\n",yyvsp[-1]->line,text);}
#line 1984 "syntax.tab.c"
    break;

  case 81:
#line 157 "syntax.y"
                {cldArray[0] = yyvsp[-1]; cldArray[1] = yyvsp[0]; yyval=createNode("Exp", 2, cldArray);}
#line 1990 "syntax.tab.c"
    break;

  case 82:
#line 158 "syntax.y"
              {cldArray[0] = yyvsp[-1]; cldArray[1] = yyvsp[0]; yyval=createNode("Exp", 2, cldArray);}
#line 1996 "syntax.tab.c"
    break;

  case 83:
#line 159 "syntax.y"
                    {cldArray[0] = yyvsp[-3]; cldArray[1] = yyvsp[-2]; cldArray[2]=yyvsp[-1]; cldArray[3]=yyvsp[0]; yyval=createNode("Exp", 4, cldArray);}
#line 2002 "syntax.tab.c"
    break;

  case 84:
#line 160 "syntax.y"
                       {cldArray[0] = yyvsp[-3]; cldArray[1] = yyvsp[-2]; cldArray[2]=yyvsp[-1]; cldArray[3]=yyvsp[0]; yyval=createNode("Exp", 4, cldArray);
        isCorrect=0;char* text = "Missing closing parenthesis ')'";printf("%d: %s\n",yyvsp[-2]->line,text);}
#line 2009 "syntax.tab.c"
    break;

  case 85:
#line 162 "syntax.y"
               {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Exp", 3, cldArray);}
#line 2015 "syntax.tab.c"
    break;

  case 86:
#line 163 "syntax.y"
                    {cldArray[0] = yyvsp[-3]; cldArray[1] = yyvsp[-2]; cldArray[2]=yyvsp[-1]; cldArray[3]=yyvsp[0]; yyval=createNode("Exp", 4, cldArray);}
#line 2021 "syntax.tab.c"
    break;

  case 87:
#line 164 "syntax.y"
                 {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Exp", 3, cldArray);}
#line 2027 "syntax.tab.c"
    break;

  case 88:
#line 165 "syntax.y"
         {cldArray[0] = yyvsp[0]; yyval=createNode("Exp", 1, cldArray);}
#line 2033 "syntax.tab.c"
    break;

  case 89:
#line 166 "syntax.y"
          {cldArray[0] = yyvsp[0]; yyval=createNode("Exp", 1, cldArray);}
#line 2039 "syntax.tab.c"
    break;

  case 90:
#line 167 "syntax.y"
            {cldArray[0] = yyvsp[0]; yyval=createNode("Exp", 1, cldArray);}
#line 2045 "syntax.tab.c"
    break;

  case 91:
#line 168 "syntax.y"
           {cldArray[0] = yyvsp[0]; yyval=createNode("Exp", 1, cldArray);}
#line 2051 "syntax.tab.c"
    break;

  case 92:
#line 169 "syntax.y"
            {cldArray[0]=yyvsp[0]; yyval=createNode("Exp", 1, cldArray); isCorrect=0;}
#line 2057 "syntax.tab.c"
    break;

  case 93:
#line 171 "syntax.y"
                     {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Args", 3, cldArray);}
#line 2063 "syntax.tab.c"
    break;

  case 94:
#line 172 "syntax.y"
          {cldArray[0] = yyvsp[0]; yyval=createNode("Args", 1, cldArray);}
#line 2069 "syntax.tab.c"
    break;


#line 2073 "syntax.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 174 "syntax.y"

void yyerror(const char *s) {
    printf("Error type B at Line ");
}
int main(int argc, char *argv[]) {
    if(argc < 2) return 1;
    FILE *f = fopen(argv[1], "r");
    if(!f) {
        perror(argv[1]);
        return 1;
    }
    yyrestart(f);
    yylineno = 1;
    yyparse();

    return 0;
}
