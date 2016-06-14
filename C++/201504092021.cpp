#include <iostream>
#include <string.h>
using namespace std;
typedef long long ll;
ll mod(char s[],int m){
	int len=strlen(s);
	ll ans=0;
	for (int i=0;i<len;i++){
		ans=(ans*10+s[i]-'0')%m;
	}
	return ans;
}
int main(){
	char a[105],b[105];
	ll m,t;
	cin>>t;
	while (t--){
		cin>>a>>b>>m;
		cout<<(mod(a,m)*mod(b,m))%m<<endl;
	}
	return 0;
}
