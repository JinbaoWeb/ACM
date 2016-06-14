#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
const double eps=1e-9;
double lim[2000];
int ans[2000];
void init()
{
	memset(ans,0,sizeof(ans));
	int res=4;
	double base=0.25;
	lim[0]=0;
	for (int i=1;i<50;i++)
	{
		lim[i]=base+lim[i-1];
		printf("%d %.11lf %.11lf\n", i, lim[i], (pow(2,i)-1)/pow(2,i+1));

		//printf("%.10f %.10f\n",base,lim[i] );
		ans[i]=res;
		res+=4;
		base*=0.5;
	}
}
int main(int argc, char const *argv[])
{
	init();
	int t;
	scanf("%d",&t);
	while(t--)
	{
		double n;
		scanf("%lf",&n);
		if (n<eps)
		{
			printf("-1\n");
			continue;
		}
		if (fabs(n-0.5)<eps)
		{
			printf("1002\n");
			continue;
		}
		for (int i=1;i<100;i++)
		{
			//printf("%.10f\n",fabs(lim[i]-n) );
			if (fabs(lim[i]-n)<eps)
			{
				printf("-1\n");
				break;
			}
			else
				if (n-lim[i]<eps)
				{
					printf("%d\n",ans[i] );
					break;
				}
		}
	}
	return 0;
}