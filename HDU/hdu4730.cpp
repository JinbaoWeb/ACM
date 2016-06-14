#include <iostream>
#include <string.h>
using namespace std;
char s[205];
int main(){
	int t;
	cin>>t;
	for (int cas=1;cas<=t;cas++){
		cin>>s;
		cout<<"Case #"<<cas<<": ";
		int len=strlen(s);
		if (s[len-1]=='u' && s[len-2]=='s' && s[len-3]=='e' && s[len-4]=='d'){
			s[len-4]=0;
		}
		cout<<s<<"nanodesu"<<endl;
	}
	return 0;
}