#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
ll mod_mul(ll a, ll b, ll n) {
    ll res = 0;
	while(b) {
	if(b&1)    res = (res + a) % n;
        a = (a + a) % n;
        b >>= 1;
    }
return res;
}
ll mod_pow(ll a,ll b){
    ll res=1;
    while (b>0){
        if (b&1)    res=mod_mul(res,a,mod);
        a=mod_mul(a,a,mod);
        b>>=1;
    }
    return res;
}
ll mod_pow_sum(ll n,ll m){
	if (m==1)
		return n;
	if (m&1){
		return (mod_pow(n,m)+mod_pow_sum(n,m-1))%mod;
	}
	return mod_mul(mod_pow(n,m/2)+1,mod_pow_sum(n,m/2),mod);
}
int main(){
	ll n,m;
	while (~scanf("%lld%lld",&n,&m)){
		if (m==0){
			cout<<1<<endl;
			continue;
		}
		if (n==1){
			cout<<1<<endl;
			continue;
		}
		cout<<mod_pow_sum(n,m)+1<<endl;
	}

	return 0;
}