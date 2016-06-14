#pragma comment(linker, "/STACK:102400000,102400000")
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAXN 1000005
using namespace std;
struct note
{
	int u,v;
	note () {}
	note (int u,int v) : u(u),v(v) {}
}p[MAXN*2];
int dfn[MAXN],low[MAXN],iscut[MAXN],head[MAXN],ne[MAXN*2],vis[MAXN],stk[MAXN],S[MAXN],L[MAXN],belong[MAXN],save[MAXN][2];
int e,n,m,index,top,cnt,t;
void init()
{
	e=0;
	cnt=0;
	memset(head,-1,sizeof(head));
	memset(vis,0,sizeof(vis));
	memset(belong,0,sizeof(belong));
	memset(dfn,0,sizeof(dfn));
}
void addnote(int u,int v)
{
	p[e] = note(u,v);
	ne[e]=head[u];
	head[u]=e++;
}
void tarjan(int x,int fa)
{
	vis[x]=1;
	dfn[x]=low[x]=++index;
	stk[top++]=x;
	for (int i=head[x];i+1;i=ne[i])
	{
		if (fa==p[i].v) continue;
		if (!vis[p[i].v])
		{
			tarjan(p[i].v,x);
			low[x]=min(low[x],low[p[i].v]);
		}
		else 
			low[x]=min(low[x],dfn[p[i].v]);
	}
	if (low[x]>=dfn[x])
	{
		cnt++;
		L[cnt]=0;
		do{
			top--;
			belong[stk[top]]=cnt;
			L[cnt]=max(L[cnt],stk[top]);
		}while(stk[top]!=x);
	}
}
void dfs(int x,int fa)
{
	vis[x]=1;S[x]=L[x];
	for (int i=head[x];i+1;i=ne[i])
		if (!vis[p[i].v])
			dfs(p[i].v,x);
	S[fa]=max(S[fa],S[x]);
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
			scanf("%d%d",&save[i][0],&save[i][1]);
			u=save[i][0];
			v=save[i][1];
			addnote(u,v);
			addnote(v,u);
		}
		index=top=0;
		tarjan(1,0);
		memset(head,-1,sizeof(head));
		for (int i=0;i<e;i++)
		{
			p[i].v=belong[p[i].v];
			p[i].u=belong[p[i].u];
			ne[i]=head[p[i].u];
			head[p[i].u]=i;
		}
		memset(vis,0,sizeof(vis));
		dfs(belong[n],0);
		for (int i=0;i<m;i++)
		{
			if (belong[save[i][0]]==belong[save[i][1]])
				printf("0 0\n");
			else
			{
				int pp=min(S[belong[save[i][0]]],S[belong[save[i][1]]]);
				printf("%d %d\n",pp,pp+1);
			}
		}
	}
	return 0;
}