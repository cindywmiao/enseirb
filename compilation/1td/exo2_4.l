%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
%}
%%
[a-zA-Z_][a-zA-Z_0-9]* {yylval.s = strdup(yytext); return ID; }
[+-]?[0-9][0-9]* {yylval.n = atoi(yytext); return N; }
\n {}
[+\-*=;()] {return yytext[0]; }
. {}
%%