#include <bits/stdc++.h>
using namespace std;
struct Node{
	int a,b;
}P[300];
bool used[300];
int main(){
	int t,n,m;
	cin>>t;
	while (t--){
		cin>>n>>m;
		for (int i=1;i<=n;i++)
			cin>>P[i].a;
		for (int i=1;i<=n;i++)
			cin>>P[i].b;
		memset(used,false,sizeof(used));
		int ans=0;
		for (int i=m-1;i>=0;i--){
			int Max=-1,index=-1;
			for (int j=1;j<=n;j++){
				if (used[j]==true) continue;
				if (Max<P[j].a+i*P[j].b){
					Max=P[j].a+i*P[j].b;
					index=j;
				}
			}
			ans+=Max;
			used[index]=true;
		}
		cout<<ans<<endl;
	}
	return 0;
}