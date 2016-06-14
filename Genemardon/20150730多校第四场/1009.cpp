#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
struct node
{
	int x,y;
	node () {}
	node (int x,int y) : x(x),y(y) {}
};
struct note
{
	int x,y,dis;
	note () {}
	note (int x,int y,int dis) : x(x),y(y),dis(dis) {}
};
int vis[1010][1010];
int ans[2010];
int n,m,MAX;
char str[1010][1010];
int dir[4][2]={0,1,1,0,0,-1,-1,0};
queue<note>q;
bool judge(int x,int y)
{
	if (x>=0 && x<n && y>=0 && y<m && !vis[x][y]) return true;
	return false;
}
bool find()
{
	MAX=0;
	queue<node>qq;
	stack<node>st;
	qq.push(node(0,0));
	vis[0][0]=1;
	while (!qq.empty())
	{
		node tmp=qq.front();qq.pop();
		st.push(tmp);
		for (int i=0;i<4;i++) 
		{
			int xx=tmp.x+dir[i][0],yy=tmp.y+dir[i][1];
			if (judge(xx,yy) && str[xx][yy]=='0')
			{
				MAX=max(MAX,xx+yy);
				vis[xx][yy]=1;
				qq.push(node(xx,yy));
			}
		}
	}
	if (vis[n-1][m-1]) return false;
	//printf("--------for 0s -------\n");
	while (!st.empty())
	{
		node tmp=st.top();st.pop();
		if (tmp.x+tmp.y==MAX)
		{
			//printf("%d  %d\n",tmp.x,tmp.y );
			for (int i=0;i<2;i++)
			{
				int xx=tmp.x+dir[i][0],yy=tmp.y+dir[i][1];
				if (judge(xx,yy) && str[xx][yy]=='1')
				{
					vis[xx][yy]=1;
					q.push(note(xx,yy,MAX+1));
				}
			}
		}
	}
	return true;
}
void bfs()
{
	//printf("-------bfs------\n");
	while (!q.empty())
	{
		note tmp=q.front();q.pop();
		if (tmp.x==n-1 && tmp.y==m-1) return;
		if (str[tmp.x][tmp.y]-'0'>ans[tmp.dis]) continue;
		//printf("%d %d %d\n",tmp.x,tmp.y,tmp.dis );
		for (int i=0;i<2;i++)
		{
			int xx=tmp.x+dir[i][0],yy=tmp.y+dir[i][1];
			if (judge(xx,yy) && str[xx][yy]-'0'<=ans[tmp.dis+1])
			{
				vis[xx][yy]=1;
				ans[tmp.dis+1]=min(ans[tmp.dis+1],str[xx][yy]-'0');
				q.push(note(xx,yy,tmp.dis+1));
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		memset(vis,0,sizeof(vis));
		while (!q.empty()) q.pop();
		scanf("%d%d",&n,&m);
		for (int i=0;i<=m+n;i++) ans[i]=2;
		for (int i=0;i<n;i++) scanf("%s",str[i]);
		if (str[0][0]=='1')
		{
			q.push(note(0,0,0));
			vis[0][0]=1;
			ans[0]=1;
			bfs();
			for (int i=0;i<=m+n-2;i++) printf("%d",ans[i] );
			printf("\n");
		}
		else
		{
			if (!find())
			{
				printf("0\n");
				continue;
			}
			bfs();
			ans[MAX+1]=1;
			for (int i=MAX+1;i<=m+n-2;i++) printf("%d",ans[i] );
			printf("\n");
		}
	}
	return 0;
}