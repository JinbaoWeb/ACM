#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 100000+10;
struct Node{
	int l,r;
	ll sum,set,add;
}tree[4*MAXN];
void build(int node,int l,int r){
	tree[node].l=l,tree[node].r=r,tree[node].set=0,tree[node].add=0;
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
	if (tree[node].set!=0){
		tree[node*2].set=tree[node*2+1].set=tree[node].set;
		tree[node*2].add=tree[node*2+1].add=0;
		tree[node*2].sum=(tree[node*2].r-tree[node*2].l+1)*tree[node].set;
		tree[node*2+1].sum=(tree[node*2+1].r-tree[node*2+1].l+1)*tree[node].set;
		tree[node].set=0;
	}
	if (tree[node].add!=0){
		tree[node*2].add+=tree[node].add;
		tree[node*2+1].add+=tree[node].add;
		tree[node*2].sum+=(tree[node*2].r-tree[node*2].l+1)*tree[node].add;
		tree[node*2+1].sum+=(tree[node*2+1].r-tree[node*2+1].l+1)*tree[node].add;
		tree[node].add=0;
	}
}

void update(int node,int l,int r,ll v,int p){
	if (l<=tree[node].l && tree[node].r<=r){
		if (p==0){
			tree[node].add+=v;
			tree[node].sum+=(tree[node].r-tree[node].l+1)*v;
		}
		else{
			tree[node].set=v;
			tree[node].add=0;
			tree[node].sum=(tree[node].r-tree[node].l+1)*v;
		}
		return;
	}
	PushDown(node);
	int mid=(tree[node].l+tree[node].r)/2;
	if (r<=mid)
		update(node*2,l,r,v,p);
	else if (mid<l)
		update(node*2+1,l,r,v,p);
	else{
		update(node*2,l,mid,v,p);
		update(node*2+1,mid+1,r,v,p);
	}
	tree[node].sum=tree[node*2].sum+tree[node*2+1].sum;
}
int main(){
	int n,q,p,L,R;
	ll v;
	while (~scanf("%d%d",&n,&q)){
		build(1,1,n+1);
		while (q--){
			scanf("%d%d%d%lld",&p,&L,&R,&v);
			L++,R++;
			update(1,L,R,v,p);
			printf("%lld\n",tree[1].sum );
		}
	}
	return 0;
}