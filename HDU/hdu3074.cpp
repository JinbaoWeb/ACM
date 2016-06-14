#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int MAX = 50000+1;
typedef long long ll;
#define mod 1000000007
struct Node{
	int l,r;
	ll mul;
}tree[4*MAX];
void build(int node,int l,int r){
	tree[node].l=l,tree[node].r=r;
	if (l==r){
		scanf("%d",&tree[node].mul);
		return;
	}
	int mid=(l+r)>>1;
	build(node*2,l,mid);
	build(node*2+1,mid+1,r);
	tree[node].mul=(tree[node*2].mul*tree[node*2+1].mul)%mod;
}
void update(int node,int x,int v){
	if (tree[node].l==tree[node].r && tree[node].l==x){
		//cout<<tree[node].mul<<"---------------\n";
		tree[node].mul=v;
		return;
	}
	int mid=(tree[node].l+tree[node].r)/2;
	if (mid>=x)
		update(2*node,x,v);
	else
		update(2*node+1,x,v);
	tree[node].mul=(tree[node*2].mul*tree[node*2+1].mul)%mod;
}
ll query(int node,int l,int r){
	if (l>tree[node].r || r<tree[node].l)
		return 1;
	if (l<=tree[node].l && tree[node].r<=r){
		return tree[node].mul;
	}
	int mid=(tree[node].l+tree[node].r)/2;
	if (mid>=r){
		return query(2*node,l,r);
	}
	else if (mid<l){
		return query(2*node+1,l,r);
	}
	else{
		return (query(2*node,l,mid)*query(2*node+1,mid+1,r))%mod; 
	}
}
int main(){
	int t,n,q,a,b,c;
	while (~scanf("%d",&t)){
		while (t--){
			scanf("%d",&n);
			build(1,1,n);
			scanf("%d",&q);
			while (q--){
				scanf("%d%d%d",&a,&b,&c);
				if (a==1){
					update(1,b,c);
				}
				else
					printf("%d\n",query(1,b,c));
			}
		}
	}
	return 0;
}