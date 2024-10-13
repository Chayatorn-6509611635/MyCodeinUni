%{
#include <stdio.h>
#include "parse.tab.h"

%}

%%
"+"                        { yylval.op = yytext[0]; /*printf("Token: ADD\n"); */return OPERATOR; }
"-"                        { yylval.op = yytext[0]; /*printf("Token: SUB\n"); */return OPERATOR; }
"*"                        { yylval.op = yytext[0]; /*printf("Token: MUL\n"); */return OPERATOR; }
"/"                        { yylval.op = yytext[0]; /*printf("Token: DIV\n"); */return OPERATOR; }
0|[+-]?[1-9][0-9]{0,3}     {    
                                yylval.number = atoi(yytext); 
                                return NUMBER; 
                           }
[a-zA-Z_$][a-zA-Z0-9_$]*   {    
                                sprintf(yylval.identifier, "%s", yytext); 
                                return IDENTIFIER;
                           }
\n                         { return EOL; }
[\t ]+                     { /* Ignore whitespace */ }
.                          { return EOL; }
%%

int yywrap() {
    return 1;
}