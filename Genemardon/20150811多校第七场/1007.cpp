#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int a[200010];
int n;
int dp[200010][2];
char str[200010];
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	for (int TT=1;TT<=t;TT++)
	{
		memset(dp,0,sizeof(dp));
		scanf("%s",str);
		n=strlen(str);
		for (int i=0;i<n;i++) scanf("%d",&a[i]);
		if (str[0]=='1')
			dp[0][1]=a[0];
		else if (str[0]=='?')
			dp[0][1]=a[0];
		for (int i=1;i<n;i++) 
		{
			if (str[i]=='?')
			{
				if (str[i-1]=='?')
				{
					dp[i][0]=max(dp[i-1][0],dp[i-1][1]+a[i]);
					dp[i][1]=max(dp[i-1][0]+a[i],dp[i-1][1]);
				}
				else
				{
					int last=str[i-1]-'0';
					dp[i][0]=dp[i-1][last]+(0^last)*a[i];
					dp[i][1]=dp[i-1][last]+(1^last)*a[i];
				}
			}
			else
			{
				int now=str[i]-'0';
				if (str[i-1]=='?')
				{
					dp[i][now]=max(dp[i-1][0]+(0^now)*a[i],dp[i-1][1]+(1^now)*a[i]);
				}
				else
				{
					int last=str[i-1]-'0';
					dp[i][now]=dp[i-1][last]+(last^now)*a[i];
				}
			}
		}
		if (str[n-1]=='?')
			printf("Case #%d: %d\n",TT,max(dp[n-1][0],dp[n-1][1]) );
		else
			printf("Case #%d: %d\n",TT,dp[n-1][str[n-1]-'0'] );
	}
	return 0;
}