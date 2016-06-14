#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	__int64 x,k,i;
	int cases=1;
	while(scanf("%I64d%I64d",&x,&k))
	{
		if(x==0&&k==0)
			break;
		for(i=1;i<=k;i++)
		{
		    if(x%i!=0)
			    x=(x/i+1)*i;
		}
		printf("Case #%d: %I64d\n",cases++,x);
	}
	return 0;
}

