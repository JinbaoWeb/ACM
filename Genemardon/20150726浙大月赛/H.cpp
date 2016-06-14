#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
vector<int>tab[50010];
int n,m,q;
int ans[50010];
int main(int argc, char const *argv[])
{
	while (scanf("%d%d%d",&n,&m,&q) != EOF)
	{
		memset(ans,0,sizeof(ans));
		for (int i=1;i<=n;i++) tab[i].clear();
		for (int i=0;i<m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			if (v<u)
				tab[u].push_back(v);
		}
		int m1=n,m2=n;
		for (int i=n;i>1;i--)
		{
			for (int j=0;j<tab[i].size();j++) if (tab[i][j]<m1)
			{
				m2=m1;
				m1=tab[i][j];
			}
			else if (tab[i][j]<m2)
			{
				m2=tab[i][j];
			}
			ans[i]=max(i-m2,0);
		}
		int ask;
		for (int i=0;i<q;i++)
		{
			scanf("%d",&ask);
			printf("%d\n", ans[ask]);
		}
	}
	return 0;
}