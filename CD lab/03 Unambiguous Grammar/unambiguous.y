%{
	#include<stdio.h>
	void yyerror(char*);
	extern int yylex(void);
%}
%token NUM
%% 
S:
S E '\n'	{printf("%d\n", $2);}
|
;
E:
E '+' T		{$$=$1+$3;}
|E '-' T	{$$=$1-$3;}
|T		{$$=$1;}
T:
T '*' F		{$$=$1*$3;}
|T '/' F	{$$=$1/$3;}
|F
F:
'(' E ')'	{$$=$2;}
|NUM		{$$=$1;}
%%
void yyerror(char* s)
{
	printf("%s\n", s);
}
int main()
{
	yyparse();
	return 0;
}