#include <iostream>
#include <string.h>
using namespace std;
int main(){
	int t,i;
	char s[100];
	cin>>t;
	while (t--){
		cin>>s;
		int ans=0;
		for (i=0;i<8;i++){
			ans=ans*2+s[i]-'0';
		}
		cout<<ans<<".";
		ans=0;
		for (i=8;i<16;i++){
			ans=ans*2+s[i]-'0';
		}
		cout<<ans<<".";
		ans=0;
		for (i=16;i<24;i++){
			ans=ans*2+s[i]-'0';
		}
		cout<<ans<<".";
		ans=0;
		for (i=24;i<32;i++){
			ans=ans*2+s[i]-'0';
		}
		cout<<ans<<endl;
	}
	return 0;
}