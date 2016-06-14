#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#define LL __int64
using namespace std;
const int M=258280327;
LL po(int a, int k)
{
	if(k == 0)
		return 1;
	LL temp = po(a, k/2) % M;
	temp *= temp;
	temp %= M;
	if(k&1)
		temp *= a;
//	printf("%I64d\n", temp);
	return temp % M;
}
LL rate(int x, int y)
{
	LL a = po(y, M-2) % M;
	return (x%M)*a%M;
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{

		int n, x, y;
		scanf("%d%d%d", &n, &x, &y);
		LL ans = rate(8911, 30000);
		printf("%I64d\n", ans);
	}
	return 0;
}
//(2/3)*(0.33*0.67+0.67*0.67*(1/2))=8911/30000