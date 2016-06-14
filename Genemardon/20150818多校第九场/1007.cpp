#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int map[200][200];
int vis[200][200];
char s1[10]="LR",s2[10]="UD";
int main(int argc, char const *argv[])
{
	int n,m;
	int sum;
	int px,py;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		px=py=0;
		sum=0;int MIN=1000000;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
			{
				scanf("%d",&map[i][j]);
				sum+=map[i][j];
				if ((i+j)%2==1 && map[i][j]<MIN)
				{
					MIN=map[i][j];
					px=i;
					py=j;
				}
			}
		if (n%2==1 || m%2==1)
		{
			printf("%d\n",sum );
			if (n%2==1)
			{
				for (int i=1;i<n;i++)
				{
					for (int j=1;j<m;j++) printf("%c",s1[i&1] );
					printf("D");
				}
				for (int j=1;j<m;j++)  printf("R" );
			}
			else
			{
				for (int i=1;i<m;i++)
				{
					for (int j=1;j<n;j++) printf("%c",s2[i&1] );
					printf("R");
				}
				for (int j=1;j<n;j++) printf("D");
			}
			printf("\n");
			continue;
		}
		memset(vis,0,sizeof(vis));
		printf("%d\n",sum-MIN );
		int x=1,y=1,dir=1;
		vis[px][py]=1;
		vis[1][1]=1;
		for (int i=0;i<=max(n,m)+1;i++)
		{
			vis[0][i]=1;
			vis[i][0]=1;
			vis[n+1][i]=1;
			vis[i][m+1]=1;
		}
		while(x!=n || y!=m)
		{
			if (px==x+1 && !vis[x+1][y])
			{
				printf("D");
				x++;
				vis[x][y]=1;
			}
			else if (!vis[x-1][y])
			{
				printf("U");
				x--;vis[x][y]=1;
			}
			else if (!vis[x][y+dir])
			{
				if (dir==1) printf("R");
				else printf("L");
				y+=dir;vis[x][y]=1;
			}
			else
			{
				printf("D");
				x++;
				vis[x][y]=1;
				if (vis[x][y+dir]) dir=-dir;
			}
		}
		printf("\n");
	}
	return 0;
}