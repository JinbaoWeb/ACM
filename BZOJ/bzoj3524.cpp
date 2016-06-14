//POJ 2104 K-th Number
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=100001;
struct Node{
    int ls,rs;
    int cnt;
}tr[maxn*20];
int cur,rt[maxn];
void init(){
    cur=0;
}
inline void push_up(int o){
    tr[o].cnt=tr[tr[o].ls].cnt+tr[tr[o].rs].cnt;
}
int build(int l,int r){
    int k=cur++;
    if (l==r) {
        tr[k].cnt=0;
        return k;
    }
    int mid=(l+r)>>1;
    tr[k].ls=build(l,mid);
    tr[k].rs=build(mid+1,r);
    push_up(k);
    return k;
}
int update(int o,int l,int r,int pos,int val){
    int k=cur++;
    tr[k]=tr[o];
    if (l==pos&&r==pos){
        tr[k].cnt+=val;
        return k;
    }
    int mid=(l+r)>>1;
    if (pos<=mid) tr[k].ls=update(tr[o].ls,l,mid,pos,val);
    else tr[k].rs=update(tr[o].rs,mid+1,r,pos,val);
    push_up(k);
    return k;
}
int query(int l,int r,int o,int v,int kth){
    if (l==r) return l;
    int mid=(l+r)>>1;
    int res=tr[tr[v].ls].cnt-tr[tr[o].ls].cnt;
    if (kth<=res) return query(l,mid,tr[o].ls,tr[v].ls,kth);
    else return query(mid+1,r,tr[o].rs,tr[v].rs,kth-res);
}
int b[maxn];
int sortb[maxn];
int main()
{
    int n,m;
    int T;
    //scanf("%d",&T);
    //while (T--){
    while (~scanf("%d%d",&n,&m)){
        init();
        for (int i=1;i<=n;i++){
            scanf("%d",&b[i]);
            sortb[i]=b[i];
        }
        sort(sortb+1,sortb+1+n);
        int cnt=1;
        for (int i=2;i<=n;i++){
            if (sortb[i]!=sortb[cnt]){
                sortb[++cnt]=sortb[i];
            }
        }
        rt[0]=build(1,cnt);
        for (int i=1;i<=n;i++){
            int p=lower_bound(sortb+1,sortb+cnt+1,b[i])-sortb;
            rt[i]=update(rt[i-1],1,cnt,p,1);
        }
        for (int i=0;i<m;i++){
            int a,b,k;
            scanf("%d%d%d",&a,&b,&k);
            int idx=query(1,cnt,rt[a-1],rt[b],k);
            printf("%d\n",sortb[idx]);
        }
    }
    return 0;
}