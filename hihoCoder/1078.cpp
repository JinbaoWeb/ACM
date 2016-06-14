#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 100000+10;
struct Node{
	int l,r;
	int flag;
	ll sum;
}tree[4*MAXN];
void build(int node,int l,int r){
	tree[node].l=l,tree[node].r=r,tree[node].flag=0;
	if (l==r){
		scanf("%lld",&tree[node].sum);
		return;
	}
	int mid=(l+r)/2;
	build(node*2,l,mid);
	build(node*2+1,mid+1,r);
	tree[node].sum=tree[node*2].sum+tree[node*2+1].sum;
}
void PushDown(int node){
	if (tree[node].flag){
		tree[node*2].flag=tree[node*2+1].flag=tree[node].flag;
		tree[node].flag=0;
		tree[node*2].sum=(tree[node*2].r-tree[node*2].l+1)*tree[node*2].flag;
		tree[node*2+1].sum=(tree[node*2+1].r-tree[node*2+1].l+1)*tree[node*2+1].flag;
	}
}
void update(int node,int l,int r,int v){
	if (l<=tree[node].l && tree[node].r<=r){
		tree[node].flag=v;
		tree[node].sum=v*(tree[node].r-tree[node].l+1);
		return;
	}
	if (tree[node].l==tree[node].r)
		return;
	PushDown(node);
	int mid=(tree[node].l+tree[node].r)/2;
	if (r<=mid)
		update(node*2,l,r,v);
	else if (mid<l)
		update(node*2+1,l,r,v);
	else{
		update(node*2,l,mid,v);
		update(node*2+1,mid+1,r,v);
	}
	tree[node].sum=tree[node*2].sum+tree[node*2+1].sum;
}
ll query(int node,int l,int r){
	if (l<=tree[node].l && tree[node].r<=r){
		return tree[node].sum;
	}
	PushDown(node);
	int mid=(tree[node].l+tree[node].r)/2;
	if (r<=mid)
		return query(node*2,l,r);
	else if (mid<l)
		return query(node*2+1,l,r);
	else{
		return query(node*2,l,mid)+query(node*2+1,mid+1,r);
	}
}
int main(){
	int n,q,L,R,v,p;
	while (~scanf("%d",&n)){
		build(1,1,n);
		scanf("%d",&q);
		while (q--){
			scanf("%d",&p);
			if (p==1){
				scanf("%d%d%d",&L,&R,&v);
				update(1,L,R,v);
			}
			else{
				scanf("%d%d",&L,&R);
				printf("%lld\n",query(1,L,R));
			}
		}
	}
	return 0;
}