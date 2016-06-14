#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAXN = 100000+5;
typedef long long ll;
#define MOD 10007
struct Node{
	int l,r;
	ll sum,sum2,sum3;
	int add,mul;
}tree[4*MAXN];
void build(int node,int l,int r){
	tree[node].l=l,tree[node].r=r;
	tree[node].add=0,tree[node].mul=1;
	if (l==r){
		tree[node].sum=tree[node].sum2=tree[node].sum3=0;
		return;
	}
	build(node*2,l,(l+r)/2);
	build(node*2+1,(l+r)/2+1,r);
	tree[node].sum=(tree[node*2].sum+tree[node*2+1].sum)%MOD;
	tree[node].sum2=(tree[node*2].sum2+tree[node*2+1].sum2)%MOD;
	tree[node].sum3=(tree[node*2].sum3+tree[node*2+1].sum3)%MOD;
}
void PushDown(int node){
	if (tree[node].add==0 && tree[node].mul==1)
		return;

	tree[node*2].sum3=(tree[node].mul*tree[node].mul%MOD*tree[node].mul%MOD*tree[node*2].sum3%MOD + 3*tree[node].mul*tree[node].mul%MOD*tree[node].add%MOD*tree[node*2].sum2%MOD + 3*tree[node].mul*tree[node].add%MOD*tree[node].add%MOD*tree[node*2].sum%MOD + (tree[node*2].r-tree[node*2].l+1)*tree[node].add%MOD*tree[node].add%MOD*tree[node].add%MOD)%MOD;
	tree[node*2].sum2=(tree[node*2].sum2*tree[node].mul%MOD*tree[node].mul%MOD + 2*tree[node].add*tree[node].mul%MOD*tree[node*2].sum%MOD + (tree[node*2].r-tree[node*2].l+1)*tree[node].add%MOD*tree[node].add%MOD)%MOD;
	tree[node*2].sum=(tree[node*2].sum*tree[node].mul + tree[node].add*(tree[node*2].r-tree[node*2].l+1)%MOD)%MOD;

	tree[node*2+1].sum3=(tree[node].mul*tree[node].mul%MOD*tree[node].mul*tree[node*2+1].sum3%MOD + 3*tree[node].mul*tree[node].mul%MOD*tree[node].add%MOD*tree[node*2+1].sum2%MOD + 3*tree[node].mul*tree[node].add%MOD*tree[node].add%MOD*tree[node*2+1].sum%MOD + (tree[node*2+1].r-tree[node*2+1].l+1)*tree[node].add%MOD*tree[node].add%MOD*tree[node].add%MOD)%MOD;
	tree[node*2+1].sum2=(tree[node*2+1].sum2*tree[node].mul%MOD*tree[node].mul%MOD + 2*tree[node].add*tree[node].mul%MOD*tree[node*2+1].sum%MOD + (tree[node*2+1].r-tree[node*2+1].l+1)*tree[node].add%MOD*tree[node].add%MOD)%MOD;
	tree[node*2+1].sum=(tree[node*2+1].sum*tree[node].mul%MOD + tree[node].add*(tree[node*2+1].r-tree[node*2+1].l+1)%MOD)%MOD;

	tree[node*2].mul=(tree[node*2].mul*tree[node].mul)%MOD;
	tree[node*2].add=(tree[node*2].add*tree[node].mul%MOD+tree[node].add)%MOD;

	tree[node*2+1].mul=(tree[node*2+1].mul*tree[node].mul)%MOD;
	tree[node*2+1].add=(tree[node*2+1].add*tree[node].mul%MOD+tree[node].add)%MOD;

	tree[node].add=0;
	tree[node].mul=1;
}
void Add(int node,int l,int r,int v){
	if (tree[node].l>r || tree[node].r<l)
		return;
	if (l<=tree[node].l && tree[node].r<=r){
		tree[node].sum3=(tree[node].sum3+3*tree[node].sum2%MOD*v%MOD + 3*tree[node].sum%MOD*v%MOD*v%MOD + (tree[node].r-tree[node].l+1)*v%MOD*v%MOD*v%MOD)%MOD;
		tree[node].sum2=(tree[node].sum2+2*tree[node].sum*v%MOD+(tree[node].r-tree[node].l+1)*v%MOD*v%MOD)%MOD;
		tree[node].sum=(tree[node].sum+v*(tree[node].r-tree[node].l+1)%MOD)%MOD;
		tree[node].add=(tree[node].add+v)%MOD;
		return;
	}
	if (tree[node].l==tree[node].r)
		return;
	PushDown(node);
	Add(node*2,l,r,v);
	Add(node*2+1,l,r,v);
	tree[node].sum=(tree[node*2].sum+tree[node*2+1].sum)%MOD;
	tree[node].sum2=(tree[node*2].sum2+tree[node*2+1].sum2)%MOD;
	tree[node].sum3=(tree[node*2].sum3+tree[node*2+1].sum3)%MOD;
}
void Mul(int node,int l,int r,int v){
	if (tree[node].l>r || tree[node].r<l)
		return;
	if (l<=tree[node].l && tree[node].r<=r){
		tree[node].sum3=(tree[node].sum3*v%MOD*v%MOD*v%MOD)%MOD;
		tree[node].sum2=(tree[node].sum2*v%MOD*v)%MOD;
		tree[node].sum=(tree[node].sum*v)%MOD;
		tree[node].add=(tree[node].add*v)%MOD;
		tree[node].mul=(tree[node].mul*v)%MOD;
		return;
	}
	if (tree[node].l==tree[node].r)
		return;
	PushDown(node);
	Mul(node*2,l,r,v);
	Mul(node*2+1,l,r,v);
	tree[node].sum=(tree[node*2].sum+tree[node*2+1].sum)%MOD;
	tree[node].sum2=(tree[node*2].sum2+tree[node*2+1].sum2)%MOD;
	tree[node].sum3=(tree[node*2].sum3+tree[node*2+1].sum3)%MOD;
}
void Change(int node,int l,int r,int v){
	if (tree[node].l>r || tree[node].r<l)
		return;
	if (l<=tree[node].l && tree[node].r<=r){
		tree[node].sum3=((tree[node].r-tree[node].l+1)*v%MOD*v%MOD*v%MOD)%MOD;
		tree[node].sum2=((tree[node].r-tree[node].l+1)*v%MOD*v%MOD)%MOD;
		tree[node].sum=((tree[node].r-tree[node].l+1)*v)%MOD;
		tree[node].add=v%MOD;
		tree[node].mul=0;
		return;
	}
	if (tree[node].l==tree[node].r)
		return;
	PushDown(node);
	Change(node*2,l,r,v);
	Change(node*2+1,l,r,v);
	tree[node].sum=(tree[node*2].sum+tree[node*2+1].sum)%MOD;
	tree[node].sum2=(tree[node*2].sum2+tree[node*2+1].sum2)%MOD;
	tree[node].sum3=(tree[node*2].sum3+tree[node*2+1].sum3)%MOD;
}
ll query(int node,int l,int r,int p){

	if (tree[node].l==l && tree[node].r==r){
		if (p==1)
			return tree[node].sum;
		if (p==2)
			return tree[node].sum2;
		if (p==3)
			return tree[node].sum3;
	}
	PushDown(node);
	int mid=(tree[node].l+tree[node].r)/2;
	if (r<=mid)
		return query(node*2,l,r,p);
	else if (l>mid)
		return query(node*2+1,l,r,p);
	else
		return (query(node*2,l,mid,p)+query(node*2+1,mid+1,r,p))%MOD;
	/*
	if (tree[node].l>r || tree[node].r<l)
		return 0;
	if (l<=tree[node].l && tree[node].r<=r){
		if (p==1)
			return tree[node].sum;
		if (p==2)
			return tree[node].sum2;
		if (p==3)
			return tree[node].sum3;
	}
	if (tree[node].l==tree[node].r)
		return 0;
	PushDown(node);
	return (query(node*2,l,r,p)+query(node*2+1,l,r,p))%MOD;
	*/
}
void Debug(int node){
	/*for (int i=0;i<4*node;i++)
		printf("%lld ",tree[i].sum );
	printf("\n");
	for (int i=0;i<4*node;i++)
		printf("%lld ",tree[i].sum2 );
	printf("\n");
	*/
	for (int i=0;i<200;i++)
		printf("%lld ",tree[i].sum3 );
	printf("\n");
}
int main(){
	int n,m,op,x,y,c,p;
	while (~scanf("%d%d",&n,&m)){
		if (n==0 && m==0) break;
		build(1,1,n);
		while (m--){
			scanf("%d%d%d%d",&op,&x,&y,&c);
			if (op==1)
				Add(1,x,y,c%MOD);
			if (op==2)
				Mul(1,x,y,c%MOD);
			if (op==3)
				Change(1,x,y,c%MOD);
			if (op==4)
				printf("%lld\n",query(1,x,y,c));
			Debug(n);
		}
	}

	return 0;
}

/*
10000 100
2 56 59 100
1 564 1254 10000
2 7 800 2
3 1 600 9999
4 5 10000 3
2 102 5645 9999
4 568 789 3
4 1 2 1
4 500 1000 1
4 500 1000 2
4 500 1000 3

*/