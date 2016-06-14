#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int MAXN = 1000000;
struct Node{
	int l,r;
	int num;
	int sum;
}tree[4*MAXN];
void build(int node,int l,int r){
	tree[node].l=l,tree[node].r=r;
	if (l==r){
		tree[node].sum=0;
		tree[node].num=0;
		return;
	}
	build(node*2,l,(l+r)/2);
	build(node*2+1,(l+r)/2+1,r);
	tree[node].sum=tree[node*2].sum+tree[node*2+1].sum;
}
void update(int node,int x,int v){
	if (node>x)
		return;
	if (node==x){
		tree[node].sum+=v;
		tree[node].num=v;
		return;
	}
	update(node*2,x,v);
	update(node*2+1,x,v);
	tree[node].sum=tree[node*2].sum+tree[node*2+1].sum;
}
int main(){
	int n,u,v,m,x;
	char str[2];
	while (scanf("%d",&n)!=EOF){
		for (int i=0;i<n-1;i++){
			scanf("%d%d",&u,&v);
			update(1,u,1);
			update(1,v,1);
		}
		scanf("%d",&m);
		while (m--){
			scanf("%s",str);
			if (str[0]=='Q'){
				scanf("%d",&x);
				printf("%d\n",tree[x].sum );
			}
			else{
				scanf("%d",&x);
				if (tree[x].num==1)
					update(1,x,0);
				else
					update(1,x,1);
			}
		}
	}

	return 0;
}