#include <stdio.h>
#include <conio.h>
#include <string.h>

int z, i, j, c;
char a[16], stk[15];

void reduce();

void main() {
	clrscr();
	puts("GRAMMAR is \n E->E+E \n E->E*E \n E->(E) \n E->a");
	puts("Enter input string: ");
	gets(a);
	c = strlen(a);
	a[c] = '$';
	stk[0] = '$';
	puts("stack \t input \t action");
	for(i = 1, j = 0; j < c; i++, j++) {
		if(a[j] == 'a') {
			stk[i] = a[j];
			stk[i + 1] = '\0';
			a[j] = ' ';
			printf("\n%s\t%s\tshift a", stk, a);
			reduce();
		} else {
			stk[i] = a[j];
			stk[i + 1] = '\0';
			a[j] = ' ';
			printf("\n%s\t%s\tshift->%c", stk, a, stk[i]);
			reduce();
		}
	}
	if(a[j] == '$')
		reduce();
	if((stk[1] == 'E') && (stk[2] == '\0'))
		printf("\n%s\t%s\tAccept", stk, a);
	else
		printf("\n%s\t%s\terror", stk, a);
	getch();
}
void reduce() {
	for(z = 1; z <= c; z++) {
		if(stk[z] == 'a') {
			stk[z] = 'E';
			stk[z + 1] = '\0';
			printf("\n%s\t%s\tReduce by E->a", stk, a);
		}
	}
	for(z = 1; z <= c; z++) {
		if(stk[z] == 'E' && stk[z + 1] == '+' && stk[z + 2] == 'E') {
			stk[z] = 'E';
			stk[z + 1] = '\0';
			stk[z + 2] = '\0';
			printf("\n%s\t%s\tReduce by E->E+E", stk, a);
			i = i - 2;
		}
	}
	for(z = 1; z <= c; z++) {
		if(stk[z] == 'E' && stk[z + 1] == '*' && stk[z + 2] == 'E') {
			stk[z] = 'E';
			stk[z + 1] = '\0';
			stk[z + 2] = '\0';
			printf("\n%s\t%s\tReduce by E->E*E", stk, a);
			i = i - 2;
		}
	}
	for(z = 1; z <= c; z++) {
		if(stk[z] == '(' && stk[z + 1] == 'E' && stk[z + 2] == ')') {
			stk[z] = 'E';
			stk[z + 1] = '\0';
			stk[z + 2] = '\0';
			printf("\n%s\t%s\tReduce by E->(E)", stk, a);
			i = i - 2;
		}
	}
}

/*
OUTPUT:
GRAMMAR is                                                                      
 E->E+E                                                                         
 E->E*E                                                                         
 E->(E)                                                                         
 E->a                                                                           
Enter input string:                                                             
a*a+a                                                                           
stack    input   action                                                         
                                                                                
$a       *a+a$  shift a                                                         
$E       *a+a$  Reduce by E->a                                                  
$E*       a+a$  shift->*                                                        
$E*a       +a$  shift a                                                         
$E*E       +a$  Reduce by E->a                                                  
$E		   +a$  Reduce by E->E*E
$E+         a$  shift->+                                                        
$E+a         $  shift a                                                         
$E+E         $  Reduce by E->a                                                  
$E           $  Reduce by E->E+E                                                
$E           $  Accept                                                          
*/