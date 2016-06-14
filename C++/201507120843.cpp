#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long ll;
const int MAXN = 131072+2;
#define M 1000000007
struct Node{
	ll l,r;
	ll k;
}tree[4*MAXN];
ll gcd(ll x, ll y){
	if (!x || !y) return x > y ? x : y;
	for (ll t; t = x % y; x = y, y = t);
	return y;
}
ll lcm(ll x,ll y){
	ll k=gcd(x%M,y%M);
	return (x/k*y)%M;
}
void build(ll node,ll l,ll r){
	tree[node].l=l,tree[node].r=r;
	if (l==r){
		scanf("%lld",&tree[node].k);
		return;
	}
	ll mid=(l+r)/2;
	build(node*2,l,mid);
	build(node*2+1,mid+1,r);
	tree[node].k=lcm(tree[node*2].k,tree[node*2+1].k)%M;
}
ll query(ll node,ll l,ll r){
	//cout<<l<<" "<<r<<endl;
	if (l>tree[node].r || r<tree[node].l)
		return 1;
	if (l<=tree[node].l && tree[node].r<=r)
		return tree[node].k%M;
	if (tree[node].l==tree[node].r)
		return 1;
	ll mid=(tree[node].l+tree[node].r)/2;
	if (r<=mid)		
		return query(node*2,l,r)%M;
	else if (mid<l)
		return query(node*2+1,l,r)%M;
	else{
		return lcm(query(node*2,l,mid),query(node*2+1,mid+1,r))%M;
	}
}
int main(){
	ll t,n,m,x,y;
	scanf("%lld",&t);
	for (ll cas=1;cas<=t;cas++){
		scanf("%lld%lld",&n,&m);
		build(1,1,n);
		//Debug(n);
		printf("Case #%lld:\n",cas);
		while (m--){
			scanf("%lld%lld",&x,&y);
			printf("%lld\n",query(1,x,y)%M);
		}
	}
	return 0;
}