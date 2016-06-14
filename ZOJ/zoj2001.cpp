#include <iostream>
#include <string.h>
using namespace std;
typedef long long ll;
int main(){
	int t;
	char s1[20],s2[20];
	cin>>t;
	while (t--){
		cin>>s1>>s2;
		int len_s1=strlen(s1);
		ll a=0;
		while (len_s1-->0){
			a=a*10+s1[len_s1]-'0';
		}
		int len_s2=strlen(s2);
		ll b=0;
		while (len_s2-->0){
			b=b*10+s2[len_s2]-'0';
		}
		ll ans=a+b;
		while (ans%10==0)
			ans/=10;
		while (ans){
			cout<<ans%10;
			ans/=10;
		}
		cout<<endl;
	}
	return 0;
}