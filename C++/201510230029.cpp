/**
是男人就下100楼；
求到达底层的最大生命值。
一上来就TLE了，从高到低更新树，每次都维护落到[l,r]上的最大值，要更新到叶子结点才可以。

正解，从下到上更新树，想到与线段覆盖，找当前线段左右断点落下的线段的id值，
然后DP
*/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 100000
#define L(i) i << 1
#define R(i) i << 1 | 1

struct _st
{
    int l,r,id;
    int mid()
    {
        return (l + r) >> 1;
    }
}st[N<<2];
struct _seg
{
    int x1,x2,h,val;
    void input()
    {
        scanf("%d%d%d%d",&h,&x1,&x2,&val);
    }
}seg[N];
int dp[N];
bool cmp(_seg a,_seg b)
{
    return a.h < b.h;
}
void build(int id,int l,int r)
{
    st[id].l = l;
    st[id].r = r;
    st[id].id = 0;
    if(l == r)
    {
        return ;
    }
    int mid = st[id].mid();
    build(L(id),l,mid);
    build(R(id),mid+1,r);
}
void pushdown(int id)
{
    if(st[id].id != -1)
    {
        st[L(id)].id = st[R(id)].id = st[id].id;
        st[id].id = -1;
    }
}
void update(int id,int l,int r,int x)
{
    if(st[id].l == l && r == st[id].r)
    {
        st[id].id = x;
        return ;
    }
    pushdown(id);
    int mid = st[id].mid();
    if(mid >= r)
        update(L(id),l,r,x);
    else if(mid < l)
        update(R(id),l,r,x);
    else
    {
        update(L(id),l,mid,x);
        update(R(id),mid+1,r,x);
    }
}
int query(int id,int pos)
{
    if(st[id].id != -1)
        return st[id].id;
    int mid = st[id].mid();
    if(mid >= pos)
        return query(L(id),pos);
    else
        return query(R(id),pos);
}
int main()
{
    int n,i;
    while(scanf("%d",&n) == 1)
    {
        for(i = 1; i <= n; ++i)
            seg[i].input();
        sort(seg + 1,seg + 1 + n,cmp);

        build(1,1,N);
        int ll,rr;
        for(i = 1; i <= n; ++i)
        {
            ll = query(1,seg[i].x1);
            rr = query(1,seg[i].x2);
            dp[i] = max(dp[ll],dp[rr]) + seg[i].val;
            update(1,seg[i].x1,seg[i].x2,i);
        }
        dp[n] += 100;
        if(dp[n] <= 0)
            dp[n] = -1;
        printf("%d\n",dp[n]);
    }
    return 0;
}
