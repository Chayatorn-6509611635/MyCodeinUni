%{
#include <stdio.h>
int yylval;
%}

%%
0|[1-9][0-9]{0,3}           {yylval = atoi(yytext); 
                                if(yylval < 0 || yylval > 9999){
                                    printf("Error: Number must be >=0 and <=9999. Your entered number = %s \n", yytext);
                                }else{
                                    printf("yytext: %s, yylval.number: %d",yytext, yylval);
                                }
                            }
[a-zA-Z_$][a-zA-Z0-9_$]*    {printf("yytext: %s\n", yytext);}
[\t ]*                      { /* Ignore whitespace */}
.                           {printf("Error: Invalid character\n");}
%%