#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000000+10;
const int MAXM = 100000+10;
struct Node{
	int l,r;
	int flag;
	int sum;
}tree[4*MAXN];
struct Node2{
	int l,r;
}P[MAXM];
void build(int node,int l,int r){
	tree[node].l=l,tree[node].r=r;
	tree[node].flag=0,tree[node].sum=0;
	if (l==r)
		return;
	int mid=(l+r)/2;
	build(node*2,l,mid);
	build(node*2+1,mid+1,r);
}
void PushDown(int node){
	if (tree[node].flag){
		tree[node*2].flag+=tree[node].flag;
		tree[node*2+1].flag+=tree[node].flag;
		tree[node*2].sum+=tree[node].flag;
		tree[node*2+1].sum+=tree[node].flag;
		tree[node].flag=0;
	}
}
void update(int node,int l,int r,int v){
	if (l<=tree[node].l && tree[node].r<=r){
		tree[node].flag+=v;
		tree[node].sum+=v;
		return;
	}
	PushDown(node);
	int mid=(tree[node].l+tree[node].r)/2;
	if (r<=mid)
		update(node*2,l,r,v);
	else if (mid<l)
		update(node*2+1,l,r,v);
	else{
		update(node*2,l,mid,v);
		update(node*2+1,mid+1,r,v);
	}
	tree[node].sum=max(tree[node*2].sum,tree[node*2+1].sum);
}
int query(int node,int l,int r){
	if (l<=tree[node].l && tree[node].r<=r){
		return tree[node].sum;
	}
	PushDown(node);
	int mid=(tree[node].l+tree[node].r)/2;
	if (r<=mid)
		return query(node*2,l,r);
	else if (mid<l)
		return query(node*2+1,l,r);
	else{
		return max(query(node*2,l,mid),query(node*2+1,mid+1,r));
	}
}
int ans[MAXM];
void Debug(){
	cout<<"----------\n";
	for (int i=0;i<15;i++){
		cout<<tree[i].sum<<" ";
	}
	cout<<endl;
}
int main(){
	int t,n,q;
	scanf("%d",&t);
	for (int cas=1;cas<=t;cas++){
		scanf("%d%d",&n,&q);
		int Max=0;
		for (int i=0;i<q;i++){
			scanf("%d%d",&P[i].l,&P[i].r);
			Max=max(P[i].r,Max);
		}
		build(1,1,Max);
		printf("Case %d:\n",cas);
		int tt=0;
		for (int i=0;i<q;i++){
			int temp=query(1,P[i].l,P[i].r-1);
			//Debug();
			//cout<<temp<<endl;
			if (temp<n){
				ans[tt++]=i+1;
				update(1,P[i].l,P[i].r-1,1);
			}
		}
		for (int i=0;i<tt-1;i++)
			printf("%d ",ans[i]);
		cout<<ans[tt-1]<<endl<<endl;;
	}

	return 0;
}