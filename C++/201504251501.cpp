#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
char f(char s){
	//1
	if (s=='_')	return '{';
	if (s=='-')	return '[';

	if (s=='+')	return '}';
	if (s=='=')	return ']';
	//2
	if (s=='q')	return '\'';
	if (s=='Q') return '"';

	if (s=='w')	return ',';
	if (s=='W')	return '<';

	if (s=='e')	return '.';
	if (s=='E')	return '>';

	if (s=='r')	return 'p';
	if (s=='R')	return 'P';

	if (s=='t')	return 'y';
	if (s=='T')	return 'Y';

	if (s=='y')	return 'f';
	if (s=='Y')	return 'F';

	if (s=='u')	return 'g';
	if (s=='U')	return 'G';

	if (s=='i')	return 'c';
	if (s=='I')	return 'C';

	if (s=='o')	return 'r';
	if (s=='O')	return 'R';

	if (s=='p')	return 'l';
	if (s=='P')	return 'L';

	if (s=='[')	return '/';
	if (s=='{')	return '?';

	if (s==']')	return '=';
	if (s=='}')	return '+';
	//3
	if (s=='s')	return 'o';
	if (s=='S')	return 'O';

	if (s=='d')	return 'e';
	if (s=='D')	return 'E';

	if (s=='f')	return 'u';
	if (s=='F')	return 'U';

	if (s=='g')	return 'i';
	if (s=='G')	return 'I';

	if (s=='h')	return 'd';
	if (s=='H')	return 'D';

	if (s=='j')	return 'h';
	if (s=='J')	return 'H';

	if (s=='k')	return 't';
	if (s=='K')	return 'T';

	if (s=='l')	return 'n';
	if (s=='L')	return 'N';

	if (s==';')	return 's';
	if (s==':')	return 'S';

	if (s=='\'')return '-';
	if (s=='"')	return '_';
	//4
	if (s=='z')	return ';';
	if (s=='Z')	return ':';

	if (s=='x')	return 'q';
	if (s=='X')	return 'Q';

	if (s=='c')	return 'j';
	if (s=='C')	return 'J';

	if (s=='v')	return 'k';
	if (s=='V')	return 'K';

	if (s=='b')	return 'x';
	if (s=='B')	return 'X';

	if (s=='n')	return 'b';
	if (s=='N')	return 'B';

	if (s=='<')	return 'W';
	if (s==',')	return 'w';

	if (s=='.')	return 'v';
	if (s=='>')	return 'V';

	if (s=='/')	return 'z';
	if (s=='?')	return 'Z';
	
	return s;
}
int main(){
	//ifstream cin("test.txt");
	char s;
	while (~scanf("%c",&s)){
		printf("%c",f(s));
	}
	return 0;
}
