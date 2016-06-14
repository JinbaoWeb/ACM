#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int dp[2][10010][110];
int n;
void plus(int a,int b,int now)
{
	for (int i=0;i<100;i++)
	{
		dp[now][a][i]+=dp[!now][b][i];
		dp[now][a][i+1]+=(dp[now][a][i]/10);
		dp[now][a][i]%=10;
	}
}
int main(int argc, char const *argv[])
{
	while (scanf("%d",&n) != EOF)
	{
		int now=0;
		memset(dp,0,sizeof(dp));
		dp[0][0][0]=1;
		for (int i=1;i<=n;i++)
		{
			for (int j=0;j<=i;j++)
				for (int k=0;k<100;k++) dp[!now][j][k]=0;
			plus(0,0,!now);plus(0,1,!now);
			for (int j=1;j<=i;j++) {plus(j,j-1,!now);plus(j,j,!now);plus(j,j+1,!now);}
			now=!now;
		}
		int len;
		for (int i=99;i>=0;i--) if (dp[now][0][i]) {len=i;break;}
		for (int i=len;i>=0;i--) printf("%d",dp[now][0][i] );printf("\n");
	}
	return 0;
}