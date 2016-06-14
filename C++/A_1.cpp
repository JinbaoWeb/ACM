#include <stdio.h>
#define M 9999999
#define N 60000
int main()
{
	long long i=0,aa[N];
	long long sum=0;
	for (i=1;i<=M;i++)
	{
		sum+=i;
		aa[i]=sum;
	}
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		if (n<0)
			n=-n;
		int i;
		for (i=1;i<M;i++)
			if (aa[i]<=n&&aa[i+1]>n)
				break;
		int a=n-aa[i],b=aa[i+1]-n;
		if (a>b)
		{
			i++;
			i+=b*2;
		}
		else
			i+=a*2;
		printf("%d\n",i);
	}
	return 0;
}
