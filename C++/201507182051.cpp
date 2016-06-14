#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct node
{
    int x,com;
    node (int X,int C){x=X;com=C;}
};
int dp[100010][2];
int n,m,flag;
int vis[100010];
vector<int>tab[100010];
void bfs(int x)
{
    queue<node>q;
    while (!q.empty()) q.pop();
    node ee(x,-1);
    vis[x]=-1;
    q.push(ee);
    dp[0][0]++;
    while (!q.empty())
    {
        node tmp=q.front();
        q.pop();
        //printf("%d ::%d\n",tmp.x,tmp.com );
        for (int i=0;i<tab[tmp.x].size();i++) if (vis[tab[tmp.x][i]]==0)
        {
            node rr(tab[tmp.x][i],-tmp.com);
            q.push(rr);
            vis[tab[tmp.x][i]]=-tmp.com;
            if (tmp.com==1) dp[0][0]++;else dp[0][1]++;
        }
        else
        if (vis[tab[tmp.x][i]]==tmp.com)
        {
            flag=0;break;
        }
    }
}
int main(int argc, char const *argv[])
{
    int t,ans;
    scanf("%d",&t);
    while (t--)
    {
        ans=0;
        flag=1;
        memset(dp,0,sizeof(dp));
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++) tab[i].clear();
        for (int i=1;i<=m;i++) 
        {
            int x,y;
            scanf("%d%d",&x,&y);
            tab[x].push_back(y);
            tab[y].push_back(x);
        }
        memset(vis,0,sizeof(vis));
        for (int i=1;i<=n;i++)  if (vis[i]==0)
        {
            dp[0][0]=0;dp[0][1]=0;
            bfs(i);
            //printf("%d %d\n",dp[0][0],dp[0][1] );
            ans=ans+max(dp[0][0],dp[0][1]);
        }
        if (flag && ans>1) 
        {
            if (ans!=n)
             printf("%d %d\n",ans,n-ans );
            else 
                printf("%d 1\n",ans-1 );
        }
        else printf("Poor wyh\n");
    }
    return 0;
}