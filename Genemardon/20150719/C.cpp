#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int vx[210],vy[210],slack[210],match[210],lx[210],ly[210];
char str[210][1010];
int dis[210][210];
int inf=1000000009;
int n;
int cal(int a,int b)
{
	int l1=strlen(str[a]),l2=strlen(str[b]);
	int len=min(l1,l2);
	for (int i=0;i<len;i++) if (str[a][l1-i-1]!=str[b][i]) return i;
	return len;
}
int dfs(int p)
{
	vx[p]=1;
	for (int i=0;i<n;i++)
	{
		if (vy[i])
			continue;
		
		int t=lx[p]+ly[i]-dis[p][i];
		if (t==0)
		{
			vy[i]=1;
			if (match[i]==-1 || dfs(match[i]))
			{
				match[i]=p;
				return 1;
			}
		}
		else
		{
			if (slack[i]>t) slack[i]=t;
		}
	}
	return 0;
}
int main(int argc, char const *argv[])
{
	while (scanf("%d",&n) != EOF)
	{
		memset(match,-1,sizeof(match));
		memset(ly,0,sizeof(ly));
		memset(lx,0,sizeof(lx));
		for (int i=0;i<n;i++)
		{
			scanf("%s",str[i]);
		}
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
			{
				int score;
				if (i==j) score=0; else score=cal(i,j);
				dis[i][j]=score;
				lx[i]=max(lx[i],dis[i][j]);
			}
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++) slack[j]=inf;
			while (1)
			{
				memset(vx,0,sizeof(vx));
				memset(vy,0,sizeof(vy));
				if (dfs(i))
					break;
				int t=inf;
				for (int j=0;j<n;j++) if (!vy[j] && slack[j]<t) t=slack[j];
				for (int j=0;j<n;j++) if (vx[j]) lx[j]-=t;
				for (int j=0;j<n;j++) if (vy[j]) ly[j]+=t;else slack[j]-=t;
			}			
		}
		//for (int i=0;i<n;i++) printf("%d ", match[i]);printf("\n");
		int ans=0;
		for (int i=0;i<n;i++) ans=ans+dis[match[i]][i];
		printf("%d\n",ans );
	}
	return 0;
}