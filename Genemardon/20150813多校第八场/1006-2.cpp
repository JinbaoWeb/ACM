#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct note
{
	int u,v,dis;
	note () {}
	note (int u,int v,int dis) : u(u),v(v),dis(dis) {}
}p[100010];
int e,n,m,t;
int head[100010],ne[100010],vis[100010],d[100010];
void init()
{
	e=0;
	memset(head,-1,sizeof(head));
	memset(vis,-1,sizeof(vis));
}
void addnote(int u,int v)
{
	p[e]=note(u,v,n);
	ne[e]=head[u];
	head[u]=e++;
}
int main(int argc, char const *argv[])
{
	scanf("%d",&t);
	while(t--)
	{
		init();
		scanf("%d%d",&n,&m);
		for (int i=0;i<m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			addnote(u,v);
			if (u==1 && vis[v]==-1) vis[v]=i;
		}
		d[1]=0;
		int l=2,r=n,c=1;
		while(l<=r)
		{
			if (vis[l]!=-1)
			{
				int i=vis[l];
				d[l]=c++;
				p[vis[l]].dis=d[l]-d[p[i].u];
				for (int j=head[l];j+1;j=ne[j])
					if (vis[p[j].v]==-1) vis[p[j].v]=j;
				l++;
			}
			if (vis[r]!=-1)
			{
				int i=vis[r];
				d[r]=c++;
				p[vis[r]].dis=d[r]-d[p[i].u];
				for (int j=head[r];j+1;j=ne[j])
					if (vis[p[j].v]==-1) vis[p[j].v]=j;
				r--;
			}
		}
		//printf("%d %d\n",n,m );
		//for (int i=0;i<e;i++) printf("%d %d %d\n",p[i].u,p[i].v,p[i].dis );
		for (int i=0;i<e;i++) printf("%d\n",p[i].dis );
	}
	return 0;
}