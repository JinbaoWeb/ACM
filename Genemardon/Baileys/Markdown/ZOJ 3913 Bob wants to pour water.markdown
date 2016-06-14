#ZOJ 3913 Bob wants to pour water
标签： 解题报告
***
##原题见[ZOJ 3913](http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemCode=3913)
在一个无限高的长方体容器里面倒一定的水，问水面有多高。其中，容器里会有一些小长方体和球体。
给定了长方体的长、宽，障碍物体的个数、位置、大小。所以很快想到，能不能求出给定高度能够倒入水的体积，二分高度逼近答案。

已知旋转体的体积公式：
$$V=\pi \int f(x)^2dx$$对于绕$x轴的连续函数f(x)$有效。因此写出圆方程$$(x-r)^2+y^2=r^2$$$y=f(x)$，代入求体积的公式，得到$$V(x_0)=\pi \int_0^{x_0} f(x)^2dx=\pi \int (r^2-(x-r)^2)dx=\pi(rx^2-{1\over 3}x^3)$$则可以知道被浸没了$x_0$的球体的体积。

##代码解释

- cuboid 长方体
a(长)b（宽）h（高）z（中心位置）l（下底面位置）u（上平面位置）v（体积）

- sphere 球体
r（半径）z（中心位置）l（下底面位置）u（上平面位置）v（体积）

- set()求出相应参数
- find(x)高为x时灌入的水体积
直接枚举累加，略暴力。可以先按照l的大小排个序，不在水面下的就break。然而不排序也不会超时。
- get(w,a,b)二分高度使得对应的体积接近于w

注意啊，二分不要用递归！为此我TLE了10+次，从此AC是路人。

##附code
```cpp
/*--------------------------------------------
 * File Name: ZOJ 3913
 * Author: Danliwoo
 * Mail: Danliwoo@outlook.com
 * Created Time: 2015-10-11 23:36:36
--------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;
#define N 100010
const double Pi = acos(-1.0);
#define eps 1e-5
double A, B;
int n, m;
struct cuboid{
	double a, b, h, z, l, u, v;
	void Set(){
		l = z-h/2;
		u = z+h/2;
		v = a*b*h;
	}
	double rest(double x){
		x -= l;
		return a*b*x;
	}
}cu[N];
struct sphere{
	double r, z, l, u, v;
	void Set(){
		l = z-r;
		u = z+r;
		v = 4.0*Pi*r*r*r/3;
	}
	double rest(double x){
		x -= l;
		return Pi*r*x*x-Pi*x*x*x/3.0;
	}
}sp[N];
bool cmp1(cuboid x, cuboid y){
	return x.l < y.l;
}
bool cmp2(sphere x, sphere y){
	return x.l < y.l;
}
double find(double x)
{
	double re = 0;
	for(int i = 0;i < n;i++)
	{
		if(cu[i].l > x) break;
		if(cu[i].u < x) re += cu[i].v;
		else re += cu[i].rest(x);
	}
	for(int i = 0;i < m;i++)
	{
		if(sp[i].l > x) break;
		if(sp[i].u < x) re += sp[i].v;
		else re += sp[i].rest(x);
	}
	return A*B*x - re;
}
double get(double w, double L, double R)
{
	while(fabs(L - R) > eps) {
		double mid = (L + R) / 2;
		double vc = find(mid);
		if(vc < w) {
			L = mid;
		} else {
			R = mid;
		}
	}
	return R;
}
int main()
{
	int T;
	scanf("%d", &T);
	double water;
	while(T--)
	{
		double vall = 0;
		scanf("%lf%lf%lf%d%d", &A, &B, &water, &n, &m);
		for(int i = 0;i < n;i++)
		{
			scanf("%lf%lf%lf%lf", &cu[i].z, &cu[i].a, &cu[i].b, &cu[i].h);
			cu[i].Set();
			vall += cu[i].v;
		}
		for(int i = 0;i < m;i++)
		{
			scanf("%lf%lf", &sp[i].z, &sp[i].r);
			sp[i].Set();
			vall += sp[i].v;
		}
		sort(cu, cu+n, cmp1);
		sort(sp, sp+m, cmp2);
		double ans = get(water,  water/(A*B), (water+vall)/(A*B));
		printf("%.7f\n", ans);
	}
	return 0;
}

```
