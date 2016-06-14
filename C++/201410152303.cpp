#include <iostream>
#include <string.h>
using namespace std;
int main(){
	char s[100];
	int count=0;
	while (cin.getline(s,100)){
		int len=strlen(s);
		for (int i=0;i<len;i++){
			if (s[i]=='f'&&s[i+1]=='f'){
				i+=2;
				if (s[i+2]=='i'||s[i+2]=='l')
					i++;
			}
			if (s[i]=='f'&&s[i+1]=='i')
				i+=2;
			if (s[i]=='f'&&s[i+1]=='l')
				i+=2;
			count++;
		}
		cout<<count<<endl;
	}
	cout<<count<<endl;
	return 0;
} 


//ff¡±, ¡°fi¡±, ¡°ffi¡±, ¡°fl¡±, and ¡°ffl¡± 
