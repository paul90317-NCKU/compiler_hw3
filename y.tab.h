/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 52 "compiler_hw3.y" /* yacc.c:1909  */

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

#line 139 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
