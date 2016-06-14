#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define ran 4048
#define Mod 1000000007
int dp[ran], te[ran];
int main()
{
	int n, m, L, R;
	while(~scanf("%d%d%d%d", &n, &m, &L, &R))
	{
		int ans = 0;
		for(int x = L;x <= R;x++)
		{
			memset(dp, 0, sizeof(dp));
			for(int j = 0;j <= m;j++)
				dp[j+x] = 1;
			printf("%d 1 %d\n", x, dp[0]);
			for(int i = 1;i < 2*n+1;i++)
			{
				memcpy(te, dp, sizeof(te));
				memset(dp, 0, sizeof(dp));
				for(int j = 0;j <= m;j++)
				{
					for(int k = 0;k < ran;k++)
					{
						if(te[k] == 0)
							continue;
						int s = k^(j+x);
						dp[s] += te[k];
						dp[s] %= Mod;
					}
				}
				printf("%d %d %d\n", x, i+1, dp[0]);
			}
			printf("--------------\n");
			ans = (ans+dp[0])%Mod;
		}
		printf("%d\n", ans);
		printf("==============\n");
	}
	return 0;
}