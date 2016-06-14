#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
int dir[4][2]={1,0,0,1,-1,0,0,-1};
struct node
{
	int x,y,dir,isget,point;
	node () {}
	node (int x,int y,int dir,int isget,int point) : x(x),y(y),dir(dir),isget(isget),point(point) {}
};
int map[21][21];
int vis[21][21][4][2];
int n;
bool isin(int x,int y)
{
	if (x<0 || y<0 || x>=n || y>=n) return false;
	if (map[x][y]==1 || map[x][y]==2) return false;
	return true;
}
int bfs()
{
	memset(vis,0,sizeof(vis));
	queue<node>q;
	q.push(node(0,0,0,0,0));
	vis[0][0][0][0]=1;
	while (!q.empty())
	{
		node tmp=q.front();q.pop();
		if (tmp.x==0 && tmp.y==0 && tmp.isget==1) return tmp.point;
		if (vis[tmp.x][tmp.y][(tmp.dir+1)%4][tmp.isget]==0)
		{
			vis[tmp.x][tmp.y][(tmp.dir+1)%4][tmp.isget]=1;
			q.push(node(tmp.x,tmp.y,(tmp.dir+1)%4,tmp.isget,tmp.point+1));
		}
		if (vis[tmp.x][tmp.y][(tmp.dir+3)%4][tmp.isget]==0)
		{
			vis[tmp.x][tmp.y][(tmp.dir+3)%4][tmp.isget]=1;
			q.push(node(tmp.x,tmp.y,(tmp.dir+3)%4,tmp.isget,tmp.point+1));
		}
		int d=tmp.dir;
		if (isin(tmp.x+dir[d][0],tmp.y+dir[d][1]) && vis[tmp.x+dir[d][0]][tmp.y+dir[d][1]][tmp.dir][tmp.isget]==0)
		{
			vis[tmp.x+dir[d][0]][tmp.y+dir[d][1]][tmp.dir][tmp.isget]=1;
			q.push(node(tmp.x+dir[d][0],tmp.y+dir[d][1],tmp.dir,tmp.isget,tmp.point+1));
		}
		if (map[tmp.x][tmp.y]==3 && vis[tmp.x][tmp.y][tmp.dir][1]==0)
		{
			vis[tmp.x][tmp.y][tmp.dir][1]=1;
			q.push(node(tmp.x,tmp.y,tmp.dir,1,tmp.point+1));
		}
	}
	return -1;
}
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		memset(map,0,sizeof(map));
		scanf("%d",&n);
		int c,x,y;
		while (scanf("%d%d%d",&c,&x,&y) && c!=-1)
		{
			map[x][y]=c;
		}
		if (map[0][0]==2)
		{
			printf("-1\n");
			continue;
		}
		int ans=bfs();
		if (ans==-1)
			printf("-1\n");
		else
		{
			ans++;
			printf("%d\n",1000-ans*10 );
		}
	}
	return 0;
}