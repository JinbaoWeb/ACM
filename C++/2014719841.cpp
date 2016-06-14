#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <math.h>

using namespace std;
long long L;

long long gcd(long long a,long long b) {
    return b==0?a:gcd(b,a%b);
}
long long multi(long long a,long long b,long long mod) {
    long long ret=0;
    while(b) {
        if(b&1)
            ret=(ret+a)%mod;
        a=(a<<1)%mod;
        b=b>>1;
    }
    return ret;
}
long long quickPow(long long a,long long b,long long mod) {
    long long ret=1;
    while(b) {
        if(b&1)
            ret=multi(ret,a,mod);  //ֱ����˵Ļ����ܻ����
        a=multi(a,a,mod);
        b=b>>1;
    }
    return ret;
}
//��ŷ������
long long eular(long long n) {
    long long ret=1,i;
    for(i=2; i*i<=n; i++) {
        if(n%i==0) {
            n=n/i;
            ret*=i-1;
            while(n%i==0) {
                n=n/i;
                ret*=i;
            }
        }
    }
    if(n>1)
        ret*=n-1;
    return ret;
}

int main() {
    int t=0;
    while(scanf("%I64d",&L)!=EOF) {
        if(L==0)
            break;
        long long p=9*L/gcd(L,8);
        long long d=gcd(10,p);
        if(d==1) {
            long long phi=eular(p);
            long long ans=phi;
            long long m=sqrt((double)phi);
            bool flag=false;
            //��ö�ٴ�С��1~sqrt(phi)֮�������
            for(int i=1; i<=m; i++) {
                if(phi%i==0 && quickPow(10,i,p)==1) {
                    ans=i;
                    flag=true;
                    break;
                }
            }
            //��1~sqrt(phi)û�ҵ����ϵ����ӣ���ôö��sqrt(phi)~phi֮�������
            if(!flag) {
                for(int i=m; i>=2; i--) {
                    if(phi%i==0 && quickPow(10,phi/i,p)==1) {
                        ans=phi/i;
                        break;
                    }
                }
            }
            printf("Case %d: %I64d\n",++t,ans);
        } else {
            printf("Case %d: 0\n",++t);
        }
    }
    return 0;
}
