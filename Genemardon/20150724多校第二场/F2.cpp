#include <stdio.h>
#include <string.h>
struct note
{
	int u,v;
	note () {}
	note (int u,int v) : u(u),v(v) {}
}p[200];
int n,m,ans;
int checkin[200],w[200],b[200];
void dfs(int x)
{
	if (x==m) ans++;
	if (b[p[x].u] && b[p[x].v])
	{
		b[p[x].u]--;
		b[p[x].v]--;
		dfs(x+1);
		b[p[x].u]++;
		b[p[x].v]++;
	}
	if (w[p[x].u] && w[p[x].v])
	{
		w[p[x].u]--;
		w[p[x].v]--;
		dfs(x+1);
		w[p[x].u]++;
		w[p[x].v]++;
	}
}
int main(int argc, char const *argv[])
{
	int t,u,v;
	scanf("%d",&t);
	while (t--)
	{
		memset(checkin,0,sizeof(checkin));
		scanf("%d%d",&n,&m);
		for (int i=0;i<m;i++)
		{
			scanf("%d%d",&u,&v);
			p[i] = note (u,v);
			checkin[u]++;checkin[v]++;
		}
		int flag=1;
		for (int i=1;i<=n;i++) if (checkin[i]%2==1) flag=0;
		if (!flag)
		{
			printf("0\n");
			continue;
		}
		for (int i=1;i<=n;i++)
		{
			w[i]=checkin[i]/2;
			b[i]=w[i];
			//printf("%d\n",b[i] );
		}
		ans=0;
		dfs(0);
		printf("%d\n",ans );
	}
	return 0;
}