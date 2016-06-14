#include <iostream>
#include <string.h>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
ll gcd(ll x, ll y){
if (!x || !y) return x > y ? x : y;
for (ll t; t = x % y; x = y, y = t);
return y;
}
int main(){
	ll n;
	ll a[1000];
	int k;
	while (cin>>n){
		k=0;
		for (ll i=1;i*i<=n;i++){
			if (n%i==0)
				a[k++]=i;
		}
		int x[64],y[64],s=0,z[64];
		memset(x,0,sizeof(x));
		while (n){
			x[s++]=n%2;
			n/=2;
		}
		s=0;
		for (int i=0;i<k;i++){
			memset(y,0,sizeof(y));
			while (a[i]){
				y[s++]=a[i]%2;
				a[i]/=2;
			}
			for (int i=0;i<64;i++)
		}
		for (int i=1;i<n;i++){
			cout<<(i^n)<<" ";
		}
		cout<<endl;
	}
	return 0;
}