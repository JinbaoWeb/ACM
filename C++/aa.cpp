#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char str[3145728+5];
char s[3145728+5];
int main(){
	int t;
	cin>>t;
	while (t--){
		cin>>str;
		int len=strlen(str),k=0;
		for (int i=0;i<len;i++){
			if (str[i]=='v' && str[i+1]=='v'){
				s[k++]='w';
				i+=2;
				for (;i<len;i++)
					if (str[i]!='v')
						break;
			}
			
			s[k++]=str[i];
		}
		s[k]=0;
		//cout<<s<<endl;
		int flag=0;
		int a=0,b=0,c=0;
		for (int i=0;i<k;i++){
			if (s[i]=='w' )
				a=1;
			if (a==1 && s[i]=='y')
				b=1;
			if (a==1 && b==1 && s[i]=='h'){
				c=1;
			}
		}
		if (a+b+c!=3)
			cout<<"No\n";
		else
			cout<<"Yes\n";
	}
	return 0;
}