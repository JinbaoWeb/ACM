#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int MOD = 1e9+7;
ll pow_mod(ll x,ll n)
{
	ll ans=1;
	while (n>0)
	{
		if (n&1)
			ans=(ans*x)%MOD;
		x=(x*x)%MOD;
		n>>=1;
	}
	return ans;
}
int main()
{
	int t;
	ll n,k;
	cin>>t;
	while (t--)
	{
		cin>>n>>k;
		ll ans=pow_mod(k-1,n-1);
		ans=(ans*k)%MOD;
		cout<<ans<<endl;
	}
	return 0;
}