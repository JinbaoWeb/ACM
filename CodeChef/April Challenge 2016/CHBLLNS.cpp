#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll R,G,B;
	ll t,k;
	cin>>t;
	while (t--){
		cin>>R>>G>>B;
		cin>>k;
		ll ans=min(k-1,R)+min(k-1,G)+min(k-1,B);
		cout<<ans+1<<endl;
	}
	return 0;
}