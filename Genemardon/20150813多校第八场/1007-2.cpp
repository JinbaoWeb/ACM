#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int res[110][110],dest[110][110];
int oper[1000][3];
int n,m;
int ans[1000],list[1000];
bool check(int p)
{
	if (oper[p][0]==0)
	{
		for (int i=1;i<=n;i++) 
			if (dest[i][oper[p][1]]!=oper[p][2] && dest[i][oper[p][1]]!=-1) 
				return false;
	}
	else
	{
		for (int i=1;i<=n;i++)
			if (dest[oper[p][1]][i]!=oper[p][2] && dest[oper[p][1]][i]!=-1)
				return false;
	}
	return true;
}
void change(int p)
{
	if (oper[p][0]==0)
	{
		for (int i=1;i<=n;i++) 
			dest[i][oper[p][1]]=-1;
	}
	else
	{
		for (int i=1;i<=n;i++)
			dest[oper[p][1]][i]=-1;
	}
}
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				scanf("%d",&res[i][j]);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				scanf("%d",&dest[i][j]);
		for(int i=0;i<m;i++)
		{
			char str[10];
			scanf("%s%d%d",str,&oper[i][1],&oper[i][2]);
			if (str[0]=='L') 
					oper[i][0]=0;
			else oper[i][0]=1;
		}
		memset(ans,0,sizeof(ans));
		for (int i=m;i>=1;i--)
		{
			for (int j=0;j<m;j++) if (!ans[j])
			{
				if (check(j))
				{
					change(j);
					ans[j]=i;
					break;
				}
			}
		}
		for (int i=0;i<m;i++) list[ans[i]]=i+1;
		printf("%d", list[1]);
		for (int i=2;i<=m;i++) printf(" %d",list[i] );printf("\n");
	}
	return 0;
}