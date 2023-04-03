#include <stdio.h>
#include <conio.h>

struct intermediate {
	int addr;
	char label[10];
	char mnem[10];
	char op[10];
} res;
struct symbol {
	char symbol[10];
	int addr;
} sy;

void main() {
	FILE *s1, *p1;
	clrscr();
	s1 = fopen("inter.txt", "r+");
	p1 = fopen("symbol.txt", "w");
	while(!feof(s1)) {
		fscanf(s1, "%d %s %s %s", &res.addr, res.label, res.mnem, res.op);
		if(strcmp(res.label, "NULL") != 0) {
			strcpy(sy.symbol, res.label);
			sy.addr = res.addr;
			fprintf(p1, "%s\t%d\n", sy.symbol, sy.addr);
		}
	}
	fcloseall();
	printf("Symbol Table Created");
	getch();
}