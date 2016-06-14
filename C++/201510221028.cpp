#include <bits/stdc++.h>
using namespace std;
int main(){
	char s[20];
	while (cin>>s){
		int ans=0;
		for (int i=1;i<8;i++){
			ans=ans*2+s[i]-'0';
		}
		cout<<"yuan:"<<ans<<endl;
		if (s[0]=='1'){
			for (int i=1;i<8;i++){
				s[i]=(s[i]-'0'+1)%2+'0';
			}
		}
		ans=0;
		for (int i=1;i<8;i++){
			ans=ans*2+s[i]-'0';
		}
		cout<<"fan:"<<ans<<endl;
	}
	return 0;
}