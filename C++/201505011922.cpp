/*******************************************************************************
 * Author :          jinbao
 * Email :           dongjinbao913106840144@gmail.com
 * Last modified :   2015-05-01 19:22
 * Filename :        201505011922.cpp
 * Description :     
 * *****************************************************************************/
#include <iostream>
using namespace std;
typedef long long ll;
int main(){
	ll t,n,x,y;
	cin>>t;
	while (t--){
		cin>>n;
		ll sum=0;
		for (int y=0;y*2<=n;y++){
			x=n-2*y;
			ll k=x+y;
			ll min=(x<y?x:y);
		//	cout<<k<<" "<<min<<endl;
			ll ans=1;
			for (ll i=0;i<min;i++){
				ans*=(k)/(i+1);
			}
		//	cout<<ans<<endl;
			sum+=ans;
		}
		cout<<sum<<endl;

	}

	return 0;
}
