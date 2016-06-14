#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int dp[2020],tmp[2020];
int w[2020],a[2020],b[2020];
int n,m;
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&m,&n);
		for (int i=1;i<=n;i++)
			scanf("%d%d%d",&w[i],&a[i],&b[i]);
		memset(dp,0,sizeof(dp));
		for (int i=1;i<=n;i++)
		{
			memset(tmp,0,sizeof(tmp));
			for (int j=0;j<=m-w[i];j++)
			{
				if (dp[j+w[i]]<dp[j]+a[i]+b[i])
					tmp[j+w[i]]=dp[j]+a[i]+b[i];
				if (tmp[j+w[i]]<tmp[j]+a[i])
					tmp[j+w[i]]=tmp[j]+a[i];
			}
			for (int j=0;j<=m;j++) dp[j]=max(dp[j],tmp[j]);
		}
		int M=0;
		for (int i=0;i<=m;i++) M=max(M,dp[i]);
		printf("%d\n",M );
	}
	return 0;
}