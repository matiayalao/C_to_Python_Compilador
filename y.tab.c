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


#line 101 "y.tab.c"

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


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IF = 258,                      /* IF  */
    ELSE = 259,                    /* ELSE  */
    WHILE = 260,                   /* WHILE  */
    RETURN = 261,                  /* RETURN  */
    INT = 262,                     /* INT  */
    FLOAT = 263,                   /* FLOAT  */
    CHAR = 264,                    /* CHAR  */
    CONST = 265,                   /* CONST  */
    DOUBLE = 266,                  /* DOUBLE  */
    FOR = 267,                     /* FOR  */
    SWITCH = 268,                  /* SWITCH  */
    CASE = 269,                    /* CASE  */
    MAYOR_IGUAL = 270,             /* MAYOR_IGUAL  */
    IGUAL_IGUAL = 271,             /* IGUAL_IGUAL  */
    MENOR_IGUAL = 272,             /* MENOR_IGUAL  */
    BREAK = 273,                   /* BREAK  */
    DEFAULT = 274,                 /* DEFAULT  */
    ID = 275,                      /* ID  */
    NUMERO = 276                   /* NUMERO  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IF 258
#define ELSE 259
#define WHILE 260
#define RETURN 261
#define INT 262
#define FLOAT 263
#define CHAR 264
#define CONST 265
#define DOUBLE 266
#define FOR 267
#define SWITCH 268
#define CASE 269
#define MAYOR_IGUAL 270
#define IGUAL_IGUAL 271
#define MENOR_IGUAL 272
#define BREAK 273
#define DEFAULT 274
#define ID 275
#define NUMERO 276

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 33 "parser.y"

    char *nombre;     
    double val_num;   

#line 198 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);



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
  YYSYMBOL_MAYOR_IGUAL = 15,               /* MAYOR_IGUAL  */
  YYSYMBOL_IGUAL_IGUAL = 16,               /* IGUAL_IGUAL  */
  YYSYMBOL_MENOR_IGUAL = 17,               /* MENOR_IGUAL  */
  YYSYMBOL_BREAK = 18,                     /* BREAK  */
  YYSYMBOL_DEFAULT = 19,                   /* DEFAULT  */
  YYSYMBOL_ID = 20,                        /* ID  */
  YYSYMBOL_NUMERO = 21,                    /* NUMERO  */
  YYSYMBOL_22_ = 22,                       /* '+'  */
  YYSYMBOL_23_ = 23,                       /* '-'  */
  YYSYMBOL_24_ = 24,                       /* '*'  */
  YYSYMBOL_25_ = 25,                       /* '/'  */
  YYSYMBOL_26_ = 26,                       /* '{'  */
  YYSYMBOL_27_ = 27,                       /* '}'  */
  YYSYMBOL_28_ = 28,                       /* ';'  */
  YYSYMBOL_29_ = 29,                       /* ','  */
  YYSYMBOL_30_ = 30,                       /* '='  */
  YYSYMBOL_31_ = 31,                       /* '('  */
  YYSYMBOL_32_ = 32,                       /* ')'  */
  YYSYMBOL_33_ = 33,                       /* '>'  */
  YYSYMBOL_34_ = 34,                       /* '<'  */
  YYSYMBOL_35_ = 35,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 36,                  /* $accept  */
  YYSYMBOL_programa = 37,                  /* programa  */
  YYSYMBOL_bloque = 38,                    /* bloque  */
  YYSYMBOL_39_1 = 39,                      /* $@1  */
  YYSYMBOL_instrucciones = 40,             /* instrucciones  */
  YYSYMBOL_instruccion = 41,               /* instruccion  */
  YYSYMBOL_declaracion = 42,               /* declaracion  */
  YYSYMBOL_for_init = 43,                  /* for_init  */
  YYSYMBOL_asignacion = 44,                /* asignacion  */
  YYSYMBOL_prefijo_declaracion = 45,       /* prefijo_declaracion  */
  YYSYMBOL_tipo = 46,                      /* tipo  */
  YYSYMBOL_declarar_lista_ids = 47,        /* declarar_lista_ids  */
  YYSYMBOL_lista_asignaciones = 48,        /* lista_asignaciones  */
  YYSYMBOL_asignacion_unitaria = 49,       /* asignacion_unitaria  */
  YYSYMBOL_loop = 50,                      /* loop  */
  YYSYMBOL_51_2 = 51,                      /* $@2  */
  YYSYMBOL_52_3 = 52,                      /* $@3  */
  YYSYMBOL_condicion_loop = 53,            /* condicion_loop  */
  YYSYMBOL_loop_consecuencia = 54,         /* loop_consecuencia  */
  YYSYMBOL_expresion = 55,                 /* expresion  */
  YYSYMBOL_condicionales = 56,             /* condicionales  */
  YYSYMBOL_57_4 = 57,                      /* $@4  */
  YYSYMBOL_58_5 = 58,                      /* $@5  */
  YYSYMBOL_59_6 = 59,                      /* $@6  */
  YYSYMBOL_60_7 = 60,                      /* $@7  */
  YYSYMBOL_61_8 = 61,                      /* $@8  */
  YYSYMBOL_bloque_else = 62,               /* bloque_else  */
  YYSYMBOL_63_9 = 63,                      /* $@9  */
  YYSYMBOL_64_10 = 64,                     /* $@10  */
  YYSYMBOL_65_11 = 65,                     /* $@11  */
  YYSYMBOL_66_12 = 66,                     /* $@12  */
  YYSYMBOL_switch_cases = 67,              /* switch_cases  */
  YYSYMBOL_68_13 = 68,                     /* $@13  */
  YYSYMBOL_69_14 = 69,                     /* $@14  */
  YYSYMBOL_70_15 = 70,                     /* $@15  */
  YYSYMBOL_condicion_IF = 71               /* condicion_IF  */
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
#define YYLAST   333

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  169

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   276


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
      31,    32,    24,    22,    29,    23,     2,    25,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    35,    28,
      34,    30,    33,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    26,     2,    27,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    51,    51,    54,    54,    73,    74,    77,    78,    79,
      80,    81,    84,    85,    88,    91,    92,    95,    97,    98,
     101,   102,   103,   104,   107,   123,   139,   156,   175,   176,
     179,   189,   199,   209,   219,   229,   241,   241,   261,   261,
     273,   280,   286,   292,   298,   304,   310,   318,   327,   338,
     349,   363,   376,   381,   387,   393,   399,   407,   410,   413,
     407,   416,   418,   416,   431,   436,   440,   431,   444,   444,
     454,   457,   465,   457,   468,   468,   477,   484,   487,   492,
     496,   500,   504,   508,   512
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
  "CASE", "MAYOR_IGUAL", "IGUAL_IGUAL", "MENOR_IGUAL", "BREAK", "DEFAULT",
  "ID", "NUMERO", "'+'", "'-'", "'*'", "'/'", "'{'", "'}'", "';'", "','",
  "'='", "'('", "')'", "'>'", "'<'", "':'", "$accept", "programa",
  "bloque", "$@1", "instrucciones", "instruccion", "declaracion",
  "for_init", "asignacion", "prefijo_declaracion", "tipo",
  "declarar_lista_ids", "lista_asignaciones", "asignacion_unitaria",
  "loop", "$@2", "$@3", "condicion_loop", "loop_consecuencia", "expresion",
  "condicionales", "$@4", "$@5", "$@6", "$@7", "$@8", "bloque_else", "$@9",
  "$@10", "$@11", "$@12", "switch_cases", "$@13", "$@14", "$@15",
  "condicion_IF", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-126)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-78)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -126,    10,   285,  -126,   -26,   -15,  -126,  -126,  -126,    34,
    -126,  -126,   -11,     6,   -19,     2,  -126,  -126,  -126,  -126,
    -126,  -126,    20,  -126,     5,  -126,  -126,  -126,  -126,   -13,
      28,  -126,    18,    41,   -13,    43,    63,   -13,    73,    74,
    -126,    76,  -126,    44,   -13,  -126,  -126,   -13,    39,   -13,
    -126,    79,     4,    65,  -126,  -126,    58,  -126,  -126,   107,
    -126,  -126,    68,    77,    99,   -13,   -13,   -13,    80,    58,
      78,  -126,   -13,  -126,  -126,  -126,   -13,   -13,   -13,   -13,
     -13,   -13,  -126,  -126,    87,    87,  -126,  -126,   -13,    97,
     299,   100,    58,    58,    58,    58,    58,    58,   102,  -126,
      58,    50,   -13,   -13,   -13,   -13,   -13,   -13,  -126,  -126,
     133,     1,   109,   105,    58,    58,    58,    58,    58,    58,
       3,   159,  -126,   117,   -13,   127,   122,     3,   -13,   114,
     123,  -126,  -126,    58,  -126,  -126,  -126,    33,  -126,  -126,
     147,   185,  -126,  -126,   149,  -126,  -126,  -126,   285,   126,
     128,   211,  -126,  -126,   130,   -13,   233,  -126,   131,  -126,
       3,  -126,  -126,   139,  -126,   259,  -126,   147,  -126
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       6,     0,     2,     1,     0,     0,    20,    21,    22,     0,
      23,    36,     0,    35,     0,     0,     3,    14,     9,     5,
       7,     8,     0,    18,     0,    28,    10,    11,    57,     0,
      24,    19,     0,     0,     0,     0,     0,     0,     0,     0,
       6,     0,    17,     0,     0,    51,    52,     0,     0,     0,
      13,     0,     0,     0,    31,    32,    30,    33,    34,     0,
      12,    29,    84,     0,     0,     0,     0,     0,     0,    26,
      25,    15,     0,    16,    61,     4,     0,     0,     0,     0,
       0,     0,    58,    56,    53,    54,    55,    38,     0,     0,
      46,     0,    81,    83,    82,    78,    79,    80,     0,     6,
      27,     0,     0,     0,     0,     0,     0,     0,    62,     6,
       0,    47,     0,     0,    43,    45,    44,    40,    41,    42,
       0,     0,    39,     0,     0,     0,     0,     0,     0,     0,
       0,    59,    48,    50,    49,     6,    76,     0,    74,    63,
      70,     0,    71,     6,    68,    60,    37,     6,    75,     0,
       0,     0,    64,     6,     0,     0,     0,    72,     0,    69,
       0,    65,    73,     0,     6,     0,    66,    70,    67
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -126,  -126,  -126,  -126,   -40,  -126,   121,  -126,   124,  -126,
     165,   153,  -126,   134,  -126,  -126,  -126,  -126,  -126,   -28,
    -126,  -126,  -126,  -126,  -126,  -126,    11,  -126,  -126,  -126,
    -126,  -125,  -126,  -126,  -126,    25
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    18,    40,     2,    19,    20,    72,    21,    22,
      23,    32,    24,    25,    26,    33,    99,    89,   113,    62,
      27,    44,    98,   140,    91,   120,   145,   155,   163,   167,
     150,   130,   147,   160,   143,    63
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      59,    48,   136,    38,   127,    28,    53,    45,    46,    56,
       3,     6,     7,     8,     9,    10,    29,   128,    47,    64,
      34,    69,   129,   123,    13,    39,    14,    15,    35,    36,
     -77,   124,    17,    42,    43,   162,    37,    84,    85,    86,
      30,     6,     7,     8,    90,    10,    50,    51,    92,    93,
      94,    95,    96,    97,    30,    65,    66,    67,    49,   110,
     100,    65,    66,    67,    13,    54,    14,    15,   142,   121,
     111,    68,    52,   112,   114,   115,   116,   117,   118,   119,
      65,    66,    67,    76,    77,    78,    55,    65,    66,    67,
      65,    66,    67,    57,    58,   141,   133,    74,    79,    70,
     137,    80,    81,   148,    60,    51,    87,   151,    88,    82,
       4,    67,     5,   156,     6,     7,     8,     9,    10,    11,
      12,    65,    66,    67,   165,   101,   108,    13,   109,    14,
      15,    83,   125,    16,    75,    17,     4,   126,     5,   132,
       6,     7,     8,     9,    10,    11,    12,   134,   135,   138,
     139,   144,   149,    13,   153,    14,    15,   152,   157,    16,
     122,    17,     4,   161,     5,   164,     6,     7,     8,     9,
      10,    11,    12,    71,    31,    41,    73,    61,   168,    13,
     158,    14,    15,     0,     0,    16,   131,    17,     4,     0,
       5,     0,     6,     7,     8,     9,    10,    11,    12,     0,
       0,     0,     0,     0,     0,    13,     0,    14,    15,     0,
       0,    16,   146,    17,     4,     0,     5,     0,     6,     7,
       8,     9,    10,    11,    12,     0,     0,     0,     0,   154,
       0,    13,     0,    14,    15,     0,     4,    16,     5,    17,
       6,     7,     8,     9,    10,    11,    12,     0,     0,     0,
       0,     0,     0,    13,     0,    14,    15,     0,     0,    16,
     159,    17,     4,     0,     5,     0,     6,     7,     8,     9,
      10,    11,    12,     0,     0,     0,     0,     0,     0,    13,
       0,    14,    15,     0,     0,    16,   166,    17,     4,     0,
       5,     0,     6,     7,     8,     9,    10,    11,    12,     0,
       0,     0,     0,     0,     0,    13,     0,    14,    15,     0,
       0,    16,     0,    17,   102,   103,   104,     0,     0,     0,
       0,    65,    66,    67,     0,     0,     0,     0,     0,   105,
       0,     0,   106,   107
};

static const yytype_int16 yycheck[] =
{
      40,    29,   127,    22,     1,    31,    34,    20,    21,    37,
       0,     7,     8,     9,    10,    11,    31,    14,    31,    47,
      31,    49,    19,    22,    20,    23,    22,    23,    22,    23,
      27,    30,    28,    28,    29,   160,    30,    65,    66,    67,
      20,     7,     8,     9,    72,    11,    28,    29,    76,    77,
      78,    79,    80,    81,    20,    22,    23,    24,    30,    99,
      88,    22,    23,    24,    20,    22,    22,    23,    35,   109,
      20,    32,    31,    23,   102,   103,   104,   105,   106,   107,
      22,    23,    24,    15,    16,    17,    23,    22,    23,    24,
      22,    23,    24,    20,    20,   135,   124,    32,    30,    20,
     128,    33,    34,   143,    28,    29,    26,   147,    30,    32,
       3,    24,     5,   153,     7,     8,     9,    10,    11,    12,
      13,    22,    23,    24,   164,    28,    26,    20,    26,    22,
      23,    32,    23,    26,    27,    28,     3,    32,     5,    22,
       7,     8,     9,    10,    11,    12,    13,    20,    26,    35,
      27,     4,     3,    20,    26,    22,    23,    31,    28,    26,
      27,    28,     3,    32,     5,    26,     7,     8,     9,    10,
      11,    12,    13,    52,     9,    22,    52,    43,   167,    20,
     155,    22,    23,    -1,    -1,    26,    27,    28,     3,    -1,
       5,    -1,     7,     8,     9,    10,    11,    12,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    -1,    22,    23,    -1,
      -1,    26,    27,    28,     3,    -1,     5,    -1,     7,     8,
       9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,    18,
      -1,    20,    -1,    22,    23,    -1,     3,    26,     5,    28,
       7,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    -1,    22,    23,    -1,    -1,    26,
      27,    28,     3,    -1,     5,    -1,     7,     8,     9,    10,
      11,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      -1,    22,    23,    -1,    -1,    26,    27,    28,     3,    -1,
       5,    -1,     7,     8,     9,    10,    11,    12,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    -1,    22,    23,    -1,
      -1,    26,    -1,    28,    15,    16,    17,    -1,    -1,    -1,
      -1,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    33,    34
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    37,    40,     0,     3,     5,     7,     8,     9,    10,
      11,    12,    13,    20,    22,    23,    26,    28,    38,    41,
      42,    44,    45,    46,    48,    49,    50,    56,    31,    31,
      20,    46,    47,    51,    31,    22,    23,    30,    22,    23,
      39,    47,    28,    29,    57,    20,    21,    31,    55,    30,
      28,    29,    31,    55,    22,    23,    55,    20,    20,    40,
      28,    49,    55,    71,    55,    22,    23,    24,    32,    55,
      20,    42,    43,    44,    32,    27,    15,    16,    17,    30,
      33,    34,    32,    32,    55,    55,    55,    26,    30,    53,
      55,    60,    55,    55,    55,    55,    55,    55,    58,    52,
      55,    28,    15,    16,    17,    30,    33,    34,    26,    26,
      40,    20,    23,    54,    55,    55,    55,    55,    55,    55,
      61,    40,    27,    22,    30,    23,    32,     1,    14,    19,
      67,    27,    22,    55,    20,    26,    67,    55,    35,    27,
      59,    40,    35,    70,     4,    62,    27,    68,    40,     3,
      66,    40,    31,    26,    18,    63,    40,    28,    71,    27,
      69,    32,    67,    64,    26,    40,    27,    65,    62
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    37,    39,    38,    40,    40,    41,    41,    41,
      41,    41,    42,    42,    42,    43,    43,    44,    45,    45,
      46,    46,    46,    46,    47,    47,    47,    47,    48,    48,
      49,    49,    49,    49,    49,    49,    51,    50,    52,    50,
      53,    53,    53,    53,    53,    53,    53,    54,    54,    54,
      54,    55,    55,    55,    55,    55,    55,    57,    58,    59,
      56,    60,    61,    56,    63,    64,    65,    62,    66,    62,
      62,    68,    69,    67,    70,    67,    67,    67,    71,    71,
      71,    71,    71,    71,    71
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     4,     2,     0,     1,     1,     1,
       1,     1,     3,     3,     1,     1,     1,     2,     1,     2,
       1,     1,     1,     1,     1,     3,     3,     5,     1,     3,
       3,     3,     3,     3,     3,     1,     0,    11,     0,     8,
       3,     3,     3,     3,     3,     3,     1,     1,     3,     3,
       3,     1,     1,     3,     3,     3,     3,     0,     0,     0,
      11,     0,     0,     9,     0,     0,     0,    12,     0,     5,
       0,     0,     0,     9,     0,     4,     2,     0,     3,     3,
       3,     3,     3,     3,     1
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
#line 1399 "y.tab.c"
    break;

  case 4: /* bloque: '{' $@1 instrucciones '}'  */
#line 64 "parser.y"
                          {
                /* Acción final: Al cerrar '}', regresamos de nivel al padre */
                struct Entorno *viejo = entorno_actual;
                entorno_actual = entorno_actual->padre;
                
                /* Opcional: Podés liberar la memoria de 'viejo' aquí si querés */
            }
#line 1411 "y.tab.c"
    break;

  case 12: /* declaracion: prefijo_declaracion declarar_lista_ids ';'  */
#line 84 "parser.y"
                                                         { es_constante_actual = 0; }
#line 1417 "y.tab.c"
    break;

  case 13: /* declaracion: CONST declarar_lista_ids ';'  */
#line 85 "parser.y"
                                           {
                printf("[Error de Sintaxis] Línea %d: Definiste una constante pero omitiste el tipo de dato (ej: const int ...).\n", yylineno);
            }
#line 1425 "y.tab.c"
    break;

  case 18: /* prefijo_declaracion: tipo  */
#line 97 "parser.y"
                                       { es_constante_actual = 0; }
#line 1431 "y.tab.c"
    break;

  case 19: /* prefijo_declaracion: CONST tipo  */
#line 98 "parser.y"
                                       { es_constante_actual = 1; }
#line 1437 "y.tab.c"
    break;

  case 20: /* tipo: INT  */
#line 101 "parser.y"
              { tipo_actual = T_INT; }
#line 1443 "y.tab.c"
    break;

  case 21: /* tipo: FLOAT  */
#line 102 "parser.y"
             { tipo_actual = T_FLOAT; }
#line 1449 "y.tab.c"
    break;

  case 22: /* tipo: CHAR  */
#line 103 "parser.y"
             { tipo_actual = T_CHAR; }
#line 1455 "y.tab.c"
    break;

  case 23: /* tipo: DOUBLE  */
#line 104 "parser.y"
             { tipo_actual = T_DOUBLE; }
#line 1461 "y.tab.c"
    break;

  case 24: /* declarar_lista_ids: ID  */
#line 107 "parser.y"
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
#line 1482 "y.tab.c"
    break;

  case 25: /* declarar_lista_ids: declarar_lista_ids ',' ID  */
#line 123 "parser.y"
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
#line 1503 "y.tab.c"
    break;

  case 26: /* declarar_lista_ids: ID '=' expresion  */
#line 139 "parser.y"
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
#line 1525 "y.tab.c"
    break;

  case 27: /* declarar_lista_ids: declarar_lista_ids ',' ID '=' expresion  */
#line 156 "parser.y"
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
#line 1547 "y.tab.c"
    break;

  case 30: /* asignacion_unitaria: ID '=' expresion  */
#line 179 "parser.y"
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
#line 1562 "y.tab.c"
    break;

  case 31: /* asignacion_unitaria: ID '+' '+'  */
#line 189 "parser.y"
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
#line 1577 "y.tab.c"
    break;

  case 32: /* asignacion_unitaria: ID '-' '-'  */
#line 199 "parser.y"
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
#line 1592 "y.tab.c"
    break;

  case 33: /* asignacion_unitaria: '+' '+' ID  */
#line 209 "parser.y"
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
#line 1607 "y.tab.c"
    break;

  case 34: /* asignacion_unitaria: '-' '-' ID  */
#line 219 "parser.y"
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
#line 1622 "y.tab.c"
    break;

  case 35: /* asignacion_unitaria: ID  */
#line 229 "parser.y"
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
#line 1637 "y.tab.c"
    break;

  case 36: /* $@2: %empty  */
#line 241 "parser.y"
           {
            struct Entorno *nuevo = (struct Entorno *) malloc(sizeof(struct Entorno));
            nuevo->tabla_simbolos = NULL; nuevo->cantidad_simbolos = 0; nuevo->capacidad_tabla = 0;
            nuevo->padre = entorno_actual; 
            nuevo->id_entorno = contador_entornos++;
            entorno_actual = nuevo;   
}
#line 1649 "y.tab.c"
    break;

  case 37: /* loop: FOR $@2 '(' for_init condicion_loop ';' loop_consecuencia ')' '{' instrucciones '}'  */
#line 247 "parser.y"
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
#line 1668 "y.tab.c"
    break;

  case 38: /* $@3: %empty  */
#line 261 "parser.y"
                                 {
        /* Acción intermedia: Abrimos entorno y loop */
        imprimir_indentacion();
        fprintf(yyout_py, "while %s:\n", (yyvsp[-2].nombre));
        nivel_indentacion++;
        free((yyvsp[-2].nombre)); // Liberamos el string de la expresión
    }
#line 1680 "y.tab.c"
    break;

  case 39: /* loop: WHILE '(' expresion ')' '{' $@3 instrucciones '}'  */
#line 267 "parser.y"
                        {    
        nivel_indentacion--;
    }
#line 1688 "y.tab.c"
    break;

  case 40: /* condicion_loop: expresion '=' expresion  */
#line 273 "parser.y"
                                         {
                    imprimir_indentacion();
                    printf("Error: aunque C acepte la forma loop('expresion = expresion'), python no lo hace, por favor, correjir la línea %d.\n", yylineno);
                    fprintf(yyout_py, "while %s = %s:\n", (yyvsp[-2].nombre), (yyvsp[0].nombre));
                    nivel_indentacion++;
                    free((yyvsp[-2].nombre)); free((yyvsp[0].nombre));
            }
#line 1700 "y.tab.c"
    break;

  case 41: /* condicion_loop: expresion '>' expresion  */
#line 280 "parser.y"
                                         {
                    imprimir_indentacion();
                    fprintf(yyout_py, "while %s > %s:\n", (yyvsp[-2].nombre), (yyvsp[0].nombre));
                    nivel_indentacion++;
                    free((yyvsp[-2].nombre)); free((yyvsp[0].nombre));
            }
#line 1711 "y.tab.c"
    break;

  case 42: /* condicion_loop: expresion '<' expresion  */
#line 286 "parser.y"
                                         {
                    imprimir_indentacion();
                    fprintf(yyout_py, "while %s < %s:\n", (yyvsp[-2].nombre), (yyvsp[0].nombre));
                    nivel_indentacion++;
                    free((yyvsp[-2].nombre)); free((yyvsp[0].nombre));
            }
#line 1722 "y.tab.c"
    break;

  case 43: /* condicion_loop: expresion MAYOR_IGUAL expresion  */
#line 292 "parser.y"
                                                 {
                    imprimir_indentacion();
                    fprintf(yyout_py, "while %s >= %s:\n", (yyvsp[-2].nombre), (yyvsp[0].nombre));
                    nivel_indentacion++;
                    free((yyvsp[-2].nombre)); free((yyvsp[0].nombre));
            }
#line 1733 "y.tab.c"
    break;

  case 44: /* condicion_loop: expresion MENOR_IGUAL expresion  */
#line 298 "parser.y"
                                                 { // NUMERO '<=' ID
                    imprimir_indentacion();
                    fprintf(yyout_py, "while %s <= %s:\n", (yyvsp[-2].nombre), (yyvsp[0].nombre));
                    nivel_indentacion++;
                    free((yyvsp[-2].nombre)); free((yyvsp[0].nombre));
            }
#line 1744 "y.tab.c"
    break;

  case 45: /* condicion_loop: expresion IGUAL_IGUAL expresion  */
#line 304 "parser.y"
                                                 {
                    imprimir_indentacion();
                    fprintf(yyout_py, "while %s == %s:\n", (yyvsp[-2].nombre), (yyvsp[0].nombre));
                    nivel_indentacion++;
                    free((yyvsp[-2].nombre)); free((yyvsp[0].nombre));
            }
#line 1755 "y.tab.c"
    break;

  case 46: /* condicion_loop: expresion  */
#line 310 "parser.y"
                        {
                    imprimir_indentacion();
                    fprintf(yyout_py, "while %s:\n", (yyvsp[0].nombre));
                    nivel_indentacion++;
                    free((yyvsp[0].nombre));
            }
#line 1766 "y.tab.c"
    break;

  case 47: /* loop_consecuencia: ID  */
#line 318 "parser.y"
                      {
                    struct entrada_tabla *entrada = buscar_variable((yyvsp[0].nombre));
                if (entrada == NULL){
                    printf("Error semántico: la variable '%s' no fue declarada en este bloque.\n", (yyvsp[0].nombre));
                    (yyval.nombre) = strdup("");
                } else {
                    (yyval.nombre) = strdup("");
                }
            }
#line 1780 "y.tab.c"
    break;

  case 48: /* loop_consecuencia: ID '+' '+'  */
#line 327 "parser.y"
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
#line 1796 "y.tab.c"
    break;

  case 49: /* loop_consecuencia: '-' '-' ID  */
#line 338 "parser.y"
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
#line 1812 "y.tab.c"
    break;

  case 50: /* loop_consecuencia: ID '=' expresion  */
#line 349 "parser.y"
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
#line 1829 "y.tab.c"
    break;

  case 51: /* expresion: ID  */
#line 363 "parser.y"
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
#line 1847 "y.tab.c"
    break;

  case 52: /* expresion: NUMERO  */
#line 376 "parser.y"
                   {
                char buf[50];
                sprintf(buf, "%g", (yyvsp[0].val_num));
                (yyval.nombre) = strdup(buf);
          }
#line 1857 "y.tab.c"
    break;

  case 53: /* expresion: expresion '+' expresion  */
#line 381 "parser.y"
                                    {
                char buf[256];
                sprintf(buf, "%s + %s", (yyvsp[-2].nombre), (yyvsp[0].nombre));
                (yyval.nombre) = strdup(buf);
                free((yyvsp[-2].nombre)); free((yyvsp[0].nombre)); // Limpiamos memoria de los hijos
          }
#line 1868 "y.tab.c"
    break;

  case 54: /* expresion: expresion '-' expresion  */
#line 387 "parser.y"
                                    {
                char buf[256];
                sprintf(buf, "%s - %s", (yyvsp[-2].nombre), (yyvsp[0].nombre));
                (yyval.nombre) = strdup(buf);
                free((yyvsp[-2].nombre)); free((yyvsp[0].nombre));
          }
#line 1879 "y.tab.c"
    break;

  case 55: /* expresion: expresion '*' expresion  */
#line 393 "parser.y"
                                    {
                char buf[256];
                sprintf(buf, "%s * %s", (yyvsp[-2].nombre), (yyvsp[0].nombre));
                (yyval.nombre) = strdup(buf);
                free((yyvsp[-2].nombre)); free((yyvsp[0].nombre));
          }
#line 1890 "y.tab.c"
    break;

  case 56: /* expresion: '(' expresion ')'  */
#line 399 "parser.y"
                              {
                char buf[256];
                sprintf(buf, "(%s)", (yyvsp[-1].nombre));
                (yyval.nombre) = strdup(buf);
                free((yyvsp[-1].nombre));
          }
#line 1901 "y.tab.c"
    break;

  case 57: /* $@4: %empty  */
#line 407 "parser.y"
                          {
            imprimir_indentacion();
            fprintf(yyout_py, "if ");
        }
#line 1910 "y.tab.c"
    break;

  case 58: /* $@5: %empty  */
#line 410 "parser.y"
                           {
            fprintf(yyout_py, ":\n");
            nivel_indentacion++;
        }
#line 1919 "y.tab.c"
    break;

  case 59: /* $@6: %empty  */
#line 413 "parser.y"
                                { 
            nivel_indentacion--;
        }
#line 1927 "y.tab.c"
    break;

  case 61: /* $@7: %empty  */
#line 416 "parser.y"
                                   {
            
        }
#line 1935 "y.tab.c"
    break;

  case 62: /* $@8: %empty  */
#line 418 "parser.y"
             {
            /*if($1 == float){
                printf("Error, prohibida sintaxis para switch, la expresion debe ser entera, arreglar linea %d\n", yylineno);
             } TODO cambiar esto cuando ya tengamos un verificador de tipos*/ 
            imprimir_indentacion();
            fprintf(yyout_py, "match %s:\n", (yyvsp[-3].nombre));
            nivel_indentacion++;
            free((yyvsp[-3].nombre));
        }
#line 1949 "y.tab.c"
    break;

  case 63: /* condicionales: SWITCH '(' expresion ')' $@7 '{' $@8 switch_cases '}'  */
#line 426 "parser.y"
                           {
            nivel_indentacion--;
        }
#line 1957 "y.tab.c"
    break;

  case 64: /* $@9: %empty  */
#line 431 "parser.y"
                             { 
                // Traducimos el 'else if' de C al 'elif' de Python
                imprimir_indentacion(); 
                fprintf(yyout_py, "elif "); 
           }
#line 1967 "y.tab.c"
    break;

  case 65: /* $@10: %empty  */
#line 436 "parser.y"
                            { 
                fprintf(yyout_py, ":\n"); 
                nivel_indentacion++;
           }
#line 1976 "y.tab.c"
    break;

  case 66: /* $@11: %empty  */
#line 440 "parser.y"
                                 {
                nivel_indentacion--;
           }
#line 1984 "y.tab.c"
    break;

  case 68: /* $@12: %empty  */
#line 444 "parser.y"
                { 
                // El caso base de cierre: un 'else:' simple
                imprimir_indentacion(); 
                fprintf(yyout_py, "else:\n"); 
                nivel_indentacion++;
           }
#line 1995 "y.tab.c"
    break;

  case 69: /* bloque_else: ELSE $@12 '{' instrucciones '}'  */
#line 450 "parser.y"
                                 {
                nivel_indentacion--;
           }
#line 2003 "y.tab.c"
    break;

  case 71: /* $@13: %empty  */
#line 457 "parser.y"
                                    {
                    if (strchr((yyvsp[-1].nombre), '_') != NULL) {
                        printf("[Error Semántico] Línea %d: El valor del 'case' debe ser una constante, no una variable ('%s').\n", yylineno, (yyvsp[-1].nombre));
                    } //si expresion trae un _ en su nombre, significa que es una variable, algo prohbido en c
                    imprimir_indentacion();
                    fprintf(yyout_py, "case %s:\n", (yyvsp[-1].nombre));
                    nivel_indentacion++; //subimos la indentación para las instrucciones de este case específico
                    free((yyvsp[-1].nombre));
    }
#line 2017 "y.tab.c"
    break;

  case 72: /* $@14: %empty  */
#line 465 "parser.y"
                              {
        nivel_indentacion--;
    }
#line 2025 "y.tab.c"
    break;

  case 74: /* $@15: %empty  */
#line 468 "parser.y"
                              {
                    // Opcional: Agregamos soporte para el 'default:' de C -> 'case _:' de Python
                    imprimir_indentacion();
                    fprintf(yyout_py, "case _:\n");
                    nivel_indentacion++;
              }
#line 2036 "y.tab.c"
    break;

  case 75: /* switch_cases: DEFAULT ':' $@15 instrucciones  */
#line 474 "parser.y"
                            {
                    nivel_indentacion--;
              }
#line 2044 "y.tab.c"
    break;

  case 76: /* switch_cases: error switch_cases  */
#line 477 "parser.y"
                                     { 
                    // Si algo falla dentro de un case, Bison limpia la pila 
                    // hasta encontrar el inicio del Siguiente CASE o el cierre '}'
                    printf("[Error Sintáctico] Línea %d: 'case' mal formado o falta ';' tras el break.\n", yylineno);
                    yyerrok; // Indica a Bison que ya retomamos el control
              }
#line 2055 "y.tab.c"
    break;

  case 78: /* condicion_IF: expresion '=' expresion  */
#line 487 "parser.y"
                                          {
                    printf("Error: aunque C acepte la forma condicional('expresion = expresion'), python no lo hace, por favor, corregir la línea %d.\n", yylineno);
                    fprintf(yyout_py, "%s = %s", (yyvsp[-2].nombre), (yyvsp[0].nombre));
                    free((yyvsp[-2].nombre)); free((yyvsp[0].nombre));
            }
#line 2065 "y.tab.c"
    break;

  case 79: /* condicion_IF: expresion '>' expresion  */
#line 492 "parser.y"
                                         {
                    fprintf(yyout_py, "%s > %s", (yyvsp[-2].nombre), (yyvsp[0].nombre));
                    free((yyvsp[-2].nombre)); free((yyvsp[0].nombre));
            }
#line 2074 "y.tab.c"
    break;

  case 80: /* condicion_IF: expresion '<' expresion  */
#line 496 "parser.y"
                                         {
                    fprintf(yyout_py, "%s < %s", (yyvsp[-2].nombre), (yyvsp[0].nombre));
                    free((yyvsp[-2].nombre)); free((yyvsp[0].nombre));
            }
#line 2083 "y.tab.c"
    break;

  case 81: /* condicion_IF: expresion MAYOR_IGUAL expresion  */
#line 500 "parser.y"
                                                 {
                    fprintf(yyout_py, "%s >= %s", (yyvsp[-2].nombre), (yyvsp[0].nombre));
                    free((yyvsp[-2].nombre)); free((yyvsp[0].nombre));
            }
#line 2092 "y.tab.c"
    break;

  case 82: /* condicion_IF: expresion MENOR_IGUAL expresion  */
#line 504 "parser.y"
                                                 { // NUMERO '<=' ID
                    fprintf(yyout_py, "%s <= %s", (yyvsp[-2].nombre), (yyvsp[0].nombre));
                    free((yyvsp[-2].nombre)); free((yyvsp[0].nombre));
            }
#line 2101 "y.tab.c"
    break;

  case 83: /* condicion_IF: expresion IGUAL_IGUAL expresion  */
#line 508 "parser.y"
                                                 {
                    fprintf(yyout_py, "%s == %s", (yyvsp[-2].nombre), (yyvsp[0].nombre));
                    free((yyvsp[-2].nombre)); free((yyvsp[0].nombre));
            }
#line 2110 "y.tab.c"
    break;

  case 84: /* condicion_IF: expresion  */
#line 512 "parser.y"
                        {
                    fprintf(yyout_py, "%s", (yyvsp[0].nombre));
                    free((yyvsp[0].nombre));
            }
#line 2119 "y.tab.c"
    break;


#line 2123 "y.tab.c"

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

#line 518 "parser.y"


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
