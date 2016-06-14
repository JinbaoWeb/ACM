/*******************************************************************************
 * Author :          jinbao
 * Email :           dongjinbao913106840144@gmail.com
 * Last modified :   2015-07-07 18:51
 * Filename :        poj3368.cpp
 * Description :     
 * *****************************************************************************/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
int a[100000+5];
int f[100000+5];
int dp[100000+5][20];
int Max(int a,int b){
    return a>b?a:b;
}
int rmq_query(int l,int r){
    if (l>r)
        return 0;
    int k=log((double)(r-l+1))/log(2.0);
    return Max(dp[l][k],dp[r-(1<<k)+1][k]);
}
int main(){
    int n,q;
    while (~scanf("%d",&n)){
        if (n==0)
            break;
        scanf("%d",&q);
        for (int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if (i==1)
                f[i]=1;
            else{
                 if (a[i]==a[i-1])
                    f[i]=f[i-1]+1;
                else
                    f[i]=1;
            }
        }
        for (int i=1;i<=n;i++)
            dp[i][0]=f[i];
        int k=log((double)(n+1))/log(2.0);
        for (int j=1;j<=k;j++){
            for (int i=1;i+(1<<(j-1))<=n;i++){
                dp[i][j]=Max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
            }
        }
        int x,y;
        while (q--){
            scanf("%d%d",&x,&y);
            int t=x;
            while (t<=y&&a[t]==a[t-1])
                t++;
            int ans=rmq_query(t,y);
            if (ans>t-x)
                cout<<ans<<endl;
            else
                cout<<t-x<<endl;
            
        }
    }

    return 0;
}