#include <iostream>
using namespace std;
typedef long long ll;
ll fact[10000];
ll mod_fact(ll n,ll p,ll& e){
	e=0;
	if (n==0)	return 1;
	ll res=mod_fact(n/p,p,e);
	e+=n/p;
	if (n/p%2!=0)
		return res*(p-fact[n%p])%p;
	return res*fact[n%p]%p;
}
int main(){
	ll n,p;
	while (cin>>n>>p){
		if (n==1)
			cout<<1<<endl;
		else if (n==2)
			cout<<n%p<<endl;
		else if (n==3)
			cout<<6%p<<endl;
		else{
			ll e=0;
			cout<<mod_fact(n,p,e)<<endl;;
		}
	}
	return 0;
}