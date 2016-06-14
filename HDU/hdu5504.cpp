#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[70];
int main(){
	int t,n;
	scanf("%d",&t);
	while (t--){
		scanf("%d",&n);
		ll mul=1;
		for (int i=0;i<n;i++){
			scanf("%lld",&a[i]);
			if (a[i]==0)
				continue;
			mul*=a[i];
		}
		if (n==1 && a[0]<=0){
			cout<<a[0]<<endl;
			continue;
		}
		sort(a,a+n);
		if (n==2 && a[1]==0){
			cout<<a[0]<<endl;
			continue;
		}
		if (mul<0){
			int flag=0;
			for (int i=0;i<n-1;i++){
				if (a[i]<0 && a[i+1]>=0){
					flag=1;
					mul/=a[i];
				}
			}
			if (flag==0)
				mul/=a[n-1];
		}
		cout<<mul<<endl;
	}
	return 0;
}