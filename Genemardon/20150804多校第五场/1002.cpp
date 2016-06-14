#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#define LL __int64
using namespace std;
int main()
{
    LL n, m, z, l;
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%I64d%I64d%I64d%I64d", &n, &m, &z, &l);
        LL ans = 0^0, t = 0;
        for(int i = 1;i < n;i++)
        {
            t = (t*m+z)%l;
            ans ^= 2*t;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}