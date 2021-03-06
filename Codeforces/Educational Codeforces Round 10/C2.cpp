#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
#define lz 2*u,l,mid
#define rz 2*u+1,mid+1,r
const int maxn=3000010;
int sum[2*maxn];
int flag[2*maxn];
int X[2*maxn];
int a[maxn];
int b[maxn];
struct Node
{
    int lx, rx, y;
    int s;
    Node(){};
    Node(int lx_, int rx_, int y_, int s_)
    {
        lx=lx_, rx=rx_, y=y_, s=s_;
    }
    bool operator <(const Node &S) const
    {
        return y<S.y;
    }
}line[maxn];

int find(int tmp, int n)
{
    int l=1, r=n, mid;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(X[mid]==tmp) return mid;
        else if(X[mid]<tmp) l=mid+1;
        else r=mid-1;
    }
}

void push_up(int u, int l, int r)
{
    if(flag[u]) sum[u]=X[r+1]-X[l];
    else if(l==r) sum[u]=0;
    else sum[u]=sum[2*u]+sum[2*u+1];
}

void Update(int u, int l, int r, int tl, int tr, int c)
{
    if(tl<=l&&r<=tr)
    {
        flag[u]+=c;
        push_up(u,l,r);
        return ;
    }
    int mid=(l+r)>>1;
    if(tr<=mid) Update(lz,tl,tr,c);
    else if(tl>mid) Update(rz,tl,tr,c);
    else
    {
        Update(lz,tl,mid,c);
        Update(rz,mid+1,tr,c);
    }
    push_up(u,l,r);
}
int main()
{
    int n,m; 
    while (~scanf("%d%d",&n,&m)){
        int num=0;
        memset(flag,0,sizeof(flag));
        memset(sum,0,sizeof(sum));
        for (int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            b[a[i]]=i;
        }
        for (int i=0;i<m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            int ix=b[x],iy=b[y];
            if (ix>iy) swap(ix,iy);
            int x1=0,x2=ix,y1=iy-1,y2=n;
            line[++num]=Node(x1,x2,y1,1);
            X[num]=x1;
            line[++num]=Node(x1,x2,y2,-1);
            X[num]=x2;
        }
        sort(X+1,X+num+1);
        sort(line+1,line+num+1);
        int k=1;
        for(int i=2; i<=num; i++)
            if(X[i]!=X[i+1]) X[++k]=X[i];
        ll ans=0;
        for(int i=1; i<num; i++)
        {
            int l=find(line[i].lx,k);
            int r=find(line[i].rx,k)-1;
            Update(1,1,k,l,r,line[i].s);
            ans+=1LL*sum[1]*(line[i+1].y-line[i].y);
        }
        ll temp=1LL*n*(n+1)/2;
        ans=temp-ans;
        cout<<ans<<endl;
    }
    return 0;
}