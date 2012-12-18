%{
#include <stdio.h>
#include "y.tab.h"
%}
%%
[a-zA-Z_][a-zA-Z_0-9]* {return ID; }
[+-]?[0-9][0-9]* {return N; }
\n {}
[+\-*=;()] {return yytext[0]; }
. {}
%%