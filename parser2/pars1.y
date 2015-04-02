%{     /* pars1.y    Pascal Parser      Gordon S. Novak Jr.  ; 30 Jul 13   */

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

        /* define the type of the Yacc stack element to be TOKEN */

#define YYSTYPE TOKEN

TOKEN parseresult;

%}

/* Order of tokens corresponds to tokendefs.c; do not change */

%token IDENTIFIER STRING NUMBER   /* token types */

%token PLUS MINUS TIMES DIVIDE    /* Operators */
%token ASSIGN EQ NE LT LE GE GT POINT DOT AND OR NOT DIV MOD IN

%token COMMA                      /* Delimiters */
%token SEMICOLON COLON LPAREN RPAREN LBRACKET RBRACKET DOTDOT

%token ARRAY BEGINBEGIN           /* Lex uses BEGIN */
%token CASE CONST DO DOWNTO ELSE END FILEFILE FOR FUNCTION GOTO IF LABEL NIL
%token OF PACKED PROCEDURE PROGRAM RECORD REPEAT SET THEN TO TYPE UNTIL
%token VAR WHILE WITH


%%

  // program    :  statement DOT                  { parseresult = $1; }
  //            ;
  // statement  :  BEGINBEGIN statement endpart
  //                                      { $$ = makeprogn($1,cons($2, $3)); }
  //            |  IF expr THEN statement endif   { $$ = makeif($1, $2, $4, $5); }
  //            |  assignment
  //            ;
  // endpart    :  SEMICOLON statement endpart    { $$ = cons($2, $3); }
  //            |  END                            { $$ = NULL; }
  //            ;
  // endif      :  ELSE statement                 { $$ = $2; }
  //            |  /* empty */                    { $$ = NULL; }
  //            ;
  // assignment :  IDENTIFIER ASSIGN expr         { $$ = binop($2, $1, $3); }
  //            ;
  // expr       :  expr PLUS term                 { $$ = binop($2, $1, $3); }
  //            |  term 
  //            ;
  // term       :  term TIMES factor              { $$ = binop($2, $1, $3); }
  //            |  factor
  //            ;
  // factor     :  LPAREN expr RPAREN             { $$ = $2; }
  //            |  IDENTIFIER
  //            |  NUMBER
  //            ;

  program    : PROGRAM IDENTIFIER LPAREN IDENTIFIER RPAREN SEMICOLON prebegin statement DOT { parseresult = makeprogram($2, $4, $8); }
             ;

  prebegin   : variables                       { $$ = NULL; printf("VARIABLES\n"); }
             | constants prebegin              { $$ = NULL; printf("CONSTANTS\n"); }
             ;

// printf("CONSTANTS\n"); 
  constants  : CONST constant                  { $$ = NULL; }
             ;
  constant   : constinst SEMICOLON constant    { $$ = NULL; }
             | constinst SEMICOLON             { $$ = NULL; }
             ;

  constinst  : IDENTIFIER EQ NUMBER            { instconst($1, $3);}
             ;

  equalsNum  : IDENTIFIER EQ NUMBER           { $$ = binop($2, $1, $3); printf("equals number:\n"); dbugprinttok($1); dbugprinttok($2); dbugprinttok($3); }
             ;
// printf("VARIABLES\n"); 
  variables  : VAR varSet                      { $$ = NULL; }
             ;

  varSet     : varLine SEMICOLON               { $$ = NULL; } 
             | varLine SEMICOLON varSet        { $$ = NULL; }
             ;

  varLine    : varNames COLON varType          { instvars($1, findtype($3)); }
             ;
// printf("COMMA FOUND\n"); 
  varNames   : IDENTIFIER COMMA varNames       { $$ = cons($1, $3); }
             | IDENTIFIER                      { $$ = $1; }
             ;

  varType    : IDENTIFIER                      { $$ = $1; }
             ;
// printf("BEGUN_STATEMENTS\n");
// printf("BEGUN_FORLOOP\n");
  statement  :  BEGINBEGIN statement endpart   { printf("OUTER STATEMENT\n"); $$ = makeprogn($1,nconc($2, $3));  }
             |  stateLine SEMICOLON statement  { printf("MULTIPLE STATEMENTS\n"); $$ = cons($1, $3); }
             |  stateLine                      { printf("LAST EXPRESSION\n"); $$ = $1;  }
             ;
// line of statement
  stateLine  :  IF expr THEN statement endif   { $$ = makeif($1, $2, $4, $5); }
             |  forLoop                        { printf("FOR LOOP IN STATELINE\n"); $$ = $1;  }
             |  funcCall                       { printf("FUNCTION CALL\n"); $$ = $1; }
             |  assignment                     { printf("ASSIGNMENT IN STATE LINE\n"); $$ = $1;  }
             |  repeatuntil                    { printf("REPEATUNTIL\n"); $$ = $1; }
             ;
  repeatuntil:  REPEAT statement UNTIL equalsNum { printf("REPEAT UNTIL\n"); $$ = makerepeat((TOKEN) talloc(), $2, (TOKEN) talloc(), $4); }
             ;
// TOKEN makerepeat(TOKEN tok, TOKEN statements, TOKEN tokb, TOKEN expr) {
// printf("FUNCTION\n");  
  funcCall   : IDENTIFIER LPAREN expr RPAREN   { printf("FUNCTION_CALL\n"); $$ = makefuncall((TOKEN) talloc(), $1, $3); }
             ; 
// printf("FOR LOOP\n"); 
  forLoop    :  FOR assignment TO IDENTIFIER DO statement { $$ = makefor(1, (TOKEN) talloc(), $2, findid($4), NULL, NULL, $6); printf("FOR LOOP\n"); }
             ;
  endpart    :  SEMICOLON statement endpart    { $$ = cons($2, $3); }
             |  END                            { $$ = NULL; }
             ;
  endif      :  ELSE statement                 { $$ = $2; }
             |  /* empty */                    { $$ = NULL; }
             ;
  assignment :  IDENTIFIER ASSIGN expr         { printf("ASSIGNMENT\n"); $$ = binop($2, $1, $3); }
             ;
  expr       :  MINUS term                     { printf("NEGATIVE\n"); $$ = unaryop($1, $2); }
             |  expr MINUS term                { $$ = binop($2, $1, $3); }
             |  expr PLUS term                 { $$ = binop($2, $1, $3); }
             |  term                           { printf("EXPRESSION_TO_TERM\n");$$ = $1; }
             ;
  term       :  term TIMES factor              { printf("TIMES\n"); $$ = binop($2, $1, $3); }
             |  factor                         { $$ = $1; }
             ;
// printf("IDENTIFIER\n"); dbugprinttok($1); 
// printf("NUMBER\n");dbugprinttok($1); 
// printf("STRING\n");dbugprinttok($1);
  factor     :  LPAREN expr RPAREN             { $$ = $2; }
             |  IDENTIFIER                     { $$ = findid($1); }
             |  NUMBER                         { $$ = $1; }                          
             |  STRING                         { $$ = $1; }
             |  funcCall                       { printf("FUNCTION CALL\n"); $$ = $1; }           
             ;

  // printDebug : IDENTIFIER   {printf("%s\n", yylval->stringval);}
  //            ;
%%

/* You should add your own debugging flags below, and add debugging
   printouts to your programs.

   You will want to change DEBUG to turn off printouts once things
   are working.
  */

#define DEBUG          1             /* set bits here for debugging, 0 = off  */
#define DB_CONS        1             /* bit to trace cons */
#define DB_NCONC        1             /* bit to trace nconc */
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

 int labelnumber = 0;  /* sequential counter for internal label numbers */

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
  printf("IS REAL: \n");
  SYMBOL sym = searchst(tok->stringval);
  dbugprinttok(tok);
  if (sym->basicdt == REAL) {
    printf("TRUE\n");
    return 1;
  }
    printf("FALSE\n");

  return 0;
}

int isInteger(TOKEN tok) {
  printf("IS INTEGER: \n");
  dbugprinttok(tok);
  SYMBOL sym = searchst(tok->stringval);
  if (sym->basicdt == INTEGER) {
    printf("TRUE\n");
    return 1;
  }
    printf("FALSE\n");
    return 0;
}

TOKEN binop(TOKEN op, TOKEN lhs, TOKEN rhs)        /* reduce binary operator */
  { op->operands = lhs;          /* link operands to operator       */
    lhs->link = rhs;             /* link second operand to first    */
    rhs->link = NULL;            /* terminate operand list          */
    if (lhs->tokentype == IDENTIFIERTOK) {
      if (rhs->tokentype == IDENTIFIERTOK) {
        // Both identifiers
        if (isReal(lhs)) {
          if (isInteger(rhs)) {
            // Float Right side
            printf("Both identifiers, left - real, right - int\n");
            TOKEN temp = makeop(FLOATOP);
            temp->operands = rhs;
            lhs->link = temp;
          }
        }
        else {
          if (isReal(rhs)) {
            // Float left side
            printf("Both identifiers, left - int, right - real\n");
            TOKEN temp = makeop(FLOATOP);
            temp->operands = lhs;
            temp->link = rhs;
          }
        }
      }
      else {
        // Left identifier, right not
        if (isReal(lhs)) {
          // Cast right side
          if (rhs->datatype == INTEGER) {
            printf("left identifier, left - real, right - int\n");
            rhs->datatype = REAL;
            rhs->realval = (double) rhs->intval;
          }
        }
        else {
          if (rhs->datatype == REAL) {
            // Float left side
            printf("left identifier, left - int, right - real\n");
            TOKEN temp = makeop(FLOATOP);
            temp->operands = lhs;
            temp->link = rhs;
          }
        }
      }
    }
    else {
      if (rhs->tokentype == IDENTIFIERTOK) {
        // right identifier, left not
        if(lhs->datatype == REAL){
          if(isInteger(rhs)) {
            printf("right identifier, left - real, right - int\n");
            TOKEN temp = makeop(FLOATOP);
            temp->operands = rhs;
            lhs->link = temp;
          }
        }
        else {
          if(isReal(rhs)) {
            printf("right identifier, left - int, right - real\n");
            lhs->datatype = REAL;
            lhs->realval = (double) lhs->intval;
          }
        }
      }
      else {
        // right not, left not
        if (lhs->datatype == REAL) {
          if (rhs->datatype == INTEGER){
            printf("Both not identifiers, left - real, right - int\n");
            rhs->datatype = REAL;
            rhs->realval = (double) rhs->intval;

          }
        }
        else {
          if (rhs->datatype == REAL) {
            printf("Both not identifiers, left - int, right - real\n");
            lhs->datatype = REAL;
            lhs->realval = (double) lhs->intval;
          }
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
  tok->operands = fn;
  tok->whichval = FUNCALLOP;
  fn->link = args;
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
  if ( typ->kind == BASICTYPE ||
       typ->kind == POINTERSYM)
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
  // int type = tok->datatype;
  // if(type == INTEGER) {
  //   tok->symtype = searchst("integer");
  // }
  // else if(type == REAL) {
  //   tok->symtype = searchst("real");
  // }
  // else if(type == BOOLETYPE) {
  //   tok->symtype = searchst("boolean");
  // }
  // else{
  //   tok->symtype = searchst(tok->stringval);
  // }

  SYMBOL sym, typ;        /* symbol table entry and its type */
  sym = searchst(tok->stringval);     /* look up the name in the table */
        
     //tok->symentry = sym;                /* point token to its sym entry  */
    //printf("This is what symentry looks like: %")
     //typ = sym->datatype;                /* get the type of the symbol    */

     
   if(sym->kind == BASICTYPE ) //then the token is itself a basic datatype (Integer, Real, String, Bool)
   {
      tok->symtype = sym; 
      tok->datatype = sym->basicdt; 
        
   }
  else if(sym->kind == TYPESYM)
  {
      tok->symtype = sym->datatype;
      
  }
  return tok;
}

void  instconst(TOKEN idtok, TOKEN consttok) {
    consttok = findtype(consttok);
    SYMBOL sym, typesym;
    typesym = consttok->symtype;
    int align = alignsize(typesym);

    sym = insertsym(idtok->stringval);
    sym->kind = CONSTSYM;
    sym->offset = wordaddress(blockoffs[blocknumber], align);
    sym->size = typesym->size;
    blockoffs[blocknumber] = sym->offset + sym->size;
    sym->datatype = typesym;
    sym->basicdt = typesym->basicdt;
    if(sym->basicdt == REAL) //real
    {
        sym->constval.realnum = consttok->realval;
    }
    if(sym->basicdt == INTEGER) //int
    {
        sym->constval.intnum = consttok->intval;
    }
    
}

/* instvars will install variables in symbol table.
   typetok is a token containing symbol table pointer for type. */
void instvars(TOKEN idlist, TOKEN typetok)
  {  SYMBOL sym, typesym; int align;
     typesym = typetok->symtype;
     align = alignsize(typesym);
     while ( idlist != NULL )   /* for each id */
       {  sym = insertsym(idlist->stringval);
          sym->kind = VARSYM;
          sym->offset =
              wordaddress(blockoffs[blocknumber],
                          align);
          sym->size = typesym->size;
          blockoffs[blocknumber] =
                         sym->offset + sym->size;
          sym->datatype = typesym;
          sym->basicdt = typesym->basicdt;
          idlist = idlist->link;
        };
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
