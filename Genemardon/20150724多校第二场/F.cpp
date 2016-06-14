#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct note
{
	int u,v;
	note () {}
	note (int u,int v) : u(u),v(v) {}
}p[200];
int head[200],NEXT[200],vis[200];
int checkin[10],w[10],b[10];
int n,m,ans,e;
void init()
{
	e=0;ans=0;
	memset(head,-1,sizeof(head));
	memset(NEXT,-1,sizeof(NEXT));
}
void dfs(int x,int cur)
{
	printf("%d %d\n",x,cur );
	if (cur==-1)
	{
		if (x==n)
		{
			ans++;
			return;
		}
		dfs(x+1,head[x+1]);
	}
	if (vis[cur]) dfs(x,NEXT[cur]);
	vis[cur]=1;
	vis[cur^1]=1;
	if (b[x] && b[p[cur].v])
	{
		b[x]--;
		b[p[cur].v]--;
		dfs(x,NEXT[cur]);
		b[x]++;
		b[p[cur].v]++;
	}
	if (w[x] && w[p[cur].v])
	{
		w[x]--;
		w[p[cur].v]--;
		dfs(x,NEXT[cur]);
		w[x]++;
		w[p[cur].v]++;
	}
	vis[cur]=0;
	vis[cur^1]=0;
}
void addnote(int u,int v)
{
	p[e]= note (u,v);
	NEXT[e]=head[u];head[u]=e++;
}
int main(int argc, char const *argv[])
{
	int t,u,v;
	scanf("%d",&t);
	while (t--)
	{
		init();
		scanf("%d%d",&n,&m);
		for (int i=0;i<m;i++)
		{
			scanf("%d%d",&u,&v);
			addnote(u,v);
			addnote(v,u);
			checkin[u]++;checkin[v]++;
		}
		int flag=1;
		for (int i=1;i<=n;i++) if (checkin[i]%2==1) flag=0;
		if (!flag )
		{
			printf("0\n");
			continue;
		}
		for (int i=1;i<=n;i++)
		{
			b[i]=checkin[i]/2;
			w[i]=b[i];
			printf("%d %d\n",w[i],b[i] );
		}
		memset(vis,0,sizeof(vis));
		dfs(1,head[1]);
		printf("%d\n",ans );
	}
	return 0;
}