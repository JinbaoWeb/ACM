#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#define MAXN 100009
#define inf 1000000009
using namespace std;
struct edge
{
	int to;
	int c;
	edge(int T,int C){to=T;c=C;}
};
vector<edge>e[MAXN];
int dis[MAXN],vis[MAXN],pre[MAXN][2];
int t1[MAXN],t2[MAXN];
int n,m,x,y,c;
queue<int>q;
int match(int xx,int yy)
{
	int len=0;
	while (xx!=1)
	{
		len++;
		t1[len]=pre[xx][1];
		t2[len]=pre[yy][1];
		xx=pre[xx][0];
		yy=pre[yy][0];
	}
	for (int i=len;i>0;i--) if (t1[i]<t2[i]) return 1;
		else if (t1[i]>t2[i]) return -1;
	return 0;
}
bool spfa(int x)
{
	while (!q.empty()) q.pop();
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=n;i++) dis[i]=inf;
	for (int i=1;i<=n;i++) pre[i][0]=-1;
	dis[x]=0;vis[x]=1;q.push(x);
	while (!q.empty())
	{
		int FROM=q.front();
		q.pop();
		vis[FROM]=0;
		for (int i=0;i<e[FROM].size();i++) if (dis[FROM]+1<dis[e[FROM][i].to])
		{
			int TO=e[FROM][i].to;
			dis[TO]=dis[FROM]+1;
			pre[e[FROM][i].to][0]=FROM;
			pre[e[FROM][i].to][1]=e[FROM][i].c;
			if (!vis[TO])
			{
				vis[TO]=1;
				q.push(TO);
			}
		}
		else if (dis[FROM]+1 == dis[e[FROM][i].to])
		{
			int flag=match(FROM,pre[e[FROM][i].to][0]);
			if (flag == 1 || (flag==0 && e[FROM][i].c < pre[e[FROM][i].to][1]))
			{
				pre[e[FROM][i].to][0]=FROM;
				pre[e[FROM][i].to][1]=e[FROM][i].c;
			}
		}
	}
	return true;
}
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++) e[i].clear();
		for (int i=0;i<m;i++)
		{
			scanf("%d%d%d",&x,&y,&c);
			edge ee(y,c);
			e[x].push_back(ee);
			edge rr(x,c);
			e[y].push_back(rr);
		}
		spfa(1);
		printf("%d\n",dis[n] );
		int tmp=n,len=0;
		while (tmp!=1)
		{
			len++;
			t1[len]=pre[tmp][1];
			tmp=pre[tmp][0];
		}
		for (int i=len;i>0;i--) if (i==1) printf("%d\n",t1[i] ); else printf("%d ",t1[i]);
	}
	return 0;
}