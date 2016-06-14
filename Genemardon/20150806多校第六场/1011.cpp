#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int n;
int MOD=1000000007;
long long mult(int x)
{
	long long res=1;
	long long now=2;
	while (x)
	{
		if (x&1)
		{
			res=res*now%MOD;
		}
		x/=2;
		now=now*now%MOD;
	}
	return res;
}
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		long long ans=mult(n-1);
		printf("%d\n",ans-1 );
	}
	return 0;
}