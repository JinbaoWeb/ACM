#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <iostream>
#include <algorithm>
#define sf scanf
#define pf printf
#define fst first
#define scd second
#define pb push_back
#define mkp make_pair
#define cls(a) memset(a,0,sizeof a)
#define _cls(a) memset(a,-1,sizeof a)

using namespace std;

int g[20][20];

inline void Floyd(int n)
{
    int i, j, k, v;
    for (k = 0; k < n; ++k)
        for (i = 0; i < n; ++i)
            if (i != k)
                for (j = 0; j < n; ++j)
                    if (j != i && j != k)
                    {
        v = g[i][k] + g[k][j];
        if (g[i][j] > v) g[i][j] = v;
                    }
}

int dp[1 << 17][16];

inline int work(int n)
{

    int lmt = 1 << n, i, j, k;
    for (i = 0; i < lmt; ++i)
        std::fill(dp[i], dp[i] + 18, INT_MAX >> 2);
    dp[1][0] = 0;

    for (i = 0; i < lmt; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            for (k = 0; k < n; ++k)
            {
                if (j == k) continue;
                dp[i | (1<<k)][k] = min(dp[i | (1<<k)][k], dp[i][j] + g[j][k]);
            }
        }
    }
    return dp[lmt - 1][0];
}

int main()
{
    int n, m, i, u, v, w, ret, top;
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        for (i = 0; i < 20; ++i)
            std::fill(g[i], g[i] + 18, INT_MAX >> 2);
        for (i = 0; i < m; ++i)
        {
            scanf("%d%d%d", &u, &v, &w);
            --u; --v;
            if (g[u][v] > w) g[u][v] = g[v][u] = w;
        }
        Floyd(n);
        printf("%d\n", work(n));
    }
    return 0;
}