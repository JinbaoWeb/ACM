#include <stdio.h>
#include <string.h>
#include <algorithm>
#define  maxn 400010
#define maxm 400010
using namespace std;
struct node
{
	int l,r,lazy,min;
}tree[maxn*4];
struct note
{
	int u,v;
	note () {}
	note (int u,int v) : u(u),v(v) {}
}p[maxm*2];
int n,m,e,z;
int first[maxn], dep[maxn], w[maxn], fa[maxn], top[maxn], son[maxn], siz[maxn],lazy[maxn],ne[maxm*2],head[maxn];
void init()
{
	e=z=0;
	memset(head,-1,sizeof(head));
	memset(son,0,sizeof(son));
}
void addnote(int u,int v)
{
	p[e] = note(u,v);
	ne[e]=head[u];
	head[u]=e++;
}
void dfs1(int x)
{
     siz[x] = 1; son[x] = 0;
     for (int i = head[x]; i+1; i = ne[i])
         if (p[i].v!=fa[x])
         {
         	 int v=p[i].v;
             fa[v]=x;
             dep[v] = dep[x]+1;
             dfs1(v);
             if (siz[v] > siz[son[x]]) son[x] = v;
             siz[x] += siz[v];
         }
}
void dfs2(int x,int tp)
{
	w[x]=++z;
	top[x]=tp;
	if (son[x]!=0) dfs2(son[x],tp);
	for (int i=head[x];i+1;i=ne[i])
		if (p[i].v!=fa[x] && p[i].v!=son[x])
			dfs2(p[i].v,p[i].v);
}
void build(int p,int l,int r)
{
	tree[p].l=l;
	tree[p].r=r;
	tree[p].lazy=tree[p].min=0;
	if (l==r) return;
	build(p*2,l,(l+r)/2);
	build(p*2+1,(l+r)/2+1,r);
}
void add(int p,int l,int r)
{
	if (tree[p].l==l && tree[p].r==r)
	{
		tree[p].min++;
		tree[p].lazy++;
		return;
	}
	if (tree[p].lazy)
	{
		tree[p*2].min+=tree[p].lazy;
		tree[p*2+1].min+=tree[p].lazy;
		tree[p*2].lazy+=tree[p].lazy;
		tree[p*2+1].lazy+=tree[p].lazy;
		tree[p].lazy=0;
	}
	if (tree[p*2].r>=r) add(p*2,l,r);
	else if (tree[p*2+1].l<=l) add(p*2+1,l,r);
	else
	{
		add(p*2,l,tree[p*2].r);
		add(p*2+1,tree[p*2+1].l,r);
	}
	tree[p].min=min(tree[p*2].min,tree[p*2+1].min);
}
void change(int x,int y)
{
	//printf("%d %d %d %d\n",x,y,top[x],top[y] );
	while(top[x]!=top[y])  
    {
        if(dep[top[x]]<dep[top[y]]) swap(x,y); 
        // printf("%d %d %d\n",top[x],son[top[x]],w[son[top[x]]] );
        // printf("222 %d %d\n",w[son[top[x]]],w[x] ); 
        add(1,w[top[x]],w[x]);
        x=fa[top[x]];  
    }  
    if(dep[x]>dep[y]) swap(x,y); 
   // printf("%d %d\n",w[son[x]],w[y] );
    add(1,w[son[x]],w[y]); 
}
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	for (int TT=1;TT<=t;TT++)
	{
		init();
		scanf("%d%d",&n,&m);
		m=m-n+1;
		for (int i=0;i<n-1;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			addnote(u,v);
			addnote(v,u);
		}
		dfs1(1);
		fa[1]=1;
		dfs2(1,1);
		build(1,2,n);
		// for (int i=1;i<=n;i++) printf("%d ",dep[i] );printf("\n");
		// for (int i=1;i<=n;i++) printf("%d ",siz[i] );printf("\n");
		// for (int i=1;i<=n;i++) printf("%d ",son[i] );printf("\n");
		// for (int i=1;i<=n;i++) printf("%d ",fa[i] );printf("\n");
		// for (int i=1;i<=n;i++) printf("%d ",w[i] );printf("\n");
		for (int i=0;i<m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			change(u,v);
		}
		printf("Case #%d: %d\n",TT,tree[1].min+1 );
	}
	return 0;
}