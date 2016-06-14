#include <iostream>
using namespace std;
typedef long long ll;
int main(){
	ll t,n,k,x;
	while (cin>>t){
		while (t--){
			cin>>n>>k;
			ll ans=1;
			ll left=k;
			for (int i=0;i<n;i++){
				cin>>x;
				if (x<left)
					left-=(x+1);
				else if (x==left)
					left=0;
				else{
					ll temp=x-left;
					//cout<<temp<<endl;
					ll temp2=temp/k+(temp%k==0?0:1);
					//cout<<left<<" "<<temp2<<endl;
					ans+=temp2;
					left+=temp2*k;
					left-=x;
					if (left>0)
						left--;
				}
			}
			cout<<ans<<endl;
		}
	}

	return 0;
}