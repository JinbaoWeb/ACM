#include <stdio.h>
#include <string.h>
#include <math.h>
#define mod 100000000
int n,m,a[15];
int dp[13][(1<<12)+10];
 
int check(int x,int flag)
{
    int i,temp=3;
    if((a[x]&flag)!=flag)//判断下那一行种是否能够找出flag这个状态
     return 0;
    if((flag&(flag<<1))!=0||(flag&(flag>>1))!=0)
     return 0;
    return 1;
}
 
void solve()
{
    int i,j,k,max,res=0;
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    max=1<<m;
    for(i=1;i<=n;i++)//枚举每一行
    {
        for(j=0;j<max;j++)//每一行的状态
        {
            if(check(i,j)==0)//看这一状态是否合法
             continue;
            for(k=0;k<max;k++)//枚举这一行上面的所有状态
            {
                if((j&k)!=0)
                 continue;
                dp[i][j]=dp[i][j]+dp[i-1][k];
                if(dp[i][j]>=mod)
                 dp[i][j]-=mod;
            }
        }
    }
    for(i=0;i<max;i++)
    {
        res=res+dp[n][i];
        if(res>=mod)
         res=res%mod;
    }
    printf("%d\n",res);
}
int main(){
    int x;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int i,j;
        for(i=1;i<=n;i++)
        {
            a[i]=0;
            for(j=1;j<=m;j++)
            {
                scanf("%d",&x);
                a[i]=(a[i]<<1)+x;//把二进制压缩成一个十进制数字
            }
        }
        solve();
    }
    return 0;
}