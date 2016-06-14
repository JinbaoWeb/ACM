#include <bits/stdc++.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
const int MAXN = 2000+10;
#define eps 1e-6
struct Node{
	int l,r;
	double Max;
};
struct Node2{
	int l,r;
	Node subtree[4*MAXN];
}tree[4*MAXN];
void buildsubtree(int id,int node,int l,int r){
	tree[id].subtree[node].l=l,tree[id].subtree[node].r=r,tree[id].subtree[node].Max=-1;
	if (l==r)
		return;
	int mid=(l+r)/2;
	buildsubtree(id,node*2,l,mid);
	buildsubtree(id,node*2+1,mid+1,r);
}
void build(int node,int l,int r,int ll,int rr){
	tree[node].l=l,tree[node].r=r;
	buildsubtree(node,1,ll,rr);
	if (l==r)
		return;
	int mid=(l+r)/2;
	build(node*2,l,mid,ll,rr);
	build(node*2+1,mid+1,r,ll,rr);
}
void updatesubtree(int id,int node,int x,double v){
	if (tree[id].subtree[node].l==x && tree[id].subtree[node].r==x){
		tree[id].subtree[node].Max=max(tree[id].subtree[node].Max,v);
		return;
	}
	int mid=(tree[id].subtree[node].l+tree[id].subtree[node].r)/2;
	if (x<=mid)
		updatesubtree(id,node*2,x,v);
	else
		updatesubtree(id,node*2+1,x,v);
	tree[id].subtree[node].Max=max(tree[id].subtree[node*2].Max,tree[id].subtree[node*2+1].Max);
}
void update(int node,int l,int r,double v){
	updatesubtree(node,1,r,v);
	if (tree[node].l==tree[node].r && tree[node].l==l){
		return;
	}
	int mid=(tree[node].l+tree[node].r)/2;
	if (l<=mid)
		update(node*2,l,r,v);
	else
		update(node*2+1,l,r,v);
}
double querysubtree(int id,int node,int l,int r){
	if (l<=tree[id].subtree[node].l && tree[id].subtree[node].r<=r){
		return tree[id].subtree[node].Max;
	}
	int mid=(tree[id].subtree[node].l+tree[id].subtree[node].r)/2;
	if (r<=mid)
		return querysubtree(id,node*2,l,r);
	else if (mid<l)
		return querysubtree(id,node*2+1,l,r);
	else{
		return max(querysubtree(id,node*2,l,mid),querysubtree(id,node*2+1,mid+1,r));
	}
}
double query(int node,int l,int r,int ll,int rr){
	if (l<=tree[node].l && tree[node].r<=r){
		return querysubtree(node,1,ll,rr);
	}
	int mid=(tree[node].l+tree[node].r)/2;
	if (r<=mid)
		return query(node*2,l,r,ll,rr);
	else if (mid<l)
		return query(node*2+1,l,r,ll,rr);
	else{
		return max(query(node*2,l,mid,ll,rr),query(node*2+1,mid+1,r,ll,rr));
	}
}
int main(){
	int n;
	char s[2];
	int l,r,ll,rr;
	double v,temp;
	while (~scanf("%d",&n)){
		if (n==0)
			break;
		build(1,100,200,0,1000);
		for (int i=0;i<n;i++){
			scanf("%s",s);
			if (s[0]=='I'){
				scanf("%d%lf%lf",&l,&temp,&v);
				r=temp*10;
				update(1,l,r,v);
			}
			else{
				scanf("%d%d%lf%lf",&l,&r,&v,&temp);
				ll=v*10;
				rr=temp*10;
				if (l>r)
					swap(l,r);
				if (ll>rr)
					swap(ll,rr);
				double ans=query(1,l,r,ll,rr);
				if (ans<0)
					printf("-1\n");
				else
					printf("%.1f\n",ans );
			}
		}
	}
	return 0;
}