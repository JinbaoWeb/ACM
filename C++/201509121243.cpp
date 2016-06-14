#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#define MOD 880803841
#define LL long long
using namespace std;
struct node
{
	int l,r,avi,unavi,lazy;
}tree[400010];
int N, M;

void print(int p)
{
	printf("p %d   L %d   R %d   avi %d   unavi %d   lazy %d\n",p,tree[p].l,tree[p].r,tree[p].avi,tree[p].unavi,tree[p].lazy );
	if (tree[p].l==tree[p].r) return;
	print(p*2);
	print(p*2+1);
}
void build(int p,int L,int R)
{
	tree[p].l=L;
	tree[p].r=R;
	tree[p].avi=R-L+1;
	tree[p].unavi=0;
	tree[p].lazy=0;
	if (L==R) return;
	build(p*2,L,(L+R)/2);
	build(p*2+1,(L+R)/2+1,R);
}
int reverse(int p,int L,int R)
{
	int res=0;
	if (L==tree[p].l && R==tree[p].r)
	{
		res=tree[p].unavi-tree[p].avi;
		swap(tree[p].unavi,tree[p].avi);
		tree[p].lazy=tree[p].lazy ^ 1;
		return res;
	}
	if (tree[p].lazy)
	{
		swap(tree[p*2].avi,tree[p*2].unavi);
		swap(tree[p*2+1].avi,tree[p*2+1].unavi);
		tree[p*2].lazy  = tree[p*2].lazy ^ 1;
		tree[p*2+1].lazy =tree[p*2+1].lazy ^ 1;
		tree[p].lazy=0;
	}
	if (tree[p*2].r>=R) res=reverse(p*2,L,R);
	else if (tree[p*2+1].l<=L) res=reverse(p*2+1,L,R);
	else res=reverse(p*2,L,tree[p*2].r)+reverse(p*2+1,tree[p*2+1].l,R);
	tree[p].avi=tree[p*2].avi+tree[p*2+1].avi;
	tree[p].unavi=tree[p*2].unavi+tree[p*2+1].unavi;
	return res;
}



LL Pow(LL a, LL n, LL p)
{
    LL x = a;
    LL res = 1;
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
LL Cm(LL n, LL m, LL p)
{
    LL a = 1, b = 1;
    if (m > n)return 0;
    while (m)
    {
        a = (a * n) % p;
        b = (b * m) % p;
        m--;
        n--;
    }
    return (a * Pow(b, p - 2, p)) % p;
}
LL Lucas(LL n, LL m, LL p)
{
    if (m == 0)
        return 1;
    return (Cm(n % p, m % p, p) * Lucas(n / p, m / p, p)) % p;
}



LL anti[100005] = {1, 1};
LL extend_Euclid(LL a, LL b, LL &x, LL &y){
	if(b==0){
	x = 1; y = 0;
	return a;
	}
	LL r = extend_Euclid(b, a%b, y, x);
	y -= a/b*x;
	return r;
}
LL equation(LL a, LL b, LL c)
{
    LL x, y;
    LL g = extend_Euclid(a, b, x, y);
    if(c % g)
        return 0;    //表示无解
    LL ran = b/g;
        //只需存最小整数解
    return (c/g*x%ran+ran)%ran;
}
void set()
{
	for(int i = 2;i < 100005;i++)
	{
		LL t = equation(i, MOD, 1);
		anti[i] = anti[i-1]*t%MOD;
		//printf("%d ", anti[i]);
	}
}



int main(int argc, char const *argv[])
{
	int t,q;
	set();
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&N,&M,&q);
		build(1,1,M);
		
		for (int i=0;i<q;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			M=M+reverse(1,u,v);
			int dir=1;
			LL fenmu=anti[M],fenzi=0;
			for (LL i=0;i<M;i++)
			{
				fenzi=fenzi+dir*Lucas(M,i,MOD)*Pow(M-i,N,MOD);
				fenzi=(fenzi+MOD)%MOD;
				dir*=-1;
			}
			printf("%lld\n",fenzi*fenmu%MOD );
		}
	}
	return 0;
}
