#include <bits/stdc++.h>
using namespace std;
struct Node{
	int a,b;
}P[300];
int dp[300][300];
bool cmp(Node x,Node y){
	return x.b<y.b;
}
int main(){
	int t,n,m;
	cin>>t;
	while (t--){
		cin>>n>>m;
		for (int i=1;i<=n;i++)
			cin>>P[i].a;
		for (int i=1;i<=n;i++)
			cin>>P[i].b;
		sort(P+1,P+n+1,cmp);
		memset(dp,0,sizeof(dp));
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m && j<=i;j++){
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]+P[i].a+(j-1)*P[i].b);
			}
		}
		cout<<dp[n][m]<<endl;
	}
	return 0;
}