#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#define LL long long
using namespace std;
LL c,k1,k2,b1;
LL multimod(LL a,LL b,LL MOD)
{
	LL res=1;
	while(b)
	{
		if (b & 1)
			res=res*a%MOD;
		a=a*a%MOD;
		b/=2;
	}
	return res;
}
int main(int argc, char const *argv[])
{
	int ccc=0;
	while(scanf("%I64d%I64d%I64d%I64d",&c,&k1,&b1,&k2) != EOF)
	{
		printf("Case #%d:\n",++ccc );
		// memset(len,0,sizeof(len));
		// for (int i=1;i<c;i++){tab1[i].clear();tab2[i].clear();}
		int cnt=0;
		for (LL i=1;i<c;i++)
		{
			LL A=multimod(i,k1+b1,c);
			LL a=A;
			LL B=c-A;
			LL b=B;
			LL d1=multimod(i,k1,c);
			LL d2=multimod(B,k2,c);
			//printf("%I64d %I64d %I64d %I64d %I64d %I64d\n",i,b,A,B,d1,d2 );
			if (A==0 || B==0 || B>=c) continue;
			if (multimod(i,k1,c) != multimod(B,k2,c)) continue;
			else
			{
				cnt++;
				printf("%I64d %I64d\n",i,b );
			}
			int flag=1;
			 // printf("-----------\n");
			 // printf("%I64d %I64d\n",A,B );
			//while(1)
			// for (int j=1;j<=10;j++)
			// {
			// 	A=A*d1%c;
			// 	B=B*d2%c;
			// 	//printf("%I64d %I64d\n",A,B );
			// 	if ((A+B)%c!=0)
			// 	{
			// 		flag=0;
			// 		break;
			// 	}
			// 	if (A==a && B==b)
			// 		break;
			// }
			// if (flag)
			// {
			// 	printf("%I64d %I64d\n",i,b );
			// 	cnt++;
			// }
		}
		//printf("%d\n",cnt );
		if (cnt==0)
			printf("-1\n");
	}
	return 0;
}