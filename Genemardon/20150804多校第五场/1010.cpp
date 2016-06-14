#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int n,m,k,N;
int match[600],vis[600],ans[600];
int tab[600][600];
vector<int>graph[600];
void init()
{
	N=0;
	memset(tab,0,sizeof(tab));
}
void ddfs(int p,int ro)
{
	graph[ro].push_back(p);
	for (int i=1;i<=n;i++) if (tab[p][i] && !vis[i])
	{
		vis[i]=1;
		ddfs(i,ro);
	}
}
bool dfs(int p)
{
	for (int i=0;i<graph[p].size();i++) if (!vis[graph[p][i]])
	{
		vis[graph[p][i]]=1;
		if (match[graph[p][i]]==-1 || dfs(match[graph[p][i]]))
		{
			match[graph[p][i]]=p;
			return true;
		}
	}
	return false;
}
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d%d",&n,&m,&k);
		init();
		for (int i=0;i<m;i++)
		{
			int com,x,y;
			scanf("%d",&com);
			if (com==1)
			{
				N++;
				graph[N].clear();
				scanf("%d",&x);
				memset(vis,0,sizeof(vis));
				vis[x]=1;
				ddfs(x,N);
			}
			else if (com==2)
			{
				scanf("%d%d",&x,&y); 
				tab[x][y]=tab[y][x]=1;
			}
			else
			{
				int mm;
				scanf("%d",&mm);
				for (int j=0;j<mm;j++)
				{
					scanf("%d%d",&x,&y);
					tab[x][y]=tab[y][x]=0;
				}
			}
		}
		int cnt=0;
		memset(match,-1,sizeof(match));
		memset(ans,0,sizeof(ans));
		for (int i=N;i>=1;i--)
		{
			for (int j=0;j<k;j++)
			{
				memset(vis,0,sizeof(vis));
				if (dfs(i)) ans[i]++;
				else break;
			}
			cnt+=ans[i];
		}
		printf("%d\n", cnt);printf("%d",ans[1] );
		for (int i=2;i<=N;i++) printf(" %d",ans[i] );printf("\n");
	}
	return 0;
}