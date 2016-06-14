#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
struct node
{
	int v, a, b, c[2000];
}p[50][50];
int p2(int x)
{
	return x*x;
}
int dp[2][2] = {0,-1,-1,0};
int main()
{
	int T, o = 0;
	scanf("%d", &T);
	while(T--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		memset(p, 0, sizeof(p));
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= m;j++)
				scanf("%d", &p[i][j].v);
		p[1][1].a = p2(p[1][1].v);
		p[1][1].b = p[1][1].v;
		p[1][1].c[p[1][1].v] = p2(p[1][1].v);
		for(int j = 2;j <= m;j++)
		{
			p[1][j].a = p[1][j-1].a+p2(p[1][j].v);
			p[1][j].b = p[1][j-1].b+p[1][j].v;
			p[1][j].c[p[1][j].b] = p[1][j].a;
		}
		for(int i = 2;i <= n;i++)
		{
			p[i][1].a = p[i-1][1].a+p2(p[i][1].v);
			p[i][1].b = p[i-1][1].b+p[i][1].v;
			p[i][1].c[p[i][1].b] = p[i][1].a;
		}
		for(int i = 2;i <= n;i++)
			for(int j = 2;j <= m;j++)
				for(int k = 0;k < 2000;k++)
					for(int l = 0;l < 2;l++)
					{
						int tx = i+dp[l][0], ty = j+dp[l][1];
						if(p[tx][ty].c[k])
						{
							int f = k+p[i][j].v;
							if(p[i][j].c[f])
								p[i][j].c[f] = min(p[i][j].c[f], p[tx][ty].c[k]+p2(p[i][j].v));
							else
								p[i][j].c[f] = p[tx][ty].c[k]+p2(p[i][j].v);
						}
					}
		int ans = 1000000000;
		for(int i = 0;i < 2000;i++)
			if(p[n][m].c[i])
				ans = min(ans, (n+m-1)*p[n][m].c[i]-p2(i));
		printf("Case #%d: %d\n", ++o, ans);
	}
	return 0;
}