#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct node
{
	int x,a;
	bool operator<(const node &A)const{
		return x<A.x;
	}
}app[100005];
long long left[100005],right[100005],sa1[100005],sa2[100005];
int n,t,st1,st2,end1,end2,l,k;
int main(int argc, char const *argv[])
{
	scanf("%d",&t);
	while(t--)
	{
		memset(left,0,sizeof(left));
		memset(right,0,sizeof(right));
		memset(sa1,0,sizeof(sa1));
		memset(sa2,0,sizeof(sa2));
		st1=st2=end1=end2=0;
		scanf("%d%d%d",&l,&n,&k);
		for (int i=0;i<n;i++)
			scanf("%d%d",&app[i].x,&app[i].a);
		sort(app,app+n);
		for (int i=0;i<n;i++)
			if (app[i].x<=l/2)
			{
				if (app[i].x==0) continue;
				for (int j=0;j<app[i].a;j++)
					left[++end1]=app[i].x;
			}
			else break;
		for (int i=1;i<=end1;i++)
			if (i<=k) sa1[i]=left[i];
			else sa1[i]=sa1[i-k]+left[i];
		for (int i=n-1;i>=0;i--)
			if (app[i].x>l/2)
			{
				if (app[i].x==l) continue;
				for (int j=0;j<app[i].a;j++)
					right[++end2]=l-app[i].x;
			}
			else break;
		for (int i=1;i<=end2;i++)
			if (i<=k) sa2[i]=right[i];
			else sa2[i]=sa2[i-k]+right[i];
		sa1[0]=sa2[0]=0;
		//for (int i=0;i<=end1;i++) printf("%d ",sa1[i] );printf("\n");
		//for (int i=0;i<=end2;i++) printf("%d ",sa2[i] );printf("\n");
		long long ans=sa1[end1]*2+sa2[end2]*2;
		for (int i=1;i<=k && end1-i>=0;i++)
		{
			int m2=max(0,end2-k+i);
			ans=min(ans,l+sa1[end1-i]*2+sa2[m2]*2);
		}
		printf("%I64d\n",ans );
	}
	return 0;
}