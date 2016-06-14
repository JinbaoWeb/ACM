#include <stdio.h>
#include <iostream>
#include <cstdio>
using namespace std;
#define N 100001
#define MAX 4*N
#define lld long long int
#define mod 1000000007
lld arr[100001];
struct Tree
{
    lld sum;
}tree[400004];
 
struct Lazy
{
    lld add;
    lld init;
    lld mul;
}lazy[400004];
 
void build_tree(int node,int begin,int end)
{
    if(begin>end) return;
    if(begin==end)
    {
        tree[node].sum=arr[begin];
        lazy[node].init=0;
        lazy[node].add=0;
        lazy[node].mul=1;
        return;
    }
    build_tree(2*node,begin,(begin+end)/2);
    build_tree(2*node+1,1+(begin+end)/2,end);
    tree[node].sum=(tree[2*node].sum%mod+tree[2*node+1].sum%mod)%mod;
    lazy[node].init=0;
    lazy[node].add=0;
    lazy[node].mul=1;
}
void update_tree(int node,int a,int b,int begin,int end,int select,lld val)
{
     if(lazy[node].init!=0)
        {
            tree[node].sum=((b-a+1)*lazy[node].init)%mod;
            if(a!=b)
            {
                lazy[node*2].init=lazy[node].init;
                lazy[node*2].add=0;
                lazy[node*2].mul=1;
                lazy[1+2*node].init=lazy[node].init;
                lazy[1+2*node].add=0;
                lazy[1+2*node].mul=1;
            }
            lazy[node].init=0;
        }
        if(lazy[node].mul!=1)
        {
            tree[node].sum=(tree[node].sum*lazy[node].mul)%mod;
            if(a!=b)
            {
                lazy[node*2].mul=(lazy[node].mul*lazy[node*2].mul)%mod;
                lazy[1+2*node].mul=(lazy[node].mul*lazy[1+2*node].mul)%mod;
                lazy[node*2].add=(lazy[node*2].add*lazy[node].mul)%mod;
                lazy[1+2*node].add=(lazy[1+2*node].add*lazy[node].mul)%mod;
            }
            lazy[node].mul=1;
        }
        if(lazy[node].add!=0)
        {
            tree[node].sum=(tree[node].sum+(lazy[node].add*(b-a+1))%mod)%mod;
            if(a!=b)
            {
                lazy[node*2].add=(lazy[node*2].add+lazy[node].add)%mod;
                lazy[1+2*node].add=(lazy[1+2*node].add+lazy[node].add)%mod;
            }
            lazy[node].add=0;
        }
 
    if(a>b||a>end||b<begin)
        {
            return;
        }
    if(select==1)
    {
        if(a>=begin&&b<=end)
        {
            tree[node].sum=((b-a+1)*val)%mod;
            if(a!=b)
            {
                lazy[node*2].init=val;
                lazy[node*2].add=0;
                lazy[node*2].mul=1;
                lazy[1+2*node].init=val;
                lazy[1+2*node].add=0;
                lazy[1+2*node].mul=1;
            }
            return;
        }
        update_tree(node*2,a,(a+b)/2,begin,end,1,val);
        update_tree(1+2*node,1+(a+b)/2,b,begin,end,1,val);
        tree[node].sum=(tree[2*node].sum+tree[2*node+1].sum)%mod;
    }
    else if(select==2)
    {
        if(a>=begin&&b<=end)
        {
            tree[node].sum=(tree[node].sum+(val*(b-a+1))%mod)%mod;
            if(a!=b)
            {
                lazy[node*2].add=(lazy[node*2].add+val)%mod;
                lazy[1+2*node].add=(lazy[1+2*node].add+val)%mod;
            }
            return;
        }
        update_tree(node*2,a,(a+b)/2,begin,end,2,val);
        update_tree(1+2*node,1+(a+b)/2,b,begin,end,2,val);
        tree[node].sum=(tree[2*node].sum+tree[2*node+1].sum)%mod;
    }
    else
    {
        if(a>=begin&&b<=end)
        {
            tree[node].sum=(tree[node].sum*val)%mod;
            if(a!=b)
            {
                lazy[node*2].mul=(lazy[2*node].mul*val)%mod;
                lazy[1+node*2].mul=(lazy[1+2*node].mul*val)%mod;
                lazy[2*node].add=(lazy[node*2].add*val)%mod;
                lazy[1+2*node].add=(lazy[1+2*node].add*val)%mod;
            }
            return;
        }
        update_tree(node*2,a,(a+b)/2,begin,end,3,val);
        update_tree(1+2*node,1+(a+b)/2,b,begin,end,3,val);
        tree[node].sum=(tree[2*node].sum+tree[2*node+1].sum)%mod;
    }
}
 
lld query_tree(int node,int a,int b,int begin,int end)
{
 
    if(lazy[node].init!=0)
        {
            tree[node].sum=((b-a+1)*lazy[node].init)%mod;
            if(a!=b)
            {
                lazy[node*2].init=lazy[node].init;
                lazy[node*2].add=0;
                lazy[node*2].mul=1;
                lazy[1+2*node].init=lazy[node].init;
                lazy[1+2*node].add=0;
                lazy[1+2*node].mul=1;
            }
            lazy[node].init=0;
        }
          if(lazy[node].mul!=1)
        {
            tree[node].sum=(tree[node].sum*lazy[node].mul)%mod;
            if(a!=b)
            {
                lazy[node*2].mul=(lazy[node].mul*lazy[node*2].mul)%mod;
                lazy[1+2*node].mul=(lazy[node].mul*lazy[1+2*node].mul)%mod;
                lazy[node*2].add=(lazy[node*2].add*lazy[node].mul)%mod;
                lazy[1+2*node].add=(lazy[1+2*node].add*lazy[node].mul)%mod;
            }
            lazy[node].mul=1;
        }
        if(lazy[node].add!=0)
        {
            tree[node].sum=(tree[node].sum+(lazy[node].add*(b-a+1))%mod)%mod;
            if(a!=b)
            {
                lazy[node*2].add=(lazy[node*2].add+lazy[node].add)%mod;
                lazy[1+2*node].add=(lazy[1+2*node].add+lazy[node].add)%mod;
            }
            lazy[node].add=0;
        }
 
    if(a > b || a > end || b < begin) return 0; // Out of range
 
    if(a >= begin && b <= end) // Current segment is totally within range [i, j]
        return tree[node].sum;
 
    lld q1 = query_tree(node*2, a, (a+b)/2, begin, end); // Query left child
    lld q2 = query_tree(1+node*2, 1+(a+b)/2, b, begin, end); // Query right child
 
    lld res = (q1+q2)%mod; // Return final result
 
    return res;
}
 
int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n,q,c,x,y;
    lld val;
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++)
    scanf("%lld",&arr[i]);
    build_tree(1,0,n-1);
    for(int i=0;i<q;i++)
    {
        scanf("%d",&c);
        if(c==1)
        {
            scanf("%d%d%lld",&x,&y,&val);
            update_tree(1,0,n-1,x-1,y-1,2,val);
        }
        else if(c==2)
        {
            scanf("%d%d%lld",&x,&y,&val);
            update_tree(1,0,n-1,x-1,y-1,3,val);
        }
        else if(c==3)
        {
            scanf("%d%d%lld",&x,&y,&val);
            update_tree(1,0,n-1,x-1,y-1,1,val);
        }
        else
        {
            scanf("%d%d",&x,&y);
            lld res=query_tree(1,0,n-1,x-1,y-1);
            printf("%lld\n",res);
        }
    }
    return 0;
}