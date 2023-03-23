%option noyywrap
%{
	#include<stdio.h>
	void yyerror(char*);
%}
letter [a-zA-Z]
digit [0-9]
op [-+*]
%%
else|int|float {printf("%s is a keyword\n", yytext);}
{digit}+ {printf("%s is a number\n", yytext);}
{letter}({letter}|{digit})* {printf("%s is an identifier\n", yytext);}
{op} {printf("%s is an operator\n", yytext);}
. yyerror("error");
%%
void yyerror(char* s)
{
	printf("%s\n", s);
}
int main()
{
	yylex();
	return 0;
}