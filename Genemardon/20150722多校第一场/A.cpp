#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int a[100010],pos[10010],front[100010],tail[100010];
int n,m;
int MOD=1000000007;
int presplit(int x)
{
	int res=0;
	for (int i=1;i*i<=x;i++) if (x%i==0)
	{
		if (pos[i]>res) res=pos[i];
		if (pos[x/i]>res) res=pos[x/i];
	}
	return res;
}
int postsplit(int x)
{
	int res=n+1;
	for (int i=1;i*i<=x;i++) if (x%i==0)
	{
		if (pos[i]<res) res=pos[i];
		if (pos[x/i]<res) res=pos[x/i];
	}
	return res;
}
int main(int argc, char const *argv[])
{
	while (~scanf("%d",&n))
	{
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		memset(pos,0,sizeof(pos));
		for (int i=1;i<=n;i++)
		{
			front[i]=presplit(a[i]);
			pos[a[i]]=i;
		}
		for (int i=1;i<=10000;i++) pos[i]=n+1;
		for (int i=n;i>0;i--)
		{
			tail[i]=postsplit(a[i]);
			pos[a[i]]=i;
		}
		long long ans=0;
		for (int i=1;i<=n;i++)
		{
			long long tmp=i-front[i];
			long long ttmp=tail[i]-i;
			ans=(ans+tmp*ttmp)%MOD;
		}
		//for (int i=1;i<=n;i++) printf("%d ",front[i] );printf("\n");
		//for (int i=1;i<=n;i++) printf("%d ",tail[i] );printf("\n");
		printf("%lld\n",ans );
	}
	return 0;
}