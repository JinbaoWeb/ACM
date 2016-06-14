#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 100000+10;
const int MOD = 10007;
struct Node{
	int l,r;
	int sum;
	int pre;
	int pos;
	int mul;
}tree[4*MAXN];
void PushUp(int node){
	tree[node].mul=(tree[node*2].mul*tree[node*2+1].mul)%MOD;
	tree[node].pre=(tree[node*2].pre+tree[node*2+1].pre*tree[node*2].mul)%MOD;
	tree[node].pos=(tree[node*2+1].pos+tree[node*2].pos*tree[node*2+1].mul)%MOD;
	tree[node].sum=(tree[node*2].sum+tree[node*2+1].sum+tree[node*2].pos*tree[node*2+1].pre)%MOD;
}
void build(int node,int l,int r){
	tree[node].l=l,tree[node].r=r;
	if (l==r){
		tree[node].sum=tree[node].pre=tree[node].pos=tree[node].mul=0;
		return;
	}
	int mid=(l+r)/2;
	build(node*2,l,mid);
	build(node*2+1,mid+1,r);
	PushUp(node);
}
void update(int node,int x,int v){
	if (tree[node].l==x && tree[node].r==x){
		tree[node].sum=tree[node].pre=tree[node].pos=tree[node].mul=v;
		return;
	}
	int mid=(tree[node].l+tree[node].r)/2;
	if (x<=mid)
		update(node*2,x,v);
	else
		update(node*2+1,x,v);
	PushUp(node);
}
int main(){
	int n,q,a,b;
	while (~scanf("%d%d",&n,&q)){
		build(1,1,n);
		while (q--){
			scanf("%d%d",&a,&b);
			update(1,a,b);
			printf("%d\n",tree[1].sum%MOD );
		}
	}
	return 0;
}