#include <iostream>
#include <stdio.h>
#define c 10000000007
using namespace std;
typedef long long ll;
ll mod_mul(ll a, ll b, ll n) {
    ll res = 0;
    while(b) {
    	//cout<<"-"<<b<<endl;
        if(b&1)    res = (res + a) % n;
        a = (a + a) % n;
        b /=2;
    }
    return res;
}
ll mod_exp(ll a, ll b, ll n) {
    ll res = 1;
    while(b) {
    	//cout<<"--------"<<endl;
        if(b&1)    res = mod_mul(res, a, n);
        a = mod_mul(a, a, n);
        b /=2;
    }
    return res;
}
int main(){
	ll a,b;
	int t;
	scanf("%d",&t);
	while (t--){
		scanf("%lld%lld",&a,&b);
		int flag=0;
		ll ans = mod_exp(a,b,c);
		if (a<0&&b%2!=0)
			printf("-");
		printf("%lld\n",ans);
	}
}


