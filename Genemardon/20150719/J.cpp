#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
vector<int>tab[70];
int vis[100010],match[100010],vv[70];
int n,x,y;
bool dfs(int p)
{
	for (int i=0;i<tab[p].size();i++) if (vis[tab[p][i]]==0)
	{
		vis[tab[p][i]]=1;
		if (match[tab[p][i]]==-1 || dfs(match[tab[p][i]]))
		{
			match[tab[p][i]]=p;
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
		scanf("%d",&n);
		memset(match,-1,sizeof(match));
		for (int i=1;i<=n;i++) tab[i].clear();
		for (int i=1;i<=n;i++)
		{
			scanf("%d%d",&x,&y);
			for (int j=x;j<=y;j++) tab[i].push_back(j);
		}
		int ans=0;
		memset(vv,0,sizeof(vv));
		for (int i=n;i>=1;i--)
		{
			memset(vis,0,sizeof(vis));
			if (dfs(i)) {ans++;vv[i]=1;}
		}
		printf("%d\n",ans );
		for (int i=1;i<=n;i++) if (vv[i]!=0)
		{
			ans--;
			if (ans) printf("%d ",i );
			else printf("%d\n", i);
		}
	}
	return 0;
}