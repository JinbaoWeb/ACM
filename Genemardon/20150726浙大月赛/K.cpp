#include <stdio.h>
#include <string.h>
#include <algorithm>
using  namespace std;
char str[50010];
int k;
int dp[50010][40];
int cnt[40];
int main(int argc, char const *argv[])
{
	while (scanf("%s%d",str,&k) !=EOF)
	{
		memset(cnt,0,sizeof(cnt));
		memset(dp,0,sizeof(dp));
		int len=strlen(str);
		for (int i=0;i<len;i++)
		{
			int num=str[i]-'0';
			for (int j=0;j<k;j++) dp[i+1][(j*10+num)%k]+=dp[i][j];
			dp[i+1][num%k]++;
			for (int j=0;j<k;j++) cnt[j]+=dp[i+1][j];
			for (int i=0;i<k;i++) printf("%d ",cnt[i] );printf("\n");
		}
		printf("%d",cnt[0] );
		for (int i=1;i<k;i++) printf(" %d",cnt[i] );printf("\n");
	}
	return 0;
}