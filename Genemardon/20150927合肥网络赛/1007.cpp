#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
int a[100][100];

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

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int b1, q, a1, d, n, m;
		scanf("%d%d%d%d%d%d", &b1, &q, &a1, &d, &n, &m);
		for(int j = 0;j < 10;j++)
		{
			if(j == 0)
				a[0][j] = 0;
			else if(j == 1)
				a[0][j] = b1;
			else
				a[0][j] = a[0][j-1]*q;
			printf("%5d%c", a[0][j], " \n"[j==9]);
		}
		for(int i = 1;i < 10;i++)
		{
			if(i == 1)
				a[i][0] = a1;
			else
				a[i][0] = a[i-1][0]+d;
			printf("%5d ", a[i][0]);
			for(int j = 1;j < 10;j++)
			{
				a[i][j] = a[i][j-1]+a[i-1][j];
				printf("%5d%c", a[i][j], " \n"[j==9]);
			}
		}
	}
	return 0;
}