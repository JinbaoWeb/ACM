#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 200907
ll a[4];
ll mod_pow(ll q,ll k){
	ll ans=1;
	while (k){
		if (k&1)
			ans=(ans*q)%MOD;
		q=q*q%MOD;
		k>>=1;
	}
	return ans;
}
int main(){
	int n;
	while (cin>>n){
		while (n--){
			for (int i=0;i<4;i++)
				cin>>a[i];
			if (a[2]-a[1]==a[1]-a[0]){
				ll d=a[1]-a[0];
				ll ans=a[0]+((a[3]-1)%MOD*(d%MOD))%MOD;
				cout<<ans%MOD<<endl;
			}
			else{
				ll q=a[1]/a[0];
				q%=MOD;
				a[0]%=MOD;
				ll ans=mod_pow(q,a[3]-1);
				ans=(a[0]%MOD*ans%MOD)%MOD;
				cout<<ans<<endl;
			}
		}
	}
	return 0;
}