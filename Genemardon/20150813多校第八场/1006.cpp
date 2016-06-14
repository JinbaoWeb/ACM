#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
struct note
{
	int u,v,dis;
	note () {}
	note (int u,int v,int dis) : u(u),v(v),dis(dis) {}
}p[100010],p2[100010];
int e,n,m;
int head[100010],ne[100010],vis[100010],dd[100010],head2[100010],ne2[100010];;
void init()
{
	e=0;
	memset(head,-1,sizeof(head));
	memset(head2,-1,sizeof(head2));
}
void addnote(int u,int v)
{
	if (v==9) printf("pp %d\n",u );
	p[e]=note(u,v,n);
	p2[e]=note(v,u,n);
	ne[e]=head[u];
	ne2[e]=head2[v];
	head2[v]=e;	
	head[u]=e++;
}
void bfs()
{
	queue<int>q;
	memset(vis,0,sizeof(vis));
	q.push(1);vis[1]=1;
	while (!q.empty())
	{
		int tmp=q.front();q.pop();
		for (int i=head[tmp];i+1;i=ne[i])
			if (vis[p[i].v] || p[i].v<tmp)
			continue;
			else
			{
				p[i].dis=p[i].v-tmp;
				//printf("%d %d %d %d\n",i,tmp,p[i].v,p[i].dis );
				vis[p[i].v]=1;
				q.push(p[i].v);
			}
	}
}
int main(int argc, char const *argv[])
{
	int t;
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
		}
		bfs();
		int pos=n+1;
		//for (int i=1;i<=n;i++) printf("%d ",vis[i] );printf("\n");
		for (int i=1;i<=n;i++) if (!vis[i])
		{
			pos=i;
			break;
		}
		else dd[i]=i-1;
		printf("pos:%d\n",pos );
		dd[n+1]=0;
		for (int i=pos;i<=n;i++) dd[i]=1000000009;
		for (int i=n;i>=pos;i--)
		{
			for (int j=head2[i];j+1;j=ne2[j])
				if (p2[j].v>i || p2[j].v<pos)
				{
					if (dd[p2[j].v]<=dd[i+1])
					{
						p[j].dis=dd[i+1]+1-dd[p2[j].v];
						dd[i]=dd[i+1]+1;
					}
					else
					{
						p[j].dis=1;
						if (dd[i]>dd[p2[j].v]+1) dd[i]=dd[p2[j].v]+1;
					}
				}
				else
					p[j].dis=n;
			printf("%d\n",dd[i] );
			if (dd[i]>1000000000)
			{
				for (int j=head2[i];j+1;j=ne2[j])
					printf("%d %d %d\n",p[j].u,p[j].v,p[j].dis );
				return 0;
			}
		}
		if (pos!=n+1 && dd[pos]==dd[pos-1])
		{
			for (int i=head2[pos];i+1;i=ne2[i])
				if (p[i].dis<n) p[i].dis++;
		}
		//for (int i=1;i<=n;i++) printf("%d ",dd[i] );printf("\n");
		printf("%d %d\n",n,m );
		for (int i=0;i<e;i++) printf("%d %d %d\n",p[i].u,p[i].v,p[i].dis );
	}
	return 0;
}