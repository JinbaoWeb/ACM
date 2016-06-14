#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
struct note
{
	int u,v;
	note () {}
	note (int u,int v) : u(u),v(v){}
}p[30000];
int e,n,l,flag;
int head[30000],ne[30000],vis[30000];
char tree[20000],str[20000];
vector<int>tab1[30000],tab2[30000];
void init()
{
	e=flag=0;
	memset(head,-1,sizeof(head));
}
void addnote(int u,int v)
{
	p[e]=note(u,v);
	ne[e]=head[u];
	head[u]=e++;
}
void dfs(int x)
{
	int ex1[10010],ex2[10010];
	memset(ex1,0,sizeof(ex1));
	memset(ex2,0,sizeof(ex2));
	vis[x]=1;
	if (tree[x-1]==str[0]) {ex1[0]=1;}
	if (tree[x-1]==str[l-1]) {ex2[l-1]=1;}
	// printf("-----%d-----\n",x );
	// printf("%c %c %c\n",tree[x-1],str[0],str[l-1] );
	// for (int j=0;j<l;j++) printf("%d ",ex1[j] );printf("\n");
	// for (int j=0;j<l;j++) printf("%d ",ex2[j] );printf("\n");
	for (int i=head[x];i+1;i=ne[i])
		if (vis[p[i].v]==0)
		{
			int v=p[i].v;
			dfs(v);
			if (flag) return;
			for (int j=0;j<tab1[v].size();j++)
				if (tree[x-1]==str[tab1[v][j]+1])
					ex1[tab1[v][j]+1]=1;
			for (int j=0;j<tab2[v].size();j++)
				if (tree[x-1]==str[tab2[v][j]-1])
					ex2[tab2[v][j]-1]=1;
		}
	
	if (ex1[l-1]==1)
	{
		flag=1;
		return;
	}
	if (ex2[0]==1)
	{
		flag=1;
		return;
	}
	for (int i=0;i<l;i++)
	{
		if (ex1[i]) tab1[x].push_back(i);
		if (ex2[l-i-1]) tab2[x].push_back(l-1-i);
		if (ex1[i]==1 && ex2[i]==1)
		{
			flag=1;
			return;
		}
	}
	// printf("-----%d-----\n",x );
	// for (int j=0;j<l;j++) printf("%d ",ex1[j] );printf("\n");
	// for (int j=0;j<l;j++) printf("%d ",ex2[j] );printf("\n");
	// for (int j=0;j<tab1[x].size();j++)
	// 			printf("%d ",tab1[x][j] );
	// printf("\n" );
	// for (int j=0;j<tab2[x].size();j++)
	// 			printf("%d ",tab2[x][j] );
	// printf("\n");
}
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	for (int TT=1;TT<=t;TT++)
	{
		memset(vis,0,sizeof(vis));
		init();
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		{
			tab1[i].clear();
			tab2[i].clear();
		}
		for (int i=0;i<n-1;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			addnote(u,v);
			addnote(v,u);
		}
		scanf("%s%s",tree,str);
		l=strlen(str);
		dfs(1);
		if (flag)
			printf("Case #%d: Find\n",TT );
		else
			printf("Case #%d: Impossible\n",TT );
	}
	return 0;
}