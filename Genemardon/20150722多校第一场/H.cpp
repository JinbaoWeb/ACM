#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
double a, b, c, d, e;
struct node
{
	double x, y;
	node(){}
	node(double a, double b){
		x = a, y = b;
	}
}A, B, C, D;
double xd(double xc)
{
	return (2*b*b+2*d*d-a*a-4*e-c*c+2*xc*a)/(2.0*a);
}
double yc(double xc)
{
	return sqrt(b*b-(xc-a)*(xc-a));
}
double yd(double xdd)
{
	return d*d - xdd*xdd;
}
double find(double t1, double t2)
{

}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%lf%lf%lf%lf%lf", &a, &b, &c, &d, &e);
		A = node(0, 0); B = node(a, 0);
		c.x = find(a-b, a+b);
	}
	return 0;
};