#include <iostream>
using namespace std;
int main(){
	int a[33];
	int n,t;
	cin>>t;
	while (t--){
		cin>>n;
		int k=0;
		while (n){
			a[k++]=n%2;
			n/=2;
		}
		int ans=0,s=0;
		while (s<k){
			ans = ans*2+a[s++];
		}
		cout<<ans<<endl;
	}
	return 0;
}