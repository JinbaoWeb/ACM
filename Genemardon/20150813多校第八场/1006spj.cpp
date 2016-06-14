#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <queue>
#include <vector>
#define MAXN 100010
#define inf 1000000009
using namespace std;
struct node
{
    node(int xx, int disx)
    {
        x = xx; dis = disx;
    }
    int x;
    int dis;
};
struct edge
{
    int to;
    int v;
    edge(int TO, int V)
    {
        to = TO; v = V;
    }
};
int dis[MAXN]; int vis[MAXN];
int n,m;
bool operator<(node a, node b)
{
    return a.dis > b.dis;
}
vector<edge>e[MAXN];
void priq_dij(int x)
{
    priority_queue<node>q;
    while (!q.empty()) q.pop();
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) dis[i] = inf;
    dis[x] = 0; vis[x] = 0;
    for (int i = 0; i < e[x].size(); i++) if (e[x][i].v < dis[e[x][i].to])
        {
            dis[e[x][i].to] = e[x][i].v;
            node tmp(e[x][i].to, e[x][i].v);
            q.push(tmp);
        }
    for (int i = 1; i <= n; i++)
    {
        while (!q.empty() && vis[q.top().x]) q.pop();
        if (q.empty()) break;
        node tmp = q.top();
        q.pop();
        vis[tmp.x] = 1;
            for (int j = 0; j < e[tmp.x].size(); j++) if (!vis[e[tmp.x][j].to] && tmp.dis + e[tmp.x][j].v<dis[e[tmp.x][j].to])
            {
                dis[e[tmp.x][j].to] = tmp.dis + e[tmp.x][j].v;
                node ttmp(e[tmp.x][j].to, dis[e[tmp.x][j].to]);
                q.push(ttmp);
            }
    }
}
int main(int argc, char const *argv[])
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        for (int i=1;i<=n;i++) e[i].clear();
        for (int i=0;i<m;i++)
        {
            int u,v,dis;
            scanf("%d%d%d",&u,&v,&dis);
            e[u].push_back(edge(v,dis));
        }
        priq_dij(1);
        for (int i=1;i<=n;i++) printf("%d\n",dis[i] );
    }
    return 0;
}