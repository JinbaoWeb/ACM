#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
struct node
{
	int x, y, dir;
	node(){}
	node(int a, int b, int c){
		x = a, y = b, dir = c;
	}
}N[1005];
char str[1005];
int a[1005], take;
int mp[13][10];
int b[3][4][4][4]={
	{0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,0},
	{0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,0},
	{0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,0},
	{0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,0},
	{1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
	{1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
	{0,0,0,0,0,0,0,0,1,0,0,0,1,1,1,0},
	{0,0,0,0,1,1,0,0,1,0,0,0,1,0,0,0},
	{0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,0},
	{0,0,0,0,0,1,0,0,0,1,0,0,1,1,0,0}
};
int test(int id, int q)
{
	for(int i = 0;i < 4;i++)
		for(int j = 0;j < 4;j++)
		{
			int tx = N[id].x + i, ty = N[id].y + j;
			if(b[id][q][i][j] == 0)
				continue;
			if(tx < 1 || tx > 12 || ty < 1 || ty > 9)
				return 0;
			if(mp[tx][ty])
				return 0;
		}
	return 1;
}
void put(int id, int q)
{
	for(int i = 0;i < 4;i++)
		for(int j = 0;j < 4;j++)
		{
			int tx = N[id].x + i, ty = N[id].y + j;
			if(b[id][q][i][j] == 0)
				continue;
			if(tx < 1 || tx > 12 || ty < 1 || ty > 9)
				continue;
			mp[tx][ty] = b[id][q][i][j];
		}
}
int play(int id, char c)
{
	if(id.x == 12)
		take++;
	if(c == 'w')
		if(test(id, (id.dir+1)%4))
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n;
		scanf("%s", str);
		for(int i = 0;i < n;i++)
		{
			N[i] = node(4, 4, 0);
			scanf("%d", &a[i]);
		}
		memset(mp, 0, sizeof(mp));
		int len = strlen(str);
		take = 0;
		int ans = 0;
		for(int i = 0;i < len;i++)
			ans += play(take, str[i]);
		printf("%d\n", ans);
	}
	return 0;
}