#include <stdio.h>
#include <string.h>
#define M 8005
#define L(x) (x<<1)
#define R(x) ((x<<1)+1)

struct data
{
    int l,r,col;      //col 等于 -1 表示什么色都没有
}node[M*3];
int color[M];       //记录每块板上的是什么颜色

void BuildTree(int left,int right,int u)
{
    node[u].l = left;
    node[u].r = right;
    node[u].col = -1;
    if (left == right)
        return ;
    int mid = (left + right)>>1;
    BuildTree(left,mid,L(u));
    BuildTree(mid+1,right,R(u));
}

void getdown(int u)
{
    node[L(u)].col = node[u].col;
    node[R(u)].col = node[u].col;
    node[u].col = -1;
}
void updata (int left,int right,int val,int u)
{
    if (node[u].col == val)
        return ;
    if (left <= node[u].l&&node[u].r <= right)
    {
        node[u].col = val;
        return ;
    }
    if (node[u].col != -1)       //延迟覆盖 不然可能会TLE（最近做一直都是延迟覆盖）
        getdown (u);
    int mid = (node[u].l+ node[u].r)>>1;
    if (right <= mid)
        updata (left,right,val,L(u));
    else if (left >= mid+1)
        updata (left,right,val,R(u));
    else
    {
        updata (left,right,val,L(u));
        updata (left,right,val,R(u));
    }

    if ((node[L(u)].col == node[R(u)].col)&&node[L(u)].col != -1)  //递归回来修改父结点颜色
        node[u].col = node[L(u)].col;

}

void query (int u)
{
    if (node[u].col != -1)
    {
        for (int i = node[u].l;i <= node[u].r;i ++)
            color[i] = node[u].col;
        return ;
    }
    if (node[u].l == node[u].r)   //这是不加这个竟然会运行不起来
        return ;
    query (L(u));
    query (R(u));
}
void ans ()
{
    int res[M];
    memset (res,0,sizeof(res));
    int pre = -1,i;
    for (i = 0;i < M;i ++)
        if (pre != color[i]) 
        {
            pre = color[i];
            res[pre] ++;
        }
    for (i = 0;i < M;i ++)
        if (res[i] !=0)
            printf ("%d %d\n",i,res[i]);
    printf ("\n");
}
int main ()
{
    int n,x,y,val;
    while (~scanf ("%d",&n))
    {
        memset (color,-1,sizeof (color));
        BuildTree(0,M,1);
        while (n --)
        {
            scanf ("%d%d%d",&x,&y,&val);
            if (x == y)
                continue;
            updata (x,y-1,val,1);   //后面一个不涂就能避免那种情况
        }
        query (1);
        ans();
    }
    return 0;
}
