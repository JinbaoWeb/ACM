#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000000+9;
ll a[100000],b[100000];
ll mul[100000];
ll Pow(int x,int y){
	if (y==0)
		return 1;
	ll ans=1;
	for (int i=0;i<y;i++){
		ans=ans*x;
	}
	return ans;
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=0;i<n/k;i++)
		scanf("%I64d",&a[i]);
	for (int i=0;i<n/k;i++)
		scanf("%I64d",&b[i]);
	for (int i=0;i<n/k;i++){
		ll Max=Pow(10,k)-1;
		ll l=b[i]*Pow(10,k-1),r;
		if (a[i]==9)
			r=Pow(10,k);
		else
			r=(b[i]+1)*Pow(10,k-1);
		r--;
		ll k1,k2;
		if (l%a[i]==0)
			k1=l;
		else
			k1=(l/a[i]+1)*a[i];
		if (r%a[i]==0)
			k2=r;
		else
			k2=(r/a[i])*a[i];
		ll num=1ll*(k2-k1)/a[i]+1;
		ll num2=1ll*Max/a[i]+1;
		//if (b[i]==0)
		//	num2++;
		mul[i]=num2-num;
		cout<<k1<<" "<<k2<<" "<<num<<" "<<num2<<" "<<mul[i]<<endl;
		/*
		cout<<l<<" "<<r<<" ";
		cout<<r/a[i]<<" "<<l/a[i]<<" ";
		int k1=r/a[i]-l/a[i];
		int k=Max/a[i]-k1;
		if (Max%a[i]!=0)
			k++;
		cout<<k1<<" "<<k<<endl;;
		mul[i]=k;
		*/
	}
	ll ans=1;
	for (int i=0;i<n/k;i++){
		ans=(ans*mul[i]+MOD)%MOD;
	}
	cout<<ans<<endl;
	return 0;
}