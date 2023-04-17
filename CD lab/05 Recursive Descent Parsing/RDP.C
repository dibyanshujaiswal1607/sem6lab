#include <stdio.h>
#include <conio.h>

int i = 0, f = 0;
char str[30];

void E();
void Eprime();
void T();
void Tprime();
void F();

void E() {
	printf("\nE->TE'");
	T();
	Eprime();
}
void Eprime() {
	if(str[i] == '+') {
		printf("\nE'->+TE'");
		i++;
		T();
		Eprime();
	} else if((str[i] == ')') || (str[i] == '$'))
		printf("\nE'->^");
}
void T() {
	printf("\nT->FT'");
	F();
	Tprime();
}
void Tprime() {
	if(str[i] == '*') {
		printf("\nT'->*FT'");
		i++;
		F();
		Tprime();
	} else if((str[i] == ')') || (str[i] == '+') || (str[i] == '$'))
		printf("\nT'->^");
}
void F() {
	if(str[i] == 'a') {
		printf("\nF->a");
		i++;
	} else if(str[i] == '(') {
		printf("\nF->(E)");
		i++;
		E();
		if(str[i] == ')')
			i++;
	} else
		f = 1;
}
void main() {
	int len;
	clrscr();
	printf("Enter the string: ");
	scanf("%s", str);
	len = strlen(str);
	str[len] = '$';
	E();
	if((str[i] == '$') && (f == 0))
		printf("\nString successfully parsed!");
	else
		printf("\nSyntax Error!");
	getch();
}

/*
OUTPUT:
Enter the string: a+a*a                                                         
                                                                                
E->TE'                                                                          
T->FT'                                                                          
F->a                                                                            
T'->^                                                                           
E'->+TE'                                                                        
T->FT'                                                                          
F->a                                                                            
T'->*FT'                                                                        
F->a                                                                            
T'->^                                                                           
E'->^                                                                           
String successfully parsed!                                                     
*/                                 