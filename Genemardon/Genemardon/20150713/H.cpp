#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
#define N 10005
int t[N], n, c[N];
double end;
int cmp(int x, int y)
{
	return x < y;
}
double solve(int f)
{
	if(f > c[n-1])
		return end;
	double ans = 0;
	for(int i = 0;i < n;i++)
	{
		if(f > c[i])
			ans += t[c[i]];
		else
			ans += 1.0+solve(f+c[i]);
	}
	return ans/n;
}
int main()
{
	//freopen("in", "r", stdin);
	int f;
	double a = (1.0+sqrt(5))/2;
	for(int i = 0;i < N;i++)
		t[i] = (int)(a*i*i);
	while(~scanf("%d%d", &n, &f))
	{
		end = 0;
		for(int i = 0;i < n;i++)
		{
			scanf("%d", &c[i]);
			end += t[c[i]];
		}
		end /= 1.0*n;
		//printf("--------%.3f\n", end);
		sort(c, c+n, cmp);
		double ans = solve(f);
		printf("%.3f\n", ans);
	}
	return 0;
}