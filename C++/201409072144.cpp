#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
char bb[1000005];
__int64 euler(__int64 x){
    __int64 i, res = x;
    for(i=2;i<(__int64)sqrt(x*10)+1;i++){//
        if(x%i==0){
            res = res /i *(i-1);
            while(x%i==0) x/=i;
        }
    }
    if(x>1) res = res/x*(x-1);
    return res;
}
__int64 quickpow(__int64 m, __int64 n, __int64 k){
    __int64 b = 1;
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
    __int64 a=4, c, b, phic, sum;
    int i, j, k, l;
    while(scanf("%s",bb)!=EOF){
        scanf("%I64d",&c);
        l = strlen(bb);
        phic = euler(c);
        if(l<=10){
            b = bb[0]-'0';
            for(i=1;i<l;i++){
                b = b*10 + (bb[i]-'0');
            }
            if(b<phic){
                printf("%I64d\n",quickpow(a,b,c));continue;
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
        printf("%I64d\n",quickpow(a,b+phic,c));
    }
    return 0;
}
