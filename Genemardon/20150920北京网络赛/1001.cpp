#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
double d[105][105], l[105];
struct node
{
	double x, y;	
}p[105];
double dis(node a, node b)
{
	return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}
double cmp(double x, double y)
{
	return x < y;
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int m, n;
		scanf("%d%d", &m, &n);
		for(int i = 0;i < m;i++)
			scanf("%lf%lf", &p[i].x, &p[i].y);
		for(int i = 0;i < m;i++)
			for(int j = 0;j <= i;j++)
				d[i][j] = d[j][i] = dis(p[i], p[j]);
		int ans = 1000000000;
		/*for(int i = 0;i < m;i++)
			for(int j = 0;j < m;j++)
				printf("%.3f%c", d[i][j], " \n"[j==m-1]);*/
		for(int i = 0;i < m;i++)
		{
			for(int j = 0;j < m;j++)
				l[j] = d[i][j];
			//printf("%d\n", i);
			
			sort(l, l+m, cmp);
			l[m] = 1000000000;
			/*for(int j = 0;j < m;j++)
				printf("%.5lf%c", l[j], " \n"[j==m-1]);*/

			double r1 = l[n-1], r2 = l[n];
			int R1 = ceil(r1), R2 = floor(r2);
			if(R1-r1 < 1e-5)
				R1++;
			if(r2-R2 < 1e-5)
				R2--;
			//printf("r %lf %lf %d %d \n", r1, r2, R1, R2);
			if(R1 > R2)
				continue;
			ans = min(R1, ans);
			//printf("ans %d\n", ans);
		}
		if(ans > 100000000)
			ans = -1;
		printf("%d\n", ans);

	}
	return 0;
}