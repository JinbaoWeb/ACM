#include <stdio.h>
#include <string.h>
#include <algorithm>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int MOD = 1e9+7;
struct note
{
	int u,v;
	note () {}
	note (int u,int v) : u(u),v(v) {} 
}p[200010];
struct node
{
	int leaf,sub;
	int Sub[2];
	long long sum;
}tr[100010];
int e,n,flag;
int head[100010],ne[200010],vis[100010];
int perm[100010];
void init()
{
	e=0;
	flag=1;
	memset(head,-1,sizeof(head));
	memset(tr,0,sizeof(tr));
	memset(vis,0,sizeof(vis));
}
void addnote(int u,int v)
{
	p[e]=note(u,v);
	ne[e]=head[u];head[u]=e++;
}
void makeperm()
{
	long long pp=1;
	perm[0]=1;
	for (int i=1;i<=100000;i++)
	{
		pp=pp*i%MOD;
		perm[i]=int(pp);
	}
}
void dfs(int x,int fa)
{
	vis[x]=1;
	tr[x].sum=1;
	for (int i=head[x];i+1;i=ne[i]) if (!vis[p[i].v]) dfs(p[i].v,x);
	if (!flag) return;
	if (tr[x].sub>2)
	{
		flag=0;
		return;
	}
	if (tr[x].sub==1) tr[x].sum=tr[x].sum*(tr[tr[x].Sub[0]].sum)*2%MOD;
	if (tr[x].sub==2) tr[x].sum=tr[x].sum*tr[tr[x].Sub[0]].sum*tr[tr[x].Sub[1]].sum*2%MOD;
	tr[x].sum=tr[x].sum*perm[tr[x].leaf]%MOD;
	//printf("node:%d fa:%d leaf:%d sub:%d sum:%I64d\n",x,fa,tr[x].leaf,tr[x].sub,tr[x].sum );
	if (tr[x].leaf==0 && tr[x].sub==0)
	{
		tr[fa].leaf++;
		return;
	}
	else
	{
		int i=tr[fa].sub++;
		if (tr[fa].sub>2)
		{
			flag=0;
			return;
		}
		tr[fa].Sub[i]=x;
		return;
	}
}
int main(int argc, char const *argv[])
{
	makeperm();
	int t;
	scanf("%d",&t);
	for (int TT=1;TT<=t;TT++)
	{
		init();
		scanf("%d",&n);
		for (int i=0;i<n-1;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			addnote(u,v);
			addnote(v,u);
		}
		dfs(1,0);
		if (!flag)
		{
			printf("Case #%d: 0\n",TT );
			continue;
		}
		if (tr[1].leaf!=0 || tr[1].sub!=0) tr[1].sum=tr[1].sum*2%MOD;
		printf("Case #%d: %I64d\n",TT,tr[1].sum );
	}
	return 0;
}