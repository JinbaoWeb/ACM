#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef struct treasures
{
	int t;
	int s;
}tre;
int cmpt(tre a, tre b)
{
	if (a.t != b.t)
		return a.t < b.t;
	else
		return a.s < b.s;
}
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		tre a[10005] = {0,0};
		int i,j;
		int time = 0;
		int bleg = 1,f=0;
		for(i = 0;i<n;i++)
		{
			scanf("%d %d",&a[i].s,&a[i].t);
			if(a[i].t == 0) f=1;
		}
		sort(a,a+n,cmpt);
		/*for(i=0;i<n;i++)
			printf("%d %d\n",a[i].s,a[i].t);
		printf("\n");*/
		if(f==1) bleg=0;
		else
		for(i=1;i<n;i++)
		{
			int min = a[i].s<a[i-1].s?a[i].s:a[i-1].s;
			int max = a[i].s>a[i-1].s?a[i].s:a[i-1].s;
			//printf("min = %d,max = %d,a[%d] s = %d,t = %d\n",min,max,i,a[i].s,a[i].t);
			if(a[i].t != 0)
			{
				if(max - min > 1)
				for(j = i+1;j<n;j++)
			    {
					if(a[j].s > min && a[j].s < max)
						a[j].t = 0;
				}
				time  += abs(a[i].s  - a[i-1].s);
				//printf(" %d time = %d,a[i].t = %d\n",i,time,a[i].t);
				if(time >= a[i].t) {bleg = 0;break;}
			}

		}

		if(n==0 || bleg == 0) printf("No solution\n");
		else if(bleg == 1) printf("%d\n",time);
	}
}

