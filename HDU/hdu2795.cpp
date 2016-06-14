#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200000+10;
struct Node{
	int l,r;
	int num;
}tree[666666];
int h,w,n;
void build(int node,int l,int r){
	tree[node].l=l,tree[node].r=r,tree[node].num=w;
	if (l==r)
		return;
	int mid=(l+r)/2;
	build(node*2,l,mid);
	build(node*2+1,mid+1,r);
}
int query(int node,int v){
	if (tree[node].num<v)
		return -1;
	if (tree[node].l==tree[node].r){
		tree[node].num-=v;
		return tree[node].l;
	}
	int temp=query(node*2,v);
	if (temp==-1)
		temp=query(node*2+1,v);
	if (temp!=-1)
		tree[node].num=max(tree[node*2].num,tree[node*2+1].num);
	return temp;
}
int main(){
	int x;
	while (scanf("%d%d%d",&h,&w,&n)!=-1){
		if(h>200000)	
			h=200000;
		build(1,1,h);
		for (int i=0;i<n;i++){
			scanf("%d",&x);
			int ans=query(1,x);
			printf("%d\n", ans);
		}
	}
	return 0;
}