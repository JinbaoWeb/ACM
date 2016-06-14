#include <iostream>
#include <stdio.h>
using namespace std;
const int MAXN = 100000+10;
struct Node{
	int l,r;
	int sum;
	int flag;
}tree[4*MAXN];
void build(int node,int l,int r){
	tree[node].l=l,tree[node].r=r;
	tree[node].flag=0;
	if (l==r){
		tree[node].sum=1;
		return;
	}
	int mid=(l+r)/2;
	build(node*2,l,mid);
	build(node*2+1,mid+1,r);
	tree[node].sum=tree[node*2].sum+tree[node*2+1].sum;
}
void PushDown(int node){
	if (tree[node].flag>0){
		tree[node*2].flag=tree[node*2+1].flag=tree[node].flag;
		tree[node*2].sum=tree[node].flag*(tree[node*2].r-tree[node*2].l+1);
		tree[node*2+1].sum=tree[node].flag*(tree[node*2+1].r-tree[node*2+1].l+1);
		tree[node].flag=0;
	}
}
void update(int node,int l,int r,int v){
	if (l<=tree[node].l && tree[node].r<=r){
		tree[node].flag=v;
		tree[node].sum=(tree[node].r-tree[node].l+1)*v;
		return;
	}
	PushDown(node);
	if (tree[node].l==tree[node].r)
		return;
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
int main(){
	int t,n,m,x,y,v;
	scanf("%d",&t);
	for (int i=1;i<=t;i++){
		scanf("%d",&n);
		build(1,1,n);
		scanf("%d",&m);
		while (m--){
			scanf("%d%d%d",&x,&y,&v);
			update(1,x,y,v);
		}
		printf("Case %d: The total value of the hook is %d.\n",i,tree[1].sum );
	}

	return 0;
}