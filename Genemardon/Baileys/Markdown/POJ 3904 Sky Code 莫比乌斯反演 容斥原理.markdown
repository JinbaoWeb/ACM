#POJ 3904 Sky Code 莫比乌斯反演 容斥原理
标签：数学 解题报告
***
##原题见[POJ 3904](http://poj.org/problem?id=3904)
给n个数，求其中四个数的gcd是1的情况有多少种。

从反面考虑，算出gcd不是1的情况，总数取反即是结果。这是容斥原理的思想。当时在做[POJ 1091](http://poj.org/problem?id=1091)的时候即是这样的想法。画一个vene图，每个集合表示最大公约数为k的情况数。
当k含有素数因子的平方项，如4，其实已经被2的情况数覆盖，不必再进行任何处理。只需考虑k是素数的一次方的乘积的情况。当素数个数为奇数个，如2，3，5，30，情况数是向上累加的；而当素数个数是6，10，15时，情况数应该被减去，因为被重复算进过。
其实和莫比乌斯反演里的系数的产生是一样的原理。

有了[莫比乌斯反演](http://blog.csdn.net/danliwoo/article/details/48918947)的知识背景以后，可以这样想：

设$f(x)$=四个数的gcd是x的情况数
$F(x)=\sum_{x\mid d}f(d)$，即四个数的gcd是x的倍数的情况数
利用上一篇博客提到的[莫比乌斯反演的第二种形式](http://blog.csdn.net/danliwoo/article/details/48918947#t3)

现在要求$f(1)=\sum_{x\mid d}\mu({d\over x})F( d)|_{x=1}=\sum_d\mu(d)F(d)$其中d是1~10000的所有数。

##附code
```cpp
/*--------------------------------------------
 * File Name: POJ 3904
 * Author: Danliwoo
 * Mail: Danliwoo@outlook.com
 * Created Time: 2015-10-06 12:36:28
--------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 10001
#define LL long long
int mobi[N]={0,1}, num[N], prim[N], cnt = 0, a[N];
void set()
{
	for(int i = 0;i < N;i++) num[i] = 1;
	for(int i = 2;i < N;i++)
	{
		if(num[i])
		{
			prim[cnt++] = i;
			mobi[i] = -1;
		}
		for(int j = 0;j < cnt && prim[j]*i < N;j++)
		{
			num[prim[j]*i] = 0;
			if(i % prim[j] == 0)
			{
				mobi[prim[j]*i] = 0;
				break;
			}
			mobi[prim[j]*i] = -mobi[i];
		}
	}
}
void sep(int n)
{
	int s = sqrt(n);
	for(int i = 1;i <= s;i++) if(n % i == 0)
	{
		a[i]++;
		a[n/i]++;
	}
	if(s*s == n)
		a[s]--;
}
LL get(LL i)
{
	return i*(i-1)*(i-2)*(i-3)/24;
}
int main()
{
	set();
	int n, tp;
	while(~scanf("%d", &n))
	{
		memset(a, 0, sizeof(a));
		for(int i = 0;i < n;i++)
		{
			scanf("%d", &tp);
			sep(tp);
		}
		LL ans = 0;
		for(LL i = 1;i < N;i++)
		{
			if(mobi[i] == 0 || a[i] < 4) continue;
			ans += get(a[i])*mobi[i];
		}
		printf("%lld\n", ans);
	}
	return 0;
}
```



