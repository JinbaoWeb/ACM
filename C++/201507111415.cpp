#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;
#define M 1000000007
const int MAXN = 100000+5;
struct Node{
	int l,r;
	ll sum;
	int add,mul,set;
}tree[4*MAXN];
void build(int node,int l,int r){
	tree[node].l=l,tree[node].r=r;
	tree[node].add=0;
	tree[node].mul=1;
	tree[node].set=0;
	if (l==r){
		scanf("%lld",&tree[node].sum);
		return;
	}
	int mid=(l+r)/2;
	build(node*2,l,mid);
	build(node*2+1,mid+1,r);
	tree[node].sum=(tree[node*2].sum+tree[node*2+1].sum)%M;
}
void down(int node){
	if (tree[node].mul==1 && tree[node].add==0 && tree[node].set==0)
		return;
	if (tree[node].set!=0){
		tree[node*2].set=tree[node*2+1].set=tree[node].set;
		tree[node].set=0;
		tree[node].mul=1;
		tree[node].add=0;
		tree[node*2].sum=tree[node*2].set*(tree[node*2].r-tree[node*2].l+1);
		tree[node*2+1].sum=tree[node*2+1].set*(tree[node*2+1].r-tree[node*2+1].l+1);
		return;
	}
	tree[node*2].mul=(tree[node*2].mul*tree[node].mul)%M;
	tree[node*2+1].mul=(tree[node*2+1].mul*tree[node].mul)%M;

	tree[node*2].add=(tree[node*2].add*tree[node].mul+tree[node].add)%M;
	tree[node*2+1].add=(tree[node*2+1].add*tree[node].mul+tree[node].add)%M;

	tree[node*2].sum=(tree[node*2].sum*tree[node].mul+tree[node].add*(tree[node*2].r-tree[node*2].l+1))%M;
	tree[node*2+1].sum=(tree[node*2+1].sum*tree[node].mul+tree[node].add*(tree[node*2+1].r-tree[node*2+1].l+1))%M;

	tree[node].add=0;
	tree[node].mul=1;
}
void Add(int node,int l,int r,int v){
	if (tree[node].l>r || tree[node].r<l)
		return;
	if (l<=tree[node].l && tree[node].r<=r){
		if (tree[node].set==0){
			tree[node].sum=(tree[node].sum+v*(tree[node].r-tree[node].l+1))%M;
			tree[node].add=(tree[node].add+v)%M;
		}
		else{
			tree[node].set+=v;
			tree[node].sum=(tree[node].r-tree[node].l+1)*tree[node].set%M;
			tree[node].add=0;
			tree[node].mul=1;
		}
		return;
	}
	if (tree[node].l==tree[node].r)
		return;
	down(node);
	Add(2*node,l,r,v);
	Add(2*node+1,l,r,v);
	tree[node].sum=(tree[node*2].sum+tree[node*2+1].sum)%M;
}
void Mul(int node,int l,int r,int v){
	if (tree[node].l>r || tree[node].r<l)
		return;
	if (l<=tree[node].l && tree[node].r<=r){
		if (tree[node].set==0){
			tree[node].sum=(tree[node].sum*v)%M;
			tree[node].add=(tree[node].add*v)%M;
			tree[node].mul=(tree[node].mul*v)%M;
		}
		else{
			tree[node].set=(tree[node].set*v)%M;
			tree[node].sum=(tree[node].r-tree[node].l+1)*tree[node].set%M;
		}
		return;
	}
	if (tree[node].l==tree[node].r)
		return;
	down(node);
	Mul(2*node,l,r,v);
	Mul(2*node+1,l,r,v);
	tree[node].sum=(tree[node*2].sum+tree[node*2+1].sum)%M;
}
void Set(int node,int l,int r,int v){
	if (tree[node].l>r || tree[node].r<l)
		return;
	if (l<=tree[node].l && tree[node].r<=r){
		tree[node].sum=(v*(tree[node].r-tree[node].l+1))%M;
		tree[node].add=0;
		tree[node].mul=1;
		tree[node].set=v;
		return;
	}
	if (tree[node].l==tree[node].r)
		return;
	down(node);
	Set(2*node,l,r,v);
	Set(2*node+1,l,r,v);
	tree[node].sum=(tree[node*2].sum+tree[node*2+1].sum)%M;
}

ll query(int node,int l,int r){
	if (tree[node].l>r || tree[node].r<l)
		return 0;
	if (l<=tree[node].l && tree[node].r<=r)
		return tree[node].sum%M;
	if (tree[node].l==tree[node].r)
		return 0;
	down(node);
	return (query(node*2,l,r)+query(node*2+1,l,r))%M;
}
void Debug(int n){
	cout<<"------------------"<<endl;
	for (int i=0;i<4*n;i++)
		cout<<tree[i].sum<<" ";
	cout<<endl;
	cout<<"------------------"<<endl;
	for (int i=0;i<4*n;i++)
		cout<<tree[i].add<<" ";
	cout<<endl;
	cout<<"------------------"<<endl;
	for (int i=0;i<4*n;i++)
		cout<<tree[i].mul<<" ";
	cout<<endl;
	cout<<"------------------"<<endl;
}
int main(){
	int n,q;
	int a,b,c,d;
	while (~scanf("%d%d",&n,&q)){
		build(1,1,n);
		//Debug(n);
		while (q--){
			scanf("%d%d%d",&a,&b,&c);
			if (a==4)
				printf("%d\n",query(1,b,c));
			else{
				scanf("%d",&d);
				if (a==1)
					Add(1,b,c,d);
				if (a==2)
					Mul(1,b,c,d);
				if (a==3)
					Set(1,b,c,d);
			}
			//Debug(n);
		}
	}

	return 0;
}