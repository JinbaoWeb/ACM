#include <iostream>
#include <fstream>
using namespace std;
int main(){
	ifstream cin("b.in");
	ofstream cout("b.out");
	int t,n,x;
	cin>>t;
	while (t--){
		cin>>n;
		int ans=100000;
		for (int i=0;i<n;i++){
			cin>>x;
			ans=min(x,ans);
		}
		cout<<ans<<endl;
	}
	return 0;
}