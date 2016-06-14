# HDU 5476 Explore Track of Point 2015上海网络赛 几何题

标签： 解题报告 几何

---

题目见[HDU 5476](http://acm.hdu.edu.cn/showproblem.php?pid=5476)

给出等腰三角形ABC，AB=AC，M为BC中点。P点为三角形内使min{∠MPB+∠APC,∠MPC+∠APB} 最大的点。求P点轨迹。
则容易找到中线AM上的P点都满足使得∠MPB=∠MPC，∠APC=∠APB，则∠MPB+∠APC=∠MPC+∠APB=180°
故轨迹包含中线AM。
并且所有满足的P点都应满足：∠MPB+∠APC=∠MPC+∠APB=180°

任取中线上的一点P，可找到与之对应的一点Q，使得∠MQB=∠MPB，且∠AQC=∠APC，则∠MQB+∠AQC=180°成立，故**Q点形成另一条子轨迹。**
Q点的作法：ΔBPM与ΔAPC的外接圆的交点。另一个交点即为P点。（由此可证明没有其他多余的轨迹）圆弧BM、AC分别对应圆上的∠MQB=∠MPB，且∠AQC=∠APC。

**P与Q重合时，两者在ΔABC的内心上。**
证明：P与Q重合，即ΔBPM与ΔAPC的外接圆相切。作切线PD，则：
∠DPM=∠APE=∠ACP（对顶角相等，弦切角相等）……[1]
又∠AMB=∠BPD=90°
则∠CPM=∠BPM=∠PDB（左右对称，余角相等）
则∠PCM=∠DPM（余角相等，对顶角相等）……[2]
由[1][2]得到∠ACP=∠PCM即PC是角平分线，又AP也为角平分线，故此时的P点为ΔABC的内心I。

**猜测Q的轨迹是个圆弧**
这一点是猜的，还没证明。但可以尝试证明∠BQC是个常量入手，得到Q的轨迹是个圆弧。
猜的依据是：轨迹关于AM左右对称，且经过ΔABC的内心时为最高点。

**圆弧为ΔBCI的外接圆的一部分**
前面已经证明了Q的轨迹过ΔABC的内心I。由对称得圆心在AM的延长线上，现在直接求该圆心的位置即可。

计算过程：
由三点坐标得到AB的距离为b，BC的距离为2a，AM即高为h,则内接圆的半径r=2ah/C=2ah/(2a+2b)=ah/(a+b)
ΔBCI的外接圆半径为R，且设M到圆心距离为x,$a^2+x^2=(r+x)^2$，则$x={a^2-r^2\over 2r}$，R=r+x
圆弧BIC张角为2β=2arcsin(a/R)
圆弧BIC长为2Rβ

附code:
```cpp
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
```
