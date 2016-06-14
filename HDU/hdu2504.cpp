#include <iostream>
using namespace std;
typedef long long ll;
ll gcd(ll x, ll y){
if (!x || !y) return x > y ? x : y;
for (ll t; t = x % y; x = y, y = t);
return y;
}
int main(){
	ll n,a,b;
	cin>>n;
	while (n--){
		cin>>a>>b;
		ll k=a/b;
		for (ll i=2;;i++){
			if (gcd(i,k)!=1)
				continue;
			else{
				cout<<b*i<<endl;
				break;
			}
		}
	}
	return 0;
}