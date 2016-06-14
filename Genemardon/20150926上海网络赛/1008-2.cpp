#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define LL __int64
int flag[100010];
LL num[100010], ans[100010];
int main()
{
	int T, o = 0;
	scanf("%d", &T);
	while(T--)
	{
		printf("Case #%d:\n", ++o);
		int n, op;
		LL x, M;
		scanf("%d%I64d", &n, &M);
		for(int i = 0;i <= n;i++)
			ans[i] = 1;
		for(int i = 1;i <= n;i++)
		{
			scanf("%d%I64d", &op, &x);
			flag[i] = op; num[i] = x;
			if(op == 1)
				ans[i] = ans[i-1]*x%M;
			else
			{
				ans[x] = ans[x-1];
				flag[x] = 0;
				for(int j = x+1;j <= i;j++)
				{
					if(flag[j] == 1)
						ans[j] = ans[j-1]*num[j]%M;
					else
						ans[j] = ans[j-1];
				}
			}
			printf("%I64d\n", ans[i]%M);
		}
	}
	return 0;
}