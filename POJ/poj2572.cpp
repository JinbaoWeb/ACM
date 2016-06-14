#include <iostream>
#include <string.h>
using namespace std;
int main(){
	int a,b,c;
	char s[100];
	while (cin>>s){
		a=0;b=0;c=0;
		int len=strlen(s);
		while (len--){	//c
			if (s[len]=='=')
				break;
			c=c*10+s[len]-'0';
		}
		while (len--){	//b
			if (s[len]=='+')
				break;
			b=b*10+s[len]-'0';
		}
		while (len--){	//a
			a=a*10+s[len]-'0';
		}
		//cout<<a<<" "<<b<<" "<<c<<endl;
		if (a==c-b){
			cout<<"True"<<endl;
		}
		else{
			cout<<"False"<<endl;
		}
	}
	return 0;
}