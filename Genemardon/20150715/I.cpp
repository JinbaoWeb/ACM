#include <stdio.h>
#include <string.h>
long long p[1010][1010];
long long P,N;
int main(int argc, char const *argv[])
{
	memset(p,0,sizeof(p));
	for (int i=0;i<=1000;i++) p[i][0]=i+1;
	for (int i=1;i<=1000;i++)
		for (int j=0;j<=1000;j++) p[j][i]=p[j][0]*(i+1)%10000; 
	// for (int i=0;i<4;i++)
	// {
	// 	for (int j=0;j<4;j++) printf("%d ",p[i][j] );
	// 	printf("\n");
	// }
			long long cnt=0;
	while (scanf("%lld%lld",&P,&N) && P && N )
	{
		cnt++;
		N++;
		if (P==1)
		{
			printf("Case %lld: 0000\n",cnt );
			continue;
		}
		long long x=(N-1)/(P*P),y=N-x*P*P,xx=(y-1)/P,yy=y-xx*P;
		//printf("%d %d %d %d\n", x,y,xx,yy);
		long long ans=(p[xx][yy-1]%10000*((x+1)%10000))%10000;
		printf("Case %lld: %04lld\n",cnt ,ans);
		//printf("%d%d%d%d\n",ans/1000,ans%1000/100,ans%100/10,ans%10 );
	}
	return 0;
}