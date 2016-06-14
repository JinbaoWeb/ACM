#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
const int MAXN = 100000+5;
typedef __int64 ll;
struct Node{
	int l,r;
	ll msum,lsum,rsum,lsum2,rsum2;	//区间保存方式[lsum,lsum2,rsum,rsum2]
}tree[4*MAXN];
int num[MAXN];
void PushUp(int node){
	tree[node].msum=max(tree[node*2].msum,tree[node*2+1].msum);
	tree[node].lsum=tree[node*2].lsum+(tree[node*2+1].lsum>0?tree[node*2+1].lsum:0);
	tree[node].lsum2=tree[node*2].lsum2+(tree[node*2+1].lsum2>0?tree[node*2+1].lsum2:0);
	tree[node].rsum=tree[node*2+1].rsum+(tree[node*2].rsum>0?tree[node*2].rsum:0);
	tree[node].rsum2=tree[node*2+1].rsum2+(tree[node*2].rsum2>0?tree[node*2].rsum2:0);
	tree[node].msum=max(tree[node].msum,max(max(tree[node].lsum,tree[node].lsum2),max(tree[node].rsum,tree[node].rsum2)));
}
void build(int node,int l,int r){
	//printf("%d %d %d\n",node,l,r );
	tree[node].l=l,tree[node].r=r;
	if (l==r){
		tree[node].msum=num[l];
		//printf("%d-----\n",num[l] );
		if (l%2==1){
			//printf("%d-----\n",num[l] );
			tree[node].lsum=num[l];
			//printf("%lld ",tree[node].lsum );
			tree[node].rsum=num[l];
			//printf("%lld ",tree[node].rsum );
			tree[node].lsum2=0;
			tree[node].rsum2=0;
			//printf("%lld %lld\n",tree[node].lsum2,tree[node].rsum2 );
			//printf("%d %lld %lld %lld %lld\n",node,tree[node].lsum,tree[node].rsum,tree[node].lsum2,tree[node].rsum2 );
		}
		else{
			tree[node].lsum=tree[node].rsum=0;
			tree[node].lsum2=tree[node].rsum2=num[l];
		}
		//printf("%d %d %d %d %d\n",node,tree[node].lsum,tree[node].lsum2,tree[node].rsum,tree[node].rsum2 );
		return;
	}
	int mid=(l+r)/2;
	build(node*2,l,mid);
	build(node*2+1,mid+1,r);
	PushUp(node);
}
void update(int node,int x,int v){
	if (tree[node].l==tree[node].r && tree[node].l==x){
		tree[node].msum=v;
		if (tree[node].l%2==1){
			tree[node].lsum=tree[node].rsum=v;
			tree[node].lsum2=tree[node].rsum2=0;
		}
		else{
			tree[node].lsum=tree[node].rsum=0;
			tree[node].lsum2=tree[node].rsum2=v;
		}
		return;
	}
	int mid=(tree[node].l+tree[node].r)/2;
	if (x<=mid)
		update(node*2,x,v);
	else
		update(node*2+1,x,v);
	PushUp(node);
}
ll query(int node,int l,int r){
	if (l<=tree[node].l&&tree[node].r<=r){
		return tree[node].msum;
	}
	int mid=(tree[node].l+tree[node].r)/2;
	if (r<=mid)
		return query(node*2,l,r);
	else if (mid<l)
		return query(node*2+1,l,r);
	else{
		ll ans=0;
		ll q1=query(node*2,l,mid);
		ll q2=query(node*2+1,mid+1,r);
		if (q1>0)
			ans+=q1;
		if (q2>0)
			ans+=q2;
		return ans;
	}
}
void Debug(){
	for (int i=0;i<15;i++){
		printf("%lld %lld %lld %lld\n",tree[i].lsum,tree[i].lsum2,tree[i].rsum,tree[i].rsum2 );
	}
}
int main(){
	int t,n,m;
	int op,a,b;
	scanf("%d",&t);
	while (t--){
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++)
			scanf("%d",&num[i]);
		build(1,1,n);
		//Debug();
		while (m--){
			scanf("%d%d%d",&op,&a,&b);
			if (op==0)
				printf("%d\n",query(1,a,b) );
			else
				update(1,a,b);
			//Debug();
		}
	}
	return 0;
}
/*
1
6 5
1 2 -1 3 0 6
*/