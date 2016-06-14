#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<cstdio>
#include<cstring>
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const LL LINF = (1LL <<63);
const int INF = 1 << 30;

const int NS = 55;
const int MS = 19;
const LL MOD = 1000000007;

int n;
int a[2][NS];
int s[2][NS];
int b[NS];

int main()
{
    while(cin>>n)
    {
        memset(s, 0, sizeof(s));
        for(int r = 0; r < 2; r++)
        for(int i = 2; i <= n; i++)
        {
            cin>>a[r][i];
            s[r][i] = s[r][i - 1] + a[r][i];
        }

        for(int i = 1; i <= n; i ++)
        {
            cin>>b[i];
        }

        int ans = INF;
        for(int i = 1; i <= n; i++)
        {
            for(int j = i + 1; j <= n; j++)
            {
                int t1 = (s[0][i] + b[i] + s[1][n] - s[1][i]);
                int t2 = (s[0][j] + b[j] + s[1][n] - s[1][j]);
                ans = min(ans, t1 + t2);

               // printf("i = %d j = %d t1 = %d t2 = %d\n", i,j,t1,t2);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}