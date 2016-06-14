#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
struct note
{
	int u,v;
	note () {}
	note (int u,int v) : u(u),v(v) {}
}p[300000];
int n,m,e;
int val[20000],ne[300000],head[20000],d[20000],ex[300000],vis[20000];
long long ans,cnt;
int num;
void init()
{
	e=0;
	memset(head,-1,sizeof(head));
	memset(d,0,sizeof(d));
	memset(vis,0,sizeof(vis));
}
void addnote(int u,int v)
{
	p[e] = note (u,v);
	ex[e]=0;
	ne[e]=head[u];
	head[u]=e++;
}
void dfs(int x)
{
	vis[x]=1;
	num++;
	cnt+=val[x];
	for (int i=head[x];i+1;i=ne[i])
		if (!ex[i] && !vis[p[i].v])
			dfs(p[i].v);
}
void solve()
{
	queue<int>q;
	for (int i=1;i<=n;i++)
		if (d[i]<=1)
			q.push(i);
	while(!q.empty())
	{
		int tmp=q.front();q.pop();
		for (int i=head[tmp];i+1;i=ne[i])
			if (!ex[i])
			{
				ex[i]=1;
				ex[i ^ 1]=1;
				d[tmp]--;
				d[p[i].v]--;
				if (d[p[i].v]<=1) q.push(p[i].v);
			}
	}
	ans=0;
	for (int i=1;i<=n;i++)
		if (!vis[i] && d[i]>=2)
		{
			cnt=0;num=0;
			dfs(i);
			if (num%2==1) ans+=cnt;
		}
	printf("%I64d\n",ans );
}
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		init();
		for (int i=1;i<=n;i++)
			scanf("%d",&val[i]);
		for (int i=0;i<m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			addnote(u,v);
			addnote(v,u);
			d[u]++;d[v]++;
		}
		solve();
	}
	return 0;
}