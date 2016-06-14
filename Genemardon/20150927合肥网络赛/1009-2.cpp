#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
struct node
{
	int a, b, v;
}p[50][50];
int p2(int x)
{
	return x*x;
}
int judge(int x, int y, int v)
{
	return p[x][y].a-2*v*p[x][y].b;
}
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
		for(int j = 2;j <= m;j++)
		{
			p[1][j].a = p[1][j-1].a+p2(p[1][j].v);
			p[1][j].b = p[1][j-1].b+p[1][j].v;
		}
		for(int i = 2;i <= n;i++)
		{
			p[i][1].a = p[i-1][1].a+p2(p[i][1].v);
			p[i][1].b = p[i-1][1].b+p[i][1].v;
		}
		for(int i = 2;i <= n;i++)
			for(int j = 2;j <= m;j++)
				if(judge(i,j-1, p[i][j].v) > judge(i-1,j,p[i][j].v))
				{
					p[i][j].a = p[i][j-1].a+p2(p[i][j].v);
					p[i][j].b = p[i][j-1].b+p[i][j].v;
				}
				else
				{
					p[i][j].a = p[i-1][j].a+p2(p[i][j].v);
					p[i][j].b = p[i-1][j].b+p[i][j].v;
				}
		int ans = p[n][m].a*(n+m-1)-p2(p[n][m].b);
		printf("Case #%d: %d\n", ++o, ans);
	}
	return 0;
}