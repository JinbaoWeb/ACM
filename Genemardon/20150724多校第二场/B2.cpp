#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int cmp(int a,int b,int c)
{
	int res;
	res=min(a,b);
	res=min(res,c);
	return res;
}
int main(int argc, char const *argv[])
{
	int n,m,x,y;
	while (scanf("%d%d%d%d",&n,&m,&x,&y) != EOF)
	{
		int a=x-1,b=n-x,c=y-1,d=m-y;
		printf("%d %d %d %d\n", a,b,c,d);
		int m1=
		if (c>m1)
		{
			m2=m1;
			m1=c;
		}		
		else if (c>m2) m2=c;
		if (d>m1)
		{
			m2=m1;
			m1=d;
		}
		else m2=d;
		printf("%d\n",m2 );
	}
	return 0;
}