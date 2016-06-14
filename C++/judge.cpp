#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[40];
ll a[20];
ll MOD(ll x,ll y)
{
	ll res=0;
	for (int i=0;i<32;i++)
	{
		res=(res*x+(s[i]-'0'))%y;
	}
	return res;
}
int main(){
	memset(s,0,sizeof(s));
	while (cin>>s){
		for (int i=2;i<11;i++){
			cin>>a[i];
		}
		int flag=0;
		for (int i=2;i<11;i++)
		{
			if (MOD(i,a[i])!=0){
				flag=1;
				cout<<a[i]<<endl;
				break;
			}
		}
		if (flag==1){
			cout<<s<<endl;
		}
	}
	return 0;
}