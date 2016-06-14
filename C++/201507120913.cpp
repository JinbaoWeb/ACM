#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
const int MAXN = 262144+2;
#define M 1000000007
ll a[MAXN];
ll gcd(ll x, ll y){
	if (!x || !y) return x > y ? x : y;
	for (ll t; t = x % y; x = y, y = t);
	return y;
}
ll lcm(ll x,ll y){
	ll k=gcd(x,y);
	return (x*y/k)%M;
}
int main(){
	int t,n,m,x,y;
	cin>>t;
	for (int cas=1;cas<=t;cas++){
		cin>>n>>m;
		for (int i=1;i<=n;i++)
			cin>>a[i];
		cout<<"Case #"<<cas<<":"<<endl;
		while (m--){
			cin>>x>>y;
			ll ans=1;
			for (int i=x;i<=y;i++){
				ans=lcm(ans,a[i])%M;
			}
			cout<<ans<<endl;
		}
	}
	

	return 0;
}

/*
2
2 2
131072 131071
1 1
1 2
9 3
1125 468 5694 5624 3885 4521 2654 3541 125960
2 5
3 9
5 8

*/