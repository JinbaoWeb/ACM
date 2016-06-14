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
//const LL  maxn = 1e6+7;
const LL  maxn = 200;
const LL  mod  = 1e9+7;

LL dp[maxn], arr[maxn];
LL gcd(LL a, LL b)
{
    return b == 0 ? a: gcd(b, a%b);
}
LL extend (LL a, LL b, LL &x, LL &y)
{
    if(b == 0){
        x = 1; y = 0; return a;
    }
    LL r = extend(b, a%b, y, x);
    y -= a/b*x;
    return r;
}
LL anti(LL b, LL x, LL y)
{
    LL r = extend(b, mod, x, y);
    return (x%mod+mod)%mod;
}
void init ()
{
    dp[0] = arr[0] = 1LL;
    for (LL i=1; i<maxn; i++)
    {
        dp[i] = (dp[i-1] / gcd(dp[i-1], i) * i) % mod;
        printf("%I64d %I64d\n", i, dp[i]);
    }
    for (LL i=1; i<maxn; i++)
    {
        LL x, y;
        arr[i] = anti(i, x, y);
    }
}
int main ()
{
    LL t, n;
    init ();
    scanf ("%lld", &t);
    while (t --)
    {
        scanf ("%lld", &n);
        printf ("%lld\n", dp[n+1] * arr[n+1] % mod);
    }
    return 0;
}
