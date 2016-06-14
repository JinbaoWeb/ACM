#include <stdio.h>
#include <string.h>
#include <stack>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define LLLson l,m,rt<<1
#define RRRson m+1,r,rt<<1|1
const int MAXN = 200010;
int M[MAXN<<2];
int add[MAXN<<2];
struct node{
    int s,t,w,next;
}edge[MAXN*2];
int E,n;
int size[MAXN] , fa[MAXN] , heavy[MAXN] , head[MAXN] , vis[MAXN];
int dep[MAXN] , rev[MAXN] , num[MAXN] ;
int Seg_size;
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void add_edge(int s,int t,int w)
{
    edge[E].w=w;
    edge[E].s=s;
    edge[E].t=t;
    edge[E].next=head[s];
    head[s]=E++;
}
void dfs(int u,int f)
{
    int mx=-1,e=-1;
    size[u]=1;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].t;   
        if(v==f) continue; 
        dep[v]=dep[u]+1;
        rev[v]=i^1;
        dfs(v,u);
        size[u]+=size[v];
        if(size[v]>mx)
        {
            mx=size[v];
            e=i;
        }
    }
    heavy[u]=e;
    if(e!=-1)  fa[edge[e].t]=u;
}
inline void pushup(int rt){
    M[rt]=M[rt<<1]+M[rt<<1|1];
}
void pushdown(int rt,int m){
    if(add[rt]){
        add[rt<<1]+=add[rt];
        add[rt<<1|1]+=add[rt];
        M[rt<<1]+=add[rt]*(m-(m>>1));
        M[rt<<1|1]+=add[rt]*(m>>1);
        add[rt]=0;
    }
}
void build(int l,int r,int rt){
    M[rt]=add[rt]=0;
    if(l==r){
        return ;
    }
    int m=(l+r)>>1;
    build(LLLson);
    build(RRRson);
}
void update(int L,int R,int val,int l,int r,int rt){
    if(L<=l&&r<=R){
        M[rt]+=val;
        add[rt]+=val;
        return ;
    }
    if (l==r) return;
    pushdown(rt,r-l+1);
    int m=(l+r)>>1;
    if(L<=m) update(L,R,val,LLLson);
    if(R>m) update(L,R,val,RRRson);
    pushup(rt);
}
int query(int L,int R,int l,int r,int rt){
    if(L<=l&&r<=R){
        return M[rt];
    }
    pushdown(rt,r-l+1);
    int m=(l+r)>>1;
    int ret=0;
    if(L<=m) ret+=query(L,R,LLLson);
    if(R>m) ret+=query(L,R,RRRson);
    return ret;
}
void INIT2()
{
    int i;
    build(1,n,1);
    memset(num,-1,sizeof(num));
    dep[0]=0;Seg_size=0;
    for(i=0;i<n;i++) fa[i]=i;
    dfs(0,0);  
    for(i=0;i<n;i++)
    {
        if(heavy[i]==-1)
        {
            int pos=i;
            while(pos && edge[heavy[edge[rev[pos]].t]].t == pos)
            {
                int t=rev[pos];
                num[t]=num[t^1]=++Seg_size;
                update(Seg_size,Seg_size,edge[t].w,1,n,1);
                pos=edge[t].t;
            }
        }
    }
}
int lca(int u,int v)
{
    while(1)
    {
        int a=find(u),b=find(v);
        if(a==b) return dep[u] < dep[v] ? u : v;
        else if(dep[a]>=dep[b]) u=edge[rev[a]].t;
        else v=edge[rev[b]].t;
    }
}
void CH(int u,int lca,int val)
{
    while(u!=lca)
    {
        int r=rev[u];
        if(num[r]==-1) edge[r^1].w+=val,edge[r].w+=val,u=edge[r].t;
        else
        {
            int p=fa[u];
            if(dep[p] < dep[lca]) p=lca;
            int l=num[r];
            r=num[heavy[p]];
            update(l,r,val,1,n,1);
            u=p;
        }
    }
}
void change(int u,int v,int val)
{
    int p=lca(u,v);
    CH(u,p,val);
    CH(v,p,val);
}
int solve(int id)
{
    int r=id;
    if(num[r]==-1) return edge[r].w;
    else return query(num[r],num[r],1,n,1);
}
void init()
{
    memset(head,-1,sizeof(head));
    E=0;
}
int main()
{
    int t,i,a,b,c,m,ca=1,p;
    int T;
    scanf("%d",&T);   
    for (int TT=1;TT<=T;TT++)
    {
        scanf("%d%d",&n,&p);
        p=p-n+1;
        init();
        for(i=0;i<n-1;i++)
        {
            scanf("%d%d",&a,&b);a--;b--;
            add_edge(a,b,0);
            add_edge(b,a,0);
        }
        INIT2();
        while(p--)
        {
            scanf("%d%d",&a,&b);a--;b--;
            change(a,b,1);
        }
        int MIN=100000009;
        for(i=0;i<n-1;i++)
        {
            MIN=min(MIN,solve(2*i));
        }
        printf("Case #%d: %d\n",TT,MIN+1 );
    }
    return 0;
}