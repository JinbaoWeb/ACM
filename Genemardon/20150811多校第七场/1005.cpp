#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
int digitSum(int x)
{
	int r = 0;
	while(x)
	{
		r += x%10;
		x /= 10;
	}
	return r;
}
int how(int x)
{
	int r = 0;
	while(x)
	{
		x /= 10;
		r++;
	}
	return r;
}
int main()
{
	int n, t, o = 0;
	while(~scanf("%d%d", &n, &t))
	{
		if(n == -1 && t == -1)
			break;
		int re = digitSum(n);
		int ans = n % 11;
			//printf("%d %d\n", re, ans);
		while(t--)
		{
			int s = digitSum(re);
			int d = how(re);
			if(d & 1LL)
				ans *= -1;
			ans += re%11;
			re += s;
			//printf("%d %d ddd--%d\n", re, ans, d);
		}
		printf("Case #%d: ", ++o);
		if(ans % 11)
			printf("No\n");
		else
			printf("Yes\n");
		//printf("%d\n", ans);
	}
	return 0;
}