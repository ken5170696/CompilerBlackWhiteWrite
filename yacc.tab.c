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
#line 1 "yacc.y"

#include "main.h"
#include "./Utilities/customDS.h"
#include "./Utilities/symbolTable.h"

void yyerror(const char *s);
extern int yylex();
extern int yyparse();

#line 81 "yacc.tab.c"

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

#include "yacc.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_FUN = 3,                        /* FUN  */
  YYSYMBOL_MAIN = 4,                       /* MAIN  */
  YYSYMBOL_VAR = 5,                        /* VAR  */
  YYSYMBOL_PRINT = 6,                      /* PRINT  */
  YYSYMBOL_PRINTLN = 7,                    /* PRINTLN  */
  YYSYMBOL_RET = 8,                        /* RET  */
  YYSYMBOL_IF = 9,                         /* IF  */
  YYSYMBOL_ELSE = 10,                      /* ELSE  */
  YYSYMBOL_WHILE = 11,                     /* WHILE  */
  YYSYMBOL_FOR = 12,                       /* FOR  */
  YYSYMBOL_TO = 13,                        /* TO  */
  YYSYMBOL_INT = 14,                       /* INT  */
  YYSYMBOL_REAL = 15,                      /* REAL  */
  YYSYMBOL_NEWLINE = 16,                   /* NEWLINE  */
  YYSYMBOL_LBRACE = 17,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 18,                    /* RBRACE  */
  YYSYMBOL_LBRACKET = 19,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 20,                  /* RBRACKET  */
  YYSYMBOL_LPAREN = 21,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 22,                    /* RPAREN  */
  YYSYMBOL_SEMICOLON = 23,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 24,                     /* COMMA  */
  YYSYMBOL_ASSIGN = 25,                    /* ASSIGN  */
  YYSYMBOL_COLON = 26,                     /* COLON  */
  YYSYMBOL_INTEGER_CONST = 27,             /* INTEGER_CONST  */
  YYSYMBOL_REAL_CONST = 28,                /* REAL_CONST  */
  YYSYMBOL_IDENTIFIER = 29,                /* IDENTIFIER  */
  YYSYMBOL_STRING_CONST = 30,              /* STRING_CONST  */
  YYSYMBOL_31_ = 31,                       /* '+'  */
  YYSYMBOL_32_ = 32,                       /* '-'  */
  YYSYMBOL_33_ = 33,                       /* '*'  */
  YYSYMBOL_34_ = 34,                       /* '/'  */
  YYSYMBOL_UMINUS = 35,                    /* UMINUS  */
  YYSYMBOL_PAREN = 36,                     /* PAREN  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_program = 38,                   /* program  */
  YYSYMBOL_function = 39,                  /* function  */
  YYSYMBOL_block = 40,                     /* block  */
  YYSYMBOL_41_1 = 41,                      /* $@1  */
  YYSYMBOL_statement_list = 42,            /* statement_list  */
  YYSYMBOL_statement = 43,                 /* statement  */
  YYSYMBOL_variable_declaration = 44,      /* variable_declaration  */
  YYSYMBOL_assignment = 45,                /* assignment  */
  YYSYMBOL_print_statement = 46,           /* print_statement  */
  YYSYMBOL_type = 47,                      /* type  */
  YYSYMBOL_expr = 48,                      /* expr  */
  YYSYMBOL_value = 49,                     /* value  */
  YYSYMBOL_value_list = 50,                /* value_list  */
  YYSYMBOL_value_list_value = 51           /* value_list_value  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   97

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  38
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  82

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   287


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
       2,     2,    33,    31,     2,    32,     2,    34,     2,     2,
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
      25,    26,    27,    28,    29,    30,    35,    36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    39,    39,    45,    51,    60,    60,    76,    85,    96,
     100,   104,   108,   115,   156,   234,   312,   344,   379,   382,
     385,   389,   396,   399,   429,   488,   549,   616,   676,   688,
     695,   701,   710,   719,   734,   742,   753,   756,   767
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
  "\"end of file\"", "error", "\"invalid token\"", "FUN", "MAIN", "VAR",
  "PRINT", "PRINTLN", "RET", "IF", "ELSE", "WHILE", "FOR", "TO", "INT",
  "REAL", "NEWLINE", "LBRACE", "RBRACE", "LBRACKET", "RBRACKET", "LPAREN",
  "RPAREN", "SEMICOLON", "COMMA", "ASSIGN", "COLON", "INTEGER_CONST",
  "REAL_CONST", "IDENTIFIER", "STRING_CONST", "'+'", "'-'", "'*'", "'/'",
  "UMINUS", "PAREN", "$accept", "program", "function", "block", "$@1",
  "statement_list", "statement", "variable_declaration", "assignment",
  "print_statement", "type", "expr", "value", "value_list",
  "value_list_value", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-46)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      34,    16,    55,   -46,    35,   -46,    49,    -3,   -46,    25,
     -46,    -2,    43,    56,    57,    47,    64,    65,    62,   -46,
       4,   -46,   -46,   -46,   -46,    61,    63,   -46,    66,    17,
      17,    17,   -46,   -46,    69,    71,    25,    40,    17,   -46,
     -46,   -46,   -46,    17,    19,   -46,    26,    46,   -46,   -46,
       3,    40,    40,   -46,     0,   -46,    32,   -46,    70,    17,
      17,    17,    17,    72,   -46,   -46,    17,    74,   -46,   -46,
      40,   -46,   -46,     9,     9,   -46,   -46,   -46,    50,   -46,
     -46,   -46
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     0,     1,     0,     0,     5,     0,
       3,     0,    18,    19,     0,     0,     0,     0,     0,    12,
       0,     8,     9,    10,    11,     0,     0,     4,     0,     0,
       0,     0,     6,     7,     0,     0,     0,     0,     0,    32,
      31,    23,    33,     0,     0,    22,     0,     0,    21,    20,
       0,     0,     0,    36,     0,    35,     0,    28,     0,     0,
       0,     0,     0,     0,    15,    13,     0,     0,    37,    30,
       0,    29,    16,    24,    25,    26,    27,    17,     0,    38,
      34,    14
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -46,   -46,   -46,     5,   -46,   -46,    77,   -46,   -46,   -46,
      58,   -30,   -35,   -46,   -45
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,    19,    11,    20,    21,    22,    23,    24,
      14,    44,    45,    54,    55
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      46,    47,    53,    15,    16,    17,    67,    68,    56,    15,
      16,    17,    10,    57,     8,     8,    53,    53,    69,    27,
       4,     8,    32,     9,    70,    80,    65,    18,    66,    73,
      74,    75,    76,    18,    37,    53,    78,     1,    38,    12,
      13,    58,    61,    62,    39,    40,    41,    42,    63,    43,
      59,    60,    61,    62,    71,     5,     6,    59,    60,    61,
      62,    51,    25,    59,    60,    61,    62,    39,    40,    64,
      42,     7,    52,    81,     8,    26,    28,    59,    60,    61,
      62,    59,    60,    61,    62,    29,    30,    31,    34,    48,
      35,    49,    36,    72,    50,    77,    79,    33
};

static const yytype_int8 yycheck[] =
{
      30,    31,    37,     5,     6,     7,    51,    52,    38,     5,
       6,     7,     7,    43,    17,    17,    51,    52,    18,    14,
       4,    17,    18,    26,    24,    70,    23,    29,    25,    59,
      60,    61,    62,    29,    17,    70,    66,     3,    21,    14,
      15,    22,    33,    34,    27,    28,    29,    30,    22,    32,
      31,    32,    33,    34,    22,     0,    21,    31,    32,    33,
      34,    21,    19,    31,    32,    33,    34,    27,    28,    23,
      30,    22,    32,    23,    17,    19,    29,    31,    32,    33,
      34,    31,    32,    33,    34,    21,    21,    25,    27,    20,
      27,    20,    26,    23,    36,    23,    22,    20
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    38,    39,     4,     0,    21,    22,    17,    26,
      40,    41,    14,    15,    47,     5,     6,     7,    29,    40,
      42,    43,    44,    45,    46,    19,    19,    40,    29,    21,
      21,    25,    18,    43,    27,    27,    26,    17,    21,    27,
      28,    29,    30,    32,    48,    49,    48,    48,    20,    20,
      47,    21,    32,    49,    50,    51,    48,    48,    22,    31,
      32,    33,    34,    22,    23,    23,    25,    51,    51,    18,
      24,    22,    23,    48,    48,    48,    48,    23,    48,    22,
      51,    23
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    41,    40,    42,    42,    43,
      43,    43,    43,    44,    44,    45,    46,    46,    47,    47,
      47,    47,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    49,    49,    49,    50,    50,    51,    51,    51
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     5,     7,     0,     4,     2,     1,     1,
       1,     1,     1,     5,     7,     4,     5,     5,     1,     1,
       4,     4,     1,     1,     3,     3,     3,     3,     2,     3,
       3,     1,     1,     1,     3,     1,     1,     2,     3
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
  case 2: /* program: function  */
#line 39 "yacc.y"
             {
        cout << "#include <stdio.h>\n#include \"customVector.h\"\n\n" << (yyvsp[0].cppStr)->str << endl;
    }
#line 1170 "yacc.tab.c"
    break;

  case 3: /* function: FUN MAIN LPAREN RPAREN block  */
#line 45 "yacc.y"
                                 {
        (yyval.cppStr) = new StringWrapper();
        string mainStr = "int main() ";

        (yyval.cppStr)->str = mainStr + (yyvsp[0].cppStr)->str;
    }
#line 1181 "yacc.tab.c"
    break;

  case 4: /* function: FUN MAIN LPAREN RPAREN COLON type block  */
#line 51 "yacc.y"
                                              {
        (yyval.cppStr) = new StringWrapper();
        string mainStr = "int main() ";

        (yyval.cppStr)->str = mainStr + (yyvsp[0].cppStr)->str;
    }
#line 1192 "yacc.tab.c"
    break;

  case 5: /* $@1: %empty  */
#line 60 "yacc.y"
           { push_scope(); }
#line 1198 "yacc.tab.c"
    break;

  case 6: /* block: LBRACE $@1 statement_list RBRACE  */
#line 60 "yacc.y"
                                                   {
        pop_scope(); 
        int scopeCount = get_scope_count();
        char* tabStr = generateTabByScopeTab(scopeCount);

        (yyval.cppStr) = new StringWrapper();
        string statement_listStr = (yyvsp[-1].cppStr)->str;
        (yyval.cppStr)->str += "\n";
        (yyval.cppStr)->str += tabStr;
        (yyval.cppStr)->str += "{\n";
        (yyval.cppStr)->str += statement_listStr;
        (yyval.cppStr)->str += tabStr;
        (yyval.cppStr)->str += "}\n";
    }
#line 1217 "yacc.tab.c"
    break;

  case 7: /* statement_list: statement_list statement  */
#line 76 "yacc.y"
                            {
        int scopeCount = get_scope_count();
        char* tabStr = generateTabByScopeTab(scopeCount);
        
        (yyval.cppStr) = new StringWrapper();
        (yyval.cppStr)->str += (yyvsp[-1].cppStr)->str;
        (yyval.cppStr)->str += tabStr;
        (yyval.cppStr)->str += (yyvsp[0].cppStr)->str;
    }
#line 1231 "yacc.tab.c"
    break;

  case 8: /* statement_list: statement  */
#line 85 "yacc.y"
                {
        int scopeCount = get_scope_count();
        char* tabStr = generateTabByScopeTab(scopeCount);

        (yyval.cppStr) = new StringWrapper();
        (yyval.cppStr)->str += tabStr;
        (yyval.cppStr)->str += (yyvsp[0].cppStr)->str;
    }
#line 1244 "yacc.tab.c"
    break;

  case 9: /* statement: variable_declaration  */
#line 96 "yacc.y"
                             {
        (yyval.cppStr) = new StringWrapper();
        (yyval.cppStr)->str = (yyvsp[0].cppStr)->str;
    }
#line 1253 "yacc.tab.c"
    break;

  case 10: /* statement: assignment  */
#line 100 "yacc.y"
                 {
        (yyval.cppStr) = new StringWrapper();
        (yyval.cppStr)->str = (yyvsp[0].cppStr)->str;
    }
#line 1262 "yacc.tab.c"
    break;

  case 11: /* statement: print_statement  */
#line 104 "yacc.y"
                          {
        (yyval.cppStr) = new StringWrapper();
        (yyval.cppStr)->str = (yyvsp[0].cppStr)->str;
    }
#line 1271 "yacc.tab.c"
    break;

  case 12: /* statement: block  */
#line 108 "yacc.y"
            {
            (yyval.cppStr) = new StringWrapper();
            (yyval.cppStr)->str = (yyvsp[0].cppStr)->str;
    }
#line 1280 "yacc.tab.c"
    break;

  case 13: /* variable_declaration: VAR IDENTIFIER COLON type SEMICOLON  */
#line 115 "yacc.y"
                                        {
        (yyval.cppStr) = new StringWrapper();

        variable var;
        strcpy(var.name, (yyvsp[-3].cppStr)->str.c_str());
        var.type = (yyvsp[-1].type_val).varType;
        var.arrayLength = (yyvsp[-1].type_val).arrayLength;
        if (lookup_variable_with_scope(get_current_table(), (yyvsp[-3].cppStr)->str.c_str())) {
            yyerror("ERROR: duplicate declaration"); 
            YYABORT; 
        } else {
            insert_variable(var);
        }

        if((yyvsp[-1].type_val).varType == INT_TYPE){
            stringstream ss;
            ss << "int " << var.name << ";\n";
            (yyval.cppStr)->str = ss.str();
        }else if((yyvsp[-1].type_val).varType == REAL_TYPE){
            stringstream ss;
            ss << "float " << var.name << ";\n";
            (yyval.cppStr)->str = ss.str();
        }else if((yyvsp[-1].type_val).varType == INT_ARRAY_TYPE){
            var.arrayLength = (yyvsp[-1].type_val).arrayLength;
            var.value.intArr = (int *)malloc(sizeof(int) * var.arrayLength);

            // Return string
            stringstream ss;
            ss << "int " << var.name << "[" << (yyvsp[-1].type_val).arrayLength << "];\n";
            (yyval.cppStr)->str = ss.str();

        }else if((yyvsp[-1].type_val).varType == REAL_ARRAY_TYPE){
            var.arrayLength = (yyvsp[-1].type_val).arrayLength;
            var.value.realArr = (float *)malloc(sizeof(float) * var.arrayLength);
            
            // Return string
            stringstream ss;
            ss << "int " << var.name << "[" << (yyvsp[-1].type_val).arrayLength << "];\n";
            (yyval.cppStr)->str = ss.str();
        }
    }
#line 1326 "yacc.tab.c"
    break;

  case 14: /* variable_declaration: VAR IDENTIFIER COLON type ASSIGN expr SEMICOLON  */
#line 156 "yacc.y"
                                                      {
        (yyval.cppStr) = new StringWrapper();

        variable var;
        strcpy(var.name, (yyvsp[-5].cppStr)->str.c_str());
        var.type = (yyvsp[-3].type_val).varType;
        var.arrayLength = (yyvsp[-3].type_val).arrayLength;
        if (lookup_variable_with_scope(get_current_table(), (yyvsp[-5].cppStr)->str.c_str())) {
            yyerror("ERROR: duplicate declaration"); 
            YYABORT; 
        } else {
            
            if(is_var_type_array((yyvsp[-1].expr_val).type)){
                if((var.type == INT_TYPE || var.type == REAL_TYPE)) {
                    yyerror("ERROR: You cannot asign a const to an array."); 
                    YYABORT; 
                }
                
                if(var.arrayLength < (yyvsp[-1].expr_val).arrayLength) {
                    yyerror("ERROR: Array out of bounds."); 
                    YYABORT; 
                }
                if (var.type == INT_ARRAY_TYPE) {
                    var.value.intArr = (int *)malloc(sizeof(int) * var.arrayLength);
                    for(int i = 0; i < (yyvsp[-1].expr_val).arrayLength; i++){
                        var.value.intArr[i] = (yyvsp[-1].expr_val).value.arrayNum[i];
                    }

                    char* returnStr = getArrayString(var.value.intArr, var.arrayLength);

                    // Return string
                    stringstream ss;
                    ss << "int " << var.name << "[" << (yyvsp[-3].type_val).arrayLength << "] = " << returnStr << ";\n";
                    (yyval.cppStr)->str = ss.str();
                } 
                else if (var.type == REAL_ARRAY_TYPE) {
                    var.value.realArr = (float *)malloc(sizeof(float) * var.arrayLength);
                    for(int i = 0; i < (yyvsp[-1].expr_val).arrayLength; i++){
                        var.value.realArr[i] = (yyvsp[-1].expr_val).value.arrayNum[i];
                    }

                    char* returnStr = getArrayString(var.value.realArr, var.arrayLength);

                    // Return string
                    stringstream ss;
                    ss << "float " << var.name << "[" << (yyvsp[-3].type_val).arrayLength << "] = " << returnStr << ";\n";
                    (yyval.cppStr)->str = ss.str();
                }
            }else {
                if (var.type == INT_TYPE) {
                    if (is_var_type_real((yyvsp[-1].expr_val).type)) {
                        var.value.ival = (yyvsp[-1].expr_val).value.realNum;
                    } else {
                        var.value.ival = (yyvsp[-1].expr_val).value.intNum;
                    }

                    // Return string
                    stringstream ss;
                    ss << "int " << var.name << " = "<<var.value.ival<<";\n";
                    (yyval.cppStr)->str = ss.str();
                } else if (var.type == REAL_TYPE) {
                    if (is_var_type_real((yyvsp[-1].expr_val).type)) {
                        var.value.rval = (yyvsp[-1].expr_val).value.realNum;
                    } else {
                        var.value.rval = (yyvsp[-1].expr_val).value.intNum;
                    }
                    // Return string
                    stringstream ss;
                    ss << "float " << var.name << " = "<<var.value.rval<<";\n";
                    (yyval.cppStr)->str = ss.str();
                }
            }
            insert_variable(var);
        }
    }
#line 1406 "yacc.tab.c"
    break;

  case 15: /* assignment: IDENTIFIER ASSIGN expr SEMICOLON  */
#line 234 "yacc.y"
                                     {
        (yyval.cppStr) = new StringWrapper();

        variable *var = lookup_variable_with_scope(get_current_table(), (yyvsp[-3].cppStr)->str.c_str());
        if (!var) {
            yyerror("Variable not declared"); 
            yyerror((yyvsp[-3].cppStr)->str.c_str()); 
            YYABORT; 
        } else {
            if(is_var_type_array((yyvsp[-1].expr_val).type)){
                yyerror("Error: assigning to an array from an initializer list"); 
                YYABORT; 

                // if((var->type == INT_TYPE || var->type == REAL_TYPE)) {
                //     yyerror("Error: You cannot asign a const to an array."); 
                //     YYABORT; 
                // }
                
                // if(var->arrayLength < $3.arrayLength) {
                //     yyerror("Error: Array out of bounds."); 
                //     YYABORT; 
                // }

                // if (var->type == INT_ARRAY_TYPE) {
                //     var->value.intArr = (int *)malloc(sizeof(int) * var->arrayLength);
                //     for(int i = 0; i < $3.arrayLength; i++){
                //         var->value.intArr[i] = $3.value.arrayNum[i];
                //     }

                //     char* returnStr = getArrayString(var->value.intArr, var->arrayLength);
                //     // Return string
                //     $$ = (char*)malloc(sizeof(var->name) + 12 + sizeof(returnStr));
                //     sprintf($$, "%s = %s;\n", var->name, returnStr);
                // } else if (var->type == REAL_ARRAY_TYPE) {

                //     var->value.realArr = (float *)malloc(sizeof(float) * var->arrayLength);
                //     for(int i = 0; i < $3.arrayLength; i++){
                //         var->value.realArr[i] = $3.value.arrayNum[i];
                //     }

                //     char* returnStr = getArrayString(var->value.realArr, var->arrayLength);
                //     // Return string
                //     $$ = (char*)malloc(sizeof(var->name) + 12 + sizeof(returnStr));
                //     sprintf($$, "%s = %s;\n", var->name, returnStr);
                // }
            }else {
                if((var->type == INT_ARRAY_TYPE || var->type == REAL_ARRAY_TYPE)) {
                    yyerror("You cannot asign an array to a const variable."); 
                    YYABORT; 
                }

                if (var->type == INT_TYPE) {
                    if (is_var_type_real((yyvsp[-1].expr_val).type)) {
                        var->value.ival = (yyvsp[-1].expr_val).value.realNum;
                    } else {
                        var->value.ival = (yyvsp[-1].expr_val).value.intNum;
                    }
                    stringstream ss;
                    ss << var->name << " = " << var->value.ival << ";\n";
                    (yyval.cppStr)->str = ss.str();

                } else if (var->type == REAL_TYPE) {
                    if (is_var_type_real((yyvsp[-1].expr_val).type)) {
                        var->value.rval = (yyvsp[-1].expr_val).value.realNum;
                    } else {
                        var->value.rval = (yyvsp[-1].expr_val).value.intNum;
                    }

                    stringstream ss;
                    ss << var->name << " = " << var->value.rval << ";\n";
                    (yyval.cppStr)->str = ss.str();
                }
            }
        }
    }
#line 1486 "yacc.tab.c"
    break;

  case 16: /* print_statement: PRINT LPAREN expr RPAREN SEMICOLON  */
#line 312 "yacc.y"
                                       { 
        (yyval.cppStr) = new StringWrapper();

    	if((yyvsp[-2].expr_val).type == INT_TYPE){
            stringstream ss;
            ss << "printf(\"%d\"," << getExprStrStr(*((yyvsp[-2].expr_val).exprStr)) << ");\n";
            (yyval.cppStr)->str = ss.str();
        }
    	else if((yyvsp[-2].expr_val).type == REAL_TYPE){ 
            stringstream ss;
            ss << "printf(\"%f\"," << getExprStrStr(*((yyvsp[-2].expr_val).exprStr)) << ");\n";
            (yyval.cppStr)->str = ss.str();
        } 
        else if(is_var_type_array((yyvsp[-2].expr_val).type)){
            char* arrayStr;
            switch((yyvsp[-2].expr_val).type){
            case INT_ARRAY_TYPE:
                arrayStr = getArrayString((yyvsp[-2].expr_val).value.arrayNum, (yyvsp[-2].expr_val).arrayLength);
                break; 
            case REAL_ARRAY_TYPE:
                arrayStr = getArrayString((yyvsp[-2].expr_val).value.arrayNum, (yyvsp[-2].expr_val).arrayLength);
                break; 
            case STRING_TYPE:
                arrayStr = getArrayString((yyvsp[-2].expr_val).value.str);
                break; 
            }
            
                stringstream ss;
                ss << "printArray(" << getExprStrStr(*((yyvsp[-2].expr_val).exprStr)) << ", " << (yyvsp[-2].expr_val).value.arrayNum << ");\n";
                (yyval.cppStr)->str = ss.str();
        }
    }
#line 1523 "yacc.tab.c"
    break;

  case 17: /* print_statement: PRINTLN LPAREN expr RPAREN SEMICOLON  */
#line 344 "yacc.y"
                                           { 
        (yyval.cppStr) = new StringWrapper();

    	if((yyvsp[-2].expr_val).type == INT_TYPE){
            stringstream ss;
            ss << "printf(\"%d\\n\"," << getExprStrStr(*((yyvsp[-2].expr_val).exprStr)) << ");\n";
            (yyval.cppStr)->str = ss.str();
        }
    	else if((yyvsp[-2].expr_val).type == REAL_TYPE){ 
            stringstream ss;
            ss << "printf(\"%f\\n\"," << getExprStrStr(*((yyvsp[-2].expr_val).exprStr)) << ");\n";
            (yyval.cppStr)->str = ss.str();
        } 
        else if(is_var_type_array((yyvsp[-2].expr_val).type)){
            char* arrayStr;
            switch((yyvsp[-2].expr_val).type){
            case INT_ARRAY_TYPE:
                arrayStr = getArrayString((yyvsp[-2].expr_val).value.arrayNum, (yyvsp[-2].expr_val).arrayLength);
                break; 
            case REAL_ARRAY_TYPE:
                arrayStr = getArrayString((yyvsp[-2].expr_val).value.arrayNum, (yyvsp[-2].expr_val).arrayLength);
                break; 
            case STRING_TYPE:
                arrayStr = getArrayString((yyvsp[-2].expr_val).value.str);
                break; 
            }
            
                stringstream ss;
                ss << "printArrayln(" << getExprStrStr(*((yyvsp[-2].expr_val).exprStr)) << ", " << (yyvsp[-2].expr_val).arrayLength << ");\n";
                (yyval.cppStr)->str = ss.str();
        }
    }
#line 1560 "yacc.tab.c"
    break;

  case 18: /* type: INT  */
#line 379 "yacc.y"
        { 
        (yyval.type_val).varType = INT_TYPE; 
    }
#line 1568 "yacc.tab.c"
    break;

  case 19: /* type: REAL  */
#line 382 "yacc.y"
           { 
        (yyval.type_val).varType = REAL_TYPE; 
    }
#line 1576 "yacc.tab.c"
    break;

  case 20: /* type: REAL LBRACKET INTEGER_CONST RBRACKET  */
#line 385 "yacc.y"
                                           { 
        (yyval.type_val).varType = REAL_ARRAY_TYPE; 
        (yyval.type_val).arrayLength = (yyvsp[-1].intNum); 
    }
#line 1585 "yacc.tab.c"
    break;

  case 21: /* type: INT LBRACKET INTEGER_CONST RBRACKET  */
#line 389 "yacc.y"
                                          { 
        (yyval.type_val).varType = INT_ARRAY_TYPE; 
        (yyval.type_val).arrayLength = (yyvsp[-1].intNum); 
    }
#line 1594 "yacc.tab.c"
    break;

  case 22: /* expr: value  */
#line 396 "yacc.y"
          { 
        (yyval.expr_val) = (yyvsp[0].expr_val); 
    }
#line 1602 "yacc.tab.c"
    break;

  case 23: /* expr: IDENTIFIER  */
#line 399 "yacc.y"
                 {
        variable *var = lookup_variable_with_scope(get_current_table(), (yyvsp[0].cppStr)->str.c_str());
        if (!var) {
            yyerror("ERROR: Variable not declared");
            yyerror((yyvsp[0].cppStr)->str.c_str()); 
            YYABORT; 
        } else {
            if (var->type == INT_TYPE) {
                (yyval.expr_val).type = INT_TYPE;
                (yyval.expr_val).value.intNum = var->value.ival;
            } else if (var->type == REAL_TYPE) {
                (yyval.expr_val).type = REAL_TYPE;
                (yyval.expr_val).value.realNum = var->value.rval;
            } else if (var->type == INT_ARRAY_TYPE) {
                (yyval.expr_val).type = INT_ARRAY_TYPE;
                (yyval.expr_val).arrayLength = var->arrayLength;
                (yyval.expr_val).value.arrayNum = (float*)malloc(var->arrayLength * sizeof(float));
                for(int i = 0; i < (yyval.expr_val).arrayLength; i++)
                    (yyval.expr_val).value.arrayNum[i] = var->value.intArr[i];
            } else if (var->type == REAL_ARRAY_TYPE) {
                (yyval.expr_val).type = REAL_ARRAY_TYPE;
                (yyval.expr_val).arrayLength = var->arrayLength;
                (yyval.expr_val).value.arrayNum = (float*)malloc(var->arrayLength * sizeof(float));
                for(int i = 0; i < (yyval.expr_val).arrayLength; i++)
                    (yyval.expr_val).value.arrayNum[i] = var->value.realArr[i];
            }
        }
        (yyval.expr_val).exprStr = new vector<string>();
        (yyval.expr_val).exprStr->push_back((yyvsp[0].cppStr)->str.c_str());
    }
#line 1637 "yacc.tab.c"
    break;

  case 24: /* expr: expr '+' expr  */
#line 429 "yacc.y"
                    {
        int isAllArray = is_var_type_array((yyvsp[-2].expr_val).type) + is_var_type_array((yyvsp[0].expr_val).type);

        if(isAllArray == 1){
            yyerror("ERROR: expr type mismatch."); 
            YYABORT; 
        }

        if(isAllArray == 2) {
            
            if((yyvsp[-2].expr_val).arrayLength != (yyvsp[0].expr_val).arrayLength){
                yyerror("ERROR: mismatched dimensions"); 
                YYABORT; 
            }
            int maxLen = MAX((yyvsp[-2].expr_val).arrayLength, (yyvsp[0].expr_val).arrayLength);
            (yyval.expr_val).value.arrayNum = (float *)(malloc((maxLen) * sizeof(float)));
            
            if(is_var_type_real((yyvsp[-2].expr_val).type) || is_var_type_real((yyvsp[0].expr_val).type)){
                (yyval.expr_val).type = REAL_ARRAY_TYPE;
            }else{
                (yyval.expr_val).type = INT_ARRAY_TYPE;
            }

            for(int i = 0; i < maxLen; i++) {
                (yyval.expr_val).value.arrayNum[i] =  (i < (yyvsp[-2].expr_val).arrayLength) ? (yyvsp[-2].expr_val).value.arrayNum[i] : 0;
                (yyval.expr_val).value.arrayNum[i] += (i < (yyvsp[0].expr_val).arrayLength) ? (yyvsp[0].expr_val).value.arrayNum[i] : 0;
            }

        } else {
            float v1 = is_var_type_real((yyvsp[-2].expr_val).type) ? (yyvsp[-2].expr_val).value.realNum : (yyvsp[-2].expr_val).value.intNum;
            float v2 = is_var_type_real((yyvsp[0].expr_val).type) ? (yyvsp[0].expr_val).value.realNum : (yyvsp[0].expr_val).value.intNum;

            if(is_var_type_real((yyvsp[-2].expr_val).type) || is_var_type_real((yyvsp[0].expr_val).type)){
                (yyval.expr_val).type = REAL_TYPE;
                (yyval.expr_val).value.realNum = (v1 + v2);
            }else{
                (yyval.expr_val).type = INT_TYPE;
                (yyval.expr_val).value.intNum = (v1 + v2);
            }
        }
        (yyval.expr_val).exprStr = new vector<string>();

        if(isAllArray == 2 ){
            (yyval.expr_val).exprStr->push_back("addArray(");
            (yyval.expr_val).exprStr->insert((yyval.expr_val).exprStr->end(),(yyvsp[-2].expr_val).exprStr->begin(),(yyvsp[-2].expr_val).exprStr->end());
            (yyval.expr_val).exprStr->push_back(",");
            (yyval.expr_val).exprStr->insert((yyval.expr_val).exprStr->end(),(yyvsp[0].expr_val).exprStr->begin(),(yyvsp[0].expr_val).exprStr->end());
            (yyval.expr_val).exprStr->push_back(",");
            (yyval.expr_val).exprStr->push_back(to_string((yyvsp[-2].expr_val).arrayLength));
            (yyval.expr_val).exprStr->push_back(",");
            (yyval.expr_val).exprStr->push_back(to_string((yyvsp[0].expr_val).arrayLength));
            (yyval.expr_val).exprStr->push_back(")");

        } else {
            (yyval.expr_val).exprStr->insert((yyval.expr_val).exprStr->end(),(yyvsp[-2].expr_val).exprStr->begin(),(yyvsp[-2].expr_val).exprStr->end());
            (yyval.expr_val).exprStr->push_back("+");
            (yyval.expr_val).exprStr->insert((yyval.expr_val).exprStr->end(),(yyvsp[0].expr_val).exprStr->begin(),(yyvsp[0].expr_val).exprStr->end());
        }
    }
#line 1701 "yacc.tab.c"
    break;

  case 25: /* expr: expr '-' expr  */
#line 488 "yacc.y"
                    {
        int isAllArray = is_var_type_array((yyvsp[-2].expr_val).type) + is_var_type_array((yyvsp[0].expr_val).type);

        if(isAllArray == 1){
            yyerror("ERROR: expr type mismatch."); 
            YYABORT; 
        }

        if(isAllArray == 2) {
            
            if((yyvsp[-2].expr_val).arrayLength != (yyvsp[0].expr_val).arrayLength){
                yyerror("ERROR: mismatched dimensions"); 
                YYABORT; 
            }
            // vector math
            int maxLen = MAX((yyvsp[-2].expr_val).arrayLength, (yyvsp[0].expr_val).arrayLength);
            (yyval.expr_val).value.arrayNum = (float *)(malloc((maxLen) * sizeof(float)));
            
            if(is_var_type_real((yyvsp[-2].expr_val).type) || is_var_type_real((yyvsp[0].expr_val).type)){
                (yyval.expr_val).type = REAL_ARRAY_TYPE;
            }else{
                (yyval.expr_val).type = INT_ARRAY_TYPE;
            }

            for(int i = 0; i < maxLen; i++) {
                (yyval.expr_val).value.arrayNum[i] =  (i < (yyvsp[-2].expr_val).arrayLength) ? (yyvsp[-2].expr_val).value.arrayNum[i] : 0;
                (yyval.expr_val).value.arrayNum[i] -= (i < (yyvsp[0].expr_val).arrayLength) ? (yyvsp[0].expr_val).value.arrayNum[i] : 0;
            }

        } else {
            // Non vector math
            float v1 = is_var_type_real((yyvsp[-2].expr_val).type) ? (yyvsp[-2].expr_val).value.realNum : (yyvsp[-2].expr_val).value.intNum;
            float v2 = is_var_type_real((yyvsp[0].expr_val).type) ? (yyvsp[0].expr_val).value.realNum : (yyvsp[0].expr_val).value.intNum;

            if(is_var_type_real((yyvsp[-2].expr_val).type) || is_var_type_real((yyvsp[0].expr_val).type)){
                (yyval.expr_val).type = REAL_TYPE;
                (yyval.expr_val).value.realNum = (v1 - v2);
            }else{
                (yyval.expr_val).type = INT_TYPE;
                (yyval.expr_val).value.intNum = (v1 - v2);
            }
        }

        (yyval.expr_val).exprStr = new vector<string>();
        
        if(isAllArray == 2 ){
            (yyval.expr_val).exprStr->push_back("subArray(");
            (yyval.expr_val).exprStr->insert((yyval.expr_val).exprStr->end(),(yyvsp[-2].expr_val).exprStr->begin(),(yyvsp[-2].expr_val).exprStr->end());
            (yyval.expr_val).exprStr->push_back(",");
            (yyval.expr_val).exprStr->insert((yyval.expr_val).exprStr->end(),(yyvsp[0].expr_val).exprStr->begin(),(yyvsp[0].expr_val).exprStr->end());
            (yyval.expr_val).exprStr->push_back(",");
            (yyval.expr_val).exprStr->push_back(to_string((yyvsp[-2].expr_val).arrayLength));
            (yyval.expr_val).exprStr->push_back(",");
            (yyval.expr_val).exprStr->push_back(to_string((yyvsp[0].expr_val).arrayLength));
            (yyval.expr_val).exprStr->push_back(")");
        } else {
            (yyval.expr_val).exprStr->insert((yyval.expr_val).exprStr->end(),(yyvsp[-2].expr_val).exprStr->begin(),(yyvsp[-2].expr_val).exprStr->end());
            (yyval.expr_val).exprStr->push_back("-");
            (yyval.expr_val).exprStr->insert((yyval.expr_val).exprStr->end(),(yyvsp[0].expr_val).exprStr->begin(),(yyvsp[0].expr_val).exprStr->end());
        }
    }
#line 1767 "yacc.tab.c"
    break;

  case 26: /* expr: expr '*' expr  */
#line 549 "yacc.y"
                    {
        int isAllArray = is_var_type_array((yyvsp[-2].expr_val).type) + is_var_type_array((yyvsp[0].expr_val).type);

        if(isAllArray == 1){
            yyerror("ERROR: expr type mismatch."); 
            YYABORT; 
        }

        if(isAllArray == 2) {

            
            if((yyvsp[-2].expr_val).arrayLength != (yyvsp[0].expr_val).arrayLength){
                yyerror("ERROR: mismatched dimensions"); 
                YYABORT; 
            }

            // vector math
            int maxLen = MAX((yyvsp[-2].expr_val).arrayLength, (yyvsp[0].expr_val).arrayLength);

            // vector * vector = number
            float result = 0;
            for(int i = 0; i < maxLen; i++) {
                float v1 =  (i < (yyvsp[-2].expr_val).arrayLength) ? (yyvsp[-2].expr_val).value.arrayNum[i] : 0;
                float v2 =  (i < (yyvsp[0].expr_val).arrayLength) ? (yyvsp[0].expr_val).value.arrayNum[i] : 0;
                result += v1 * v2;
            }

            if(is_var_type_real((yyvsp[-2].expr_val).type) || is_var_type_real((yyvsp[0].expr_val).type)){
                (yyval.expr_val).type = REAL_TYPE;
                (yyval.expr_val).value.realNum = result;
            }else{
                (yyval.expr_val).type = INT_TYPE;
                (yyval.expr_val).value.intNum = result;
            }

        } else {
            // Non vector math
            float v1 = is_var_type_real((yyvsp[-2].expr_val).type) ? (yyvsp[-2].expr_val).value.realNum : (yyvsp[-2].expr_val).value.intNum;
            float v2 = is_var_type_real((yyvsp[0].expr_val).type) ? (yyvsp[0].expr_val).value.realNum : (yyvsp[0].expr_val).value.intNum;

            if(is_var_type_real((yyvsp[-2].expr_val).type) || is_var_type_real((yyvsp[0].expr_val).type)){
                (yyval.expr_val).type = REAL_TYPE;
                (yyval.expr_val).value.realNum = (v1 * v2);
            }else{
                (yyval.expr_val).type = INT_TYPE;
                (yyval.expr_val).value.intNum = (v1 * v2);
            }
        }

        (yyval.expr_val).exprStr = new vector<string>();
        
        if(isAllArray == 2 ){
            (yyval.expr_val).exprStr->push_back("dotArray(");
            (yyval.expr_val).exprStr->insert((yyval.expr_val).exprStr->end(),(yyvsp[-2].expr_val).exprStr->begin(),(yyvsp[-2].expr_val).exprStr->end());
            (yyval.expr_val).exprStr->push_back(",");
            (yyval.expr_val).exprStr->insert((yyval.expr_val).exprStr->end(),(yyvsp[0].expr_val).exprStr->begin(),(yyvsp[0].expr_val).exprStr->end());
            (yyval.expr_val).exprStr->push_back(",");
            (yyval.expr_val).exprStr->push_back(to_string((yyvsp[-2].expr_val).arrayLength));
            (yyval.expr_val).exprStr->push_back(",");
            (yyval.expr_val).exprStr->push_back(to_string((yyvsp[0].expr_val).arrayLength));
            (yyval.expr_val).exprStr->push_back(")");
        } else {
            (yyval.expr_val).exprStr->insert((yyval.expr_val).exprStr->end(),(yyvsp[-2].expr_val).exprStr->begin(),(yyvsp[-2].expr_val).exprStr->end());
            (yyval.expr_val).exprStr->push_back("*");
            (yyval.expr_val).exprStr->insert((yyval.expr_val).exprStr->end(),(yyvsp[0].expr_val).exprStr->begin(),(yyvsp[0].expr_val).exprStr->end());
        }
    }
#line 1839 "yacc.tab.c"
    break;

  case 27: /* expr: expr '/' expr  */
#line 616 "yacc.y"
                    {
        int isAllArray = is_var_type_array((yyvsp[-2].expr_val).type) + is_var_type_array((yyvsp[0].expr_val).type);

        if(isAllArray == 1){
            yyerror("ERROR: expr type mismatch."); 
            YYABORT; 
        }

        if(isAllArray == 2) {
            
            if((yyvsp[-2].expr_val).arrayLength != (yyvsp[0].expr_val).arrayLength){
                yyerror("ERROR: mismatched dimensions"); 
                YYABORT; 
            }
            // vector math
            int maxLen = MAX((yyvsp[-2].expr_val).arrayLength, (yyvsp[0].expr_val).arrayLength);

            // vector * vector = number
            float result = 0;
            for(int i = 0; i < maxLen; i++) {
                float v1 =  (i < (yyvsp[-2].expr_val).arrayLength) ? (yyvsp[-2].expr_val).value.arrayNum[i] : 0;
                float v2 =  (i < (yyvsp[0].expr_val).arrayLength) ? (yyvsp[0].expr_val).value.arrayNum[i] : 0;
                if (v2 == 0.0) { 
                    yyerror("Error: divisor cannot be zero!"); 
                    YYABORT; 
                }
                result += v1 / v2;
            }

            if(is_var_type_real((yyvsp[-2].expr_val).type) || is_var_type_real((yyvsp[0].expr_val).type)){
                (yyval.expr_val).type = REAL_TYPE;
                (yyval.expr_val).value.realNum = result;
            }else{
                (yyval.expr_val).type = INT_TYPE;
                (yyval.expr_val).value.intNum = result;
            }

        } else {
            float v1 = is_var_type_real((yyvsp[-2].expr_val).type) ? (yyvsp[-2].expr_val).value.realNum : (yyvsp[-2].expr_val).value.intNum;
            float v2 = is_var_type_real((yyvsp[0].expr_val).type) ? (yyvsp[0].expr_val).value.realNum : (yyvsp[0].expr_val).value.intNum;
                
            if (v2 == 0.0) { 
                yyerror("Error: divisor cannot be zero!"); 
                YYABORT; 
            } else { 
                if(is_var_type_real((yyvsp[-2].expr_val).type) || is_var_type_real((yyvsp[0].expr_val).type)){
                    (yyval.expr_val).type = REAL_TYPE;
                    (yyval.expr_val).value.realNum = (v1 / v2);
                }else{
                    (yyval.expr_val).type = INT_TYPE;
                    (yyval.expr_val).value.intNum = (v1 / v2);
                }
            } 
        }

        (yyval.expr_val).exprStr = new vector<string>();
        (yyval.expr_val).exprStr->insert((yyval.expr_val).exprStr->end(),(yyvsp[-2].expr_val).exprStr->begin(),(yyvsp[-2].expr_val).exprStr->end());
        (yyval.expr_val).exprStr->push_back("/");
        (yyval.expr_val).exprStr->insert((yyval.expr_val).exprStr->end(),(yyvsp[0].expr_val).exprStr->begin(),(yyvsp[0].expr_val).exprStr->end());
    }
#line 1904 "yacc.tab.c"
    break;

  case 28: /* expr: '-' expr  */
#line 676 "yacc.y"
                            { 
        if(is_var_type_real((yyvsp[0].expr_val).type) && !is_var_type_array((yyvsp[0].expr_val).type)){
            (yyval.expr_val).value.realNum = -(yyvsp[0].expr_val).value.realNum;
        }
        else{
            (yyval.expr_val).value.intNum = -(yyvsp[0].expr_val).value.intNum;
        }
        (yyval.expr_val).type = (yyvsp[0].expr_val).type;
        (yyval.expr_val).exprStr = new vector<string>();
        (yyval.expr_val).exprStr->push_back("-");
        (yyval.expr_val).exprStr->insert((yyval.expr_val).exprStr->end(),(yyvsp[0].expr_val).exprStr->begin(),(yyvsp[0].expr_val).exprStr->end());
    }
#line 1921 "yacc.tab.c"
    break;

  case 29: /* expr: LPAREN expr RPAREN  */
#line 688 "yacc.y"
                                     {
        (yyval.expr_val) = (yyvsp[-1].expr_val); 
        (yyval.expr_val).exprStr = new vector<string>();
        (yyval.expr_val).exprStr->push_back("(");
        (yyval.expr_val).exprStr->insert((yyval.expr_val).exprStr->end(),(yyvsp[-1].expr_val).exprStr->begin(),(yyvsp[-1].expr_val).exprStr->end());
        (yyval.expr_val).exprStr->push_back(")");
    }
#line 1933 "yacc.tab.c"
    break;

  case 30: /* expr: LBRACE value_list RBRACE  */
#line 695 "yacc.y"
                               {
        (yyval.expr_val) = (yyvsp[-1].expr_val); 
    }
#line 1941 "yacc.tab.c"
    break;

  case 31: /* value: REAL_CONST  */
#line 701 "yacc.y"
               { 
        (yyval.expr_val).value.realNum = (yyvsp[0].realNum); 
        (yyval.expr_val).type = REAL_TYPE;
        
        stringstream ss;
        ss << (yyvsp[0].realNum);
        (yyval.expr_val).exprStr = new vector<string>();
        (yyval.expr_val).exprStr->push_back(ss.str());
    }
#line 1955 "yacc.tab.c"
    break;

  case 32: /* value: INTEGER_CONST  */
#line 710 "yacc.y"
                    { 
        (yyval.expr_val).value.intNum = (float)(yyvsp[0].intNum);  
        (yyval.expr_val).type = INT_TYPE;

        stringstream ss;
        ss << (yyvsp[0].intNum);
        (yyval.expr_val).exprStr = new vector<string>();
        (yyval.expr_val).exprStr->push_back(ss.str());
    }
#line 1969 "yacc.tab.c"
    break;

  case 33: /* value: STRING_CONST  */
#line 719 "yacc.y"
                   {  
        (yyval.expr_val).value.str = (char *)malloc(strlen((yyvsp[0].cppStr)->str.c_str()));
        strcpy((yyval.expr_val).value.str,((yyvsp[0].cppStr)->str.c_str() + 1)); 
        (yyval.expr_val).value.str[strlen((yyval.expr_val).value.str) - 1] = '\0';
        
        (yyval.expr_val).type = STRING_TYPE;
        
        stringstream ss;
        ss << (yyvsp[0].cppStr)->str.c_str();
        (yyval.expr_val).exprStr = new vector<string>();
        (yyval.expr_val).exprStr->push_back(ss.str());
    }
#line 1986 "yacc.tab.c"
    break;

  case 34: /* value_list: value_list COMMA value_list_value  */
#line 734 "yacc.y"
                                      {
        const int len = (yyvsp[-2].expr_val).arrayLength + 1;
        float* fPtr = (float *)(realloc((yyvsp[-2].expr_val).value.arrayNum, (len) * sizeof(float)));
        (yyval.expr_val).value.arrayNum = fPtr;
        (yyval.expr_val).value.arrayNum[len - 1] = is_var_type_real((yyvsp[0].expr_val).type) ? (yyvsp[0].expr_val).value.realNum : (yyvsp[0].expr_val).value.intNum;
        (yyval.expr_val).arrayLength = len;
        (yyval.expr_val).type = is_var_type_real((yyvsp[0].expr_val).type) ? REAL_ARRAY_TYPE : INT_ARRAY_TYPE;
    }
#line 1999 "yacc.tab.c"
    break;

  case 35: /* value_list: value_list_value  */
#line 742 "yacc.y"
                       {
        (yyval.expr_val).value.arrayNum = (float *)malloc(sizeof(float));
        
        (yyval.expr_val).value.arrayNum[0] = is_var_type_real((yyvsp[0].expr_val).type) ? (yyvsp[0].expr_val).value.realNum : (yyvsp[0].expr_val).value.intNum;
        (yyval.expr_val).arrayLength = 1;
        (yyval.expr_val).type = is_var_type_real((yyvsp[0].expr_val).type) ? REAL_ARRAY_TYPE : INT_ARRAY_TYPE;
    }
#line 2011 "yacc.tab.c"
    break;

  case 36: /* value_list_value: value  */
#line 753 "yacc.y"
          { 
        (yyval.expr_val) = (yyvsp[0].expr_val); 
    }
#line 2019 "yacc.tab.c"
    break;

  case 37: /* value_list_value: '-' value_list_value  */
#line 756 "yacc.y"
                                        { 
        if(!is_var_type_array((yyvsp[0].expr_val).type)){
            if(is_var_type_real((yyvsp[0].expr_val).type)){
                (yyval.expr_val).value.realNum = -(yyvsp[0].expr_val).value.realNum;
            }
            else{
                (yyval.expr_val).value.intNum = -(yyvsp[0].expr_val).value.intNum;
            }
            (yyval.expr_val).type = (yyvsp[0].expr_val).type;
        }
    }
#line 2035 "yacc.tab.c"
    break;

  case 38: /* value_list_value: LPAREN value_list_value RPAREN  */
#line 767 "yacc.y"
                                     { 
        if(is_var_type_real((yyvsp[-1].expr_val).type))
            (yyval.expr_val).value.realNum = (yyvsp[-1].expr_val).value.realNum;
        else
            (yyval.expr_val).value.intNum = (yyvsp[-1].expr_val).value.intNum;
        (yyval.expr_val).type = (yyvsp[-1].expr_val).type;
    }
#line 2047 "yacc.tab.c"
    break;


#line 2051 "yacc.tab.c"

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

#line 775 "yacc.y"


void yyerror(const char *s) {
    cerr << s << endl;
}
