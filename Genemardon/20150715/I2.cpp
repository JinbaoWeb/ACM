#include <stdio.h>
#include <string.h>
#include <math.h>
long long mp[1010][1010];
#define N 1000000005
int p;
int po(int a, int k)
{
	if(k == 0)
		return 1;
	if(k == 1)
		return a;
	int temp = po(a, k/2);
	temp *= temp;
	if(k & 1)
		temp *= a;
	return temp;
}
int solve(int n, int k)
{
	int temp = pow(p, k);
	int x = (n-1)/temp+1, y = (n-1)%temp+1;
	printf("%d %d %d %d\n", k, temp, x, y);
	if(k == 1 && x <= p)
		return mp[y][x];
	if(k == 1 && x > p)
	{
		int tx = (x-1)/p+1, ty = (x-1)%p+1;
		return mp[y][ty]*tx%10000;
	}
	if(x == 1)
		return solve(n, k/p);
	return solve(y, k/p)*x%10000;
}
int main()
{
	memset(mp,0,sizeof(mp));
	for (int i=1;i<=1000;i++) mp[i][1]=i;
	for (int i=1;i<=1000;i++)
		for (int j=1;j<=1000;j++) mp[j][i]=mp[j][1]*i%10000; 
	int n, o = 0;
	while(scanf("%d%d", &p, &n))
	{
		if(!p && !n)
			break;
		int k = ;
		n++;
		printf("Case %d: %04d\n", ++o, solve(n, k)%10000);
	}
}