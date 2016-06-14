#include <iostream>
#include <string.h>
using namespace std;
int main(){
	char s[55];
	int a[55],b;
	while (cin>>s>>b){
		int len=strlen(s),flag=0;
		if (s[0]=='-')
			flag=1;
		int c=0;
		for (int k=flag;k<len;k++){
			c=(c*10+s[k]-'0')%b;
		}
		if (flag)
			cout<<'-';
		cout<<c<<endl;
	}
	return 0;
}
