#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 100000+5;
#define MOD 1000000007
struct NOde{
	int l,r;
	ll sum;
	ll add,mul,set;
}tree[4*MAXN];
void build(int node,int l,int r){
	tree[node].l=l,tree[node].r=r;
	tree[node].mul=1;
	tree[node].add=0;
	tree[node].set=0;
	if (l==r){
		scanf("%lld",&tree[node].sum);
		return;
	}
	int mid=(l+r)/2;
	build(node*2,l,mid);
	build(node*2+1,mid+1,r);
	tree[node].sum=(tree[2*node].sum+tree[node*2+1].sum)%MOD;
}
void PushDown(int node){
	if (tree[node].mul==1 && tree[node].add==0 && tree[node].set==0)
		return;
	if (tree[node].set!=0){
		tree[node*2].sum=(tree[node].set*(tree[node*2].r-tree[node*2].l+1))%MOD;
		tree[node*2+1].sum=(tree[node].set*(tree[node*2+1].r-tree[node*2+1].l+1))%MOD;

		tree[node*2].set=tree[node*2+1].set=tree[node].set;
		tree[node].set=0;

		tree[node].mul=tree[node*2].mul=tree[node*2+1].mul=1;
		tree[node].add=tree[node*2].add=tree[node*2+1].add=0;
		return;
	}

	tree[node*2].mul=(tree[node*2].mul*tree[node].mul)%MOD;
	tree[node*2+1].mul=(tree[node*2+1].mul*tree[node].mul)%MOD;

	tree[node*2].add=(tree[node*2].add*tree[node].mul+tree[node].add)%MOD;
	tree[node*2+1].add=(tree[node*2+1].add*tree[node].mul+tree[node].add)%MOD;

	tree[node*2].sum=(tree[node*2].sum*tree[node].mul+tree[node].add*(tree[node*2].r-tree[node*2].l+1))%MOD;
	tree[node*2+1].sum=(tree[node*2+1].sum*tree[node].mul+tree[node].add*(tree[node*2+1].r-tree[node*2+1].l+1))%MOD;

	tree[node].mul=1;
	tree[node].add=0;

}
void Mul(int node,int l,int r,ll v){
	if (l>tree[node].r && r<tree[node].l)
		return;
	if (l<=tree[node].l && tree[node].r<=r){
		tree[node].sum=(tree[node].sum*v)%MOD;
		tree[node].mul=(tree[node].mul*v)%MOD;
		tree[node].add=(tree[node].add*v)%MOD;
		tree[node].set=(tree[node].set*v)%MOD;
		return;
	}
	if (tree[node].l == tree[node].r)
		return;
	PushDown(node);
	Mul(node*2,l,r,v);
	Mul(node*2+1,l,r,v);
	tree[node].sum=(tree[node*2].sum+tree[node*2+1].sum)%MOD;
}
void Add(int node,int l,int r,ll v){
	if (tree[node].l>r || tree[node].r<l)
		return;
	if (l<=tree[node].l && tree[node].r<=r){
		tree[node].sum=(tree[node].sum+v*(tree[node].r-tree[node].l+1))%MOD;
		tree[node].add=(tree[node].add+v)%MOD;
		tree[node].set=(tree[node].set+v)%MOD;
		return;
	}
	if (tree[node].l == tree[node].r)
		return;
	PushDown(node);
	Add(node*2,l,r,v);
	Add(node*2+1,l,r,v);
	tree[node].sum=(tree[node*2].sum+tree[node*2+1].sum)%MOD;
}
void Set(int node,int l,int r,ll v){
	if (tree[node].l>r || tree[node].r<l)
		return;
	if (l<=tree[node].l && tree[node].r<=r){
		tree[node].sum=v*(tree[node].r-tree[node].l+1)%MOD;
		tree[node].set=v;
		tree[node].mul=1;
		tree[node].add=0;
		return;
	}
	if (tree[node].l == tree[node].r)
		return;
	PushDown(node);
	Set(node*2,l,r,v);
	Set(node*2+1,l,r,v);
	tree[node].sum=(tree[node*2].sum+tree[node*2+1].sum)%MOD;
}
ll query(int node,int l,int r){
	if (tree[node].l>r || tree[node].r<l)
		return 0;
	if (l<=tree[node].l && tree[node].r<=r){
		return tree[node].sum;
	}
	if (tree[node].l == tree[node].r)
		return 0;
	PushDown(node);
	return (query(node*2,l,r)+query(node*2+1,l,r))%MOD;
}
int main(){
	int n,q;
	int a,b,c;
	ll d;
	while (~scanf("%d%d",&n,&q)){
		build(1,1,n);
		//Debug(n);
		while (q--){
			scanf("%d",&a);
			if (a==1){
				scanf("%d%d%lld",&b,&c,&d);
				Add(1,b,c,d);
			}
			if (a==2){
				scanf("%d%d%lld",&b,&c,&d);
				Mul(1,b,c,d);
			}
			if (a==3){
				scanf("%d%d%lld",&b,&c,&d);
				Set(1,b,c,d);
			}
			if (a==4){
				scanf("%d%d",&b,&c);
				printf("%lld\n",query(1,b,c));
			}
			//Debug(n);
		}
	}
	return 0;
}