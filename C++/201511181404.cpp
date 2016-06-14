#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100000+10];
ll Sum(ll x){
	ll ans=0;
	while (x){
		ans+=x%10;
		x/=10;
	}
	return ans;
}
int num[100];
int main(){
	int n,t;
	int cas=1;
	while (~scanf("%d%d",&n,&t)){
		if (n==-1 && t==-1)
			break;
		a[0]=n;
		ll sum=0;
		for (int i=1;i<=t;i++){
			sum+=Sum(a[i-1]);
			a[i]=sum;
		}
		ll l=0,r=0;
		int flag=0;
		for (int i=0;i<=t;i++){
			int k=0;
			while (a[i]){
				num[k++]=a[i]%10;
				a[i]/=10;
			}
			for (int j=k-1;j>=0;j--){
				if (flag==0)
					l+=num[j];
				if (flag==1)
					r+=num[j];
				flag=(flag+1)%2;
			}
		}
		printf("Case #%d: ", cas++);
		int tmep=abs(l-r);
		if (tmep%11==0)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}