#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#define Max 200
#define inf  1000000009
using namespace std;
int qa[20000],qb[20000];
int tab[2000][2000];
int n,m,cnta,cntb;
int c[2000];
int ans,la,lb;
int cap[Max][Max], pre[Max];
int cost[Max][Max], dis[Max];
int que[Max];
bool vis[Max];
bool spfa(){                  //  源点为0，汇点为n。
    int i, head = 0, tail = 1;
    for(i = 0; i <= la+lb+1; i ++){
        dis[i] = inf;
        vis[i] = false;
    }
    dis[0] = 0;
    que[0] = 0;
    vis[0] = true;
    while(tail != head){      //  循环队列。
        int u = que[head];
        for(i = 0; i <= la+lb+1; i ++)
            if(cap[u][i] && dis[i] > dis[u] + cost[u][i]){    //  存在路径，且权值变小。
                dis[i] = dis[u] + cost[u][i];
                pre[i] = u;
                if(!vis[i]){
                    vis[i] = true;
                    que[tail ++] = i;
                    if(tail == Max) tail = 0;
                }
            }
        vis[u] = false;
        head ++;
        if(head == Max) head = 0;
    }
    if(dis[la+lb+1] == inf) return false;
    return true;
}

void end(){
    int i, sum = inf;
    for(i = la+lb+1; i != 0; i = pre[i])
        sum = min(sum, cap[pre[i]][i]);
    	cnta-=sum;
    	cntb-=sum;
    for(i = la+lb+1; i != 0; i = pre[i]){
        cap[pre[i]][i] -= sum;
        cap[i][pre[i]] += sum;
        ans += cost[pre[i]][i] * sum;   //  cost[][]记录的为单位流量费用，必须得乘以流量。
    }
}
int main(int argc, char const *argv[])
{
	while (scanf("%d%d",&n,&m) !=EOF)
	{
		la=lb=0;cnta=cntb=0;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++) tab[i][j]=inf;
		for (int i=1;i<=n;i++)
		{
			int ai,bi;
			scanf("%d%d",&ai,&bi);
			c[i]=ai-bi;
			if (c[i]>0)
			{
				la++;
				qa[la]=i;
				cnta+=c[i];
			}
			else if (c[i]<0)
			{
				lb++;
				qb[lb]=i;
				cntb-=c[i];
			}
		}
		for (int i=0;i<m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			tab[u][v]=1;
			tab[v][u]=1;
		}
		for (int k=1;k<=n;k++)
			for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++) if (tab[i][k]+tab[k][j]<tab[i][j])
					{
						tab[i][j]=tab[i][k]+tab[k][j];
						tab[j][i]=tab[j][i];
					}
		memset(cap,0,sizeof(cap));
		memset(cost,0,sizeof(cost));
		for (int i=1;i<=la;i++)
			for (int j=1;j<=lb;j++)
				if (tab[qa[i]][qb[j]]!=inf)
				{
					cost[i][la+j]=tab[qa[i]][qb[j]];
					cost[la+j][i]=-cost[i][la+j];
					cap[i][la+j]=inf;
				}
		for (int i=1;i<=la;i++)
			cap[0][i]=c[qa[i]];
		for (int j=1;j<=lb;j++)
			cap[la+j][la+lb+1]=-c[qb[j]];
		// printf("-------cap------\n");
		// for (int i=0;i<=la+lb+1;i++)
		// {
		// 	for (int j=0;j<=la+lb+1;j++)
		// 		printf("%d ",cap[i][j]);
		// 	printf("\n");
		// }
		// printf("-------cost--------\n");
		// for (int i=0;i<=la+lb+1;i++)
		// {
		// 	for (int j=0;j<=la+lb+1;j++)
		// 		printf("%d ",cost[i][j]);
		// 	printf("\n");
		// }
		// printf("%d %d\n",cnta,cntb );
		ans=0;
		while (spfa()) end();
		//printf("%d %d\n",cnta,cntb );
		if (cnta==0 && cntb==0) printf("%d\n",ans );
		else printf("-1\n");
	}
	return 0;
}