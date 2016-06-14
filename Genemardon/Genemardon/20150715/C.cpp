#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int n,m,x,y;
int st[100010];
long long sonsum[100010];
vector<int>tab[100010];
long long sum;
void dfs(int x,int fa)
{
	for (int i=0;i<tab[x].size();i++) if (tab[x][i]!=fa) dfs(tab[x][i],x);
	sonsum[x]+=st[x];
	sonsum[fa]=sonsum[fa]+sonsum[x];
}
long long ABS(long long x)
{
	if (x>0) return x;else return -x;
}
int main(int argc, char const *argv[])
{
	int t=0;
	while (scanf("%d%d",&n,&m) && n && m)
	{
		t++;
		sum=0;
		memset(st,0,sizeof(st));
		memset(sonsum,0,sizeof(sonsum));
		for (int i=1;i<=n;i++) tab[i].clear();
		for (int i=1;i<=n;i++) {scanf("%d",&st[i]);sum+=st[i];}
		for (int i=0;i<m;i++)
		{
			scanf("%d%d",&x,&y);
			tab[x].push_back(y);
			tab[y].push_back(x);
		}
		dfs(1,0);
		//for (int i=1;i<=n;i++) printf("%lld\n",sonsum[i]);
		long long MM=sum;
		for (int i=1;i<=n;i++) MM=min(MM,ABS(sum-sonsum[i]*2));
		printf("Case %d: %lld\n", t,MM);
	}
	return 0;
}