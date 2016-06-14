#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000+10;
struct plank{
	int h,l,r,v;
}p[MAXN];
struct Node{
	int l,r;
	int flag;
	int num;
}tree[4*MAXN];
int dp[MAXN];
bool cmp(plank x,plank y){
	return x.h<y.h;
}
void build(int node,int l,int r){
	tree[node].l=l,tree[node].r=r;
	tree[node].flag=0,tree[node].num=0;
	if (l==r)
		return;
	int mid=(l+r)/2;
	build(node*2,l,mid);
	build(node*2+1,mid+1,r);
}
void PushDown(int node){
	if (tree[node].flag){
		tree[node*2].flag=tree[node*2+1].flag=tree[node*2].num=tree[node*2+1].num=tree[node].flag;
		tree[node].flag=0;
	}
}
void update(int node,int l,int r,int v){
	if (l<=tree[node].l && tree[node].r<=r){
		tree[node].flag=v;
		tree[node].num=v;
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
	tree[node].num=max(tree[node*2].num,tree[node*2+1].num);
}
int query(int node,int x){
	if (tree[node].l==x && tree[node].r==x){
		return tree[node].num;
	}
	PushDown(node);
	int mid=(tree[node].l+tree[node].r)/2;
	if (x<=mid)
		return query(node*2,x);
	else
		return query(node*2+1,x);
}
struct que{
	int l,r;
}q[MAXN];
int main(){
	int n;
	while (~scanf("%d",&n)){
		for (int i=0;i<n;i++)
			scanf("%d%d%d%d",&p[i].h,&p[i].l,&p[i].r,&p[i].v);
		p[n].h=0,p[n].l=0,p[n].r=100010,p[n].v=0;
		sort(p,p+n+1,cmp);
		memset(dp,0,sizeof(dp));
		build(1,1,100010);
		update(1,p[0].l,p[0].r,0);
		for (int i=1;i<=n;i++){
			int l=query(1,p[i].l),r=query(1,p[i].r);
			dp[i]=max(dp[l],dp[r])+p[i].v;
			update(1,p[i].l,p[i].r,i);
		}
		dp[n]+=100;
		if (dp[n]<=0)
			dp[n]=-1;
		printf("%d\n",dp[n]);
		/*
		for (int i=0;i<=n;i++){
			if (i){
				q[i].l=query(1,p[i].l);
				q[i].r=query(1,p[i].r);
			}
			update(1,p[i].l,p[i].r,i);
		}
		dp[n]=100+p[n].v;
		int flag=0;
		for (int i=n;i>0;i--){
			int l=q[i].l,r=q[i].r;
			//cout<<l<<" "<<r<<endl;
			dp[l]=max(dp[l],dp[i]+p[l].v);
			dp[r]=max(dp[r],dp[i]+p[r].v);
			if (dp[l]==0 && dp[r]==0){
				flag=1;
				break;
			}
		}
		
		for (int i=0;i<=n;i++)
			cout<<dp[i]<<" ";
		cout<<endl;
		
		if (dp[0]==0)
			flag=1;
		if (flag)
			printf("-1\n");
		else
			printf("%d\n", dp[0]);
		*/
	}

	return 0;
}