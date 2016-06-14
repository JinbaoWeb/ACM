#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000+10;
typedef long long ll;
ll c[MAXN];
ll b[MAXN];
ll a[MAXN];
int lowbit(int x){
    return x&(-x);
}
void update(int x,ll add,ll c[]){
    while (x<MAXN){
        c[x]+=add;
        x+=lowbit(x);
    }
}
ll getSum(int x,ll c[]){
    ll sum=0;
    while (x>0){
        sum+=c[x];
        x-=lowbit(x);
    }
    return sum;
}
void init(){
    memset(c,0,sizeof(c));
    memset(b,0,sizeof(b));
}
int main(){
    int n,m;
    char str[10];
    while (~scanf("%d%d",&n,&m)){
        init();
        for (int i=0;i<n;i++){
            scanf("%lld",&a[i]);
            update(i+1,(n-i)*a[i],c);
            update(i+1,a[i],b);
        }
        while (m--){
            scanf("%s",str);
            if (str[0]=='Q'){
                int x;
                scanf("%d",&x);
                ll ans=getSum(x,c);
                ll temp=getSum(x,b);
                
                printf("%lld\n",ans-(n-x)*temp);
            }
            else{
                int x;
                ll k;
                scanf("%d%lld",&x,&k);
                ll temp=(x,(n-x+1)*(k-a[x-1]));
                //cout<<temp<<endl;
                update(x,temp,c);
                update(x,k-a[x-1],b);
                a[x-1]=k;
            }
        }
    }
    return 0;
}