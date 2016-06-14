#include <iostream>
#include <string.h>
using namespace std;
int main(){
	char ss[10000],s;
	while (gets(ss)){
		int len=strlen(ss),i=0;
		while (i<len){
			s=ss[i++];
			if (s=='W')	cout<<'Q';
			else if (s=='E')	cout<<'W';
			else if (s=='R')	cout<<'E';
			else if (s=='T')	cout<<'R';
			else if (s=='Y')	cout<<'T';
			else if (s=='U')	cout<<'Y';
			else if (s=='I')	cout<<'U';
			else if (s=='O')	cout<<'I';
			else if (s=='P')	cout<<'O';
			else if (s=='[')	cout<<'P';
			else if (s==']')	cout<<'[';
			else if (s=='\\')	cout<<']';
			
			else if (s=='S')	cout<<'A';
			else if (s=='D')	cout<<'S';
			else if (s=='F')	cout<<'D';
			else if (s=='G')	cout<<'F';
			else if (s=='H')	cout<<'G';
			else if (s=='J')	cout<<'H';
			else if (s=='K')	cout<<'J';
			else if (s=='L')	cout<<'K';
			else if (s==';')	cout<<'L';
			else if(s=='\'')	cout<<';';

			else if (s=='X')	cout<<'Z';
			else if (s=='C')	cout<<'X';
			else if (s=='V')	cout<<'C';
			else if (s=='B')	cout<<'V';
			else if (s=='N')	cout<<'B';
			else if (s=='M')	cout<<'N';
			else if (s==',')	cout<<'M';
			else if (s=='.')	cout<<',';
			else if (s=='/')	cout<<'.';

			else if (s=='2')	cout<<'1';
			else if (s=='3')	cout<<'2';
			else if (s=='4')	cout<<'3';
			else if (s=='5')	cout<<'4';
			else if (s=='6')	cout<<'5';
			else if (s=='7')	cout<<'6';
			else if (s=='8')	cout<<'7';
			else if (s=='9')	cout<<'8';
			else if (s=='0')	cout<<'9';
			else if (s=='-')	cout<<'0';
			else if (s=='=')	cout<<'-';

			else
				cout<<s;
		}
		cout<<endl;
		//cin.getline(ss,10000);
	}
	return 0;
}