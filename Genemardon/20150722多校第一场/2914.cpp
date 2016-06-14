#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#define inf 1000000009
using namespace std;
int n,m,ans,MAX,minC;
int vis[510],comb[510],w[510];
int tab[510][510];
void search(int &s,int &t)
{
	int pos;
	memset(vis,0,sizeof(vis));
	memset(w,0,sizeof(w));
	for (int i=0;i<n;i++)
	{
		MAX=-inf;
		for (int j=0;j<n;j++) 
			if (!vis[j]&&!comb[j]&&MAX<w[j]){
			    MAX=w[j];
			    pos=j;
		    }
		if (t==pos){
			minC=w[pos];
			return;
		}
		vis[pos]=1;
		s=t;t=pos;
		for (int j=0;j<n;j++) 
			if (!vis[j]&&!comb[j])
			    w[j]=w[j]+tab[t][j];
		
	}
	minC=w[t];
}
void mincut()
{
	ans=inf;
	memset(comb,0,sizeof(comb));
	for (int i=0;i<n-1;i++)
	{
		int s=-1,t=-1;
		search(s,t);
		comb[t]=1;
		ans=min(ans,minC);
		for (int j=0;j<n;j++)
		{
			tab[s][j]+=tab[t][j];
			tab[j][s]+=tab[j][t];
		}
	}
}
int main(int argc, char const *argv[])
{
	while (~scanf("%d%d",&n,&m))
	{
		memset(tab,0,sizeof(tab));
		for (int i=0;i<m;i++)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			tab[u][v]+=w;
			tab[v][u]+=w;
		}
		mincut();
		printf("%d\n",ans );
	}
	return 0;
}