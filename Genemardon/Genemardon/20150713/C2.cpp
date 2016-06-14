#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int MAXN = 50000+5;
struct Node{
	int l,r;
	int sum;
}tree[4*MAXN];
int ans[MAXN];
void build(int node,int l,int r){
	tree[node].l=l,tree[node].r=r;
	if (l==r){
		tree[node].sum=1;
		return;
	}
	int mid=(l+r)/2;
	build(node*2,l,mid);
	build(node*2+1,mid+1,r);
	tree[node].sum=tree[node*2].sum+tree[node*2+1].sum;
}
void update(int node,int i,int v){
	if (tree[node].l==tree[node].r){
		ans[i]=tree[node].l;
		tree[node].sum=0;
		return;
	}
	if (tree[node*2].sum>=v){
		update(node*2,i,v);
	}
	else{
		update(node*2+1,i,v-tree[node*2].sum);
	}
	tree[node].sum=tree[node*2].sum+tree[node*2+1].sum;

}
int main(){
	int n,m,x;
	while (~scanf("%d",&n)){
		build(1,1,n);
		for (int i=1;i<=n;i++){
			scanf("%d",&x);
			update(1,i,x);
		}
		scanf("%d",&m);
		for (int i=1;i<m;i++){
			scanf("%d",&x);
			printf("%d ",ans[x] );
		}
		scanf("%d",&x);
		printf("%d\n",ans[x] );
	}
	return 0;
}