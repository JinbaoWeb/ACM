#pragma comment(linker, "/STACK:1024000000,1024000000") 
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct note
{
    int u,v;
    note () {}
    note (int u,int v) : u(u),v(v) {}
} p[1000000];
int n,e;
int head[500010],NEXT[1000000],in[500010],w[500010],vis[500010];
void addnote(int u,int v)
{
    p[e]= note (u,v);
    NEXT[e]=head[u],head[u]=e++;
}
void init()
{
    e=0;
    memset(vis,0,sizeof(vis));
    memset(in,0,sizeof(in));
    memset(head,-1,sizeof(head));
    memset(NEXT,-1,sizeof(NEXT));
}
int dfs(int x)
{
    int res=1;
    for (int i=head[x];i+1;i=NEXT[i])
        if (vis[p[i].v]) res+=vis[p[i].v];
    else res+=dfs(p[i].v);
    vis[x]=res;
    return res;
}
int main(int argc, char const *argv[])
{
    while (scanf("%d",&n) != EOF)
    {
        printf("%d~\n",n );
        init();
        for (int i=1;i<=n;i++) scanf("%d",&w[i]);
        for (int i=1;i<n;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            if (w[u]<w[v])
            {
                addnote(u,v);
                in[v]++;
            }
            else 
            {
                addnote(v,u);
                in[u]++;
            }
        }
        int ans=0;
        for (int i=1;i<=n;i++) if (in[i]==0)
        {
            int tmp=dfs(i);
            ans=max(ans,tmp);
        }
        printf("%d\n",ans );
    }
    return 0;
}