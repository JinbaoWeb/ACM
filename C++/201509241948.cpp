#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100011;
struct Node{
    int l,r;
    int cnt;
}tree[20*MAXN];
int cur;    //记录节点的个数
int root[20*MAXN]; //保存每一次更新的位置
int a[20*MAXN],b[20*MAXN];
void init(){
    cur=0;
}
void PushUp(int node){
    tree[node].cnt=tree[tree[node].l].cnt+tree[tree[node].r].cnt;
}
int build(int l,int r){
    int k=cur++;
    if (l==r){
        tree[k].cnt=0;
        return k;
    }
    int mid=(l+r)/2;
    tree[k].l=build(l,mid);
    tree[k].r=build(mid+1,r);
    PushUp(k);
    return k;
}
int update(int node,int l,int r,int x,int v){
    int k=cur++;
    tree[k]=tree[node];
    if (l==x && r==x){
        tree[k].cnt+=v;
        return k;
    }
    int mid=(l+r)/2;
    if (mid>=x)
        tree[k].l=update(tree[node].l,l,mid,x,v);
    else
        tree[k].r=update(tree[node].r,mid+1,r,x,v);
    PushUp(k);
    return k;
}
int query(int node1,int node2,int l,int r,int k){   //node1表示前一个版本，node2表示后一个版本
    if (l==r)
        return l;
    int mid=(l+r)/2;
    int res=tree[tree[node2].l].cnt-tree[tree[node1].l].cnt;
    if (res>=k)
        return query(tree[node1].l,tree[node2].l,l,mid,k);
    return query(tree[node1].r,tree[node2].r,mid+1,r,k-res);
}
int main(){
    int n,m;
    while (~scanf("%d%d",&n,&m)){
        init();
        for (int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            b[i]=a[i];
        }
        sort(b+1,b+n+1);
        int tmp=1;
        for (int i=2;i<=n;i++){
            if (b[i]!=b[tmp]){
                b[++tmp]=b[i];
            }
        }
        //int tmp=unique(b+1,b+n+1)-b;
        root[0]=build(1,tmp);
        for (int i=1;i<=n;i++){
            int temp=lower_bound(b+1,b+tmp+1,a[i])-b;
            root[i]=update(root[i-1],1,tmp,temp,1);
        }
        for (int i=0;i<m;i++){
            int l,r,k;
            scanf("%d%d%d",&l,&r,&k);
            int temp=query(root[l-1],root[r],1,tmp,k);
            cout<<b[temp]<<endl;
        }
    }

    return 0;
}