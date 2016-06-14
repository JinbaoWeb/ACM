#POJ 3696 The Luckiest number 欧拉函数 或 BSGS
标签：数学
***
##原题见[POJ 3696](http://poj.org/problem?id=3696)
给一个数L，问至少几个8（如88，8888，88888）可以整数L。若不能，就输出-1.

首先把连续的x个8表示成$8+8·10+8·10^2+...+8·10^{x-1}={8(10^x-1)\over 10-1}$
若能整除L，则存在y，使得${8(10^x-1)\over 9}=Ly$，即$8(10^x-1)=9Ly$
先明白一个性质，若正整数$ab=cd$成立，则两边同除gcd(a,c)后，$a'b=c'd，gcd(a',c')=1$，则$c'与a'$没什么关系了，$c'只能整除b$才能使等式成立。
现在回到原先这个式子，两边同除gcd(8,9L)，即gcd(8,L)，则${9L\over gcd(8,L)}\mid 10^x-1$，即$10^x\equiv 1\pmod {{9L\over gcd(8,L)}}$

记$m={9L\over gcd(8,L)}$，现在要解决的是一个高次同余方程$$10^x\equiv 1\pmod m$$已知m，求最小的x.

##BSGS
很快想起了BSGS有木有！[上篇博客](http://blog.csdn.net/danliwoo/article/details/48827813#t15)已经讲过这种算法。
```cpp
/*--------------------------------------------
 * File Name: POJ 3696
 * Author: Danliwoo
 * Mail: Danliwoo@outlook.com
 * Created Time: 2015-10-02 22:16:59
--------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 44725
#define LL long long
#define MOD 150000   //是sqrt(1999999999*9)要求那么大的
LL gcd(LL a, LL b)
{
	return b == 0?a:gcd(b, a%b);
}
LL hs[MOD],head[MOD],next[MOD],id[MOD],top;
void insert(LL x, LL y)
{
    LL k = x%MOD;
    hs[top] = x, id[top] = y, next[top] = head[k], head[k] = top++;
}
LL find(LL x)
{
    LL k = x%MOD;
    for(LL i = head[k]; i != -1; i = next[i])
        if(hs[i] == x)
            return id[i];
    return -1;
}
LL mult(LL a, LL b, LL c)
{
    a %= c; b %= c;
    LL ret = 0, tmp = a;
    while(b)
    {
        if(b & 1LL)
        {
            ret += tmp;
            if(ret > c) ret -= c;
        }
        tmp <<= 1;
        if(tmp > c) tmp -= c;
        b >>= 1;
    }
    return ret%c;
}
LL BSGS(LL a,LL b,LL c)
{
    memset(head, -1, sizeof(head));
    top = 1;
    LL m = sqrt(c*1.0), j;
    long long x = 1, p = 1;
    for(LL i = 0; i < m; ++i, p = p*a%c)
        insert(p*b%c, i);//存的是(a^j*b, j)
    for(long long i = m; ;i += m)
    {
        if( (j = find(x = mult(x,p,c))) != -1 )//注意x要用mult()函数否则超LL
            return i-j;  //a^(ms-j)=b(mod c)
        if(i > c)
            break;
    }
    return 0;
}
int main()
{
	LL o = 0;
	LL n;
	while(scanf("%lld", &n), n)
	{
		printf("Case %d: ", ++o);
		LL m = n/gcd(n, 8)*9;
		if(gcd(m,10) != 1)
		{
			printf("0\n");
			continue;
		}
		printf("%lld\n", BSGS(10,1,m));
	}
	return 0;
}
```

##Euler
还可以试一试欧拉定理。
> 当(a,p)=1时，$a^{\phi(p)}=1$

所以$10^x\equiv 1\pmod m$这个式子，若(10,m)!=1时，即无解。若(10,m)=1，则必有一个解$\phi(m)$.然而，这次要找的是最小的x，记为ans，这个解和ans有什么关系呢？显然，ans是$\phi(m)$的一个因数。所以可以从$\phi(m)$出发，除去其中多余的素因子即可得到ans.

具体做法是，选取在$\phi(m)$以内的素因子，试除成功且商x'满足$10^{x'}\equiv 1\pmod m$则可以继续逐步进行操作。详见solve()函数。

需要友情提示的是在输入的数很大时，对应的m也会很大。在快速幂阶段即使模除了也会爆long long，此时应该注意再用一个mult()函数，把除法化为加法模除。
```cpp
/*--------------------------------------------
 * File Name: POJ 3696
 * Author: Danliwoo
 * Mail: Danliwoo@outlook.com
 * Created Time: 2015-10-02 14:26:08
--------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 44725
#define LL long long
LL num[N], prim[N];
int cnt = 0;
void get_prim()
{
	for(int i = 0;i < N;i++) num[i] = i;
	for(int i = 2;i < N;i++) if(num[i])
	{
		for(int j = i*i;j < N;j += i)
			num[j] = 0;
		prim[cnt++] = i;
	}
}
LL phi(LL n)
{
	LL ans = n;
	for(int i = 0;prim[i]*prim[i]<=n;i++) if(n%prim[i] == 0)
	{
		ans -= ans/prim[i];
		while(n%prim[i] == 0) n /= prim[i];
	}
	if(n != 1)
		ans -= ans/n;
	return ans;
}
LL gcd(LL a, LL b)
{
	return b == 0?a:gcd(b, a%b);
}
LL mult(LL a, LL b, LL c)
{
	a %= c; b %= c;
	LL ret = 0, tmp = a;
	while(b)
	{
		if(b & 1LL)
		{
			ret += tmp;
			if(ret > c) ret -= c;
		}
		tmp <<= 1;
		if(tmp > c) tmp -= c;
		b >>= 1;
	}
	return ret%c;
}
LL po(LL a, LL k, LL m)
{
	if(k == 0) return 1;
	if(k == 1) return a%m;
	LL t = po(a, k/2, m);
	t = mult(t, t, m);
	if(k & 1LL) t *= a;
	return t%m;
}
LL solve(LL x, LL p, LL m, LL f)
{
	LL d = po(10, x, m);
	if(d == 1)
	{
		if(x%p == 0)
			return solve(x/p, p, m, f+1);
		else
			return x;
	}
	if(f == 0) return x;
	return x*p;
}
int main()
{
	get_prim();
	int o = 0;
	LL n;
	while(scanf("%lld", &n), n)
	{
		printf("Case %d: ", ++o);
		LL m = n/gcd(n, 8)*9;
		if(gcd(m,10) != 1)
		{
			printf("0\n");
			continue;
		}
		if(po(10, 1, m) == 1)
		{
			printf("1\n");
			continue;
		}
		LL x = phi(m);
		LL ans = x, t = x;
		for(int i = 0; prim[i]*prim[i] <= x && i < cnt;i++) if(ans%prim[i] == 0)
		{
			while(t % prim[i] == 0) t /= prim[i];
			ans = solve(ans, prim[i], m, 0);
		}
		if(t != 1)
			ans = solve(ans, t, m, 0);
		ans = ans == x ? 0 : ans;
		printf("%lld\n", ans);
	}
	return 0;
}
```