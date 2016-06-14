#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
const int MAXN = 30000+10;
struct Node{
	int l,r;
	int cnt;
}tree[20*MAXN];
int cur;
int a[MAXN];
int root[MAXN];
int used[40*MAXN];
void init(){	cur=0;	}
inline void PushUp(int node){	
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
	if (x<=mid)
		tree[k].l=update(tree[node].l,l,mid,x,v);
	else
		tree[k].r=update(tree[node].r,mid+1,r,x,v);
	PushUp(k);
	return k;
}
int query(int node,int l,int r,int x){
	if (l==r)
		return tree[node].cnt;
	int mid=(l+r)/2;
	if (mid>=x)
		return tree[tree[node].r].cnt+query(tree[node].l,l,mid,x);
	return query(tree[node].r,mid+1,r,x);
}
int main(){
	int n,q,l,r;
	while (~scanf("%d",&n)){
		init();
		memset(used,0,sizeof(used));
		for (int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		root[0]=build(1,n);
		for (int i=1;i<=n;i++){
			int t=update(root[i-1],1,n,i,1);
			if (used[a[i]]!=0){
				root[i]=update(t,1,n,used[a[i]],-1);
			}
			else
				root[i]=t;
			used[a[i]]=i;
		}
		scanf("%d",&q);
		while (q--){
			scanf("%d%d",&l,&r);
			printf("%d\n",query(root[r],1,n,l));
		}

	}
	return 0;
}