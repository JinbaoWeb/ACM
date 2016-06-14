#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
long long d;
int s1,s2;
long long base[50];
int ex[50];
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	base[0]=1;
	for (int i=1;i<=40;i++) base[i]=base[i-1]*2;
	for (int TT=1;TT<=t;TT++)
	{
		memset(ex,0,sizeof(ex));
		scanf("%I64d%d%d",&d,&s1,&s2);
		long long x=d;
		int l=0,cnt=0;
		while(x)
		{
			if (x%2==1)
			{
				cnt++;
				ex[l]=1;
			}
			l++;
			x/=2;
		}
		//printf("%d %d\n",l,cnt );
		if (cnt<s2 && d%2==0)
		{
			printf("Case #%d: %I64d\n",TT,d+1 );
			continue;
		}
		int pos,cc=0;
		x=d;
		//for (int i=0;i<l;i++) printf("%d ",ex[i] );printf("\n");
		for (int i=0;i<=l-1;i++)
		{
			x=x-ex[i]*base[i];
			if (ex[i] && ex[i+1]==0)
			{
				pos=i;break;
			}
			cc+=ex[i];
		}
		x+=base[pos+1];
		//printf("%I64d %d\n",x,cc );
		for (int i=0;i<max(0,s1-(cnt-cc));i++)
			x+=base[i];
		printf("Case #%d: %I64d\n", TT,x);
	}
	return 0;
}