#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#define MAXN 4050
#define MAXM 120500
#define inf  1000000009
using namespace std;
struct note
{
	int u,v,w;
	note () {}
	note (int u,int v,int w) : u(u),v(v),w(w) {};
}p[MAXM];
struct node
{
	int x,dis;
	node () {}
	node (int x,int dis) : x(x),dis(dis) {}
	bool operator<(const node &a)const
	{
		return dis>a.dis;
	}
};
vector<int>tab[MAXN];
int n,m,e,ans1,ans2,cnte;
int head[MAXN],NEXT[MAXM],vis[MAXN],dis[MAXN],dep[MAXN],cur[MAXN],tag[MAXM];
bool bfs(int start,int end)
{
	memset(dep,-1,sizeof(dep));
	queue<int>q;q.push(start);
	dep[start]=0;
	while (!q.empty())
	{
		int x=q.front();q.pop();
		if (end==x) return true;
		for (int i=head[x];i+1;i=NEXT[i]) if (p[i].w>0 && dep[p[i].v]==-1 && tag[i])
		{
			dep[p[i].v]=dep[x]+1;
			q.push(p[i].v);
		}
	}
	return false;
}
int dinic(int x,int maxflow,int start,int end)
{
	if (x==end)
		return maxflow;
	for (int i=cur[x];i+1;cur[x]=i=NEXT[i])
		if (p[i].w>0 && dep[p[i].v]==dep[x]+1 && tag[i])
		{
			int flow=dinic(p[i].v,min(maxflow,p[i].w),start,end);
			if (flow)
			{
				p[i].w-=flow;
				p[i^1].w+=flow;
				return flow;
			}
		}
	return 0;
}
void solve(int start,int end)
{
	int flow;ans1=0;
	while(bfs(start,end))
	{
		memcpy(cur,head,sizeof(head));
		while (flow=dinic(start,inf,start,end)) ans1+=flow;
	} 
}
void heap_dij(int x)
{
	priority_queue<node>q;
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=n;i++) dis[i]=inf;
	dis[x]=0;q.push(node(x,0));
	while (!q.empty())
	{
		while (!q.empty() && vis[q.top().x]) q.pop();
		if (q.empty()) break;
		node tmp = q.top();q.pop();
		vis[tmp.x]=1;
		for (int i=head[tmp.x];i+1;i=NEXT[i]) 
			if (dis[p[i].v]>dis[tmp.x]+p[i].w)
		{
			tab[p[i].v].clear();
			tab[p[i].v].push_back(i);
			dis[p[i].v]=dis[tmp.x]+p[i].w;
			q.push(node(p[i].v,dis[p[i].v]));
		}
		else if (dis[p[i].v]==dis[tmp.x]+p[i].w)
			tab[p[i].v].push_back(i);
	}
}
void init()
{
	e=0;
	memset(head,-1,sizeof(head));
	memset(NEXT,-1,sizeof(NEXT));
	for (int i=1;i<=n;i++) tab[i].clear();
}
void addnote(int u,int v,int w)
{
	p[e] = note (u,v,w);
	NEXT[e]=head[u];head[u]=e++;
}
void makemap()
{
	queue<int>q;cnte=0;
	memset(vis,0,sizeof(vis));
	memset(tag,0,sizeof(tag));
	q.push(n);vis[n]=1;
	while (!q.empty())
	{
		int x=q.front();
		q.pop();
		for (int i=0;i<tab[x].size();i++)
		{
			tag[tab[x][i]]=1;tag[tab[x][i]^1]=1;cnte++;
			p[tab[x][i]].w=1;p[tab[x][i]^1].w=0;
			if (!vis[p[tab[x][i]].u])
			{
				q.push(p[tab[x][i]].u);
				vis[p[tab[x][i]].u]=1;
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	while (scanf("%d%d",&n,&m) != EOF)
	{
		init();
		for (int i=0;i<m;i++)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			addnote(u,v,w);
			addnote(v,u,w);
		}
		heap_dij(1);
		if (dis[n]==inf)
		{
			printf("0 0\n");
			continue;
		}
		makemap();
		bfs(1,n);
		ans2=m-dep[n];
		solve(1,n);
		printf("%d %d\n",ans1 ,ans2);
	}
	return 0;
}