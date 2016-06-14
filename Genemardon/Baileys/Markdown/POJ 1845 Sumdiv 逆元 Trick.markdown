#POJ 1845 Sumdiv 逆元 费马小定理 Trick
标签：数学 逆元 费马小定理
***
##原题见[POJ 1845](http://poj.org/problem?id=1845)
给A，B，求$A^B$的所有因子的和模9901。

首先把A分解成素数的幂的形式$$A^B=p_1^{s_1B}p_2^{s_2B}...p_k^{s_kB}$$再求和$$sum={p_1^{s_1B}-1\over p_1-1}{p_2^{s_2B}-1\over p_2-1}...{p_k^{s_kB}-1\over p_k-1}$$

因为被模除的9901是个质数，所以对于上面的$p^n-1$部分，可以利用[费马小定理](http://blog.csdn.net/danliwoo/article/details/48827813#t20)，得到$$p^n-1\equiv p^{n\% (9901-1)}-1\pmod {9901}$$

对于下面的部分，可以直接[求逆元](http://blog.csdn.net/danliwoo/article/details/48827813#t11)，将除的部分转化为成分。

但是Trick来了！当p-1是9901的倍数时，不存在逆元！
此时再审视一番原式，其实这是等比数列化过来的式子，原式是这样的$${p^n-1\over p-1}=p^0+p^1+p^2+...+p^n$$代入$p=9901x+1$，则原式即为$n+1$特判一下这种情况即可！

##附code
```cpp
/*--------------------------------------------
 * File Name: POJ 2992
 * Author: Danliwoo
 * Mail: Danliwoo@outlook.com
 * Created Time: 2015-10-03 09:53:42
--------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 7100
int num[N], prim[N], fq[N], cnt = 0;

int extend_Euclid(int a, int b, int &x, int &y){
    if(b==0){
    x = 1; y = 0;
    return a;
    }
    int r = extend_Euclid(b, a%b, y, x);
    y -= a/b*x;
    return r;
}
int anti(int a, int m)
{
	int x, y;
	extend_Euclid(a, m, x, y);
	return (x%m+m)%m;
}
void set()
{
	for(int i = 0;i < 7100;i++) num[i] = 1;
	for(int i = 2;i < 7100;i++) if(num[i])
	{
		fq[i-1] = anti(i-1, 9901);
		prim[cnt++] = i;
		for(int j = i*i;j < 7100;j += i)
			num[j] = 0;
	}
}
int po(int a, int k, int m)
{
	if(k == 0) return 1;
	if(k == 1) return a;
	int t = po(a, k/2, m);
	t = t*t%m;
	if(k & 1LL)
		t *= a;
	return t%m;
}
int main()
{
	set();
	int a, b, m = 9901;
	while(~scanf("%d%d", &a, &b))
	{
		if(a == 0)
		{
			printf("0\n");
			continue;
		}
		int ans = 1;
		int t = a;
		for(int i = 0;i < cnt && prim[i]*prim[i] <= a;i++) if(t%prim[i] == 0)
		{
			int s = 0;
			while(t % prim[i] == 0)
			{
				t /= prim[i];
				s++;
			}
			ans = ans*fq[prim[i]-1]%m*(po(prim[i], b%(m-1)*s%(m-1)+1, m)-1)%m;
		}
		if(t != 1)
		{
			if(t % m == 1)
				ans = ans*(b%m+1)%m;
			else
				ans = ans*anti(t-1, m)%m*(po(t%m, b%(m-1)+1, m)-1)%m;
		}
		printf("%d\n", (ans%m+m)%m);
	}
	return 0;
}
```