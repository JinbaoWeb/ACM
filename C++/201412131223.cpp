#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
char bb[1000005];
long long euler(long long x){
    long long i, res = x;
    for(i=2;i<(long long)sqrt(x*10)+1;i++){//
        if(x%i==0){
            res = res /i *(i-1);
            while(x%i==0) x/=i;
        }
    }
    if(x>1) res = res/x*(x-1);
    return res;
}
long long quickpow(long long m, long long n, long long k){
    long long b = 1;
    while(n>0){
        if(n&1){
            b = ((b%k)*(m%k))%k;
        }
        n = (n>>1);
        m = ((m%k)*(m%k))%k;
    }
    return b;
}
int main(){
    long long a, c, b, phic, sum;
    int i, j, k, l;
    int t;
    cin>>t;
    while(~scanf("%lld",&a)){
        scanf("%s",bb);
        //scanf("%lld",&c);
        c=10000000007;
        l = strlen(bb);
        phic = euler(c);
        if(l<=10){
            b = bb[0]-'0';
            for(i=1;i<l;i++){
                b = b*10 + (bb[i]-'0');
            }
            if(b<phic){
                printf("%lld\n",quickpow(a,b,c));continue;
            }
        }
        b = 0ll;   //求一个很大的数对一个数的模数的方法
        for(i=0;i<l;i++){
            b = b*10 + (bb[i]-'0');
            while(b>=phic){   //while很重要！！！，防溢出
                b -= phic;
            }
        /*if(b>=phic){
        b = b%phic;
        }*/
        }
        printf("%lld\n",quickpow(a,b+phic,c));
    }
    return 0;
}