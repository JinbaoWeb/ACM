#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct node
{
	int l,r;
};
struct point
{
	int num,pos;
};
node edge[500010];
point a[500010];
int b[500010];
int pre[500010];
int n,m;
int cmp(point x,point y)
{
	if (x.num<y.num) return 1;
	else if (x.num>y.num) return 0;
	else return x.pos<y.pos;
}
int main(int argc, char const *argv[])
{
	int pp=0;
	while (scanf("%d",&n) != EOF)
	{
		//if (pp) printf("\n");
		memset(pre,-1,sizeof(pre));
		for (int i=0;i<n;i++) 
			{
				scanf("%d",&a[i].num);
				b[i]=a[i].num;
				a[i].pos=i;
			}
		sort(a,a+n,cmp);
		for (int i=0;i<n-1;i++) if (a[i].num==a[i+1].num)
			pre[a[i].pos]=a[i+1].pos;
		//for (int i=0;i<n;i++) printf("%d ",pre[i] );printf("\n");
		scanf("%d",&m);
		int L,R;
		for (int i=0;i<m;i++)
		{
			int flag=-1;
			scanf("%d%d",&L,&R);
			L--;R--;
			for (int j=R-1;j>=L;j--) if (pre[j]!=-1 && pre[j]<=R)
			{
				//printf("jjj%d\n",j );
				flag=b[j];
				break;
			}
			if (flag!=-1) printf("%d\n", flag);else printf("OK\n");
		}
		pp=1;
		printf("\n");
	}
	return 0;
}