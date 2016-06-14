#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000+10;
struct Node{
	int l,r;
	int flag;
	int lsum1,rsum1,msum1;	//black
	int lsum2,rsum2,msum2;	//white
}tree[4*MAXN];
void PushUp(int node){
	if (tree[node*2].lsum1==(tree[node*2].r-tree[node*2].l+1))
		tree[node].lsum1=tree[node*2].lsum1+tree[node*2+1].lsum1;
	else
		tree[node].lsum1=tree[node*2].lsum1;
	if (tree[node*2+1].rsum1==(tree[node*2+1].r-tree[node*2+1].l+1))
		tree[node].rsum1=tree[node*2].rsum1+tree[node*2+1].rsum1;
	else
		tree[node].rsum1=tree[node*2+1].rsum1;
	tree[node].msum1=max(tree[node*2].rsum1+tree[node*2+1].lsum1,max(tree[node*2].msum1,tree[node*2+1].msum1));

	if (tree[node*2].lsum2==(tree[node*2].r-tree[node*2].l+1))
		tree[node].lsum2=tree[node*2].lsum2+tree[node*2+1].lsum2;
	else
		tree[node].lsum2=tree[node*2].lsum2;
	if (tree[node*2+1].rsum2==(tree[node*2+1].r-tree[node*2+1].l+1))
		tree[node].rsum2=tree[node*2].rsum2+tree[node*2+1].rsum2;
	else
		tree[node].rsum2=tree[node*2+1].rsum2;
	tree[node].msum2=max(tree[node*2].rsum2+tree[node*2+1].lsum2,max(tree[node*2].msum2,tree[node*2+1].msum2));
}
void PushDown(int node){
	if (tree[node].flag){
		tree[node*2].flag=(tree[node*2].flag+1)%2;
		tree[node*2+1].flag=(tree[node*2+1].flag+1)%2;
		swap(tree[node*2].msum1,tree[node*2].msum2);
		swap(tree[node*2].lsum1,tree[node*2].rsum2);
		swap(tree[node*2].rsum1,tree[node*2].lsum2);

		swap(tree[node*2+1].msum1,tree[node*2+1].msum2);
		swap(tree[node*2+1].lsum1,tree[node*2+1].rsum2);
		swap(tree[node*2+1].rsum1,tree[node*2+1].lsum2);

		tree[node].flag=0;
	}
}
void build(int node,int l,int r){
	tree[node].l=l,tree[node].r=r,tree[node].flag=0;
	if (l==r){
		int x;
		scanf("%d",&x);
		if (x==0){
			tree[node].msum2=tree[node].lsum2=tree[node].rsum2=1;
			tree[node].msum1=tree[node].lsum1=tree[node].rsum1=0;
		}
		else{
			tree[node].msum1=tree[node].lsum1=tree[node].rsum1=1;
			tree[node].msum2=tree[node].lsum2=tree[node].rsum2=0;
		}
		return;
	}
	int mid=(l+r)/2;
	build(node*2,l,mid);
	build(node*2+1,mid+1,r);
	PushUp(node);
}
void update(int node,int l,int r){
	if (l<=tree[node].l && tree[node].r<=r){
		tree[node].flag=(tree[node].flag+1)%2;
		swap(tree[node].msum1,tree[node].msum2);
		swap(tree[node].lsum1,tree[node].rsum2);
		swap(tree[node].rsum1,tree[node].lsum2);
		return;
	}
	PushDown(node);
	int mid=(tree[node].l+tree[node].r)/2;
	if (r<=mid)
		update(node*2,l,r);
	else if (mid<l)
		update(node*2+1,l,r);
	else{
		update(node*2,l,mid);
		update(node*2+1,mid+1,r);
	}
	PushUp(node);
}
int query(int node,int l,int r){
	if (l==tree[node].l && tree[node].r==r){
		return tree[node].msum1;
	}
	PushDown(node);
	int mid=(tree[node].l+tree[node].r)/2;
	if (r<=mid)
		return query(node*2,l,r);
	else if (mid<l)
		return query(node*2+1,l,r);
	else{
		int ans=max(query(node*2,l,mid),query(node*2+1,mid+1,r));
		int temp=min(mid-l+1,tree[node*2].rsum1)+min(r-mid,tree[node*2+1].lsum1);
		return max(ans,temp);
	}
}
int main(){
	int n,m;
	int op,l,r;
	while (~scanf("%d",&n)){
		build(1,1,n);
		scanf("%d",&m);
		for (int i=0;i<m;i++){
			scanf("%d%d%d",&op,&l,&r);
			if (op==0)
				printf("%d\n",query(1,l,r));
			else{
				update(1,l,r);
			}
		}
	}
	return 0;
}