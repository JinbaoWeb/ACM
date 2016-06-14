#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
int main(){
	ll n,m;
	while (~scanf("%lld%lld",&n,&m)){
		ll ans=1;
		ll k=1;
		for (ll i=1;i<=m;i++){
			k=k*n%mod;
			ans=(ans+k)%mod;
		}
		cout<<ans<<endl;
	}
	return 0;
}