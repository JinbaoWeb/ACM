#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAXN = 100000+5;
struct Node{
	int l,r;
	int msum,lsum,rsum;
}tree[4*MAXN];
int a[MAXN];
void PushUp(int node){
	tree[node].lsum=tree[node*2].lsum;
	tree[node].rsum=tree[node*2+1].rsum;
	tree[node].msum=max(tree[node*2].msum,tree[node*2+1].msum);
	if (a[tree[node*2].r]<a[tree[node*2+1].l]){
		tree[node].msum=max(tree[node].msum,tree[node*2].rsum+tree[node*2+1].lsum);
		if (tree[node*2].lsum==tree[node*2].r-tree[node*2].l+1)
			tree[node].lsum+=tree[node*2+1].lsum;
		if (tree[node*2+1].lsum==tree[node*2+1].r-tree[node*2+1].l+1)
			tree[node].rsum+=tree[node*2].rsum;
	}
}
void build(int node,int l,int r){
	tree[node].l=l,tree[node].r=r;
	if (l==r){
		tree[node].msum=tree[node].lsum=tree[node].rsum=1;
		return;
	}
	build(node*2,l,(l+r)/2);
	build(node*2+1,(l+r)/2+1,r);
	PushUp(node);
}
void update(int node,int x,int v){
	if (tree[node].l==tree[node].r && tree[node].l==x){
		a[x]=v;
		return;
	}
	int mid=(tree[node].l+tree[node].r)/2;
	if (x<=mid)
		update(node*2,x,v);
	else
		update(node*2+1,x,v);
	PushUp(node);
}
int queryR(int node,int l,int r){
	if (r-l+1>=tree[node].rsum)
		return tree[node].rsum;
	return r-l+1;
}
int queryL(int node,int l,int r){
	if (r-l+1>=tree[node].lsum)
		return tree[node].lsum;
	return r-l+1;
}
int query(int node,int l,int r){
	if (l==tree[node].l && tree[node].r==r){
		return tree[node].msum;
	}
	int mid=(tree[node].l+tree[node].r)/2;
	if (r<=mid)
		return query(node*2,l,r);
	else if (mid<l)
		return query(node*2+1,l,r);
	else{
		int ans=0;
		if (a[tree[node*2].r]<a[tree[node*2+1].l])
			ans=max(ans,queryR(node*2,l,mid)+queryL(node*2+1,mid+1,r));
		ans=max(ans,query(node*2,l,mid));
		ans=max(ans,query(node*2+1,mid+1,r));
		return ans;
	}
}
int main(){
	int t,n,m;
	int x,y;
	char s[2];
	scanf("%d",&t);
	while (t--){
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		build(1,1,n);
		while (m--){
			scanf("%s%d%d",s,&x,&y);
			if (s[0]=='Q')
				printf("%d\n",query(1,x+1,y+1));
			else
				update(1,x+1,y);
		}
	}

	return 0;
}