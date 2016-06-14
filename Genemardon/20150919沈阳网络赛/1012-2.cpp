#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 5000010
#define inf 100000000
#define LL __int64
int num[N], n, a, b;
int cmp(int x, int y)
{
	return x < y;
}
LL f(int x, int y)
{
	return 1LL*a*x*x+1LL*b*y;
}
int main()
{
	int T, o = 0;
	scanf("%d", &T);
	while(T--)
	{
		printf("Case #%d: ", ++o);
		scanf("%d%d%d", &n, &a, &b);
		for(int i = 0;i < n;i++)
			scanf("%d", &num[i]);
		sort(num, num+n, cmp);
		int max_id, min_id, max_v = -1, min_v = inf;
		LL g = 1;
		LL ans = f(num[1], num[0]);
		for(int i = 0;i < n;i++)
		{
			if(abs(num[i]) > max_v)
			{
				max_v = abs(num[i]);
				max_id = i;
			}
			if(abs(num[i]) < min_v)
			{
				min_v = abs(num[i]);
				min_id = i;
			}
		}
		/*for(int i = 0;i < n;i++)
			printf("%d%c", num[i], " \n"[i==n-1]);
		printf("==%d %d %d %d\n", max_id, max_v, min_id, min_v);*/
		if(a >= 0 && b >= 0)
		{
			if(max_id != n-1)
				ans = f(max_v, num[n-1]);
			else
			{
				for(int i = 0;i < n-1;i++)
				{
					LL t = max(f(num[i], num[n-1]), f(num[n-1], num[i]));
					ans = max(t, ans);
					//printf("%d %I64d %I64d\n", i, t, ans);
				}
			}
		}
		else if(a >= 0 && b < 0)
		{
			if(max_id != 0)
				ans = f(max_v, num[0]);
			else
			{
				for(int i = 1;i < n;i++)
				{
					LL t = max(f(num[i], num[0]), f(num[0], num[i]));
					ans = max(t, ans);
				}
			}
		}
		else if(a < 0 && b >= 0)
		{
			if(min_id != n-1)
				ans = f(min_v, num[n-1]);
			else
			{
				for(int i = 0;i < n-1;i++)
				{
					LL t = max(f(num[i], num[n-1]), f(num[n-1], num[i]));
					ans = max(t, ans);
				}
			}
		}
		else
		{
			if(min_id != 0)
				ans = f(min_v, num[0]);
			else
			{
				for(int i = 1;i < n;i++)
				{
					LL t = max(f(num[i], num[0]), f(num[0], num[i]));
					ans = max(t, ans);
				}
			}
		}
		printf("%I64d\n", ans);
	}
	return 0;
}