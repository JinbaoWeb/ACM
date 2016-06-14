#include <stdio.h>
#include <string.h>
#include <algorithm>
#define LL long long 
using namespace std;
const int MOD=1000000007;
LL  dp[2][2000][2000];
char str[1000010];
int ope[2000],list[2000];
int N;
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		N=0;
		scanf("%s",str);
		int l=strlen(str);
		for (int i=0;i<l;)
		{
			if (str[i]>='0' && str[i]<='9')
			{
				N++;
				list[N]=0;
				while(i<l &&str[i]>='0' && str[i]<='9' ) i++;
				if (i==l) break;
				if (str[i]=='*')
					ope[N]=1;
				else if (str[i]=='.')
					ope[N]=2;
				else if (str[i]=='^')
					ope[N]=3;
				else if (str[i]=='!')
					ope[N]=4;
				i++;
			}
			else
			{
				N++;
				list[N]=1;
				while(i<l && str[i]>='a' && str[i]<='z') i++;
				if (i==l) break;
				if (str[i]=='*')
					ope[N]=1;
				else if (str[i]=='.')
					ope[N]=2;
				else if (str[i]=='^')
					ope[N]=3;
				else if (str[i]=='!')
					ope[N]=4;
				i++;
			}
		}
		 // printf("%d\n",N );
		 // for (int i=1;i<=N;i++) printf("%d ",list[i] ); printf("\n");
		 // for (int i=1;i<N;i++) printf("%d ",ope[i] );printf("\n");
		memset(dp,0,sizeof(dp));
		for (int i=1;i<=N;i++) dp[list[i]][i][i]=1;
		for (int i=1;i<N;i++)
			for (int j=1;j<=N-i;j++)
				for (int k=j;k<j+i;k++)
				{
					//printf("%d %d %d %d\n",i,j,k,ope[k] );
					if (ope[k]==1)
					{
						dp[1][j][i+j]+=(dp[0][j][k]*dp[1][k+1][i+j]%MOD);
						dp[1][j][i+j]+=(dp[1][j][k]*dp[0][k+1][i+j]%MOD);
						dp[0][j][i+j]+=(dp[0][j][k]*dp[0][k+1][i+j]%MOD);
					}
					else if (ope[k]==2)
						dp[0][j][i+j]+=(dp[1][j][k]*dp[1][k+1][i+j]%MOD);
					else if (ope[k]==3)
						dp[1][j][i+j]+=(dp[1][j][k]*dp[1][k+1][i+j]%MOD);
					else if (ope[k]==4)
					{
						dp[1][j][i+j]+=(dp[0][j][k]*dp[0][k+1][i+j]%MOD);
						dp[1][j][i+j]+=(dp[1][j][k]*dp[0][k+1][i+j]%MOD);
						dp[1][j][i+j]+=(dp[0][j][k]*dp[1][k+1][i+j]%MOD);
						//if (j==2 && i+j==4) printf("%d +",dp[0][j][i+j] );
						dp[0][j][i+j]+=(dp[1][j][k]*dp[1][k+1][i+j]%MOD);
						//if (j==2 && i+j==4) printf("%d*%d\n",dp[1][j][k],dp[1][k+1][i+j] );
					}
					dp[0][j][i+j]%=MOD;
					dp[1][j][i+j]%=MOD;
				}
		// for (int i=0;i<N;i++)
		// {
		// 	for (int j=1;j<=N-i;j++) printf("(%d,%d):%d ",j,j+i,dp[0][j][j+i] );
		// 	printf("\n");
		// }
		// printf("-------\n");
		// for (int i=0;i<N;i++)
		// {
		// 	for (int j=1;j<=N-i;j++) printf("(%d,%d):%d ",j,j+i,dp[1][j][j+i] );
		// 	printf("\n");
		// }
		printf("%lld\n",(dp[0][1][N]+dp[1][1][N])%MOD );
	}
	return 0;
}