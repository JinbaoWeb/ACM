#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int a[100010];
int ex[10];
int main(int argc, char const *argv[])
{
	memset(a,0,sizeof(a));
	for (int i=1;i<=100000;i++)
	{
		int x=i,flag=1;
		memset(ex,0,sizeof(ex));
		while (x)
		{
			if (!ex[x%10]) ex[x%10]=1;
			else
			{
				flag=0;break;
			}
			x/=10;
		}
		a[i]=flag;
	}
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int l,r,cnt=0;
		scanf("%d%d",&l,&r);
		for (int i=l;i<=r;i++) if (a[i]) cnt++;
		printf("%d\n",cnt);
	}
	return 0;
}