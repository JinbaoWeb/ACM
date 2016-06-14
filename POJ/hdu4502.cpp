#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int dp[105];
struct Node{
	int s,e,c;
}P[1005];
int n,m;
void solve(){

	memset(dp,0,sizeof(dp));
	for (int i=0;i<=m;i++){
		for (int j=0;j<n;j++){
			if (P[j].s>i)
				dp[P[j].e]=max(dp[i]+P[j].c,dp[P[j].e]);
			dp[i+1]=max(dp[i+1],dp[i]);
		}
	}
	/*
	for (int i=0;i<=m;i++)
		cout<<dp[i]<<" ";
	cout<<endl;
	*/
	cout<<dp[m]<<endl;
}
	int main(){
		int t;
	scanf("%d",&t);
	while (t--){
		scanf("%d%d",&m,&n);
		for (int i=0;i<n;i++)
			scanf("%d%d%d",&P[i].s,&P[i].e,&P[i].c);
		solve();
	}

	return 0;
}