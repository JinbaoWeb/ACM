#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define n 30
#define LL __int64
LL C[n][n];
LL gcd(LL x, LL y)
{
	return y == 0 ? x : gcd(y, x%y);
}
LL lcm(LL x, LL y)
{
	if(x == 0 || y == 0)
		return 0;
	LL g = gcd(x, y);
	return x/g*y;
}
int main()
{
	C[0][0] = 1;
	for(int i = 1;i < n;i++)
	{
		C[i][0] = C[i][i] = 1;
		for(int j = 1;j < i;j++)
			C[i][j] = C[i-1][j-1]+C[i-1][j];
	}
	for(int i = 1;i < n;i++)
	{
		LL ans = 1;
		for(int j = 0;j <= i/2;j++)
		{
			ans = lcm(ans, C[i][j]);
		//	printf("(((%d %d\n", C[i][j], ans);
		}
		printf("%I64d\n", ans%1000000007);
	}
	return 0;
}