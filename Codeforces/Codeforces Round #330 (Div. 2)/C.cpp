#include <iostream>
using namespace std;
int main(){
	int n,m,x,y;
	cin>>n>>m;
	int ans=0;
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			cin>>x>>y;
			int temp=x+y;
			if (temp>0)
				ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}