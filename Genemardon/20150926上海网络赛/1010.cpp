#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int t,n,a,b,l;
int MIN;
int main(int argc, char const *argv[])
{
	scanf("%d",&t);
	for (int TT=1;TT<=t;TT++)
	{
		scanf("%d%d%d%d",&n,&a,&b,&l);
		MIN=0;
		int last=0,head,tail,cnt=0;
		for (int i=0;i<n;i++)
		{
			scanf("%d%d",&head,&tail);
			cnt=cnt+(head-last)*b;
			cnt=cnt-(tail-head)*a;
			MIN=min(MIN,cnt);
			last=tail;
		}
		printf("Case #%d: %d\n",TT,-MIN );
	}
	return 0;
}