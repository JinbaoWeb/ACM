#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;
#define N 30005
#define ll long long

struct Node{
    int l,r;
    ll sum,v;
    bool lazy;

    void mark(ll v){
        this->v=v;
        lazy=true;
        sum=v*(r-l+1);
    }
}seg[N<<2];

ll val[N],oldSum,curSum,segSum;
int n,m;

void build(int l,int r,int id){
    seg[id].l=l;
    seg[id].r=r;
    seg[id].lazy=false;
    if(l==r){
        seg[id].sum=val[l];
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,id<<1);
    build(mid+1,r,id<<1|1);
    seg[id].sum=seg[id<<1].sum+seg[id<<1|1].sum;
}

void update(int l,int r,int id,ll average){

    if(seg[id].l==l && seg[id].r==r){
        seg[id].mark(average);
        return;
    }

    if(seg[id].lazy){
        seg[id<<1].mark(seg[id].v);
        seg[id<<1|1].mark(seg[id].v);
        seg[id].lazy=false;
    }

    int mid=(seg[id].l+seg[id].r)>>1;
    if(r<=mid)
        update(l,r,id<<1,average);
    else if(l>mid)
        update(l,r,id<<1|1,average);
    else{
        update(l,mid,id<<1,average);
        update(mid+1,r,id<<1|1,average);
    }
    seg[id].sum=seg[id<<1].sum+seg[id<<1|1].sum;
}

ll Search(int l,int r,int id){
    if(seg[id].l>=l && seg[id].r<=r)
        return seg[id].sum;
    if(seg[id].lazy){

        seg[id<<1].mark(seg[id].v);
        seg[id<<1|1].mark(seg[id].v);

        seg[id].lazy=false;
    }
    int mid=(seg[id].l+seg[id].r)>>1;
    if(r<=mid)
        return Search(l,r,id<<1);
    else if(l>mid)
        return Search(l,r,id<<1|1);
    else
        return Search(l,mid,id<<1)+Search(mid+1,r,id<<1|1);
}

void query(int id){
    if(seg[id].l==seg[id].r){
        if(seg[id].l!=1)
            putchar(' ');
        printf("%lld",seg[id].sum);
        return;
    }
    if(seg[id].lazy){

        seg[id<<1].mark(seg[id].v);
        seg[id<<1|1].mark(seg[id].v);

        seg[id].lazy=false;
    }
    query(id<<1);
    query(id<<1|1);
}
ll myceil(ll sum,int n){
    if(sum>=0)
        return sum/n+(sum%n!=0);
    else
        return sum/n;
}

ll myfloor(ll sum,int n){
    if(sum>=0)
        return sum/n;
    else
        return sum/n-(sum%n!=0);
}
int main()
{

    while(scanf("%d%d",&n,&m)!=EOF){
        oldSum=0;
        for(int i=1;i<=n;i++){
            scanf("%lld",&val[i]);
            oldSum+=val[i];
        }
        build(1,n,1);

        int l,r;
        ll average;

        while(m--){
            scanf("%d%d",&l,&r);
            curSum=Search(1,n,1);
            segSum=Search(l,r,1);
            if(curSum<=oldSum)
                average=myceil(segSum,r-l+1);
            else
                average=myfloor(segSum,r-l+1);
            printf("%d\n",average);
            update(l,r,1,average);
        }
        query(1);
        puts("");puts("");
    }
    return 0;
}