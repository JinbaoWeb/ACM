#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
int main()
{
	int n, m, x, y;
	while(~scanf("%d%d%d%d", &n, &m, &x, &y))
	{
		if(n < m)
		{
			swap(n, m);
			swap(x, y);
		}
		int midx = (n+1)/2, midy = (m+1)/2;
		if(x > midx) x = n+1-x;
		if(y > midy) y = m+1-y;
		//printf("%d %d %d %d\n", n, m, x, y);
		if((n&1) && (m&1) && x == midx && y == midy)
		{
			printf("%d\n",  x == y ? x-1:y);
			continue;
		}
		//printf("%d %d %d\n", m-y, x, midy);
		int ans = min(m-y, x);
		ans = max(ans, midy);
		printf("%d\n", ans);
	}
	return 0;
}