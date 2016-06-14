//#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string> 
//using namespace std;
typedef long long ll;
const ll  p = 1e9+7;

int n;
ll f[110][110];
char o[110];
ll fac[110];
inline void read(ll &x){
    char c=0;
    for(;c<'0'||c>'9';c=getchar());
    for(x=0;c>='0'&&c<='9';c=getchar())x=x*10+(c-'0');
}
int cal(ll x, ll a,ll y,ll b, char ch){
    ll tmp;
    if (ch == '+') tmp = (x*b%p+y*a%p)%p;
    else if (ch == '-') tmp = (x*b%p-y*a%p+p)%p;
    else if (ch == '*') tmp = (x*y)%p;
    return tmp;
}
ll qpow(ll x,ll n){
    ll res = 1;
    while(n){
        if(n&1){
            res = res * x % p;
        }
        x = x * x % p;
        n = n >> 1;
    }
    return res;
}
ll inv(ll x){
    return qpow(x,p-2);
}
void work(){
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; i++) {
        read(f[i][i]);
        f[i][i] = (f[i][i]+p)%p;
    }
    scanf("%s", o);
    for (int len = 2; len <= n; len++){
        for (int i = 1; i <= n-len+1; i++){
            int j = i+len-1;
            ll sign = 2;
            for (int k = i; k < j; k++)
            {
                sign = fac[j-i-1]*inv(fac[k-i])%p*inv(fac[j-k-1])%p;
                f[i][j] = (f[i][j] + sign*cal(f[i][k],fac[k-i],f[k+1][j],fac[j-k-1],o[k-1])%p)%p;
                //cout << i << " " << j << " " << f[i][j] <<endl;
            }
        }
    }
    printf("%lld\n", f[1][n]);
}

int main() {
    fac[0] = 1;
    for(ll i=1;i<=105;++i){
        fac[i] = fac[i-1] * i%p;
    }
    while (scanf("%d", &n) != EOF)
    {
        work();
    }
    return 0;
}