#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cstdlib>
using namespace std;
int gcd(int a, int b)
{
	if(a == 0)
		return b;
	if(b == 0)
		return a;
	return gcd(b, a%b);
}
void pr(int x)
{
	x %= 43200;
	//printf("(x-%d)", x);
	if(x > 21600)
		x = 43200 - x;
	if(x % 120 == 0)
	{
		x /= 120;
		printf("%d", x);
		return;
	}
	int g = gcd(x, 120);
	printf("%d/%d", x/g, 120/g);
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int x, y, z;
		scanf("%d:%d:%d", &x, &y, &z);
		//printf("%d %d %d\n", x, y, z);
		int tim = 3600*x+60*y+z;
		int a = 720*tim, b = 12*tim, c = tim;
		//printf("%d %d %d %d\n", tim, a, b, c);
		int as = abs(b-c), bs = abs(a-c), cs = abs(b-a);
		//printf("===%d %d %d\n", as, bs, cs);
		pr(as);printf(" ");
		pr(bs);printf(" ");
		pr(cs);printf(" \n");
	}
	return 0;
}