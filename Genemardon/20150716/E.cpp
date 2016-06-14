#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int n,t,cnt;
int a[20],b[20],c[20],now[20][2];
void init()
{
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	memset(now,0,sizeof(now));
}
int gao(int x)
{
	if (now[x][0]==0)
	{
		if (now[x][1]==a[x] && cnt>(n/2))
		{
			now[x][0]=1;
			now[x][1]=1;
			return 1;
		}
		else
		{
			now[x][1]++;
			return 0;
		}
	}
	else
	{
		if (now[x][1]==b[x])
		{
			now[x][0]=0;
			now[x][1]=1;
			return 0;
		}
		else
		{
			now[x][1]++;
			return 1;
		}
	}
}
int main(int argc, char const *argv[])
{
	t=0;
	while (scanf("%d",&n) && n)
	{
		t++;
		init();cnt=0;
		for (int i=0;i<n;i++)
		{
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			if (c[i]<=a[i])
			{
				now[i][0]=0;now[i][1]=c[i];cnt++;
			}
			else
			{
				now[i][0]=1;now[i][1]=c[i]-a[i];
			}
		}
		if (cnt==n)
		{
			printf("Case %d: 1\n",t );
			continue;
		}
		for (int k=2;;k++)
		{
			int flag=1;cnt=0;
			for (int i=0;i<n;i++) if(now[i][0]==1) cnt++;
			for (int i=0;i<n;i++) if (gao(i)) flag=0;
			if (flag)
			{
				printf("Case %d: %d\n", t,k);
				break;
			}
			if (k>1000000)
			{
				printf("Case %d: -1\n",t );
				break;
			}
		}
	}
	return 0;
}