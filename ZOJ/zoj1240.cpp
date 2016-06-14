#include <iostream>
#include <string.h>
using namespace std;
int main(){
	int t;
	char s[100];
	cin>>t;
	for (int cas=1;cas<=t;cas++){
		cin>>s;
		int len=strlen(s);
		while (len--){
			if (s[len]=='Z')
				s[len]='A';
			else
				s[len]+=1;
		}
		cout<<"String #"<<cas<<endl;
		cout<<s<<endl<<endl;;
	}
	return 0;
}