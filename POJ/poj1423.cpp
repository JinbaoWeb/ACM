#include <stdio.h>
#include <cmath>
#define pi 3.1415926535897932384626433832795
#define e 2.7182818284590452354
int main()
{
	int t;
	int n,s;
	scanf("%d",&t);
	while (scanf("%d",&n)!=EOF)
	{
		if (n==1)
			s=1;
		else
			s=log10(2*pi*n)/2+n*log10(n/e)+1;	
		printf("%d\n",s);
	}
	return 0;
}
