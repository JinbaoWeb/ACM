#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long ll;
const int MAXN = 100000+5;
ll p;
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
		tree[node].sum%=p;	//1
		return;
	}
	int mid=(l+r)/2;
	build(node*2,l,mid);
	build(node*2+1,mid+1,r);
	tree[node].sum=(tree[node*2].sum+tree[node*2+1].sum)%p;
}
void PushDown(int node){
	if (tree[node].mul==1 && tree[node].add==0)
		return;

	tree[node*2].mul=(tree[node*2].mul*tree[node].mul)%p;
	tree[node*2+1].mul=(tree[node*2+1].mul*tree[node].mul)%p;

	tree[node*2].add=(tree[node*2].add*tree[node].mul+tree[node].add)%p;
	tree[node*2+1].add=(tree[node*2+1].add*tree[node].mul+tree[node].add)%p;

	tree[node*2].sum=(tree[node*2].sum*tree[node].mul+tree[node].add*(tree[node*2].r-tree[node*2].l+1))%p;
	tree[node*2+1].sum=(tree[node*2+1].sum*tree[node].mul+tree[node].add*(tree[node*2+1].r-tree[node*2+1].l+1))%p;

	tree[node].mul=1;
	tree[node].add=0;

}
void Add(int node,int l,int r,ll v){
	if (l>tree[node].r || r<tree[node].l)
		return;
	if (l<=tree[node].l && tree[node].r<=r){
		tree[node].add=(tree[node].add+v)%p;
		tree[node].sum=(tree[node].sum+v*(tree[node].r-tree[node].l+1))%p;
		return;
	}
	if (tree[node].l==tree[node].r)
		return;
	PushDown(node);
	Add(node*2,l,r,v);
	Add(node*2+1,l,r,v);
	tree[node].sum=(tree[node*2].sum+tree[node*2+1].sum)%p;
}
void Mul(int node,int l,int r,ll v){
	if (l>tree[node].r || r<tree[node].l)
		return;
	if (l<=tree[node].l && tree[node].r<=r){
		tree[node].mul=(tree[node].mul*v)%p;
		tree[node].add=(tree[node].add*v)%p;
		tree[node].sum=(tree[node].sum*v)%p;
		return;
	}
	if (tree[node].l==tree[node].r)
		return;
	PushDown(node);
	Mul(node*2,l,r,v);
	Mul(node*2+1,l,r,v);
	tree[node].sum=(tree[node*2].sum+tree[node*2+1].sum)%p;
}
ll query(int node,int l,int r){
	if (l>tree[node].r || r<tree[node].l)
		return 0;
	if (l<=tree[node].l && tree[node].r<=r){
		return tree[node].sum;
	}
	if (tree[node].l==tree[node].r)
		return 0;
	PushDown(node);
	return (query(node*2,l,r)+query(node*2+1,l,r))%p;
}
void Debug(int node){
	for (int i=0;i<4*node;i++)
		cout<<tree[i].sum<<" ";
	cout<<endl;
}
int main(){
	int n,m;
	int tag,a,b;
	ll v;
	while (~scanf("%d%lld",&n,&p)){
		build(1,1,n);
		scanf("%d",&m);
		//Debug(n);
		while (m--){
			scanf("%d",&tag);
			if (tag==3){
				scanf("%d%d",&a,&b);
				printf("%lld\n",query(1,a,b)%p);
			}
			if (tag==1){
				scanf("%d%d%lld",&a,&b,&v);
				Mul(1,a,b,v);
			}
			if (tag==2){
				scanf("%d%d%lld",&a,&b,&v);
				Add(1,a,b,v);
			}
			//Debug(n);
		}
	}
	return 0;
}