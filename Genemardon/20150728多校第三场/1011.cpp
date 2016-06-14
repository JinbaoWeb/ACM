#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int dp[200],in[200];
int n,k;
vector<int>tab[200];
void dfs(int x,int fa)
{
	for (int i=0;i<tab[x].size();i++) dfs(tab[x][i],x);
	dp[fa]=dp[fa]+dp[x]+1;
}
int main(int argc, char const *argv[])
{
	while (scanf("%d%d",&n,&k)!=EOF)
	{
		memset(in,0,sizeof(in));
		for (int i=1;i<=n;i++) tab[i].clear();
		for (int i=0;i<n-1;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			tab[u].push_back(v);
			in[v]++;
		}
		memset(dp,0,sizeof(dp));
		for (int i=1;i<=n;i++) if (in[i]==0)
		{
			dfs(i,0);
		}
		int cnt=0;
		for (int i=1;i<=n;i++) 
		{
			//printf("%d  ",dp[i] );
			if (dp[i]==k) cnt++;
		}
		//printf("\n");
		printf("%d\n",cnt );
	}
	return 0;
}