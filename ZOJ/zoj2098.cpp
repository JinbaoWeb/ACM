#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;
typedef long long ll;
ll C(ll n,ll m){
	if (m==0)
		return 1;
	ll ans=1;
	ll t;
	if (m>n-m)
		t=n-m;
	else
		t=m;
	for (ll i=1;i<=t;i++)
		ans=ans*(n-i+1)/i;
	return ans;
}
int main(){
	int n,k;
	int a[100],b[100];
	while (cin>>n>>k){
		if (n==k && k==-1)
			break;
		ll sum=0;
		for (int i=0;i<n;i++){
			cin>>a[i];
			sum+=a[i];
		}
		ll ans1=C(sum,k);
		ll ans2=1;
		for (int i=0;i<n;i++){
			cin>>b[i];
			ans2*=C(a[i],b[i]);
		//	cout<<ans2<<"-----------"<<endl;
		}
	//	cout<<ans1<<"  "<<ans2<<endl;
		double ans = ans2 * 1.0 / ans1;
		cout<<fixed<<setprecision(5)<<ans<<endl;
	}
	return 0;
}
