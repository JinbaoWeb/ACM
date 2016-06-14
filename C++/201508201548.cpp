#include<map>
#include<set>
#include<queue>
#include<math.h>
#include<string>
#include<vector>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#define clr(a,b) memset(a,b,sizeof a)
using namespace std;

int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}


typedef long long ll;
const int N=100007;
int n,q;
struct Adj{
    int to,next,w;
}adj[N];
int head[N],tot_;
ll hash_[N];
int vis[N];
int rsum[N];
void add_edge(int u,int v,int w)
{
    adj[tot_].to=v;
    adj[tot_].w=w;
    adj[tot_].next=head[u];
    head[u]=tot_++;
}

void dfs(int cur,int sum,int pre)
{
    rsum[cur]=sum;
    hash_[sum]++;
    for(int i=head[cur];i!=-1;i=adj[i].next)
    {
        int to=adj[i].to;
        if(to!=pre)
            dfs(to,sum^adj[i].w,cur);
    }
}


int main()
{
    int T;scanf("%d",&T);
    while(T--)
    {
        memset(vis,0,sizeof 0);
        memset(hash_,0,sizeof hash_);
        memset(head,-1,sizeof head);tot_=0;
        scanf("%d",&n);
        int u,v,w;
        for(int i=1;i<n;i++)
        {
            u=read();
            v=read();
            w=read();
            add_edge(u,v,w);
            add_edge(v,u,w);
        }
        dfs(1,0,-1);
        q=read();
        ll ans=0;
        int val,tmp;
        for(int i=1;i<=q;i++)
        {
            ans=0;
            val=read();
            if(val==0)
            {
                printf("%d\n",n);
                continue;
            }
            for(int j=1;j<=n;j++)
            {
                tmp=rsum[j];
                if(vis[tmp]!=i&&vis[tmp^val]!=i)
                {
                    vis[tmp]=i;
                    vis[tmp^val]=i;
                    if(tmp==(tmp^val))
                        ans=ans+hash_[tmp];
                    else
                        ans=ans+hash_[tmp]*hash_[tmp^val];
                }
            }
            printf("%I64d\n",ans);
        }
    }
    return 0;
}