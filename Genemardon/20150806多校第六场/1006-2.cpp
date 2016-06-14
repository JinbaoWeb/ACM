#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define LL __int64
#define N 100005
int a[N];
LL sum[N];
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n;
		scanf("%d", &n);
		for(int i = 1;i <= n;i++)
			scanf("%d", &a[i]);
		//LL ans = (LL)n*(LL)(n+1)*(LL)(5*n+1)/6;
		LL ans = 0;
		printf("-----%I64d\n", ans);
		for(int i = 1;i <= n;i++)
		{
			LL s = 0, t = 0;
			for(int j = i;j <= n;j++)
			{
				s += a[j];
				double r;
				if(s)
					r = log(1.0*s)/log(2);
				else
					r = 0;
				printf("%I64d %f\n", s, r);
				printf("%d %d\n", i, j);
				t += (i+j)*((int)r+0);
			}
			ans += t;
		}
		printf("%I64d\n", ans);
	}
	return 0;
}