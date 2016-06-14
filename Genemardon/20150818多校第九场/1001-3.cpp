#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
long long dp[200][200];
long long a[200];
long long perm[300];
long long C[300][300];
int ope[200];
char str[200];
long long MOD = 1e9 + 7;
void getPerm()
{
    perm[0] = 1;
    perm[1] = 1;
    for (int i = 2; i <= 200; i++) perm[i] = perm[i - 1] * i % MOD;
}
void getcomb()
{
    C[0][0] = 1;
    C[1][0] = 1; C[1][1] = 1;
    for (int i = 2; i <= 200; i++)
    {
        C[i][0] = 1; C[i][i] = 1;
        for (int j = 1; j < i; j++) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
    }
}
long long mult (long long a, long long b)
{
    long long res = 0;
    while (b)
    {
        if (b & 1)
            res = (res + a) % MOD;
        b /= 2;
        a = a * 2 % MOD;
    }
    return res;
}
int main(int argc, char const *argv[])
{
    int n;
    getPerm();
    getcomb();
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 1; i <= n; i++) scanf("%I64d", &a[i]);
        scanf("%s", str);
        for (int i = 1; i < n; i++)
        {
            if (str[i - 1] == '+')
                ope[i] = 0;
            else if (str[i - 1] == '-')
                ope[i] = 1;
            else if (str[i - 1] == '*')
                ope[i] = 2;
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++) dp[i][i] = a[i];
        for (int i = 1; i < n; i++)
            for (int j = 1; j <= n - i; j++)
                for (int k = j; k < j + i; k++)
                {
                    if (ope[k] == 0)
                    {
                        dp[j][j + i] = (dp[j][j + i] + C[i - 1][k - j] * ((perm[j + i - k - 1] * dp[j][k] % MOD + perm[k - j] * dp[k + 1][j + i] % MOD) % MOD)) % MOD;
                        dp[j][j + i] = (dp[j][j + i] % MOD + MOD) % MOD;
                    }
                    else if (ope[k] == 1)
                    {
                        dp[j][j + i] = (dp[j][j + i] + C[i - 1][k - j] * ((perm[j + i - k - 1] * dp[j][k] % MOD - perm[k - j] * dp[k + 1][j + i]) % MOD) % MOD) % MOD;
                        dp[j][j + i] = (dp[j][j + i] % MOD + MOD) % MOD;
                    }
                    else
                    {
                        dp[j][j + i] = (dp[j][j + i] + C[i - 1][k - j] * (dp[j][k] * dp[k + 1][j + i] % MOD) % MOD) % MOD;
                        dp[j][j + i] = (dp[j][j + i] % MOD + MOD) % MOD;
                    }
                    //printf("[%d,%d]  %lld  by [%d,%d] %lld*(%lld) %c [%d,%d] %lld*(%lld)\n", j,j+i,dp[j][j+i],j,k,perm[j+i-k-1],dp[j][k],str[k-1],k+1,i+j,perm[k-j],dp[k+1][j+i]);
                }
        // for (int i=1;i<n;i++)
        // {
        //     for (int j=1;j<=n-i;j++) printf("%I64d ",dp[j][j+i] );
        //     printf("\n");
        // }
        printf("%I64d\n", (dp[1][n] % MOD + MOD) % MOD );
    }
    return 0;
}