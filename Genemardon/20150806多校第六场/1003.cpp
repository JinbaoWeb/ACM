#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 100000+10;
bool used[MAXN];
ll ans[MAXN];
int main(){
    ll t,n,m;
    scanf("%d",&t);
    while (t--){
        scanf("%I64d%I64d",&n,&m);
        memset(used,false,sizeof(used));
        ll sum=n*(n+1)/2;
        if (sum%m!=0 || sum/m<n){
            printf("NO\n");
            continue;
        }
        ll k=sum/m;
        //printf("%I64D\n", k);
        printf("YES\n");
        for (int i=0;i<m;i++){
            ll num=0;
            ll temp=k;
            ll s=n;
            ll flag=0;
            while (1){
                if (temp==0)
                    break;
                if (s<=0 && temp>0){
                    break;
                    flag=1;
                }
                if (used[s]==true){
                    s--;
                    continue;
                }
                temp-=s;
                used[s]=true;
                ans[num++]=s;
                if (temp<=n)
                    s=temp;
            }
            //if (flag==1)
                //printf("NO\n");
            printf("%I64d ", num);
            for (int j=0;j<num-1;j++)
                printf("%I64d ",ans[j] );
            printf("%I64d\n",ans[num-1] );
        }
    }


    return 0;
}