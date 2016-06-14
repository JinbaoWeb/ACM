#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;
ll a[200000+5];
ll Min(ll a,ll  b){
	return a<b?a:b;
}
int main(){
	ll n,w;
	while (cin>>n>>w){
		for (int i=0;i<2*n;i++)
			cin>>a[i];
		sort(a,a+2*n);
		ll x=a[0],y=a[n];
		ll k=Min(2*x,y);
		if (3*k*n/2.0>1.0*w)
			cout<<w<<endl;
		else
			cout<<3*k*n/2.0<<endl;
	}
	return 0;
}