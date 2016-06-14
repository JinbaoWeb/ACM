#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 10000+10;
struct Node{
	int l,r;
	ll v,sum;
}tree[4*MAXN];
ll gcd(ll x, ll y){
	if (!x || !y) return x > y ? x : y;
	for (ll t; t = x % y; x = y, y = t);
	return y;
}
ll fr(int node){
	return gcd(tree[node].v,tree[(node+1)*2].v)+f((node+1)*2);
}
ll fl(int node){
	return gcd(tree[node].v,tree[(node-1)*2+1].v)+f((node-1)*2+1);
}
void build(int node,int l,int r){
	tree[node].l=l,tree[node].r=r;
	if (l==r){
		scanf("%lld",&tree[node].v);
		tree[node].sum=tree[node].v;
		return;
	}
	build(node*2,l,(l+r)/2);
	build(node*2+1,(l+r)/2+1,r);
	tree[node].v=gcd(tree[node*2].v,tree[node*2+1].v);
	tree[node].sum=tree[node*2].sum+tree[node*2+1].sum+tree[node].v;
	//+fl(node*2)+fr(node*2+1);
}
ll query(int node,int l,int r){
	if (l<=tree[node].l && tree[node].r<=r){
		return tree[node].sum;
	}
	int mid=(tree[node].l+tree[node].r)/2;
	if (r<=mid)
		return query(node*2,l,r);
	else if (mid<l)
		return query(node*2+1,l,r);
	else{
		ll temp = query(node*2,l,mid)+query(node*2+1,mid+1,r);

	}

}
int main(){
	int t,n,q,l,r;
	scanf("%d",&t);
	while (t--){
		scanf("%d",&n);
		build(1,1,n);
		scanf("%d",&q);
		while (q--){
			scanf("%d%d",&l,&r);
			ll sum=0;
			for (int i=l;i<=r;i++){
				for (int j=i;j<=r;j++)
					sum+=query(1,i,j);
			}
			printf("%lld\n",sum);
		}
	}

	return 0;
}