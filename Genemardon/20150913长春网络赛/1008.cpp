#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
char ans[2010][2010];
int n,m;
int list[2010];
void dfs(int l,int r,int level)
{
	//printf("%d %d %d\n",l,r,level );
	ans[l][level]='\0';
	if (l==r) return;
	int p=0;
	for (int i=l+1;i<=r;i++)
		if (list[i]<list[l])
			ans[list[i]][level]='E';
		else
		{
			p=i;
			break;
		}
	//printf("p %d\n",p );
	if (p==0) p=r+1;
	if (p>l+1) dfs(l+1,p-1,level+1);
	if (p<=r)
	{
		for (int i=p;i<=r;i++)
			ans[list[i]][level]='W';
		dfs(p,r,level+1);
	}
}
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(ans,0,sizeof(ans));
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
			scanf("%d",&list[i]);
		dfs(1,n,0);
		scanf("%d",&m);
		for (int i=0;i<m;i++)
		{
			int x;
			scanf("%d",&x);
			printf("%s\n",ans[x] );
		}
	}
	return 0;
}