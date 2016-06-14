#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define M 258280327
__int64 dp[9], tp[9];
int num[100005];
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n, a, b;
		scanf("%d%d%d", &n, &a, &b);
		memset(dp, 0, sizeof(dp));
		int sum = 0;
		for(int i = 0;i < n;i++)
		{
			scanf("%d", &num[i]);
			sum += num[i];
		}
		__int64 ans = 0;
		if(sum%9 != (a+b)%9)
		{
			if(sum%9 == a%9)
				ans++;
			if(sum%9 == b%9)
				ans++;
			printf("%d\n", ans);
			continue;
		}
		ans = a%9 == 0 ? 1:0;
		dp[0] = 1;
		for(int i = 0;i < n;i++)
		{
			memcpy(tp, dp, sizeof(dp));
			for(int j = 0;j < 9;j++)if(dp[j])
			{
				int s = j+num[i];
				s %= 9;
				tp[s] += dp[j];
				tp[s] %= M;
				if(s == a%9)
				{
					ans += dp[j];
					ans %= M;
				}
				//printf("%d %d %d %d %I64d\n", i, num[i], j, s, ans);
			}
			memcpy(dp, tp, sizeof(tp));
		}
		printf("%I64d\n", ans%M);
	}
	return 0;
}