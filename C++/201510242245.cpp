#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2*100000+10;
struct Node{
	int l,r;
	int flag,flag2;
	int Min,Max;
	ll sum;
}tree[4*MAXN];
struct Node2{
	int a,b;
	int id;
}P[MAXN];
bool cmp(Node2 x,Node2 y){
	if (x.a!=y.a)
		return x.a<y.a;
	return x.b<y.b;
}
void PushUp(int node){
	tree[node].sum=tree[node*2].sum+tree[node*2+1].sum;
	tree[node].Min=min(tree[node*2].Min,tree[node*2+1].Min);
	tree[node].Max=max(tree[node*2].Max,tree[node*2+1].Max);
}
void build(int node,int l,int r){
	tree[node].l=l,tree[node].r=r;
	tree[node].flag=0;
	tree[node].flag2=0;
	if (l==r){
		scanf("%I64d",&tree[node].sum);
		tree[node].Min=tree[node].Max=tree[node].sum;
		return;
	}
	int mid=(l+r)/2;
	build(node*2,l,mid);
	build(node*2+1,mid+1,r);
	PushUp(node);
}
void PushDown(int node){
	if (tree[node].flag2==1){
		tree[node*2].flag2=tree[node*2+1].flag2=1;
		tree[node*2].sum=tree[node*2+1].sum=0;
		tree[node*2].Min=tree[node*2+1].Min=0;
		tree[node*2].Max=tree[node*2+1].Max=0;
	}
	else if (tree[node].flag){
		tree[node*2].flag+=tree[node].flag;
		tree[node*2+1].flag+=tree[node].flag;
		tree[node*2].sum-=(tree[node*2].r-tree[node*2].l+1)*tree[node].flag;
		tree[node*2+1].sum-=(tree[node*2+1].r-tree[node*2+1].l+1)*tree[node].flag;
		tree[node*2].Min-=tree[node].flag;
		tree[node*2+1].Min-=tree[node].flag;
		tree[node*2].Max-=tree[node].flag;
		tree[node*2+1].Max-=tree[node].flag;
		tree[node].flag=0;
	}
}
void update(int node,int v){
	if (tree[node].Max<v){
		tree[node].flag2=1;
		tree[node].Min=tree[node].Max=tree[node].sum=0;
		return;
	}
	if (tree[node].Min<v){
		if (tree[node].l==tree[node].r){
			tree[node].Min=tree[node].Max=tree[node].sum=0;
			return;
		}
		PushDown(node);
		update(node*2,v);
		update(node*2+1,v);
		PushUp(node);
	}
	else{
		tree[node].flag+=v;
		tree[node].sum-=v*(tree[node].r-tree[node].l+1);
		tree[node].Min-=v;
		tree[node].Max-=v;
	}
}
int query(int node,int v){
	if (tree[node].l==tree[node].r)
		return tree[node].l;
	PushDown(node);
	if (tree[node*2].sum<v){
		v-=tree[node*2].sum;
		return query(node*2+1,v);
	}
	else{
		return query(node*2,v);
	}
}
int ans[MAXN];
int main(){
	int n,m;
	while (~scanf("%d%d",&n,&m)){
		build(1,1,m);
		//Debug();
		for (int i=0;i<n;i++){
			scanf("%d%d",&P[i].a,&P[i].b);
			P[i].id=i;
		}
		sort(P,P+n,cmp);
		for (int i=0;i<n;i++){
			if (i && tree[1].Max<(P[i].a-P[i-1].a)){
				ans[P[i].id]=0;
				continue;
			}
			if (i)
				update(1,P[i].a-P[i-1].a);
			else
				update(1,P[i].a);
			//Debug();
			//cout<<"  --  "<<tree[1].sum<<endl;
			if (tree[1].sum<P[i].b){
				ans[P[i].id]=0;
				continue;
			}
			int temp=query(1,P[i].b);
			ans[P[i].id]=temp;
		}
		for (int i=0;i<n-1;i++){
			cout<<ans[i]<<" ";
		}
		cout<<ans[n-1]<<endl;
	}
	return 0;
}