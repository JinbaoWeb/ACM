#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
const int MAXN = 10000+5;
struct Node{
	int l,r;
	int c;
}tree[14*MAXN];	//线段树
struct Seg{
	int l,r;
}s[MAXN];	//存储报纸的范围
struct Seg2{
	int p;
	int index;
}a[2*MAXN];	//存放端点信息
bool cmp(Seg2 x,Seg2 y){
	return x.p<y.p;
}
int color[2*MAXN];
int ans=0;
void build(int node,int l,int r){
	tree[node].l=l,tree[node].r=r,tree[node].c=0;
	if (l==r) return;
	build(node*2,l,(l+r)/2);
	build(node*2+1,(l+r)/2+1,r);
}
void update(int node,int l,int r,int v){
	//cout<<l<<" "<<r<<endl;
	if (tree[node].l>=l && tree[node].r<=r){
		tree[node].c=v;
		return;
	}
	if (tree[node].c>0){
		tree[2*node].c=tree[2*node+1].c=tree[node].c;
		tree[node].c=0;
	}
	int mid=(tree[node].l+tree[node].r)/2;
	if (r<=mid)
		update(2*node,l,r,v);
	else if (mid<l)
		update(2*node+1,l,r,v);
	else{
		update(2*node,l,mid,v);
		update(2*node+1,mid+1,r,v);
	}
}
void count(int node){
	if (tree[node].c>0){
		if (color[tree[node].c]==0){
			ans++;
			color[tree[node].c]++;
		}
		return;
	}
	if (tree[node].l==tree[node].r)
		return;
	count(2*node);
	count(2*node+1);
}
void solve(int n,int t){
	build(1,1,t);
	//cout<<"--------"<<endl;
	for (int i=1;i<=n;i++){
		update(1,s[i].l,s[i].r,i);
		//cout<<"123456789\n";
	}
	ans=0;
	memset(color,0,sizeof(color));
	count(1);
	printf("%d\n",ans);
}
int main(){
	int t,n;
	scanf("%d",&t);
	while (t--){
		scanf("%d",&n);
		for (int i=1;i<=n;i++){
			scanf("%d%d",&s[i].l,&s[i].r);
			a[2*i-1].p=s[i].l;
			a[2*i-1].index=i;	//标记为左端点
			a[2*i].p=s[i].r;
			a[2*i].index=-i;	//标记为右端点
		}
		sort(a+1,a+2*n+1,cmp);
		//数据离散化
		int t=1;
		int tmp=a[1].p;
		for (int i=1;i<=2*n;i++){
			if (tmp!=a[i].p){
				tmp=a[i].p;
				t++;
			}
			if (a[i].index>0)
				s[a[i].index].l=t;
			else
				s[-a[i].index].r=t;
		}
		/*
		for (int i=1;i<=n;i++){
			printf("%d %d\n",s[i].l,s[i].r);
		}
		*/
		solve(n,t);
	}
	return 0;
}