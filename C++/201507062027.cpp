#include <iostream>
#include <math.h>
using namespace std;
typedef long long ll;
int main(){
	ll n,a[100];
	while (cin>>n){
		for (int i=1;i<=n;i++)
			cin>>a[i];
		int x,y;
		ll sum=0;
		cin>>x>>y;
		for (int i=x;i<=y;i++)
			sum+=a[i];
		cout<<sum<<endl;
		ll ans=round(sum*1.0/(y-x+1));
		cout<<ans<<endl;
	}
	return 0;
}