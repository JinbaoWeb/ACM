#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[105][105];
int a[105],b[105];
int main()
{
	int t,n,m;
	cin>>t;
	while (t--){
		cin>>n>>m;
		for (int i=1;i<=n;i++)
			cin>>a[i];
		for (int j=1;j<=m;j++)
			cin>>b[j];
		memset(dp,0,sizeof(dp));
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++)
			{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				int k,s;
				if (a[i]!=b[j]){
					for (k=j-1;k>=1;k--){
						if (b[k]==a[i])
							break;
					}
					for (s=i-1;s>=1;s--)
						if (a[s]==b[j])
							break;
					if (k>0 && s>0)
						dp[i][j]=max(dp[i][j],dp[s-1][k-1]+2);
				}
					
			}
		}
		cout<<dp[n][m]<<endl;
	}
	return 0;
}