#include <stdio.h>
#include <conio.h>
#include <string.h>

void main() {
	char icode[10][30], str[20], opr[10];
	int i = 0;
	clrscr();
	printf("\nEnter the set of intermediate code (terminated by exit):\n");
	do {
		scanf("%s", icode[i]);
	} while(strcmp(icode[i++], "exit") != 0);
	printf("\nTarget code generation");
	printf("\n**********************");
	i = 0;
	while(strcmp(icode[i], "exit") != 0); {
		strcpy(str, icode[i]);
		switch(str[3]) {
			case '+':
				strcpy(opr, "ADD");
				break;
			case '-':
				strcpy(opr, "SUB");
				break;
			case '*':
				strcpy(opr, "MUL");
				break;
			case '/':
				strcpy(opr, "DIV");
				break;
		}
		printf("\n\tMov %c,R%d", str[2], i);
		printf("\n\t%s %c,R%d", opr, str[4], i);
		printf("\n\tMov R%d,%c", i, str[0]);
		i++;
	}
	getch();
}

/*
OUTPUT:									
Enter the set of intermediate code (terminated by exit):                        
a=b+c                                                                           
b=c-d                                                                           
c=d*e                                                                           
exit                                                                            
                                                                                
Target code generation                                                          
**********************                                                          
        Mov b,R0                                                                
        ADD c,R0                                                                
        Mov R0,a                                                                
        Mov c,R1                                                                
        SUB d,R1                                                                
        Mov R1,b                                                                
        Mov d,R2                                                                
        MUL e,R2                                                                
        Mov R2,c                                                                
*/