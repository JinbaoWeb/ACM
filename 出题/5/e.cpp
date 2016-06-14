#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
int a[1005];
int main(){
	int t,n,x;
	ifstream cin("e.in");
	ofstream cout("e.out");
	cin>>t;
	while (t--){
		cin>>n;
		memset(a,0,sizeof(a));
		for (int i=0;i<n;i++){
			cin>>x;
			a[x]++;
		}
		int ans=0;
		for (int i=0;i<1005;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans<<endl;
	}

	return 0;
}