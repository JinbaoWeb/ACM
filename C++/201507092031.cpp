#include <iostream>
using namespace std;
int main(){
	int n,m;
	while (cin>>m>>n){
		long long ans=0;
		for (int i=0;i<n;i++){
			ans+=(m-i/2);
		}
		cout<<ans<<endl;
	}
	return 0;
}