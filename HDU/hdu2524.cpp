#include <iostream>
using namespace std;
int main(){
	int t,n,m;
	cin>>t;
	while (t--){
		cin>>n>>m;
		long long ans=0;
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				ans+=(n-i)*(m-j);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}