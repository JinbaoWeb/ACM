#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;
const int mod = 1000000009;

#define lson u<<1
#define rson u<<1|1

inline int sqr2(int x){
    return x * x % mod;
}

inline int sqr3(int x){
    return sqr2(x) * x % mod;
}

struct SegTree
{
    int l,r;
    int sum[4];
    int mul,add;
    inline int mid(){
        return l + r >> 1;
    }
    inline int len(){
        return r - l;
    }
    void flag_init(){
        add = 0, mul = 1;
    }
    void to_mul(int m){
        (sum[1] *= m) %= mod;
        (sum[2] *= sqr2(m)) %= mod;
        (sum[3] *= sqr3(m)) %= mod;

        (mul *= m) %= mod;
        (add *= m) %= mod;
    }
    void to_add(int a){
        (sum[3] += sqr3(a) * len()) %= mod;
        (sum[3] += 3 *    a    * sum[2]) %= mod;
        (sum[3] += 3 * sqr2(a) * sum[1]) %= mod;

        (sum[2] += sqr2(a) * len()) %= mod;
        (sum[2] += 2 * a  * sum[1]) %= mod;

        (sum[1] += a * len()) %= mod;

        (add += a) %= mod;
    }
}T[N<<2];

void build(int u,int l,int r)
{
    T[u].l = l , T[u].r = r;
    memset(T[u].sum,0,sizeof(T[u].sum));
    T[u].flag_init();
    if(l == r-1)
        return ;
    int m = T[u].mid();
    build(lson,l,m);
    build(rson,m,r);
}

int op;

void push_down(int u)
{
    T[lson].to_mul(T[u].mul);
    T[rson].to_mul(T[u].mul);

    T[lson].to_add(T[u].add);
    T[rson].to_add(T[u].add);

    T[u].flag_init();
}

void push_up(int u)
{
    for(int i=1;i<=3;i++)
        T[u].sum[i] = (T[lson].sum[i] + T[rson].sum[i]) % mod;
}

void updata(int u,int l,int r,int mul,int add)
{
    if(T[u].l == l && T[u].r == r)
    {
        T[u].to_mul(mul);
        T[u].to_add(add);
        return ;
    }
    push_down(u);
    int m = T[u].mid();
    if(r <= m)
        updata(lson,l,r,mul,add);
    else if(l >= m)
        updata(rson,l,r,mul,add);
    else
        updata(lson,l,m,mul,add), updata(rson,m,r,mul,add);
    push_up(u);
}

int query(int u,int l,int r)
{
    if(T[u].l == l && T[u].r == r)
        return T[u].sum[op];
    push_down(u);
    int m = T[u].mid();
    if(r <= m)
        return query(lson,l,r);
    else if(l >= m)
        return query(rson,l,r);
    else
        return (query(lson,l,m)+query(rson,m,r)) % mod;
}

int main()
{
    //freopen("in.ads","r",stdin);
    int n,m,a,b,c;
    while(~scanf("%d%d",&n,&m))
    {
        build(1,1,n+1);
        while(m--)
        {
            scanf("%d",&op);
            if(op == 4)
            {
                scanf("%d%d",&a,&b);
                op=1;
                printf("%d\n",query(1,a,b+1));
            }
            else
            {
                scanf("%d%d%d",&a,&b,&c);
                if(op == 1)
                    updata(1,a,b+1,1,c);
                else if(op == 2)
                    updata(1,a,b+1,c,0);
                else
                    updata(1,a,b+1,0,c);
            }
        }
    }
    return 0;
}