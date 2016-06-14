#include<iostream>
#include<algorithm>
using namespace std;
#define max 1000005
struct node
{
    int a,b;
}t[max];
int cmp(node &p,node &q)             //对东边的城市进行升序排序，当东边为同一个点时，对西边的点进行升序排序，然后就是求逆序数了
{
    if(p.a<q.a)
        return 1;
    else if(p.a==q.a&&p.b<q.b)
        return 1;
    else
        return 0;
}
int c[max],n,m;
int lowbit(int x)
{
    return x&(-x);
}
void updata(int i,int j)
{
    while(i<=m)
    {
        c[i]+=j;
        i+=lowbit(i);
    }
}
__int64 getsum(int x)
{
    __int64 sum=0;
    while(x>0)
    {
        sum+=c[x];
        x-=lowbit(x);
    }
    return sum;
}
int main()
{
    int text,j=0;
    scanf("%d",&text);
    while(text--)
    {
        int k,i;
        memset(c,0,sizeof(c));
        scanf("%d%d%d",&n,&m,&k);
        for( i=1;i<=k;i++)
        {
            scanf("%d%d",&t[i].a,&t[i].b);
        }
        sort(t+1,t+1+k,cmp);
        __int64 sum=0;
        //for(i=1;i<=k;i++)
        //  printf("%d %d\n",t[i].a,t[i].b);
        for( i=1;i<=k;i++)
        {
            updata(t[i].b,1);
            sum+=i-getsum(t[i].b);
        }
        printf("Test case %d: %I64d\n",++j,sum);
    }
    return 0;
}