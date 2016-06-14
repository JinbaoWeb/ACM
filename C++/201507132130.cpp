#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
typedef long long ll;
const int MAXN = 100000+5 ;
const int MOD = 1000000007;
struct Node{
	int l,r;
	ll sum;
	ll mul,add;
}tree[4*MAXN];
void build(int node,int l,int r){
	tree[node].l=l,tree[node].r=r;
	tree[node].mul=1,tree[node].add=0;
	if (l==r){
		scanf("%lld",&tree[node].sum);
		return;
	}
	build(node*2,l,(l+r)/2);
	build(node*2+1,(l+r)/2+1,r);
	tree[node].sum=(tree[node*2].sum+tree[node*2+1].sum)%MOD;
}
void PushDown(int node){
	if (tree[node].mul==1 && tree[node].add==0)
		return;

	tree[node*2].sum=(tree[node*2].sum*tree[node].mul+tree[node].add*(tree[node*2].r-tree[node*2].l+1))%MOD;
	tree[node*2+1].sum=(tree[node*2+1].sum*tree[node].mul+tree[node].add*(tree[node*2+1].r-tree[node*2+1].l+1))%MOD;

	tree[node*2].mul=tree[node].mul;
	tree[node*2+1].mul=tree[node].mul;

	tree[node*2].add=tree[node].add;
	tree[node*2+1].add=tree[node].add;

	tree[node].add=0;
	tree[node].mul=1;

}
void Mul(int node,int l,int r,ll v){
	if (r<tree[node].l || tree[node].r<l)
		return;
	if (l<=tree[node].l && tree[node].r<=r){
		tree[node].sum=(tree[node].sum*v)%MOD;
		tree[node].mul=(tree[node].mul*v)%MOD;
		tree[node].add=(tree[node].add*v)%MOD;
		return;
	}
	if (tree[node].l==tree[node].r)
		return;
	PushDown(node);
	Mul(node*2,l,r,v);
	Mul(node*2+1,l,r,v);
	tree[node].sum=(tree[node*2].sum+tree[node*2+1].sum)%MOD;
}
void Add(int node,int l,int r,ll v){
	if (r<tree[node].l || tree[node].r<l)
		return;
	if (l<=tree[node].l && tree[node].r<=r){
		tree[node].sum=(tree[node].sum+v*(tree[node].r-tree[node].l+1))%MOD;
		tree[node].add=(tree[node].add+v)%MOD;
		return;
	}
	if (tree[node].l==tree[node].r)
		return;
	PushDown(node);
	Add(node*2,l,r,v);
	Add(node*2+1,l,r,v);
	tree[node].sum=(tree[node*2].sum+tree[node*2+1].sum)%MOD;
}
void Set(int node,int l,int r,ll v){
	if (r<tree[node].l || tree[node].r<l)
		return;
	if (l<=tree[node].l && tree[node].r<=r){
		tree[node].sum=(v*(tree[node].r-tree[node].l+1))%MOD;
		tree[node].add=v%MOD;
		tree[node].mul=0;
		return;
	}
	if (tree[node].l==tree[node].r)
		return;
	PushDown(node);
	Set(node*2,l,r,v);
	Set(node*2+1,l,r,v);
	tree[node].sum=(tree[node*2].sum+tree[node*2+1].sum)%MOD;
}
ll query(int node,int l,int r){
	if (r<tree[node].l || tree[node].r<l)
		return 0;
	if (l<=tree[node].l && tree[node].r<=r){
		return tree[node].sum%MOD;
	}
	if (tree[node].l==tree[node].r)
		return 0;
	return (query(node*2,l,r)+query(node*2+1,l,r))%MOD;
}
int main(){
	int n,q;
	int a,b,c;
	ll d;
	scanf("%d%d",&n,&q);
		build(1,1,n);
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
		}
	
	return 0;
}