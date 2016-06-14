#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
struct node
{
	double x, y;
}A, B, C, M;
double dis(node a, node b)
{
	return sqrt(pow(a.x-b.x, 2)+pow(a.y-b.y, 2));
}
int main()
{
	int T, o = 0;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%lf%lf%lf%lf%lf%lf", &A.x, &A.y, &B.x, &B.y, &C.x, &C.y);
		M.x = (B.x+C.x)/2, M.y = (B.y+C.y)/2;
		double a = dis(B, C)/2, b = dis(A, B), h = dis(A,M);
		double r = a*h/(a+b);
		double R = (a*a-r*r)/r/2+r;
		double ans = 2*R*asin(a/R);
		//printf("%f %f %f %f %f %f\n", a, b, h, r, R, ans);
		ans += h;
		printf("Case #%d: %.4f\n", ++o, ans);
	}
	return 0;
}