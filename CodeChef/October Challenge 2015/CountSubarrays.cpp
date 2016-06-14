#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000+10;
typedef long long ll;
int a[MAXN];
int main(){
	int t,n,l,r;
	cin>>t;
	while (t--){
		cin>>n;
		ll num=1;
		ll ans=0;
		cin>>l;
		for (int i=1;i<n;i++){
			cin>>r;
			//cout<<l<<" "<<r<<endl;
			if (r>=l)
				num++;
			else{
				ans+=num*(num+1)/2;
				//cout<<ans<<endl;
				num=1;
			}
			l=r;
		}
		ans+=num*(num+1)/2;
		cout<<ans<<endl;
	}
	return 0;
}