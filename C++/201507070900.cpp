#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
ll fact[10000];
ll extgcd(ll a, ll b, ll& x, ll & y){
if (b == 0) { x=1; y=0; return a; }
	ll d = extgcd(b, a % b, x, y);
	ll t = x; x = y; y = t - a / b * y;
	return d;
}
ll mod_inverse(ll a,ll m){
	ll x,y;
	extgcd(a,m,x,y);
	return (m+x%m)%m;
}
ll mod_fact(ll n,ll p,ll &e){
	e=0;
	if (n==0)
		return 1;
	ll res=mod_fact(n/p,p,e);
	e+=n/p;
	if (n/p%2!=0)
		return res*(p-fact[n%p])%p;
	return res*fact[n%p]%p;
}
ll mod_comb(ll n,ll k){
	if (n<0||k<0|| n<k)
		return 0;
	ll e1,e2,e3;
	ll a1=mod_fact(n,e1),a2=mod_fact(k,e2),a3=mod_fact(n-k,e3);
	if (e1>e2+e3)
		return 0;
	return a1*mod_inverse(a2*a3%p,p)%p;
}
int main(){
	ll n,m;
	int t;
	while (~scanf("%d",&t)){
		while (t--){
		scanf("%lld%lld",&n,&m);
		cout<<mod_comb(n,m)<<endl;
	}


	}
	return 0;
}