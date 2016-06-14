#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int MAXN = 200000;
struct Node{
	int l,r;
	int max;
}tree[4*MAXN];
int Max(int a,int b){
	return a>b?a:b;
}
void build(int node,int l,int r){
	tree[node].max=0;
	tree[node].l=l,tree[node].r=r;
	if (l==r)
		return;
	build(node*2,l,(l+r)/2);
	build(node*2+1,(l+r)/2+1,r);
}
void update(int node,int l,int r,int v){
	if (r<tree[node].l || tree[node].r<l)
		return;
	if (l==tree[node].l && tree[node].r==r){
		//printf("%d %d\n",l,r );
		tree[node].max=v;
		return;
	}
	if (tree[node].l==tree[node].r)
		return;
	update(node*2,l,r,v);
	update(node*2+1,l,r,v);	
	tree[node].max=Max(tree[node*2].max,tree[node*2+1].max);
}
int query(int node,int l,int r){
	//printf("%d %d\n",l,r );
	if (r<tree[node].l || tree[node].r<l)
		return 0;
	if (l<=tree[node].l && tree[node].r<=r){
		return tree[node].max;
	}
	if (tree[node].l==tree[node].r)
		return 0;
	return Max(query(node*2,l,r),query(node*2+1,l,r));
	
}
void Debug(){
	for (int i=0;i<20;i++)
		printf("%d ",tree[i].max);
	printf("\n");

}
int main(){
	int m,d,x;
	char s[2];
	while (~scanf("%d%d",&m,&d)){
		build(1,1,MAXN);
		int t=0,k=0;
		//Debug();
		while (m--){
			scanf("%s%d",s,&x);
			if (strcmp(s,"A")==0){
				k++;
				x+=t;
				x%=d;
				update(1,k,k,x);
			}
			else{
				t=query(1,k-x+1,k);
				printf("%d\n",t);
			}
			//Debug();
		}
	}

	return 0;
}