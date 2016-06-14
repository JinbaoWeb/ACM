#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<ctime>
using namespace std;
#define bignum long long
//a^b%c=a ^(b%eular(c)+eular(c)) % c;  b>=oula(x)
//求a，b的最大公约数
bignum gcd(bignum a,bignum b)
{
    return b==0?a:gcd(b,a%b);
}
//求a*b%c,因为a，b很大，所以要先将b写成二进制数，再加：例如3*7=3*(1+2+4);
bignum mulmod(bignum a,bignum b,bignum c)
{
    bignum cnt=0,temp=a;
    while(b)
    {
        if(b&1) cnt=(cnt+temp)%c;
        temp=(temp+temp)%c;
        b>>=1;
    }
    return cnt;
}
//求a^b%c,再次将b写成二进制形式，例如：3^7=3^1*3^2*3^4;
bignum powmod(bignum a,bignum b,bignum c)
{
    bignum cnt=1,temp=a;
    while(b)
    {
        if(b&1) cnt=mulmod(cnt,temp,c);//cnt=(cnt*temp)%c;
        temp=mulmod(temp,temp,c);//temp=(temp*temp)%c;
        b>>=1;
    }
    return cnt;
}
//Miller-Rabin测试n是否为素数,1表示为素数，0表示非素数
int pri[10]={2,3,5,7,11,13,17,19,23,29};
bool Miller_Rabin(bignum n)
{
    if(n<2) return 0;
    if(n==2) return 1;
    if(!(n&1)) return 0;
    bignum k=0,m;
    m=n-1;
    while(m%2==0) m>>=1,k++;//n-1=m*2^k
    for(int i=0;i<10;i++)
    {
        if(pri[i]>=n) return 1;
        bignum a=powmod(pri[i],m,n);
        if(a==1) continue;
        int j;
        for(j=0;j<k;j++)
        {
            if(a==n-1) break;
            a=mulmod(a,a,n);
        }
        if(j<k) continue;
        return 0;
    }
    return 1;
}
//pollard_rho 大整数分解，给出n的一个非1因子，返回n是为一次没有找到
bignum pollard_rho(bignum C,bignum N)
{
    bignum I, X, Y, K, D;
    I = 1;
    X = rand() % N;
    Y = X;
    K = 2;
    do
    {
        I++;
        D = gcd(N + Y - X, N);
        if (D > 1 && D < N) return D;
        if (I == K) Y = X, K *= 2;
        X = (mulmod(X, X, N) + N - C) % N;
    }while (Y != X);
    return N;
}
//找出N的最小质因数
bignum rho(bignum N)
{
    if (Miller_Rabin(N)) return N;
    do
    {
        bignum T = pollard_rho(rand() % (N - 1) + 1, N);
        if (T < N)
        {
              bignum A, B;
              A = rho(T);
              B = rho(N / T);
              return A < B ? A : B;
        }
    }
    while(1);
}
//N分解质因数，这里是所有质因数，有重复的
bignum AllFac[1100];
int Facnum;
void findrepeatfac(bignum n)
{
    if(Miller_Rabin(n))
    {
        AllFac[++Facnum]=n;
        return ;
    }
    bignum factor;
    do
    {
        factor=pollard_rho(rand() % (n - 1) + 1, n);
    }while(factor>=n);
    findrepeatfac(factor);
    findrepeatfac(n/factor);
}
//求N的所有质因数，是除去重复的
bignum Fac[1100];
int num[1100];
int len;//0-len
void FindFac(bignum n)
{
    len=0;
    //初始化
    memset(AllFac,0,sizeof(AllFac));
    memset(num,0,sizeof(num));
    Facnum=0;
    findrepeatfac(n);
    sort(AllFac+1,AllFac+1+Facnum);
    Fac[0]=AllFac[1];
    num[0]=1;
    for(int i=2;i<=Facnum;i++)
    {
        if(Fac[len]!=AllFac[i])
        {
            Fac[++len]=AllFac[i];//important
        }
        num[len]++;
    }
}
//求n的欧拉函数值
bignum oula(bignum n)
{
    FindFac(n);
    bignum cnt=n;
    for(int i=0;i<=len;i++)
    {
        cnt-=cnt/Fac[i];
    }
    return cnt;
}
//枚举n的所有因子  cnt
/*bignum Fac[1100];
int num[1100];
int len;//0-len
*/
bignum yinzi[100000];
bignum yinzinum;//初始化在main中(0-yinzinum-1)
void dfs(int id,bignum cnt)
{
    yinzi[yinzinum++]=cnt;
    if(id==len+1)
    {
        return ;
    }
    bignum temp=1;
    for(int i=0;i<=num[id];i++)
    {
        dfs(id+1,cnt*temp);
        temp*=Fac[id];
    }
}
bignum Mod(char* B,bignum ou)
{
    bignum cnt=0;
    for(int i=0;B[i];i++)
    {
        cnt=(cnt*10+B[i]-'0')%ou;
    }
    return cnt;
}
bignum _pow(bignum A,bignum X,bignum C)
{
    if(X==0) return 1;
    if(X==1) return A%C;
    bignum cnt=_pow(A,X/2,C);
    cnt=cnt*cnt%C;
    if(X&1) cnt=cnt*A%C;
    return cnt;
}
bignum Xxiaoyuou(char* str,bignum x)
{
    bignum cnt=0;
    for(int i=0;str[i];i++)
    {
        cnt=cnt*10+str[i]-'0';
        if(cnt>=x) return 0;
    }
    return cnt;
}
char A[110000],B[110000];
int main()
{
    bignum C;
    while(cin>>A>>B)
    {
    	C= 10000000007;
        bignum a=Mod(A,C);
        bignum ou=oula(C);
        bignum cnt=Xxiaoyuou(B,ou);
        if(cnt)
        {
            cout<<_pow(a,cnt,C)<<endl;
            continue;
        }
        bignum X=Mod(B,ou);
        bignum res=_pow(a,X+ou,C);
        cout<<res<<endl;
    }
    return 0;
}

