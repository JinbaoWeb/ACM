#include <iostream>
#include <fstream>
using namespace std;
int main(){
	//ifstream cin("c.in");
	//ofstream cout("c.out");
	int t,n,m;
	cin>>t;
	while (t--){
		cin>>n>>m;
		int ans=0;
		for (int i=1;i<=n;i++){
			if (i%m!=0)
				ans+=i;
		}
		cout<<ans<<endl;
	}
	return 0;
}