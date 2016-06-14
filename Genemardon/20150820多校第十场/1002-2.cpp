#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
#define INF 0x3fffffff
typedef long long LL;
const int  maxn = 1e6+7;
const int  mod  = 1e9+7;

LL dp[maxn], arr[maxn];
LL gcd(LL a, LL b)
{
    return b == 0 ? a: gcd(b, a%b);
}


LL mult(LL a,LL b)
{
    LL res=0;
    while (b)
    {
        if (b & 1)
            res = (res + a) % mod;
        a = a<<1%mod;
        b >> 1;
    }
    return res;
}
LL Pow(LL x, LL n)
{
    LL res = 1;
    while (n)
    {
        if (n & 1)
            res = res * x % mod;
        x = x * x % mod;
        n = n >>1;
    }
    return res;
}
void init ()
{
    dp[0] = arr[0] = 1LL;
    for (int i=1; i<maxn; i++)
        dp[i] = (dp[i-1] / gcd(dp[i-1], i) * i) % mod ;
    for (int i=1; i<maxn; i++)
        arr[i] = Pow(i, mod-2);
}
int main ()
{
    LL t, n;
    init ();
    printf("1\n");
    scanf ("%lld", &t);
    while (t --)
    {
        scanf ("%lld", &n);
        printf ("%lld\n", dp[n+1] * arr[n+1] % mod);
    }
    return 0;
}