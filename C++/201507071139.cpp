#include <stdio.h>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int mod=1000000000+7;
const int maxn=50000+5;
LL prime[maxn],vis[maxn],t;
void init()
{
    LL i,j,k,m;
    t=0;
    m=(LL)sqrt(maxn+0.5);
    memset(vis,0,sizeof(vis));
    for(i=2;i<=m;i++)
    {
        if(!vis[i])
        for(j=i*i;j<maxn;j+=i)
        vis[j]=1;
    }
    for(i=2;i<maxn;i++)
    if(!vis[i])prime[t++]=i;
}
LL pow_mod(LL a,LL b)
{
    LL s=1;
    while(b)
    {
        if(b&1)s=(s*a)%mod;
        a=(a*a)%mod;
        b=b>>1;
    }
    return s;
}
LL find(LL a,LL b)
{
    LL ans=pow_mod(a,b)-1;
    ans=ans*pow_mod(a-1,mod-2)%mod;
    ans=(ans+mod)%mod;
    return ans;
}
int main()
{
    init();
    LL n,m;
    while(~scanf("%lld%lld",&n,&m))
    {
        LL i,j,k,num;
        LL ans=1;
        for(i=0;i<t&&prime[i]*prime[i]<=n;i++)
        {
            if(n%prime[i]==0)
            {
                num=0;
                while(n%prime[i]==0){
                    n=n/prime[i];
                    num++;
                }
                ans=ans*find(prime[i],m*num+1)%mod;
            }
        }
        if(n>1)
            ans=ans*find(n,m+1)%mod;
        printf("%lld\n",ans);
    }
    return 0;
}