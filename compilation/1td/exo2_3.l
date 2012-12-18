%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
%}
%%
[a-zA-Z_][a-zA-Z_0-9]* {return(yylval.s = strdup(yytext)); }
[+-]?[0-9][0-9]* {return(yylval.n = atoi(yytext)); }
\n {}
[+\-*=;()] {return yytext[0]; }
. {}
%%