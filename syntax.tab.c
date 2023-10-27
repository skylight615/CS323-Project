/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

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

#include "syntax.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_FLOAT = 4,                      /* FLOAT  */
  YYSYMBOL_CHAR = 5,                       /* CHAR  */
  YYSYMBOL_TYPE = 6,                       /* TYPE  */
  YYSYMBOL_STRUCT = 7,                     /* STRUCT  */
  YYSYMBOL_IF = 8,                         /* IF  */
  YYSYMBOL_ELSE = 9,                       /* ELSE  */
  YYSYMBOL_WHILE = 10,                     /* WHILE  */
  YYSYMBOL_RETURN = 11,                    /* RETURN  */
  YYSYMBOL_ID = 12,                        /* ID  */
  YYSYMBOL_DOT = 13,                       /* DOT  */
  YYSYMBOL_SEMI = 14,                      /* SEMI  */
  YYSYMBOL_COMMA = 15,                     /* COMMA  */
  YYSYMBOL_INCLUDE = 16,                   /* INCLUDE  */
  YYSYMBOL_FILEIN = 17,                    /* FILEIN  */
  YYSYMBOL_ASSIGN = 18,                    /* ASSIGN  */
  YYSYMBOL_LT = 19,                        /* LT  */
  YYSYMBOL_LE = 20,                        /* LE  */
  YYSYMBOL_GT = 21,                        /* GT  */
  YYSYMBOL_GE = 22,                        /* GE  */
  YYSYMBOL_NE = 23,                        /* NE  */
  YYSYMBOL_EQ = 24,                        /* EQ  */
  YYSYMBOL_PLUS = 25,                      /* PLUS  */
  YYSYMBOL_MINUS = 26,                     /* MINUS  */
  YYSYMBOL_MUL = 27,                       /* MUL  */
  YYSYMBOL_DIV = 28,                       /* DIV  */
  YYSYMBOL_AND = 29,                       /* AND  */
  YYSYMBOL_OR = 30,                        /* OR  */
  YYSYMBOL_NOT = 31,                       /* NOT  */
  YYSYMBOL_LP = 32,                        /* LP  */
  YYSYMBOL_RP = 33,                        /* RP  */
  YYSYMBOL_LB = 34,                        /* LB  */
  YYSYMBOL_RB = 35,                        /* RB  */
  YYSYMBOL_ERROR = 36,                     /* ERROR  */
  YYSYMBOL_NEG = 37,                       /* NEG  */
  YYSYMBOL_LC = 38,                        /* LC  */
  YYSYMBOL_RC = 39,                        /* RC  */
  YYSYMBOL_LOWER_ELSE = 40,                /* LOWER_ELSE  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_Program = 42,                   /* Program  */
  YYSYMBOL_HeadList = 43,                  /* HeadList  */
  YYSYMBOL_Head = 44,                      /* Head  */
  YYSYMBOL_ExtDefList = 45,                /* ExtDefList  */
  YYSYMBOL_ExtDef = 46,                    /* ExtDef  */
  YYSYMBOL_ExtDecList = 47,                /* ExtDecList  */
  YYSYMBOL_Specifier = 48,                 /* Specifier  */
  YYSYMBOL_StructSpecifier = 49,           /* StructSpecifier  */
  YYSYMBOL_VarDec = 50,                    /* VarDec  */
  YYSYMBOL_FunDec = 51,                    /* FunDec  */
  YYSYMBOL_VarList = 52,                   /* VarList  */
  YYSYMBOL_ParamDec = 53,                  /* ParamDec  */
  YYSYMBOL_CompSt = 54,                    /* CompSt  */
  YYSYMBOL_StmtList = 55,                  /* StmtList  */
  YYSYMBOL_Stmt = 56,                      /* Stmt  */
  YYSYMBOL_DefList = 57,                   /* DefList  */
  YYSYMBOL_Def = 58,                       /* Def  */
  YYSYMBOL_DecList = 59,                   /* DecList  */
  YYSYMBOL_Dec = 60,                       /* Dec  */
  YYSYMBOL_Exp = 61,                       /* Exp  */
  YYSYMBOL_Args = 62                       /* Args  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   366

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  146

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   295


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    31,    31,    32,    34,    35,    37,    38,    39,    42,
      43,    45,    46,    47,    48,    51,    52,    55,    56,    58,
      59,    61,    64,    65,    66,    68,    69,    70,    72,    75,
      76,    78,    81,    82,    86,    87,    89,    90,    91,    92,
      94,    95,    98,    99,   100,   103,   106,   107,   109,   110,
     113,   114,   116,   117,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     137,   138,   139,   140,   142,   143,   144,   145,   146,   147,
     148,   149,   151,   152
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INT", "FLOAT", "CHAR",
  "TYPE", "STRUCT", "IF", "ELSE", "WHILE", "RETURN", "ID", "DOT", "SEMI",
  "COMMA", "INCLUDE", "FILEIN", "ASSIGN", "LT", "LE", "GT", "GE", "NE",
  "EQ", "PLUS", "MINUS", "MUL", "DIV", "AND", "OR", "NOT", "LP", "RP",
  "LB", "RB", "ERROR", "NEG", "LC", "RC", "LOWER_ELSE", "$accept",
  "Program", "HeadList", "Head", "ExtDefList", "ExtDef", "ExtDecList",
  "Specifier", "StructSpecifier", "VarDec", "FunDec", "VarList",
  "ParamDec", "CompSt", "StmtList", "Stmt", "DefList", "Def", "DecList",
  "Dec", "Exp", "Args", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-62)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     105,   -62,     0,   178,    52,   107,     7,   -62,   107,    12,
     -62,    38,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,
      48,   -62,   -62,    70,    -7,    51,   107,    13,   -62,   -11,
      83,   107,   -62,   -11,     4,   107,   -62,   -62,   -11,    16,
      76,   -62,   -62,    80,   198,    72,     8,    92,   -62,   -62,
     -62,    75,   -62,   -62,   107,   -62,   -62,   -62,   -62,    84,
      86,   216,    87,   216,   216,   216,   -62,   -62,     6,   198,
      43,   216,   -62,   -62,   -11,   -62,   216,   216,    74,   213,
      47,    47,   104,   -62,   -62,   -62,   -62,   108,   -62,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   276,   -62,   134,   164,   -62,   -62,
     -62,   238,    20,   -62,   -62,   -62,   276,   316,   316,   316,
     316,   316,   316,   199,   199,    47,    47,   312,   294,   257,
     276,   198,   198,   198,   198,   216,   -62,   -62,   -62,   -62,
     127,   -62,   -62,   -62,   198,   -62
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,    17,     0,     0,     0,     9,     4,     2,     9,     0,
      18,    21,     8,     6,     7,     1,     3,     5,    10,    14,
      22,    12,    24,     0,    15,     0,    46,     0,    11,     0,
       0,    46,    13,     0,     0,    46,    27,    26,     0,     0,
      30,    22,    16,     0,    34,    52,     0,    50,    20,    19,
      47,    31,    28,    25,     0,    23,    78,    79,    80,     0,
       0,     0,    77,     0,     0,     0,    81,    37,     0,    34,
       0,     0,    49,    48,     0,    29,     0,     0,     0,     0,
      70,    71,     0,    33,    32,    35,    45,     0,    36,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,    51,     0,     0,    39,    38,
      74,    83,     0,    69,    68,    76,    54,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    55,    56,     0,
      57,     0,     0,     0,     0,     0,    73,    72,    75,    41,
      40,    44,    43,    82,     0,    42
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -62,   -62,   133,   -62,    77,   -62,   112,    24,   -62,   -27,
     -62,    88,   -62,   118,    79,   222,    23,   -62,    71,   -62,
     -61,     9
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,     7,     8,    23,     9,    10,    24,
      25,    39,    40,    67,    68,    69,    34,    35,    46,    47,
      70,   112
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      78,    41,    80,    81,    82,    48,    45,    83,    29,    72,
     104,    51,    11,    19,    36,   106,   107,    52,   111,     1,
       2,   136,    73,     3,    20,    22,    21,    30,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,    49,    86,    84,    37,    45,    22,    53,
      33,    38,    15,   137,    44,    33,    87,    88,    50,    33,
      87,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   111,   108,    26,   102,    38,   103,
      27,   102,    16,   103,    28,    18,    43,    87,   109,    31,
      71,    54,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   113,    30,    74,   102,    30,
     103,     1,     2,     1,     2,    55,    76,    87,    77,    79,
     115,     3,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   131,   144,   114,   102,    17,
     103,    42,    75,    32,   143,   105,     0,    87,    85,     0,
       0,     0,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   133,     0,   132,   102,     0,
     103,     0,     0,     0,     0,     0,     0,    87,     0,    12,
       0,     0,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,    13,     0,   134,   102,     0,
     103,    56,    57,    58,     0,     0,    59,     0,    60,    61,
      62,     0,    87,     0,    14,     0,    56,    57,    58,    56,
      57,    58,     0,     0,    63,    62,    98,    99,    62,    64,
      65,     0,     0,   102,    66,   103,    31,     0,     0,    63,
       0,     0,    63,     0,    64,    65,   110,    64,    65,    66,
       0,    87,    66,   135,     0,     0,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,     0,
      87,     0,   102,     0,   103,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,     0,    87,
       0,   102,   138,   103,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,    87,     0,     0,
     102,     0,   103,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,     0,    87,     0,     0,   102,    87,
     103,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,    96,    97,    98,    99,     0,   102,     0,   103,     0,
     102,     0,   103,   139,   140,   141,   142,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   145
};

static const yytype_int16 yycheck[] =
{
      61,    12,    63,    64,    65,     1,    33,     1,    15,     1,
      71,    38,    12,     1,     1,    76,    77,     1,    79,     6,
       7,     1,    14,    16,    12,    36,    14,    34,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,    39,     1,    39,    33,    74,    36,    33,
      26,    27,     0,    33,    31,    31,    13,    14,    35,    35,
      13,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,   135,     1,    38,    34,    54,    36,
      32,    34,     5,    36,    14,     8,     3,    13,    14,    38,
      18,    15,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,     1,    34,    15,    34,    34,
      36,     6,     7,     6,     7,    35,    32,    13,    32,    32,
      12,    16,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,     1,     9,    33,    34,     6,
      36,    29,    54,    25,   135,    74,    -1,    13,    69,    -1,
      -1,    -1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,     1,    -1,    33,    34,    -1,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    13,    -1,     1,
      -1,    -1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    17,    -1,    33,    34,    -1,
      36,     3,     4,     5,    -1,    -1,     8,    -1,    10,    11,
      12,    -1,    13,    -1,    36,    -1,     3,     4,     5,     3,
       4,     5,    -1,    -1,    26,    12,    27,    28,    12,    31,
      32,    -1,    -1,    34,    36,    36,    38,    -1,    -1,    26,
      -1,    -1,    26,    -1,    31,    32,    33,    31,    32,    36,
      -1,    13,    36,    15,    -1,    -1,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    -1,
      13,    -1,    34,    -1,    36,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    -1,    13,
      -1,    34,    35,    36,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    13,    -1,    -1,
      34,    -1,    36,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    13,    -1,    -1,    34,    13,
      36,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    25,    26,    27,    28,    -1,    34,    -1,    36,    -1,
      34,    -1,    36,   131,   132,   133,   134,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   144
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,     7,    16,    42,    43,    44,    45,    46,    48,
      49,    12,     1,    17,    36,     0,    45,    43,    45,     1,
      12,    14,    36,    47,    50,    51,    38,    32,    14,    15,
      34,    38,    54,    48,    57,    58,     1,    33,    48,    52,
      53,    12,    47,     3,    57,    50,    59,    60,     1,    39,
      57,    50,     1,    33,    15,    35,     3,     4,     5,     8,
      10,    11,    12,    26,    31,    32,    36,    54,    55,    56,
      61,    18,     1,    14,    15,    52,    32,    32,    61,    32,
      61,    61,    61,     1,    39,    55,     1,    13,    14,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    34,    36,    61,    59,    61,    61,     1,    14,
      33,    61,    62,     1,    33,    12,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,     1,    33,     1,    33,    15,     1,    33,    35,    56,
      56,    56,    56,    62,     9,    56
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    42,    43,    43,    44,    44,    44,    45,
      45,    46,    46,    46,    46,    47,    47,    48,    48,    49,
      49,    49,    50,    50,    50,    51,    51,    51,    51,    52,
      52,    53,    54,    54,    55,    55,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    57,    57,    58,    58,
      59,    59,    60,    60,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    62,    62
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     2,     2,     2,     0,
       2,     3,     2,     3,     2,     1,     3,     1,     1,     5,
       5,     2,     1,     4,     1,     4,     3,     3,     4,     3,
       1,     2,     4,     4,     0,     2,     2,     1,     3,     3,
       5,     5,     7,     5,     5,     2,     0,     2,     3,     3,
       1,     3,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     4,     4,     3,     4,     3,     1,     1,     1,
       1,     1,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* Program: ExtDefList  */
#line 31 "syntax.y"
                    {cldArray[0] = yyvsp[0]; yyval=createNode("Program", 1, cldArray); if(isCorrect==1)dfs(yyval,0);}
#line 1267 "syntax.tab.c"
    break;

  case 3: /* Program: HeadList ExtDefList  */
#line 32 "syntax.y"
                          {cldArray[0] = yyvsp[-1]; cldArray[1] = yyvsp[0];yyval=createNode("Program", 2, cldArray); if(isCorrect==1)dfs(yyval,0);}
#line 1273 "syntax.tab.c"
    break;

  case 4: /* HeadList: %empty  */
#line 34 "syntax.y"
                 {yyval = createNode("Empty", 0, cldArray);}
#line 1279 "syntax.tab.c"
    break;

  case 5: /* HeadList: Head HeadList  */
#line 35 "syntax.y"
                    {cldArray[0] = yyvsp[-1]; cldArray[1] = yyvsp[0]; yyval=createNode("HeadList", 2, cldArray);}
#line 1285 "syntax.tab.c"
    break;

  case 6: /* Head: INCLUDE FILEIN  */
#line 37 "syntax.y"
                     {cldArray[0] = yyvsp[-1]; cldArray[1] = yyvsp[0]; yyval=createNode("Head", 2, cldArray);}
#line 1291 "syntax.tab.c"
    break;

  case 7: /* Head: INCLUDE ERROR  */
#line 38 "syntax.y"
                    {cldArray[0] = yyvsp[-1]; cldArray[1] = yyvsp[0]; yyval=createNode("Head", 2, cldArray); isCorrect=0;}
#line 1297 "syntax.tab.c"
    break;

  case 8: /* Head: INCLUDE error  */
#line 39 "syntax.y"
                    {cldArray[0] = yyvsp[-1]; cldArray[1] = yyvsp[0]; yyval=createNode("Head", 2, cldArray);
        isCorrect=0;char* text = "Not a head file";printf("%d: %s\n",yyvsp[0]->line,text);}
#line 1304 "syntax.tab.c"
    break;

  case 9: /* ExtDefList: %empty  */
#line 42 "syntax.y"
                   {yyval = createNode("Empty", 0, cldArray);}
#line 1310 "syntax.tab.c"
    break;

  case 10: /* ExtDefList: ExtDef ExtDefList  */
#line 43 "syntax.y"
                        {cldArray[0] = yyvsp[-1]; cldArray[1] = yyvsp[0]; yyval=createNode("ExtDefList", 2, cldArray);}
#line 1316 "syntax.tab.c"
    break;

  case 11: /* ExtDef: Specifier ExtDecList SEMI  */
#line 45 "syntax.y"
                                  {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("ExtDef", 3, cldArray);}
#line 1322 "syntax.tab.c"
    break;

  case 12: /* ExtDef: Specifier SEMI  */
#line 46 "syntax.y"
                     {cldArray[0] = yyvsp[-1]; cldArray[1] = yyvsp[0]; yyval=createNode("ExtDef", 2, cldArray);}
#line 1328 "syntax.tab.c"
    break;

  case 13: /* ExtDef: Specifier FunDec CompSt  */
#line 47 "syntax.y"
                              {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("ExtDef", 3, cldArray);}
#line 1334 "syntax.tab.c"
    break;

  case 14: /* ExtDef: Specifier error  */
#line 48 "syntax.y"
                      {cldArray[0] = yyvsp[-1]; cldArray[1] = yyvsp[0]; yyval=createNode("ExtDef", 2, cldArray);
        isCorrect=0;char* text = "Missing semicolon ';'";printf("%d: %s\n",yyvsp[0]->line,text);}
#line 1341 "syntax.tab.c"
    break;

  case 15: /* ExtDecList: VarDec  */
#line 51 "syntax.y"
                   {cldArray[0] = yyvsp[0]; yyval=createNode("ExtDecList", 1, cldArray);}
#line 1347 "syntax.tab.c"
    break;

  case 16: /* ExtDecList: VarDec COMMA ExtDecList  */
#line 52 "syntax.y"
                              {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("ExtDecList", 3, cldArray);}
#line 1353 "syntax.tab.c"
    break;

  case 17: /* Specifier: TYPE  */
#line 55 "syntax.y"
                {cldArray[0] = yyvsp[0]; yyval=createNode("Specifier", 1, cldArray);}
#line 1359 "syntax.tab.c"
    break;

  case 18: /* Specifier: StructSpecifier  */
#line 56 "syntax.y"
                      {cldArray[0] = yyvsp[0]; yyval=createNode("Specifier", 1, cldArray);}
#line 1365 "syntax.tab.c"
    break;

  case 19: /* StructSpecifier: STRUCT ID LC DefList RC  */
#line 58 "syntax.y"
                                         {cldArray[0] = yyvsp[-4]; cldArray[1] = yyvsp[-3]; cldArray[2]=yyvsp[-2]; cldArray[3]=yyvsp[-1]; cldArray[4]=yyvsp[0]; yyval=createNode("StructSpecifier", 5, cldArray);}
#line 1371 "syntax.tab.c"
    break;

  case 20: /* StructSpecifier: STRUCT ID LC DefList error  */
#line 59 "syntax.y"
                                 {cldArray[0] = yyvsp[-4]; cldArray[1] = yyvsp[-3]; cldArray[2]=yyvsp[-2]; cldArray[3]=yyvsp[-1]; cldArray[4]=yyvsp[0]; yyval=createNode("StructSpecifier", 5, cldArray);
        isCorrect=0;char* text = "Missing closing brace '}'";printf("%d: %s\n",yyvsp[-3]->line,text);}
#line 1378 "syntax.tab.c"
    break;

  case 21: /* StructSpecifier: STRUCT ID  */
#line 61 "syntax.y"
                {cldArray[0] = yyvsp[-1]; cldArray[1] = yyvsp[0]; yyval=createNode("StructSpecifier", 2, cldArray);}
#line 1384 "syntax.tab.c"
    break;

  case 22: /* VarDec: ID  */
#line 64 "syntax.y"
           {cldArray[0] = yyvsp[0]; yyval=createNode("VarDec", 1, cldArray);}
#line 1390 "syntax.tab.c"
    break;

  case 23: /* VarDec: VarDec LB INT RB  */
#line 65 "syntax.y"
                       {cldArray[0] = yyvsp[-3]; cldArray[1] = yyvsp[-2]; cldArray[2]=yyvsp[-1]; cldArray[3]=yyvsp[0]; yyval=createNode("VarDec", 4, cldArray);}
#line 1396 "syntax.tab.c"
    break;

  case 24: /* VarDec: ERROR  */
#line 66 "syntax.y"
            {cldArray[0]=yyvsp[0]; yyval=createNode("Exp", 1, cldArray); isCorrect=0;}
#line 1402 "syntax.tab.c"
    break;

  case 25: /* FunDec: ID LP VarList RP  */
#line 68 "syntax.y"
                         {cldArray[0] = yyvsp[-3]; cldArray[1] = yyvsp[-2]; cldArray[2]=yyvsp[-1]; cldArray[3]=yyvsp[0]; yyval=createNode("FunDec", 4, cldArray);}
#line 1408 "syntax.tab.c"
    break;

  case 26: /* FunDec: ID LP RP  */
#line 69 "syntax.y"
               {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("FunDec", 3, cldArray);}
#line 1414 "syntax.tab.c"
    break;

  case 27: /* FunDec: ID LP error  */
#line 70 "syntax.y"
                  {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=createLeaf("RP",NULL);yyval=createNode("FunDec", 3, cldArray);
        isCorrect=0;char* text = "Missing closing parenthesis ')'";printf("%d: %s\n",yyvsp[-1]->line,text);}
#line 1421 "syntax.tab.c"
    break;

  case 28: /* FunDec: ID LP VarList error  */
#line 72 "syntax.y"
                         {cldArray[0] = yyvsp[-3]; cldArray[1] = yyvsp[-2]; cldArray[2]=yyvsp[-1]; cldArray[3]=yyvsp[0]; yyval=createNode("FunDec", 4, cldArray);
        isCorrect=0;char* text = "Missing closing parenthesis ')'";printf("%d: %s\n",yyvsp[-2]->line,text);}
#line 1428 "syntax.tab.c"
    break;

  case 29: /* VarList: ParamDec COMMA VarList  */
#line 75 "syntax.y"
                                {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("VarList", 3, cldArray);}
#line 1434 "syntax.tab.c"
    break;

  case 30: /* VarList: ParamDec  */
#line 76 "syntax.y"
               {cldArray[0] = yyvsp[0]; yyval=createNode("VarList", 1, cldArray);}
#line 1440 "syntax.tab.c"
    break;

  case 31: /* ParamDec: Specifier VarDec  */
#line 78 "syntax.y"
                           {cldArray[0] = yyvsp[-1]; cldArray[1] = yyvsp[0]; yyval=createNode("ParamDec", 2, cldArray);}
#line 1446 "syntax.tab.c"
    break;

  case 32: /* CompSt: LC DefList StmtList RC  */
#line 81 "syntax.y"
                               {cldArray[0] = yyvsp[-3]; cldArray[1] = yyvsp[-2]; cldArray[2]=yyvsp[-1]; cldArray[3]=yyvsp[0]; yyval=createNode("CompSt", 4, cldArray);}
#line 1452 "syntax.tab.c"
    break;

  case 33: /* CompSt: LC DefList StmtList error  */
#line 82 "syntax.y"
                                {cldArray[0] = yyvsp[-3]; cldArray[1] = yyvsp[-2]; cldArray[2]=yyvsp[-1]; cldArray[3]=yyvsp[0]; yyval=createNode("CompSt", 4, cldArray);
    isCorrect=0;if(strcmp(yyvsp[0]->value,"int")==0 ||strcmp(yyvsp[0]->value,"float")==0 ||strcmp(yyvsp[0]->value,"char")==0){char* text = "Missing specifier";printf("%d: %s\n",yyvsp[-2]->line,text);}
    else{char* text = "Missing closing brace '}'";printf("%d: %s\n",yyvsp[-2]->line,text);}}
#line 1460 "syntax.tab.c"
    break;

  case 34: /* StmtList: %empty  */
#line 86 "syntax.y"
                 {yyval = createNode("Empty", 0, cldArray);}
#line 1466 "syntax.tab.c"
    break;

  case 35: /* StmtList: Stmt StmtList  */
#line 87 "syntax.y"
                    {cldArray[0] = yyvsp[-1]; cldArray[1] = yyvsp[0]; yyval=createNode("StmtList", 2, cldArray);}
#line 1472 "syntax.tab.c"
    break;

  case 36: /* Stmt: Exp SEMI  */
#line 89 "syntax.y"
               {cldArray[0] = yyvsp[-1]; cldArray[1] = yyvsp[0]; yyval=createNode("Stmt", 2, cldArray);}
#line 1478 "syntax.tab.c"
    break;

  case 37: /* Stmt: CompSt  */
#line 90 "syntax.y"
             {cldArray[0] = yyvsp[0]; yyval=createNode("Stmt", 1, cldArray);}
#line 1484 "syntax.tab.c"
    break;

  case 38: /* Stmt: RETURN Exp SEMI  */
#line 91 "syntax.y"
                      {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Stmt", 3, cldArray);}
#line 1490 "syntax.tab.c"
    break;

  case 39: /* Stmt: RETURN Exp error  */
#line 92 "syntax.y"
                       {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Stmt", 3, cldArray);
        isCorrect=0;char* text = "Missing semicolon ';'";printf("%d: %s\n",yyvsp[-1]->line,text);}
#line 1497 "syntax.tab.c"
    break;

  case 40: /* Stmt: IF LP Exp RP Stmt  */
#line 94 "syntax.y"
                                        {cldArray[0] = yyvsp[-4]; cldArray[1] = yyvsp[-3]; cldArray[2]=yyvsp[-2]; cldArray[3]=yyvsp[-1]; cldArray[4]=yyvsp[0]; yyval=createNode("Stmt", 5, cldArray);}
#line 1503 "syntax.tab.c"
    break;

  case 41: /* Stmt: IF LP Exp error Stmt  */
#line 95 "syntax.y"
                                           {cldArray[0] = yyvsp[-4]; cldArray[1] = yyvsp[-3]; cldArray[2]=yyvsp[-2]; cldArray[3]=yyvsp[-1]; cldArray[4]=yyvsp[0]; yyval=createNode("Stmt", 5, cldArray);
        isCorrect=0;char* text = "Missing closing parenthesis ')'";printf("%d: %s\n",yyvsp[-3]->line,text);}
#line 1510 "syntax.tab.c"
    break;

  case 42: /* Stmt: IF LP Exp RP Stmt ELSE Stmt  */
#line 98 "syntax.y"
                                  {cldArray[0] = yyvsp[-6]; cldArray[1] = yyvsp[-5]; cldArray[2]=yyvsp[-4]; cldArray[3]=yyvsp[-3]; cldArray[4]=yyvsp[-2]; cldArray[5]=yyvsp[-1]; cldArray[6]=yyvsp[0];yyval=createNode("Stmt", 7, cldArray);}
#line 1516 "syntax.tab.c"
    break;

  case 43: /* Stmt: WHILE LP Exp RP Stmt  */
#line 99 "syntax.y"
                           {cldArray[0] = yyvsp[-4]; cldArray[1] = yyvsp[-3]; cldArray[2]=yyvsp[-2]; cldArray[3]=yyvsp[-1]; cldArray[4]=yyvsp[0]; yyval=createNode("Stmt", 5, cldArray);}
#line 1522 "syntax.tab.c"
    break;

  case 44: /* Stmt: WHILE LP Exp error Stmt  */
#line 100 "syntax.y"
                              {cldArray[0] = yyvsp[-4]; cldArray[1] = yyvsp[-3]; cldArray[2]=yyvsp[-2]; cldArray[3]=yyvsp[-1]; cldArray[4]=yyvsp[0]; yyval=createNode("Stmt", 5, cldArray);
        isCorrect=0;char* text = "Missing closing parenthesis ')'";printf("%d: %s\n",yyvsp[-3]->line,text);}
#line 1529 "syntax.tab.c"
    break;

  case 45: /* Stmt: Exp error  */
#line 103 "syntax.y"
                {cldArray[0] = yyvsp[-1]; cldArray[1] = yyvsp[0]; yyval=createNode("Stmt", 2, cldArray); isCorrect=0;char* text = "Missing semicolon ';'";printf("%d: %s\n",yyvsp[-1]->line,text);}
#line 1535 "syntax.tab.c"
    break;

  case 46: /* DefList: %empty  */
#line 106 "syntax.y"
                {yyval = createNode("Empty", 0, cldArray);}
#line 1541 "syntax.tab.c"
    break;

  case 47: /* DefList: Def DefList  */
#line 107 "syntax.y"
                  {cldArray[0] = yyvsp[-1]; cldArray[1] = yyvsp[0]; yyval=createNode("DefList", 2, cldArray);}
#line 1547 "syntax.tab.c"
    break;

  case 48: /* Def: Specifier DecList SEMI  */
#line 109 "syntax.y"
                            {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Def", 3, cldArray);}
#line 1553 "syntax.tab.c"
    break;

  case 49: /* Def: Specifier DecList error  */
#line 110 "syntax.y"
                              {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Def", 3, cldArray);
        isCorrect=0;char* text = "Missing semicolon ';'";printf("%d %s\n",yyvsp[-1]->line,text);}
#line 1560 "syntax.tab.c"
    break;

  case 50: /* DecList: Dec  */
#line 113 "syntax.y"
             {cldArray[0] = yyvsp[0]; yyval=createNode("DecList", 1, cldArray);}
#line 1566 "syntax.tab.c"
    break;

  case 51: /* DecList: Dec COMMA DecList  */
#line 114 "syntax.y"
                        {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("DecList", 3, cldArray);}
#line 1572 "syntax.tab.c"
    break;

  case 52: /* Dec: VarDec  */
#line 116 "syntax.y"
            {cldArray[0] = yyvsp[0]; yyval=createNode("Dec", 1, cldArray);}
#line 1578 "syntax.tab.c"
    break;

  case 53: /* Dec: VarDec ASSIGN Exp  */
#line 117 "syntax.y"
                        {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Dec", 3, cldArray);}
#line 1584 "syntax.tab.c"
    break;

  case 54: /* Exp: Exp ASSIGN Exp  */
#line 120 "syntax.y"
                    {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Exp", 3, cldArray);}
#line 1590 "syntax.tab.c"
    break;

  case 55: /* Exp: Exp AND Exp  */
#line 121 "syntax.y"
                  {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Exp", 3, cldArray);}
#line 1596 "syntax.tab.c"
    break;

  case 56: /* Exp: Exp OR Exp  */
#line 122 "syntax.y"
                 {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Exp", 3, cldArray);}
#line 1602 "syntax.tab.c"
    break;

  case 57: /* Exp: Exp ERROR Exp  */
#line 123 "syntax.y"
                    {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Exp", 3, cldArray); isCorrect=0;}
#line 1608 "syntax.tab.c"
    break;

  case 58: /* Exp: Exp LT Exp  */
#line 124 "syntax.y"
                 {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Exp", 3, cldArray);}
#line 1614 "syntax.tab.c"
    break;

  case 59: /* Exp: Exp LE Exp  */
#line 125 "syntax.y"
                 {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Exp", 3, cldArray);}
#line 1620 "syntax.tab.c"
    break;

  case 60: /* Exp: Exp GT Exp  */
#line 126 "syntax.y"
                 {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Exp", 3, cldArray);}
#line 1626 "syntax.tab.c"
    break;

  case 61: /* Exp: Exp GE Exp  */
#line 127 "syntax.y"
                 {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Exp", 3, cldArray);}
#line 1632 "syntax.tab.c"
    break;

  case 62: /* Exp: Exp NE Exp  */
#line 128 "syntax.y"
                 {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Exp", 3, cldArray);}
#line 1638 "syntax.tab.c"
    break;

  case 63: /* Exp: Exp EQ Exp  */
#line 129 "syntax.y"
                 {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Exp", 3, cldArray);}
#line 1644 "syntax.tab.c"
    break;

  case 64: /* Exp: Exp PLUS Exp  */
#line 130 "syntax.y"
                   {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Exp", 3, cldArray);}
#line 1650 "syntax.tab.c"
    break;

  case 65: /* Exp: Exp MINUS Exp  */
#line 131 "syntax.y"
                    {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Exp", 3, cldArray);}
#line 1656 "syntax.tab.c"
    break;

  case 66: /* Exp: Exp MUL Exp  */
#line 132 "syntax.y"
                  {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Exp", 3, cldArray);}
#line 1662 "syntax.tab.c"
    break;

  case 67: /* Exp: Exp DIV Exp  */
#line 133 "syntax.y"
                  {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Exp", 3, cldArray);}
#line 1668 "syntax.tab.c"
    break;

  case 68: /* Exp: LP Exp RP  */
#line 134 "syntax.y"
                {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Exp", 3, cldArray);}
#line 1674 "syntax.tab.c"
    break;

  case 69: /* Exp: LP Exp error  */
#line 135 "syntax.y"
                   {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Exp", 3, cldArray);
        isCorrect=0;char* text = "Missing closing parenthesis ')'";printf("%d: %s\n",yyvsp[-1]->line,text);}
#line 1681 "syntax.tab.c"
    break;

  case 70: /* Exp: MINUS Exp  */
#line 137 "syntax.y"
                {cldArray[0] = yyvsp[-1]; cldArray[1] = yyvsp[0]; yyval=createNode("Exp", 2, cldArray);}
#line 1687 "syntax.tab.c"
    break;

  case 71: /* Exp: NOT Exp  */
#line 138 "syntax.y"
              {cldArray[0] = yyvsp[-1]; cldArray[1] = yyvsp[0]; yyval=createNode("Exp", 2, cldArray);}
#line 1693 "syntax.tab.c"
    break;

  case 72: /* Exp: ID LP Args RP  */
#line 139 "syntax.y"
                    {cldArray[0] = yyvsp[-3]; cldArray[1] = yyvsp[-2]; cldArray[2]=yyvsp[-1]; cldArray[3]=yyvsp[0]; yyval=createNode("Exp", 4, cldArray);}
#line 1699 "syntax.tab.c"
    break;

  case 73: /* Exp: ID LP Args error  */
#line 140 "syntax.y"
                       {cldArray[0] = yyvsp[-3]; cldArray[1] = yyvsp[-2]; cldArray[2]=yyvsp[-1]; cldArray[3]=yyvsp[0]; yyval=createNode("Exp", 4, cldArray);
        isCorrect=0;char* text = "Missing closing parenthesis ')'";printf("%d: %s\n",yyvsp[-2]->line,text);}
#line 1706 "syntax.tab.c"
    break;

  case 74: /* Exp: ID LP RP  */
#line 142 "syntax.y"
               {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Exp", 3, cldArray);}
#line 1712 "syntax.tab.c"
    break;

  case 75: /* Exp: Exp LB Exp RB  */
#line 143 "syntax.y"
                    {cldArray[0] = yyvsp[-3]; cldArray[1] = yyvsp[-2]; cldArray[2]=yyvsp[-1]; cldArray[3]=yyvsp[0]; yyval=createNode("Exp", 4, cldArray);}
#line 1718 "syntax.tab.c"
    break;

  case 76: /* Exp: Exp DOT ID  */
#line 144 "syntax.y"
                 {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Exp", 3, cldArray);}
#line 1724 "syntax.tab.c"
    break;

  case 77: /* Exp: ID  */
#line 145 "syntax.y"
         {cldArray[0] = yyvsp[0]; yyval=createNode("Exp", 1, cldArray);}
#line 1730 "syntax.tab.c"
    break;

  case 78: /* Exp: INT  */
#line 146 "syntax.y"
          {cldArray[0] = yyvsp[0]; yyval=createNode("Exp", 1, cldArray);}
#line 1736 "syntax.tab.c"
    break;

  case 79: /* Exp: FLOAT  */
#line 147 "syntax.y"
            {cldArray[0] = yyvsp[0]; yyval=createNode("Exp", 1, cldArray);}
#line 1742 "syntax.tab.c"
    break;

  case 80: /* Exp: CHAR  */
#line 148 "syntax.y"
           {cldArray[0] = yyvsp[0]; yyval=createNode("Exp", 1, cldArray);}
#line 1748 "syntax.tab.c"
    break;

  case 81: /* Exp: ERROR  */
#line 149 "syntax.y"
            {cldArray[0]=yyvsp[0]; yyval=createNode("Exp", 1, cldArray); isCorrect=0;}
#line 1754 "syntax.tab.c"
    break;

  case 82: /* Args: Exp COMMA Args  */
#line 151 "syntax.y"
                     {cldArray[0] = yyvsp[-2]; cldArray[1] = yyvsp[-1]; cldArray[2]=yyvsp[0]; yyval=createNode("Args", 3, cldArray);}
#line 1760 "syntax.tab.c"
    break;

  case 83: /* Args: Exp  */
#line 152 "syntax.y"
          {cldArray[0] = yyvsp[0]; yyval=createNode("Args", 1, cldArray);}
#line 1766 "syntax.tab.c"
    break;


#line 1770 "syntax.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 154 "syntax.y"

void yyerror(const char *s) {
    printf("Error type B at Line ");
}
int main() {
    yyparse();
}
