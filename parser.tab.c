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
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Importamos tu lógica rústica de la tabla de símbolos */
#include "tabla_de_simbolos.c"

void yyerror(const char *s);
int yylex(void); 

int tipo_actual = 0;
int es_constante_actual = 0;




extern int yylineno; //contador de lineas

extern FILE *yyin; // Variable que usa Lex para leer la entrada         
FILE *yyout_py;    // Nuestra variable para escribir la salida Python 
int nivel_indentacion = 0; 
void imprimir_indentacion() {
    for (int i = 0; i < nivel_indentacion; i++) {
        fprintf(yyout_py, "    "); // Imprime 4 espacios por nivel
    }
}


#line 101 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_WHILE = 5,                      /* WHILE  */
  YYSYMBOL_RETURN = 6,                     /* RETURN  */
  YYSYMBOL_INT = 7,                        /* INT  */
  YYSYMBOL_FLOAT = 8,                      /* FLOAT  */
  YYSYMBOL_CHAR = 9,                       /* CHAR  */
  YYSYMBOL_CONST = 10,                     /* CONST  */
  YYSYMBOL_DOUBLE = 11,                    /* DOUBLE  */
  YYSYMBOL_FOR = 12,                       /* FOR  */
  YYSYMBOL_SWITCH = 13,                    /* SWITCH  */
  YYSYMBOL_CASE = 14,                      /* CASE  */
  YYSYMBOL_VOID = 15,                      /* VOID  */
  YYSYMBOL_MAYOR_IGUAL = 16,               /* MAYOR_IGUAL  */
  YYSYMBOL_IGUAL_IGUAL = 17,               /* IGUAL_IGUAL  */
  YYSYMBOL_MENOR_IGUAL = 18,               /* MENOR_IGUAL  */
  YYSYMBOL_BREAK = 19,                     /* BREAK  */
  YYSYMBOL_DEFAULT = 20,                   /* DEFAULT  */
  YYSYMBOL_ID = 21,                        /* ID  */
  YYSYMBOL_NUMERO = 22,                    /* NUMERO  */
  YYSYMBOL_23_ = 23,                       /* '+'  */
  YYSYMBOL_24_ = 24,                       /* '-'  */
  YYSYMBOL_25_ = 25,                       /* '*'  */
  YYSYMBOL_26_ = 26,                       /* '/'  */
  YYSYMBOL_27_ = 27,                       /* '{'  */
  YYSYMBOL_28_ = 28,                       /* '}'  */
  YYSYMBOL_29_ = 29,                       /* ';'  */
  YYSYMBOL_30_ = 30,                       /* ','  */
  YYSYMBOL_31_ = 31,                       /* '='  */
  YYSYMBOL_32_ = 32,                       /* '('  */
  YYSYMBOL_33_ = 33,                       /* ')'  */
  YYSYMBOL_34_ = 34,                       /* '>'  */
  YYSYMBOL_35_ = 35,                       /* '<'  */
  YYSYMBOL_36_ = 36,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_programa = 38,                  /* programa  */
  YYSYMBOL_bloque = 39,                    /* bloque  */
  YYSYMBOL_40_1 = 40,                      /* $@1  */
  YYSYMBOL_instrucciones = 41,             /* instrucciones  */
  YYSYMBOL_instruccion = 42,               /* instruccion  */
  YYSYMBOL_declaracion = 43,               /* declaracion  */
  YYSYMBOL_for_init = 44,                  /* for_init  */
  YYSYMBOL_asignacion = 45,                /* asignacion  */
  YYSYMBOL_prefijo_declaracion = 46,       /* prefijo_declaracion  */
  YYSYMBOL_tipo = 47,                      /* tipo  */
  YYSYMBOL_declarar_lista_ids = 48,        /* declarar_lista_ids  */
  YYSYMBOL_lista_asignaciones = 49,        /* lista_asignaciones  */
  YYSYMBOL_asignacion_unitaria = 50,       /* asignacion_unitaria  */
  YYSYMBOL_loop = 51,                      /* loop  */
  YYSYMBOL_52_2 = 52,                      /* $@2  */
  YYSYMBOL_53_3 = 53,                      /* $@3  */
  YYSYMBOL_condicion_loop = 54,            /* condicion_loop  */
  YYSYMBOL_loop_consecuencia = 55,         /* loop_consecuencia  */
  YYSYMBOL_expresion = 56,                 /* expresion  */
  YYSYMBOL_condicionales = 57,             /* condicionales  */
  YYSYMBOL_58_4 = 58,                      /* $@4  */
  YYSYMBOL_59_5 = 59,                      /* $@5  */
  YYSYMBOL_60_6 = 60,                      /* $@6  */
  YYSYMBOL_61_7 = 61,                      /* $@7  */
  YYSYMBOL_62_8 = 62,                      /* $@8  */
  YYSYMBOL_bloque_else = 63,               /* bloque_else  */
  YYSYMBOL_64_9 = 64,                      /* $@9  */
  YYSYMBOL_65_10 = 65,                     /* $@10  */
  YYSYMBOL_66_11 = 66,                     /* $@11  */
  YYSYMBOL_67_12 = 67,                     /* $@12  */
  YYSYMBOL_switch_cases = 68,              /* switch_cases  */
  YYSYMBOL_69_13 = 69,                     /* $@13  */
  YYSYMBOL_70_14 = 70,                     /* $@14  */
  YYSYMBOL_71_15 = 71,                     /* $@15  */
  YYSYMBOL_condicion_IF = 72,              /* condicion_IF  */
  YYSYMBOL_declaracion_variables_funcion = 73, /* declaracion_variables_funcion  */
  YYSYMBOL_lista_parametros = 74,          /* lista_parametros  */
  YYSYMBOL_75_16 = 75,                     /* $@16  */
  YYSYMBOL_parametro = 76,                 /* parametro  */
  YYSYMBOL_funcion_void = 77,              /* funcion_void  */
  YYSYMBOL_78_17 = 78,                     /* $@17  */
  YYSYMBOL_79_18 = 79,                     /* $@18  */
  YYSYMBOL_funcion_NO_void = 80,           /* funcion_NO_void  */
  YYSYMBOL_81_19 = 81,                     /* $@19  */
  YYSYMBOL_82_20 = 82                      /* $@20  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   410

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  201

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   277


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
      32,    33,    25,    23,    30,    24,     2,    26,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    36,    29,
      35,    31,    34,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    27,     2,    28,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    51,    51,    54,    54,    73,    74,    77,    78,    79,
      80,    81,    82,    83,    86,    87,    90,    93,    94,    97,
      99,   100,   103,   104,   105,   106,   109,   125,   141,   158,
     177,   178,   181,   191,   201,   211,   221,   231,   243,   243,
     263,   263,   275,   282,   288,   294,   300,   306,   312,   320,
     329,   340,   351,   365,   378,   383,   389,   395,   401,   409,
     412,   415,   409,   418,   420,   418,   433,   438,   442,   433,
     446,   446,   456,   459,   467,   459,   470,   470,   479,   486,
     489,   494,   498,   502,   506,   510,   514,   520,   521,   524,
     525,   525,   532,   549,   560,   549,   570,   581,   570
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
  "\"end of file\"", "error", "\"invalid token\"", "IF", "ELSE", "WHILE",
  "RETURN", "INT", "FLOAT", "CHAR", "CONST", "DOUBLE", "FOR", "SWITCH",
  "CASE", "VOID", "MAYOR_IGUAL", "IGUAL_IGUAL", "MENOR_IGUAL", "BREAK",
  "DEFAULT", "ID", "NUMERO", "'+'", "'-'", "'*'", "'/'", "'{'", "'}'",
  "';'", "','", "'='", "'('", "')'", "'>'", "'<'", "':'", "$accept",
  "programa", "bloque", "$@1", "instrucciones", "instruccion",
  "declaracion", "for_init", "asignacion", "prefijo_declaracion", "tipo",
  "declarar_lista_ids", "lista_asignaciones", "asignacion_unitaria",
  "loop", "$@2", "$@3", "condicion_loop", "loop_consecuencia", "expresion",
  "condicionales", "$@4", "$@5", "$@6", "$@7", "$@8", "bloque_else", "$@9",
  "$@10", "$@11", "$@12", "switch_cases", "$@13", "$@14", "$@15",
  "condicion_IF", "declaracion_variables_funcion", "lista_parametros",
  "$@16", "parametro", "funcion_void", "$@17", "$@18", "funcion_NO_void",
  "$@19", "$@20", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-147)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-80)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -147,    17,   381,  -147,   -28,    -5,  -147,  -147,  -147,    28,
    -147,  -147,     8,    12,     7,    38,    23,  -147,  -147,  -147,
    -147,  -147,  -147,    42,    53,    15,  -147,  -147,  -147,  -147,
    -147,  -147,    30,    44,  -147,    24,    45,    30,    49,    57,
      61,    30,    80,    84,  -147,    39,    74,  -147,   122,    30,
    -147,  -147,    30,    75,    30,  -147,    86,     5,    97,  -147,
    -147,  -147,    69,  -147,  -147,   146,  -147,  -147,  -147,    48,
      85,   100,    30,    30,    30,    90,    69,    81,  -147,    30,
    -147,  -147,  -147,   120,  -147,   120,    30,    30,    30,    30,
      30,    30,  -147,  -147,   110,   110,  -147,  -147,    30,   115,
      79,   112,   126,   117,   118,  -147,   127,    69,    69,    69,
      69,    69,    69,   135,  -147,    69,     1,    30,    30,    30,
      30,    30,    30,  -147,  -147,  -147,  -147,  -147,  -147,   173,
     -12,   139,   131,    69,    69,    69,    69,    69,    69,     4,
     138,   120,   141,   200,  -147,   143,    30,   150,   145,     4,
      30,   151,   149,  -147,  -147,  -147,  -147,  -147,    69,  -147,
    -147,  -147,   -16,  -147,  -147,   227,   254,   175,   277,  -147,
    -147,  -147,    30,   186,  -147,  -147,  -147,   381,   113,   158,
     164,   304,   165,  -147,  -147,   163,  -147,    30,   327,  -147,
     162,  -147,     4,  -147,  -147,   171,  -147,   354,  -147,   175,
    -147
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       6,     0,     2,     1,     0,     0,    22,    23,    24,     0,
      25,    38,     0,     0,    37,     0,     0,     3,    16,     9,
       5,     7,     8,     0,     0,     0,    30,    10,    11,    12,
      13,    59,     0,    26,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     6,     0,     0,    19,     0,     0,
      53,    54,     0,     0,     0,    15,     0,     0,     0,    93,
      33,    34,    32,    35,    36,     0,    14,    96,    31,    86,
       0,     0,     0,     0,     0,     0,    28,    27,    17,     0,
      18,    20,    63,    88,     4,    88,     0,     0,     0,     0,
       0,     0,    60,    58,    55,    56,    57,    40,     0,     0,
      48,     0,     0,     0,    87,    89,     0,    83,    85,    84,
      80,    81,    82,     0,     6,    29,     0,     0,     0,     0,
       0,     0,     0,    64,    92,    94,    90,    97,     6,     0,
      49,     0,     0,    45,    47,    46,    42,    43,    44,     0,
       0,     0,     0,     0,    41,     0,     0,     0,     0,     0,
       0,     0,     0,     6,    91,     6,    61,    50,    52,    51,
       6,    78,     0,    76,    65,     0,     0,    72,     0,    73,
       6,    95,     0,    70,    62,    39,     6,    77,     0,     0,
       0,     0,     0,    66,     6,     0,    98,     0,     0,    74,
       0,    71,     0,    67,    75,     0,     6,     0,    68,    72,
      69
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -147,  -147,  -147,  -147,   -44,  -147,   142,  -147,   147,  -147,
      -7,   183,  -147,   166,  -147,  -147,  -147,  -147,  -147,   -31,
    -147,  -147,  -147,  -147,  -147,  -147,    18,  -147,  -147,  -147,
    -147,  -146,  -147,  -147,  -147,    29,   133,  -147,  -147,    78,
    -147,  -147,  -147,  -147,  -147,  -147
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    19,    44,     2,    20,    21,    79,    22,    23,
      24,    35,    25,    26,    27,    36,   114,    99,   132,    69,
      28,    49,   113,   167,   101,   139,   174,   187,   195,   199,
     180,   152,   176,   192,   170,    70,   103,   104,   141,   105,
      29,    83,   140,    30,    85,   142
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      65,    53,    34,   161,    31,   149,    58,    72,    73,    74,
      62,   145,     6,     7,     8,     9,    10,     3,   150,   146,
     169,    71,   130,    76,   151,   131,    14,    32,    15,    16,
      39,    40,   -79,    38,    18,     6,     7,     8,    41,    10,
      37,    94,    95,    96,    47,    48,   194,    43,   100,    33,
      81,    50,    51,    55,    56,   107,   108,   109,   110,   111,
     112,    42,    52,    33,    86,    87,    88,   115,    66,    56,
     129,    72,    73,    74,    46,    54,   102,    57,   102,    89,
      60,    59,    90,    91,   143,    61,   133,   134,   135,   136,
     137,   138,    72,    73,    74,   117,   118,   119,    72,    73,
      74,    63,    72,    73,    74,    64,    67,    77,    75,   165,
     120,   166,    98,   121,   122,   158,   168,    97,    92,   162,
      72,    73,    74,    72,    73,    74,   177,     6,     7,     8,
      82,    10,   181,    93,   102,    74,    72,    73,    74,   123,
     188,   178,   182,    14,   116,    15,    16,   124,   126,     4,
     125,     5,   197,     6,     7,     8,     9,    10,    11,    12,
     127,    13,   128,   147,   148,   153,   157,    14,   155,    15,
      16,   159,   160,    17,    84,    18,     4,   164,     5,   173,
       6,     7,     8,     9,    10,    11,    12,   163,    13,   179,
     183,   184,   189,   186,    14,   193,    15,    16,   196,    78,
      17,   144,    18,     4,    80,     5,    45,     6,     7,     8,
       9,    10,    11,    12,    68,    13,   190,   200,   106,   154,
       0,    14,     0,    15,    16,     0,     0,    17,   156,    18,
       4,     0,     5,     0,     6,     7,     8,     9,    10,    11,
      12,     0,    13,     0,     0,     0,     0,     0,    14,     0,
      15,    16,     0,     0,    17,   171,    18,     4,     0,     5,
     172,     6,     7,     8,     9,    10,    11,    12,     0,    13,
       0,     0,     0,     0,     0,    14,     0,    15,    16,     0,
       4,    17,     5,    18,     6,     7,     8,     9,    10,    11,
      12,     0,    13,     0,     0,     0,     0,     0,    14,     0,
      15,    16,     0,     0,    17,   175,    18,     4,     0,     5,
       0,     6,     7,     8,     9,    10,    11,    12,     0,    13,
       0,     0,     0,   185,     0,    14,     0,    15,    16,     0,
       4,    17,     5,    18,     6,     7,     8,     9,    10,    11,
      12,     0,    13,     0,     0,     0,     0,     0,    14,     0,
      15,    16,     0,     0,    17,   191,    18,     4,     0,     5,
       0,     6,     7,     8,     9,    10,    11,    12,     0,    13,
       0,     0,     0,     0,     0,    14,     0,    15,    16,     0,
       0,    17,   198,    18,     4,     0,     5,     0,     6,     7,
       8,     9,    10,    11,    12,     0,    13,     0,     0,     0,
       0,     0,    14,     0,    15,    16,     0,     0,    17,     0,
      18
};

static const yytype_int16 yycheck[] =
{
      44,    32,     9,   149,    32,     1,    37,    23,    24,    25,
      41,    23,     7,     8,     9,    10,    11,     0,    14,    31,
      36,    52,    21,    54,    20,    24,    21,    32,    23,    24,
      23,    24,    28,    21,    29,     7,     8,     9,    31,    11,
      32,    72,    73,    74,    29,    30,   192,    24,    79,    21,
      57,    21,    22,    29,    30,    86,    87,    88,    89,    90,
      91,    23,    32,    21,    16,    17,    18,    98,    29,    30,
     114,    23,    24,    25,    21,    31,    83,    32,    85,    31,
      23,    32,    34,    35,   128,    24,   117,   118,   119,   120,
     121,   122,    23,    24,    25,    16,    17,    18,    23,    24,
      25,    21,    23,    24,    25,    21,    32,    21,    33,   153,
      31,   155,    31,    34,    35,   146,   160,    27,    33,   150,
      23,    24,    25,    23,    24,    25,   170,     7,     8,     9,
      33,    11,   176,    33,   141,    25,    23,    24,    25,    27,
     184,   172,    29,    21,    29,    23,    24,    21,    30,     3,
      33,     5,   196,     7,     8,     9,    10,    11,    12,    13,
      33,    15,    27,    24,    33,    27,    23,    21,    27,    23,
      24,    21,    27,    27,    28,    29,     3,    28,     5,     4,
       7,     8,     9,    10,    11,    12,    13,    36,    15,     3,
      32,    27,    29,    28,    21,    33,    23,    24,    27,    57,
      27,    28,    29,     3,    57,     5,    23,     7,     8,     9,
      10,    11,    12,    13,    48,    15,   187,   199,    85,   141,
      -1,    21,    -1,    23,    24,    -1,    -1,    27,    28,    29,
       3,    -1,     5,    -1,     7,     8,     9,    10,    11,    12,
      13,    -1,    15,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      23,    24,    -1,    -1,    27,    28,    29,     3,    -1,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    -1,    15,
      -1,    -1,    -1,    -1,    -1,    21,    -1,    23,    24,    -1,
       3,    27,     5,    29,     7,     8,     9,    10,    11,    12,
      13,    -1,    15,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      23,    24,    -1,    -1,    27,    28,    29,     3,    -1,     5,
      -1,     7,     8,     9,    10,    11,    12,    13,    -1,    15,
      -1,    -1,    -1,    19,    -1,    21,    -1,    23,    24,    -1,
       3,    27,     5,    29,     7,     8,     9,    10,    11,    12,
      13,    -1,    15,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      23,    24,    -1,    -1,    27,    28,    29,     3,    -1,     5,
      -1,     7,     8,     9,    10,    11,    12,    13,    -1,    15,
      -1,    -1,    -1,    -1,    -1,    21,    -1,    23,    24,    -1,
      -1,    27,    28,    29,     3,    -1,     5,    -1,     7,     8,
       9,    10,    11,    12,    13,    -1,    15,    -1,    -1,    -1,
      -1,    -1,    21,    -1,    23,    24,    -1,    -1,    27,    -1,
      29
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    38,    41,     0,     3,     5,     7,     8,     9,    10,
      11,    12,    13,    15,    21,    23,    24,    27,    29,    39,
      42,    43,    45,    46,    47,    49,    50,    51,    57,    77,
      80,    32,    32,    21,    47,    48,    52,    32,    21,    23,
      24,    31,    23,    24,    40,    48,    21,    29,    30,    58,
      21,    22,    32,    56,    31,    29,    30,    32,    56,    32,
      23,    24,    56,    21,    21,    41,    29,    32,    50,    56,
      72,    56,    23,    24,    25,    33,    56,    21,    43,    44,
      45,    47,    33,    78,    28,    81,    16,    17,    18,    31,
      34,    35,    33,    33,    56,    56,    56,    27,    31,    54,
      56,    61,    47,    73,    74,    76,    73,    56,    56,    56,
      56,    56,    56,    59,    53,    56,    29,    16,    17,    18,
      31,    34,    35,    27,    21,    33,    30,    33,    27,    41,
      21,    24,    55,    56,    56,    56,    56,    56,    56,    62,
      79,    75,    82,    41,    28,    23,    31,    24,    33,     1,
      14,    20,    68,    27,    76,    27,    28,    23,    56,    21,
      27,    68,    56,    36,    28,    41,    41,    60,    41,    36,
      71,    28,     6,     4,    63,    28,    69,    41,    56,     3,
      67,    41,    29,    32,    27,    19,    28,    64,    41,    29,
      72,    28,    70,    33,    68,    65,    27,    41,    28,    66,
      63
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    40,    39,    41,    41,    42,    42,    42,
      42,    42,    42,    42,    43,    43,    43,    44,    44,    45,
      46,    46,    47,    47,    47,    47,    48,    48,    48,    48,
      49,    49,    50,    50,    50,    50,    50,    50,    52,    51,
      53,    51,    54,    54,    54,    54,    54,    54,    54,    55,
      55,    55,    55,    56,    56,    56,    56,    56,    56,    58,
      59,    60,    57,    61,    62,    57,    64,    65,    66,    63,
      67,    63,    63,    69,    70,    68,    71,    68,    68,    68,
      72,    72,    72,    72,    72,    72,    72,    73,    73,    74,
      75,    74,    76,    78,    79,    77,    81,    82,    80
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     4,     2,     0,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     1,     1,     1,     2,
       1,     2,     1,     1,     1,     1,     1,     3,     3,     5,
       1,     3,     3,     3,     3,     3,     3,     1,     0,    11,
       0,     8,     3,     3,     3,     3,     3,     3,     1,     1,
       3,     3,     3,     1,     1,     3,     3,     3,     3,     0,
       0,     0,    11,     0,     0,     9,     0,     0,     0,    12,
       0,     5,     0,     0,     0,     9,     0,     4,     2,     0,
       3,     3,     3,     3,     3,     3,     1,     1,     0,     1,
       0,     4,     2,     0,     0,    10,     0,     0,    13
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
  case 3: /* $@1: %empty  */
#line 54 "parser.y"
               {
                /* Acción intermedia: Al abrir '{', creamos entorno local */
                struct Entorno *nuevo = (struct Entorno *) malloc(sizeof(struct Entorno));
                nuevo->tabla_simbolos = NULL;
                nuevo->cantidad_simbolos = 0;
                nuevo->capacidad_tabla = 0;
                nuevo->padre = entorno_actual;
                nuevo->id_entorno = contador_entornos++; 
                entorno_actual = nuevo; 
            }
#line 1356 "parser.tab.c"
    break;

  case 4: /* bloque: '{' $@1 instrucciones '}'  */
#line 64 "parser.y"
                          {
                /* Acción final: Al cerrar '}', regresamos de nivel al padre */
                struct Entorno *viejo = entorno_actual;
                entorno_actual = entorno_actual->padre;
                
                /* Opcional: Podés liberar la memoria de 'viejo' aquí si querés */
            }
#line 1368 "parser.tab.c"
    break;

  case 14: /* declaracion: prefijo_declaracion declarar_lista_ids ';'  */
#line 86 "parser.y"
                                                         { es_constante_actual = 0; }
#line 1374 "parser.tab.c"
    break;

  case 15: /* declaracion: CONST declarar_lista_ids ';'  */
#line 87 "parser.y"
                                           {
                printf("[Error de Sintaxis] Línea %d: Definiste una constante pero omitiste el tipo de dato (ej: const int ...).\n", yylineno);
            }
#line 1382 "parser.tab.c"
    break;

  case 20: /* prefijo_declaracion: tipo  */
#line 99 "parser.y"
                                       { es_constante_actual = 0; }
#line 1388 "parser.tab.c"
    break;

  case 21: /* prefijo_declaracion: CONST tipo  */
#line 100 "parser.y"
                                       { es_constante_actual = 1; }
#line 1394 "parser.tab.c"
    break;

  case 22: /* tipo: INT  */
#line 103 "parser.y"
              { tipo_actual = T_INT; }
#line 1400 "parser.tab.c"
    break;

  case 23: /* tipo: FLOAT  */
#line 104 "parser.y"
             { tipo_actual = T_FLOAT; }
#line 1406 "parser.tab.c"
    break;

  case 24: /* tipo: CHAR  */
#line 105 "parser.y"
             { tipo_actual = T_CHAR; }
#line 1412 "parser.tab.c"
    break;

  case 25: /* tipo: DOUBLE  */
#line 106 "parser.y"
             { tipo_actual = T_DOUBLE; }
#line 1418 "parser.tab.c"
    break;

  case 26: /* declarar_lista_ids: ID  */
#line 109 "parser.y"
                        {
                struct entrada_tabla *entrada = declarar_variable((yyvsp[0].nombre));
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' ya fue declarada.\n", (yyvsp[0].nombre));
                } else {
                    entrada->tipo_base = tipo_actual;
                    entrada->id_entorno_declarado = entorno_actual->id_entorno;

                    if(es_constante_actual == 1) entrada->es_constante = 1;

                    // --- GENERACIÓN DE CÓDIGO PYTHON ---
                    imprimir_indentacion(); // <-- Cada uno imprime su espacio al inicio
                    fprintf(yyout_py, "%s_%d = None\n", (yyvsp[0].nombre), entorno_actual->id_entorno);
                }
                free((yyvsp[0].nombre));
         }
#line 1439 "parser.tab.c"
    break;

  case 27: /* declarar_lista_ids: declarar_lista_ids ',' ID  */
#line 125 "parser.y"
                                     {
                struct entrada_tabla *entrada = declarar_variable((yyvsp[0].nombre));
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' ya fue declarada.\n", (yyvsp[0].nombre));
                } else {
                    entrada->tipo_base = tipo_actual;
                    entrada->id_entorno_declarado = entorno_actual->id_entorno;

                    if(es_constante_actual == 1) entrada->es_constante = 1;
                    
                    // --- GENERACIÓN DE CÓDIGO PYTHON ---
                    imprimir_indentacion(); // <-- Indentamos
                    fprintf(yyout_py, "%s_%d = None\n", (yyvsp[0].nombre), entorno_actual->id_entorno);
                }
                free((yyvsp[0].nombre));
         }
#line 1460 "parser.tab.c"
    break;

  case 28: /* declarar_lista_ids: ID '=' expresion  */
#line 141 "parser.y"
                            {
                struct entrada_tabla *entrada = declarar_variable((yyvsp[-2].nombre));
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' ya fue declarada.\n", (yyvsp[-2].nombre));
                } else {
                    entrada->tipo_base = tipo_actual;
                    // ¡OJO! Te faltaba esta línea fundamental para que el while sepa su ID real:
                    entrada->id_entorno_declarado = entorno_actual->id_entorno; 

                    if(es_constante_actual == 1) entrada->es_constante = 1;
                    
                    // --- GENERACIÓN DE CÓDIGO PYTHON ---
                    imprimir_indentacion(); // <-- Indentamos
                    fprintf(yyout_py, "%s_%d = %s\n", (yyvsp[-2].nombre), entorno_actual->id_entorno, (yyvsp[0].nombre));
                }
                free((yyvsp[-2].nombre));
         }
#line 1482 "parser.tab.c"
    break;

  case 29: /* declarar_lista_ids: declarar_lista_ids ',' ID '=' expresion  */
#line 158 "parser.y"
                                                   {
                struct entrada_tabla *entrada = declarar_variable((yyvsp[-2].nombre));
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' ya fue declarada.\n", (yyvsp[-2].nombre));
                } else {
                    entrada->tipo_base = tipo_actual;
                    // ¡OJO! Aquí también te faltaba:
                    entrada->id_entorno_declarado = entorno_actual->id_entorno;

                    if(es_constante_actual == 1) entrada->es_constante = 1;
                    
                    
                    imprimir_indentacion(); // Indentamos
                    fprintf(yyout_py, "%s_%d = %s\n", (yyvsp[-2].nombre), entorno_actual->id_entorno, (yyvsp[0].nombre));
                }
                free((yyvsp[-2].nombre));
         }
#line 1504 "parser.tab.c"
    break;

  case 32: /* asignacion_unitaria: ID '=' expresion  */
#line 181 "parser.y"
                                       {
                        struct entrada_tabla *entrada = buscar_variable((yyvsp[-2].nombre));
                        if (entrada == NULL){
                            printf("Error semántico: la variable '%s' no existe.\n", (yyvsp[-2].nombre));
                        } else {
                            imprimir_indentacion();
                            fprintf(yyout_py, "%s_%d = %s\n", entrada->nombre, entrada->id_entorno_declarado, (yyvsp[0].nombre));
                        }
                        free((yyvsp[-2].nombre)); free((yyvsp[0].nombre));
                    }
#line 1519 "parser.tab.c"
    break;

  case 33: /* asignacion_unitaria: ID '+' '+'  */
#line 191 "parser.y"
                               {
                        struct entrada_tabla *entrada = buscar_variable((yyvsp[-2].nombre));
                        if (entrada == NULL){
                            printf("Error semántico: la variable '%s' no existe.\n", (yyvsp[-2].nombre));
                        } else {
                            imprimir_indentacion();
                            fprintf(yyout_py, "%s_%d += 1\n", entrada->nombre, entrada->id_entorno_declarado);
                        }
                        free((yyvsp[-2].nombre));
                    }
#line 1534 "parser.tab.c"
    break;

  case 34: /* asignacion_unitaria: ID '-' '-'  */
#line 201 "parser.y"
                               {
                        struct entrada_tabla *entrada = buscar_variable((yyvsp[-2].nombre));
                        if (entrada == NULL){
                            printf("Error semántico: la variable '%s' no existe.\n", (yyvsp[-2].nombre));
                        } else {
                            imprimir_indentacion();
                            fprintf(yyout_py, "%s_%d -= 1\n", entrada->nombre, entrada->id_entorno_declarado);
                        }
                        free((yyvsp[-2].nombre));
                    }
#line 1549 "parser.tab.c"
    break;

  case 35: /* asignacion_unitaria: '+' '+' ID  */
#line 211 "parser.y"
                               {
                        struct entrada_tabla *entrada = buscar_variable((yyvsp[0].nombre));
                        if (entrada == NULL){
                            printf("Error semántico: la variable '%s' no existe.\n", (yyvsp[0].nombre));
                        } else {
                            imprimir_indentacion();
                            fprintf(yyout_py, "%s_%d += 1\n", entrada->nombre, entrada->id_entorno_declarado);
                        }
                        free((yyvsp[0].nombre));
                    }
#line 1564 "parser.tab.c"
    break;

  case 36: /* asignacion_unitaria: '-' '-' ID  */
#line 221 "parser.y"
                               {
                        struct entrada_tabla *entrada = buscar_variable((yyvsp[0].nombre));
                        if (entrada == NULL){
                            printf("Error semántico: la variable '%s' no existe.\n", (yyvsp[0].nombre));
                        } else {
                            imprimir_indentacion();
                            fprintf(yyout_py, "%s_%d -= 1\n", entrada->nombre, entrada->id_entorno_declarado);
                        }
                        free((yyvsp[0].nombre));
                    }
#line 1579 "parser.tab.c"
    break;

  case 37: /* asignacion_unitaria: ID  */
#line 231 "parser.y"
                         {
                        struct entrada_tabla *entrada = buscar_variable((yyvsp[0].nombre));
                        if (entrada == NULL){
                            printf("Error semántico: la variable '%s' no existe.\n", (yyvsp[0].nombre));
                        } else {
                            imprimir_indentacion();
                            fprintf(yyout_py, "%s_%d\n", entrada->nombre, entrada->id_entorno_declarado);
                        }
                        free((yyvsp[0].nombre));
                    }
#line 1594 "parser.tab.c"
    break;

  case 38: /* $@2: %empty  */
#line 243 "parser.y"
           {
            struct Entorno *nuevo = (struct Entorno *) malloc(sizeof(struct Entorno));
            nuevo->tabla_simbolos = NULL; nuevo->cantidad_simbolos = 0; nuevo->capacidad_tabla = 0;
            nuevo->padre = entorno_actual; 
            nuevo->id_entorno = contador_entornos++;
            entorno_actual = nuevo;   
}
#line 1606 "parser.tab.c"
    break;

  case 39: /* loop: FOR $@2 '(' for_init condicion_loop ';' loop_consecuencia ')' '{' instrucciones '}'  */
#line 249 "parser.y"
                                                                         {
            if ((yyvsp[-4].nombre) && strlen((yyvsp[-4].nombre)) > 0) {
                imprimir_indentacion();
                fprintf(yyout_py, "%s", (yyvsp[-4].nombre));
                free((yyvsp[-4].nombre));
            }

            nivel_indentacion--; // Bajamos la indentación de Python

            /* 2. Destruimos el entorno local del loop */
            struct Entorno *viejo = entorno_actual;
            entorno_actual = entorno_actual->padre;
            free(viejo);
    }
#line 1625 "parser.tab.c"
    break;

  case 40: /* $@3: %empty  */
#line 263 "parser.y"
                                 {
        /* Acción intermedia: Abrimos entorno y loop */
        imprimir_indentacion();
        fprintf(yyout_py, "while %s:\n", (yyvsp[-2].nombre));
        nivel_indentacion++;
        free((yyvsp[-2].nombre)); // Liberamos el string de la expresión
    }
#line 1637 "parser.tab.c"
    break;

  case 41: /* loop: WHILE '(' expresion ')' '{' $@3 instrucciones '}'  */
#line 269 "parser.y"
                        {    
        nivel_indentacion--;
    }
#line 1645 "parser.tab.c"
    break;

  case 42: /* condicion_loop: expresion '=' expresion  */
#line 275 "parser.y"
                                         {
                    imprimir_indentacion();
                    printf("Error: aunque C acepte la forma loop('expresion = expresion'), python no lo hace, por favor, correjir la línea %d.\n", yylineno);
                    fprintf(yyout_py, "while %s = %s:\n", (yyvsp[-2].nombre), (yyvsp[0].nombre));
                    nivel_indentacion++;
                    free((yyvsp[-2].nombre)); free((yyvsp[0].nombre));
            }
#line 1657 "parser.tab.c"
    break;

  case 43: /* condicion_loop: expresion '>' expresion  */
#line 282 "parser.y"
                                         {
                    imprimir_indentacion();
                    fprintf(yyout_py, "while %s > %s:\n", (yyvsp[-2].nombre), (yyvsp[0].nombre));
                    nivel_indentacion++;
                    free((yyvsp[-2].nombre)); free((yyvsp[0].nombre));
            }
#line 1668 "parser.tab.c"
    break;

  case 44: /* condicion_loop: expresion '<' expresion  */
#line 288 "parser.y"
                                         {
                    imprimir_indentacion();
                    fprintf(yyout_py, "while %s < %s:\n", (yyvsp[-2].nombre), (yyvsp[0].nombre));
                    nivel_indentacion++;
                    free((yyvsp[-2].nombre)); free((yyvsp[0].nombre));
            }
#line 1679 "parser.tab.c"
    break;

  case 45: /* condicion_loop: expresion MAYOR_IGUAL expresion  */
#line 294 "parser.y"
                                                 {
                    imprimir_indentacion();
                    fprintf(yyout_py, "while %s >= %s:\n", (yyvsp[-2].nombre), (yyvsp[0].nombre));
                    nivel_indentacion++;
                    free((yyvsp[-2].nombre)); free((yyvsp[0].nombre));
            }
#line 1690 "parser.tab.c"
    break;

  case 46: /* condicion_loop: expresion MENOR_IGUAL expresion  */
#line 300 "parser.y"
                                                 { // NUMERO '<=' ID
                    imprimir_indentacion();
                    fprintf(yyout_py, "while %s <= %s:\n", (yyvsp[-2].nombre), (yyvsp[0].nombre));
                    nivel_indentacion++;
                    free((yyvsp[-2].nombre)); free((yyvsp[0].nombre));
            }
#line 1701 "parser.tab.c"
    break;

  case 47: /* condicion_loop: expresion IGUAL_IGUAL expresion  */
#line 306 "parser.y"
                                                 {
                    imprimir_indentacion();
                    fprintf(yyout_py, "while %s == %s:\n", (yyvsp[-2].nombre), (yyvsp[0].nombre));
                    nivel_indentacion++;
                    free((yyvsp[-2].nombre)); free((yyvsp[0].nombre));
            }
#line 1712 "parser.tab.c"
    break;

  case 48: /* condicion_loop: expresion  */
#line 312 "parser.y"
                        {
                    imprimir_indentacion();
                    fprintf(yyout_py, "while %s:\n", (yyvsp[0].nombre));
                    nivel_indentacion++;
                    free((yyvsp[0].nombre));
            }
#line 1723 "parser.tab.c"
    break;

  case 49: /* loop_consecuencia: ID  */
#line 320 "parser.y"
                      {
                    struct entrada_tabla *entrada = buscar_variable((yyvsp[0].nombre));
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' no fue declarada en este bloque.\n", (yyvsp[0].nombre));
                    (yyval.nombre) = strdup("");
                } else {
                    (yyval.nombre) = strdup("");
                }
            }
#line 1737 "parser.tab.c"
    break;

  case 50: /* loop_consecuencia: ID '+' '+'  */
#line 329 "parser.y"
                           {
                    struct entrada_tabla *entrada = buscar_variable((yyvsp[-2].nombre));
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' no fue declarada en este bloque.\n", (yyvsp[-2].nombre));
                    (yyval.nombre) = strdup("");
                } else {
                    char buf[256];
                    snprintf(buf, sizeof(buf), "%s_%d += 1\n", entrada->nombre, entrada->id_entorno_declarado);
                    (yyval.nombre) = strdup(buf);
                }
                }
#line 1753 "parser.tab.c"
    break;

  case 51: /* loop_consecuencia: '-' '-' ID  */
#line 340 "parser.y"
                            {
                        struct entrada_tabla *entrada = buscar_variable((yyvsp[0].nombre));
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' no fue declarada en este bloque.\n", (yyvsp[0].nombre));
                    (yyval.nombre) = strdup("");
                } else {
                    char buf[256];
                    snprintf(buf, sizeof(buf), "%s_%d -= 1\n", entrada->nombre, entrada->id_entorno_declarado);
                    (yyval.nombre) = strdup(buf);
                }
                }
#line 1769 "parser.tab.c"
    break;

  case 52: /* loop_consecuencia: ID '=' expresion  */
#line 351 "parser.y"
                                   {
                    struct entrada_tabla *entrada = buscar_variable((yyvsp[-2].nombre));
                    if (entrada == NULL){
                        printf("Error semántico: la variable '%s' no fue declarada en este bloque.\n", (yyvsp[-2].nombre));
                        (yyval.nombre) = strdup("");
                    } else {
                        char buf[512];
                        snprintf(buf, sizeof(buf), "%s_%d = %s\n", entrada->nombre, entrada->id_entorno_declarado, (yyvsp[0].nombre));
                        (yyval.nombre) = strdup(buf);
                    }
                    free((yyvsp[-2].nombre)); free((yyvsp[0].nombre));
                }
#line 1786 "parser.tab.c"
    break;

  case 53: /* expresion: ID  */
#line 365 "parser.y"
               {
                struct entrada_tabla *entrada = buscar_variable((yyvsp[0].nombre));
                if (entrada == NULL) {
                    printf("Error semántico: '%s' no declarada.\n", (yyvsp[0].nombre));
                    (yyval.nombre) = strdup((yyvsp[0].nombre)); 
                } else {
                    // Si existe, generamos su nombre real de Python con su entorno: ej "i_1"
                    char buf[100];
                    sprintf(buf, "%s_%d", entrada->nombre, entrada->id_entorno_declarado);
                    (yyval.nombre) = strdup(buf);
                }
                free((yyvsp[0].nombre));
          }
#line 1804 "parser.tab.c"
    break;

  case 54: /* expresion: NUMERO  */
#line 378 "parser.y"
                   {
                char buf[50];
                sprintf(buf, "%g", (yyvsp[0].val_num));
                (yyval.nombre) = strdup(buf);
          }
#line 1814 "parser.tab.c"
    break;

  case 55: /* expresion: expresion '+' expresion  */
#line 383 "parser.y"
                                    {
                char buf[256];
                sprintf(buf, "%s + %s", (yyvsp[-2].nombre), (yyvsp[0].nombre));
                (yyval.nombre) = strdup(buf);
                free((yyvsp[-2].nombre)); free((yyvsp[0].nombre)); // Limpiamos memoria de los hijos
          }
#line 1825 "parser.tab.c"
    break;

  case 56: /* expresion: expresion '-' expresion  */
#line 389 "parser.y"
                                    {
                char buf[256];
                sprintf(buf, "%s - %s", (yyvsp[-2].nombre), (yyvsp[0].nombre));
                (yyval.nombre) = strdup(buf);
                free((yyvsp[-2].nombre)); free((yyvsp[0].nombre));
          }
#line 1836 "parser.tab.c"
    break;

  case 57: /* expresion: expresion '*' expresion  */
#line 395 "parser.y"
                                    {
                char buf[256];
                sprintf(buf, "%s * %s", (yyvsp[-2].nombre), (yyvsp[0].nombre));
                (yyval.nombre) = strdup(buf);
                free((yyvsp[-2].nombre)); free((yyvsp[0].nombre));
          }
#line 1847 "parser.tab.c"
    break;

  case 58: /* expresion: '(' expresion ')'  */
#line 401 "parser.y"
                              {
                char buf[256];
                sprintf(buf, "(%s)", (yyvsp[-1].nombre));
                (yyval.nombre) = strdup(buf);
                free((yyvsp[-1].nombre));
          }
#line 1858 "parser.tab.c"
    break;

  case 59: /* $@4: %empty  */
#line 409 "parser.y"
                          {
            imprimir_indentacion();
            fprintf(yyout_py, "if ");
        }
#line 1867 "parser.tab.c"
    break;

  case 60: /* $@5: %empty  */
#line 412 "parser.y"
                           {
            fprintf(yyout_py, ":\n");
            nivel_indentacion++;
        }
#line 1876 "parser.tab.c"
    break;

  case 61: /* $@6: %empty  */
#line 415 "parser.y"
                                { 
            nivel_indentacion--;
        }
#line 1884 "parser.tab.c"
    break;

  case 63: /* $@7: %empty  */
#line 418 "parser.y"
                                   {
            
        }
#line 1892 "parser.tab.c"
    break;

  case 64: /* $@8: %empty  */
#line 420 "parser.y"
             {
            /*if($1 == float){
                printf("Error, prohibida sintaxis para switch, la expresion debe ser entera, arreglar linea %d\n", yylineno);
             } TODO cambiar esto cuando ya tengamos un verificador de tipos*/ 
            imprimir_indentacion();
            fprintf(yyout_py, "match %s:\n", (yyvsp[-3].nombre));
            nivel_indentacion++;
            free((yyvsp[-3].nombre));
        }
#line 1906 "parser.tab.c"
    break;

  case 65: /* condicionales: SWITCH '(' expresion ')' $@7 '{' $@8 switch_cases '}'  */
#line 428 "parser.y"
                           {
            nivel_indentacion--;
        }
#line 1914 "parser.tab.c"
    break;

  case 66: /* $@9: %empty  */
#line 433 "parser.y"
                             { 
                // Traducimos el 'else if' de C al 'elif' de Python
                imprimir_indentacion(); 
                fprintf(yyout_py, "elif "); 
           }
#line 1924 "parser.tab.c"
    break;

  case 67: /* $@10: %empty  */
#line 438 "parser.y"
                            { 
                fprintf(yyout_py, ":\n"); 
                nivel_indentacion++;
           }
#line 1933 "parser.tab.c"
    break;

  case 68: /* $@11: %empty  */
#line 442 "parser.y"
                                 {
                nivel_indentacion--;
           }
#line 1941 "parser.tab.c"
    break;

  case 70: /* $@12: %empty  */
#line 446 "parser.y"
                { 
                // El caso base de cierre: un 'else:' simple
                imprimir_indentacion(); 
                fprintf(yyout_py, "else:\n"); 
                nivel_indentacion++;
           }
#line 1952 "parser.tab.c"
    break;

  case 71: /* bloque_else: ELSE $@12 '{' instrucciones '}'  */
#line 452 "parser.y"
                                 {
                nivel_indentacion--;
           }
#line 1960 "parser.tab.c"
    break;

  case 73: /* $@13: %empty  */
#line 459 "parser.y"
                                    {
                    if (strchr((yyvsp[-1].nombre), '_') != NULL) {
                        printf("[Error Semántico] Línea %d: El valor del 'case' debe ser una constante, no una variable ('%s').\n", yylineno, (yyvsp[-1].nombre));
                    } //si expresion trae un _ en su nombre, significa que es una variable, algo prohbido en c
                    imprimir_indentacion();
                    fprintf(yyout_py, "case %s:\n", (yyvsp[-1].nombre));
                    nivel_indentacion++; //subimos la indentación para las instrucciones de este case específico
                    free((yyvsp[-1].nombre));
    }
#line 1974 "parser.tab.c"
    break;

  case 74: /* $@14: %empty  */
#line 467 "parser.y"
                              {
        nivel_indentacion--;
    }
#line 1982 "parser.tab.c"
    break;

  case 76: /* $@15: %empty  */
#line 470 "parser.y"
                              {
                    // Opcional: Agregamos soporte para el 'default:' de C -> 'case _:' de Python
                    imprimir_indentacion();
                    fprintf(yyout_py, "case _:\n");
                    nivel_indentacion++;
              }
#line 1993 "parser.tab.c"
    break;

  case 77: /* switch_cases: DEFAULT ':' $@15 instrucciones  */
#line 476 "parser.y"
                            {
                    nivel_indentacion--;
              }
#line 2001 "parser.tab.c"
    break;

  case 78: /* switch_cases: error switch_cases  */
#line 479 "parser.y"
                                     { 
                    // Si algo falla dentro de un case, Bison limpia la pila 
                    // hasta encontrar el inicio del Siguiente CASE o el cierre '}'
                    printf("[Error Sintáctico] Línea %d: 'case' mal formado o falta ';' tras el break.\n", yylineno);
                    yyerrok; // Indica a Bison que ya retomamos el control
              }
#line 2012 "parser.tab.c"
    break;

  case 80: /* condicion_IF: expresion '=' expresion  */
#line 489 "parser.y"
                                          {
                    printf("Error: aunque C acepte la forma condicional('expresion = expresion'), python no lo hace, por favor, corregir la línea %d.\n", yylineno);
                    fprintf(yyout_py, "%s = %s", (yyvsp[-2].nombre), (yyvsp[0].nombre));
                    free((yyvsp[-2].nombre)); free((yyvsp[0].nombre));
            }
#line 2022 "parser.tab.c"
    break;

  case 81: /* condicion_IF: expresion '>' expresion  */
#line 494 "parser.y"
                                         {
                    fprintf(yyout_py, "%s > %s", (yyvsp[-2].nombre), (yyvsp[0].nombre));
                    free((yyvsp[-2].nombre)); free((yyvsp[0].nombre));
            }
#line 2031 "parser.tab.c"
    break;

  case 82: /* condicion_IF: expresion '<' expresion  */
#line 498 "parser.y"
                                         {
                    fprintf(yyout_py, "%s < %s", (yyvsp[-2].nombre), (yyvsp[0].nombre));
                    free((yyvsp[-2].nombre)); free((yyvsp[0].nombre));
            }
#line 2040 "parser.tab.c"
    break;

  case 83: /* condicion_IF: expresion MAYOR_IGUAL expresion  */
#line 502 "parser.y"
                                                 {
                    fprintf(yyout_py, "%s >= %s", (yyvsp[-2].nombre), (yyvsp[0].nombre));
                    free((yyvsp[-2].nombre)); free((yyvsp[0].nombre));
            }
#line 2049 "parser.tab.c"
    break;

  case 84: /* condicion_IF: expresion MENOR_IGUAL expresion  */
#line 506 "parser.y"
                                                 { // NUMERO '<=' ID
                    fprintf(yyout_py, "%s <= %s", (yyvsp[-2].nombre), (yyvsp[0].nombre));
                    free((yyvsp[-2].nombre)); free((yyvsp[0].nombre));
            }
#line 2058 "parser.tab.c"
    break;

  case 85: /* condicion_IF: expresion IGUAL_IGUAL expresion  */
#line 510 "parser.y"
                                                 {
                    fprintf(yyout_py, "%s == %s", (yyvsp[-2].nombre), (yyvsp[0].nombre));
                    free((yyvsp[-2].nombre)); free((yyvsp[0].nombre));
            }
#line 2067 "parser.tab.c"
    break;

  case 86: /* condicion_IF: expresion  */
#line 514 "parser.y"
                        {
                    fprintf(yyout_py, "%s", (yyvsp[0].nombre));
                    free((yyvsp[0].nombre));
            }
#line 2076 "parser.tab.c"
    break;

  case 90: /* $@16: %empty  */
#line 525 "parser.y"
                                        { 
                        // TRUCO: Imprimimos la coma y un espacio justo cuando Bison detecta el token ','
                        fprintf(yyout_py, ", "); 
                   }
#line 2085 "parser.tab.c"
    break;

  case 92: /* parametro: tipo ID  */
#line 532 "parser.y"
                    {
                struct entrada_tabla *entrada = declarar_variable((yyvsp[0].nombre));
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' ya fue declarada.\n", (yyvsp[0].nombre));
                } else {
                    entrada->tipo_base = tipo_actual;
                    entrada->id_entorno_declarado = entorno_actual->id_entorno;

                    if(es_constante_actual == 1) entrada->es_constante = 1;

                    // Imprimimos el nombre limpio directamente en Python, sin indentación extra
                    fprintf(yyout_py, "%s_%d", (yyvsp[0].nombre), entorno_actual->id_entorno);
                }
                free((yyvsp[0].nombre));
          }
#line 2105 "parser.tab.c"
    break;

  case 93: /* $@17: %empty  */
#line 549 "parser.y"
                                      {
                struct Entorno *nuevo = (struct Entorno *) malloc(sizeof(struct Entorno));
                nuevo->tabla_simbolos = NULL;
                nuevo->cantidad_simbolos = 0;
                nuevo->capacidad_tabla = 0;
                nuevo->padre = entorno_actual;
                nuevo->id_entorno = contador_entornos++; 
                entorno_actual = nuevo; 
                imprimir_indentacion();
                fprintf(yyout_py, "def %s(", (yyvsp[-1].nombre));
                free((yyvsp[-1].nombre));
            }
#line 2122 "parser.tab.c"
    break;

  case 94: /* $@18: %empty  */
#line 560 "parser.y"
                                                {
                fprintf(yyout_py, "):\n");
                nivel_indentacion++;
            }
#line 2131 "parser.tab.c"
    break;

  case 95: /* funcion_void: VOID ID '(' $@17 declaracion_variables_funcion ')' $@18 '{' instrucciones '}'  */
#line 563 "parser.y"
                                    {
                nivel_indentacion--;
                struct Entorno *viejo = entorno_actual;
                entorno_actual = entorno_actual->padre;
                free(viejo);
            }
#line 2142 "parser.tab.c"
    break;

  case 96: /* $@19: %empty  */
#line 570 "parser.y"
                                         {
                struct Entorno *nuevo = (struct Entorno *) malloc(sizeof(struct Entorno));
                nuevo->tabla_simbolos = NULL;
                nuevo->cantidad_simbolos = 0;
                nuevo->capacidad_tabla = 0;
                nuevo->padre = entorno_actual;
                nuevo->id_entorno = contador_entornos++; 
                entorno_actual = nuevo; 
                imprimir_indentacion();
                fprintf(yyout_py, "def %s(", (yyvsp[-1].nombre));
                free((yyvsp[-1].nombre));
            }
#line 2159 "parser.tab.c"
    break;

  case 97: /* $@20: %empty  */
#line 581 "parser.y"
                                                {
                fprintf(yyout_py, "):\n");
                nivel_indentacion++;
            }
#line 2168 "parser.tab.c"
    break;

  case 98: /* funcion_NO_void: tipo ID '(' $@19 declaracion_variables_funcion ')' $@20 '{' instrucciones RETURN expresion ';' '}'  */
#line 584 "parser.y"
                                                         {
                nivel_indentacion--;
                struct Entorno *viejo = entorno_actual;
                entorno_actual = entorno_actual->padre;
                free(viejo);
            }
#line 2179 "parser.tab.c"
    break;


#line 2183 "parser.tab.c"

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

#line 591 "parser.y"


/* Inclusión rústica del analizador léxico al final del archivo */
#include "lex.yy.c"

void yyerror(const char *s) {
    fprintf(stderr, "Error sintáctico en la línea %d: %s\n", yylineno, s);
}




int main(int argc, char **argv) {                                       
        if (argc != 3) {                                                    
            printf("Uso: %s <archivo_entrada.c> <archivo_salida.py>\n",     
  argv[0]);                                                                 
            return 1;                                                       
        }                                                                   
                                                                            
        // 1. Abrimos el archivo .c de entrada y se lo pasamos a Lex        
        yyin = fopen(argv[1], "r");                                         
        if (!yyin) {                                                        
            printf("No se pudo abrir el archivo %s\n", argv[1]);            
            return 1;                                                       
        }                                                                   
                                                                            
        // 2. Abrimos/creamos el archivo .py de salida                      
        yyout_py = fopen(argv[2], "w");                                     
        if (!yyout_py) {                                                    
            printf("No se pudo crear el archivo %s\n", argv[2]);            
            fclose(yyin);                                                   
            return 1;                                                       
        }                                                                   
                                                                            
        // 3. Iniciamos el proceso de análisis
        entorno_actual = (struct Entorno *) malloc(sizeof(struct Entorno));
        entorno_actual->tabla_simbolos = NULL;
        entorno_actual->cantidad_simbolos = 0;
        entorno_actual->capacidad_tabla = 0;
        entorno_actual->padre = NULL;

        printf("Iniciando compilacion de %s a %s...\n", argv[1], argv[2]);  
        yyparse();                                                          
        printf("Compilacion finalizada.\n");                                
                                                                            
        // 4. Cerramos los archivos                                         
        fclose(yyin);                                                       
        fclose(yyout_py);                                                   
        return 0;                                                           
    }          
