#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define LL __int64
LL mo[15], bo[15];

LL Pow(LL a, LL n, LL p)
{
    LL x = a;
    LL res = 1;
    while (n)
    {
        if (n & 1)
        {
            res = (res * x) % p;
        }
        n >>= 1;
        x = (x * x) % p;
    }
    return res;
}
LL Cm(LL n, LL m, LL p)
{
    LL a = 1, b = 1;
    if (m > n)return 0;
    while (m)
    {
        a = (a * n) % p;
        b = (b * m) % p;
        m--;
        n--;
    }
    return (a * Pow(b, p - 2, p)) % p;
}
LL Lucas(LL n, LL m, LL p)
{
    if (m == 0)
        return 1;
    return (Cm(n % p, m % p, p) * Lucas(n / p, m / p, p)) % p;
}

LL X;
LL extend_Euclid(LL a, LL b, LL &x, LL &y){
	if(b==0){
	x = 1; y = 0;
	return a;
	}
	LL r = extend_Euclid(b, a%b, y, x);
	y -= a/b*x;
	return r;
}
LL equation(LL a, LL b, LL c)
{
	LL x, y;
	LL g = extend_Euclid(a, b, x, y);
	if(c % g)
		return 0;    //表示无解
	LL ran = b/g;
	X = (c/g*x%ran+ran)%ran;    //只需存最小整数解
	return g;
}
LL eq_set(int n)
{
	LL b1, m1, b2, m2, m, r = 1;
	m1 = mo[0], b1 = bo[0];
	for(int i = 1;i < n;i++)
	{
		m2 = mo[i], b2 = bo[i];
		r = equation(m1, m2, b2-b1);
		if(!r)
			return -1;  //返回无解
		b1 += m1*X;
		m1 *= m2/r;
		b1 %= m1;
	}
	return (b1%m1+m1)%m1; //返回正整数解，0被化为最小公倍数
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		LL n, m;
		int k;
		scanf("%I64d%I64d%d", &n, &m, &k);
		for(int i = 0;i < k;i++)
		{
			scanf("%I64d", &mo[i]);
			bo[i] = Lucas(n, m, mo[i]);
			//printf("%I64d %I64d\n", mo[i], bo[i]);
		}
		LL ans = eq_set(k);
		printf("%I64d\n", ans);
		//printf("\n");
	}
	return 0;
}