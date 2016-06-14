/*涛弟弟的模板    6666666666*/
//数论常用模板
//extend_euclid     求出ax+by=k*gcd(a,b) 的一个解
int extend_euclid(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }//GCD部分
    int d = extend_euclid(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - a / b * y;
    return d;
}




//快速幂


long long multi(long long a, long long b, long long n)
{
    long long res = 0;
    while (b)
    {
        if (b & 1)     //用位运算显然要比用 %2==1 快很多嘛
        {
            res += a;
            if (res >= n) res -= n;
        }
        b >>= 2;
        a <<= 2;
        if (a >= n) a -= n;
    }
    return res;
}
long long multimod(long long a, long long b, long long n)
{
    long long res = 1;
    while (b)
    {
        if (b & 1)
        {
            res = multi(res, a, n); //如果基数已经很大的时候一定要这样写
        }
        b >>= 2;
        a = multi(a, a, n); //同上
    }
    return res;
}





//miller_rabin 素数测试，真心是快，人品机器、、、、


//素数打表
void getprime()
{
    int ex[100];
    memset(ex, 0, sizeof(ex));
    for (int i = 2; i < 100; i++)
        if (ex[i] == 0)
            for (int j = 2 * i; j < 100; j += i) ex[j] = 1;
    int count = 0;
    for (int i = 2; i < 100; i++) if (ex[i] == 0)
        {
            count++;
            prime[count] = i;
        }
    return;
}

//miller_rabin 主函数，以费马定理为基础

int miller_rabin(long long n)
{
    if (n < 2) return 0;
    else if (n == 2) return 1;
    else if (!(n & 1)) return 0;
    long long k, m, a, j;
    m = n - 1;
    k = 0;
    while (!(m & 1))
    {
        m >>= 1;
        k++;
    }      //将n-1写成 m的2的k次幂，m为奇数
    for (int i = 1; i < 5; i++)
    {
        if (prime[i] >= n) return 1;
        a = multimod(prime[i], m, n);
        if (a == 1) continue;      //如果prime[i] 的m 次幂已经同余等于1了，那么n-1次幂肯定也是同余1
        for (j = 0; j < k; j++)
        {
            if (a == n - 1) break; //如果prime[i]的m的2的j（j<k)次幂同余等于1，那么n-1次幂也是同余1
            a = multi(a, a, n);
        }
        if (j == k) return 0;   //如果都不行，那就是合数了。分部做可以减少一定的时间复杂度
    }
    return 1;
}





//pollard_rho 大整数分解，为啥这个时候人品是这么靠谱的东西、、、、


/*Pollard rho

原理：设n为待分解的大整数，用某种方法生成a和b，计算p=gcd(a-b,n),直到p不为1或a,b出现循环时为止，若p=n，则说明n是一个素数，否则p为n的一个约数。

算法步骤：选取一个小的随机数x1，迭代生成x[i] = x[i-1]^2+c，一般去c=1，若序列出现循环则退出，计算p=gcd(x[i-1]-x[i],n)，若p=1则返回上一步继续迭代，否则跳出迭代过程。若p=n，则n为素数，否则p为n的一个约数，并递归分解p和n/p。

可以在θ（sqrt(p)）的期望时间内找到n的一个小因子p。但对于因子很少，因子值很大的大整数n，该方法依然不是很有效。*/
long long gcd(long long a, long long b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}
long long pollard_rho(long long c, long long n)
{
    long long x, y, d, i = 1, k = 2;
    x = rand() % (n - 1) + 1;
    y = x;
    while (true)
    {
        ++i;
        x = (multi(x, x, n) + c) % n;
        d = gcd(y - x, n);
        if (1 < d && d < n)
            return d;
        if (x == y)
            return n;
        if (i == k)
            y = x, k <<= 1;    //k只是控制循环周期的范围
    }
}
long long rho(long long n)
{
    if (miller_rabin(n))
    {
        //flag++;
        //fac[flag]=n;    如果要求出所有的因数就添这个。
        return n;
    }
    long long t = n;
    while (t >= n) t = pollard_rho(rand() % (n - 1) + 1, n);
    long long a = rho(t);
    long long b = rho(n / t);
    return a < b ? a : b;
}


//LUCAS定理

/*
Lucas定理是用来求 c(n,m) mod p的值,p是素数（从n取m组合，模上p）。
描述为:
Lucas(n,m,p)=cm(n%p,m%p)* Lucas(n/p,m/p,p)
Lucas(x,0,p)=1;
而
cm(a,b)=a! * (b!*(a-b)!)^(p-2) mod p
也= (a!/(a-b)!) * (b!)^(p-2)) mod p
这里，其实就是直接求 (a!/(a-b)!) / (b!) mod p
由于 (a/b) mod p = a * b^(p-2) mod p*/


int N, M, P;
int Pow(long long a, long long n, long long p)
{
    long long x = a;
    long long res = 1;
    while (n)
    {
        if (n & 1)
        {
            res = (res * x) % p;
        }
        n >>= 1;
        x = (x * x) % p;
    }
    return res;
}
int Cm(long long n, long long m, long long p)
{
    long long a = 1, b = 1;
    if (m > n)return 0;
    //实现(a!/(a-b)!) * (b!)^(p-2)) mod p,由于n比较大，所以，此处不知道有什么好的优化
    while (m)
    {
        a = (a * n) % p;
        b = (b * m) % p;
        m--;
        n--;
    }
    return (a * Pow(b, p - 2, p)) % p;
}
int Lucas(long long n, long long m, long long p)
{
    if (m == 0)
        return 1;
    return (Cm(n % p, m % p, p) * Lucas(n / p, m / p, p)) % p;
}
