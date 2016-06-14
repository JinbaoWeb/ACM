#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
int dp[9], tp[9], num[100005];
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
		int ans = 0;
		if(sum%9 != (a+b)%9)
		{
			if(sum%9 == a%9)
				ans = 1;
		}
		dp[0] = 1;
		for(int i = 0;i < n;i++)
		{
			memcpy(tp, dp, sizeof(dp));
			for(int j = 0;j < 9;j++)if(dp[j])
			{
				int s = j+num[i];
				s %= 9;
				tp[s] += dp[j];
				if(s == a%9)
					ans += dp[j];
				//printf("%d %d %d %d %d\n", i, num[i], j, s, ans);
			}
			memcpy(dp, tp, sizeof(tp));
		}
		printf("%d\n", ans);
	}
	return 0;
}