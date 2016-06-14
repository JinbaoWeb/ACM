#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define N 105
int p[2][N][N], ans[N], n, m;
void compare()
{
	for(int i = 1;i <= n;i++)

}
void dfs()
{
	
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= n;j++)
				scanf("%d", &a[i][j]);
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= n;j++)
				scanf("%d", &b[i][j]);
		char c;
		int x, y;
		memset(p, 0, sizeof(p));
		for(int i = 0;i < m;i++)
		{
			scanf("%c %d %d", &c, &x, &y);
			if(c == 'H')
				p[0][x][y] = 1;
			else
				p[1][x][y] = 1;
		}
		dfs();
	}
	return 0;
}