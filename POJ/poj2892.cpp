#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
const int MAXN = 50000+10;
struct Node{
	int l,r;
	int lsum,rsum;
}tree[4*MAXN];
void PushUp(int node){
	if (tree[node*2].lsum==tree[node*2].rsum &&  tree[node*2].lsum==tree[node*2].r-tree[node*2].l+1)
		tree[node].lsum=tree[node*2].lsum+tree[node*2+1].lsum;
	else
		tree[node].lsum=tree[node*2].lsum;
	if (tree[node*2+1].lsum==tree[node*2+1].rsum &&  tree[node*2+1].lsum==tree[node*2+1].r-tree[node*2+1].l+1)
		tree[node].rsum=tree[node*2].rsum+tree[node*2+1].rsum;
	else
		tree[node].rsum=tree[node*2+1].rsum;
}
void build(int node,int l,int r){
	tree[node].l=l,tree[node].r=r;
	tree[node].lsum=tree[node].rsum=tree[node].r-tree[node].l+1;
	if (l==r){
		return;
	}
	int mid=(l+r)/2;
	build(node*2,l,mid);
	build(node*2+1,mid+1,r);
}
void update(int node,int x,int v){
	if (tree[node].l==tree[node].r && tree[node].l==x){
		tree[node].lsum=tree[node].rsum=v;
		return;
	}
	int mid=(tree[node].l+tree[node].r)/2;
	if (x<=mid)
		update(node*2,x);
	else
		update(node*2+1,x);
	PushUp(node);
}
int query(int node,int x){
	if (tree[node].lsum+tree[node].l-1>=x){
		return tree[node].lsum;
	}
	else if (tree[node].r-tree[node].rsum+1<=x){
		return tree[node].rsum;
	}
	else{
		int mid=(tree[node].l+tree[node].r)/2;
		if (x<=mid)
			return query(node*2,x);
		else
			return query(node*2+1,x);
	}
}
int main(){


	return 0;
}