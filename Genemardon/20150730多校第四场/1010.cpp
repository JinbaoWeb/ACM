#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
int mp[105][105], num[105][105], dp[4][2] = {1,0,0,1,-1,0,0,-1};
int r, c, n, T;
int flag[105], ans[105][2], put[105][105], dis[105][105];
struct node
{
	int x, y, tim;
	node(){}
	node(int a, int b, int t){
		x = a, y = b, tim = t;
	}
}drop[105], D, J;
queue <node> crack, judge;
struct happy
{
	int x, y, tim;
	int d;
	happy(){}
	happy(int a, int b, int c, int e){
		x = a, y = b, tim = c, d = e;
	}
}F;
queue <happy> fly;
void clear()
{
	memset(mp, 0, sizeof(mp));
	memset(flag, 0, sizeof(flag));
	memset(drop, 0, sizeof(drop));
	memset(num, 0, sizeof(num));
	while(!crack.empty()) crack.pop();
}
int play(int t)
{
	if(crack.empty() && fly.empty())
		return 1;
	while(!crack.empty())
	{
		if(crack.front().tim == t)
			break;
		D = crack.front(); crack.pop();
		int m = num[D.x][D.y];
		mp[D.x][D.y] = 0;
		if(!flag[m])
			ans[m][0] = 0, ans[m][1] = t-1, flag[m] = 1;
		for(int k = 0;k < 4;k++)
		{
			int tx = D.x+dp[k][0], ty = D.y+dp[k][1];
			if(tx < 1 || tx > r || ty < 1 || ty > c)
				continue;
			fly.push(happy(D.x, D.y, t-1, k));
		}
	}
	memset(put, 0, sizeof(put));
	while(!fly.empty())
	{
		if(fly.front().tim == t+3)
			break;
		F = fly.front(); fly.pop();
		if(mp[F.x][F.y] > 0)
			mp[F.x][F.y]--;
		int tx = F.x+dp[F.d][0], ty = F.y+dp[F.d][1];
		if(tx < 1 || tx > r || ty < 1 || ty > c)
			continue;
		mp[tx][ty]++;
		if(!put[tx][ty])
		{
			judge.push(node(tx, ty, t));
			put[tx][ty] = 1;
		}
		if(num[tx][ty] > 0 && flag[num[tx][ty]] == 0)
			continue;
		fly.push(happy(tx, ty, t+3, F.d));
	}
	memset(dis, 0, sizeof(dis));
	while(!judge.empty())
	{
		J = judge.front(); judge.pop();
		if(mp[J.x][J.y] > 4)
		{
			crack.push(node(J.x, J.y, t));
			dis[J.x][J.y] = 1;
		}
	}
	while(!fly.empty())
	{
		if(fly.front().tim == t)
			break;
		F = fly.front(); fly.pop();
		if(!dis[F.x][F.y])
			fly.push(happy(F.x, F.y, t, F.d));
	}
	return 0;
}
void pr()
{
	for(int i = 1;i <= r;i++)
		for(int j = 1;j <= c;j++)
			printf("%d%c", mp[i][j], " \n"[j==c]);
	printf("\n");
}
int main()
{
	while(~scanf("%d%d%d%d", &r, &c, &n, &T))
	{
		clear();
		int x, y, size;
		for(int i = 1;i <= n;i++)
		{
			scanf("%d%d%d", &x, &y,&size);
			mp[x][y] = size;
			num[x][y] = i;
			drop[i] = node(x, y, 0);
			if(mp[x][y] > 4)
				crack.push(node(x, y, 0));
		}
		scanf("%d%d", &x, &y);
		crack.push(node(x, y, 0));
		num[x][y] = 0;
		//pr();
		for(int t = 1;t <= T;t++)
		{
			if(play(t)) break;
			//pr();
		}
		for(int i = 1;i <= n;i++)
			if(!flag[i])
			{
				ans[i][0] = 1;
				ans[i][1] = mp[drop[i].x][drop[i].y];
			}
		for(int i = 1;i <= n;i++)
			printf("%d %d\n", ans[i][0], ans[i][1]);
	}
	return 0;
}