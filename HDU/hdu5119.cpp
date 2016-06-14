#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
typedef long long ll;
int a[45];
long long dp[45][1<<20];
int main(){
	int t,n,m;
	cin>>t;
	for (int cas=1;cas<=t;cas++){
		cin>>n>>m;
		for (int i=0;i<n;i++)
			cin>>a[i];
		memset(dp,0,sizeof(dp));
		// dp[i][j]+=dp[i-1][j]+dp[i-1][j^a[i]]
		ll ans=0;
		dp[0][0]=1;
		dp[1][a[0]]=1;
		for (int i=1;i<n;i++){
			for (int j=0;j<=(1<<20);j++){
				dp[i][j]+=dp[i-1][j];
				dp[i][j^a[i]]+=dp[i-1][j];
			}
		}
		
        for(int i=1<<20-1;i>=m;--i)
            ans+=dp[n-1][i];
        printf("Case #%d: %lld\n",cas,ans);
	}
	return 0;
}