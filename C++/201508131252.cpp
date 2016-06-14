#include<map>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
#include<bitset>
#include<climits>
#include<list>
#include<iomanip>
#include<stack>
#include<set>
#define clr(a,b) memset(a,b,sizeof(a))
#define M 100010
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define root 1,n,1
#define ll long long

using namespace std;

const int N = 1e5 + 5;
const ll mod = 258280327;
int p[N];

ll dp[N][10][10][2][2];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,A,B;
        scanf("%d%d%d",&n,&A,&B);
        for(int i = 1; i <= n; i++)
            scanf("%d",p+i);
        clr(dp,0);
        for(int i = 1; i <= 9; i++)
            dp[1][i][p[1]][0][1] = 1, dp[1][p[1]][i][1][0] = 1;


//        for(int i =1; i <= n; i++)
//        {
//            int num = p[i];
//            for(int j =1; j <= 9; j++)
//            {
//                dp[num][j][1][0] += 1; dp[num][j][1][0] %= mod;
//                dp[j][num][0][1] += 1; dp[j][num][0][1] %= mod;
//            }
//
//        }

        for(int k = 2; k <= n; k++)
        {
            int v = p[k];
            for(int i = 1; i <= 9; i++)
            {
                for(int j = 1; j <= 9; j++)
                {
                    printf("i = %d j = %d\n",i,j);
                    int a = (i%9 + v%9)%9;
                    printf("a = %d\n",a);
                    if(a==0) a = 9;
                    dp[k][a][j][1][0] += dp[k-1][i][j][1][0]; dp[k][a][j][1][0] %= mod;
                    dp[k][a][j][1][1] += dp[k-1][i][j][1][1]; dp[k][a][j][1][1] %= mod;
                    dp[k][v][j][1][1] += dp[k-1][i][j][0][1]; dp[k][v][j][1][1] %= mod;
                    int b = (j%9 + v%9)%9;
                    if(b==0) b = 9;
                    dp[k][i][b][0][1] += dp[k-1][i][j][0][1]; dp[k][i][b][0][1] %= mod;
                    dp[k][i][b][1][1] += dp[k-1][i][j][1][1]; dp[k][i][b][1][1] %= mod;

                    dp[k][i][v][1][1] += dp[k-1][i][j][1][0]; dp[k][i][v][1][1] %= mod;
                }
            }
        }
        ll sum = (dp[n][A][B][1][1] + dp[n][A][B][0][1] + dp[n][A][B][1][0])%mod;
        printf("%I64d\n",sum);
    }
}