#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;
const int MAXN = 50000+10;
struct Node{
	int l,r;
	int x1,x2,x3,x4,x5;
	int sum;
}tree[4*MAXN],a[MAXN];
void PushUp(int node){
	tree[node].sum=tree[node*2].sum+tree[node*2+1].sum;
	tree[node].x1=max(tree[node*2].x1,tree[node*2+1].x1);
	tree[node].x2=max(tree[node*2].x2,tree[node*2+1].x2);
	tree[node].x3=max(tree[node*2].x3,tree[node*2+1].x3);
	tree[node].x4=max(tree[node*2].x4,tree[node*2+1].x4);
	tree[node].x5=max(tree[node*2].x5,tree[node*2+1].x5);
}
void build(int node,int l,int r){
	tree[node].l=l,tree[node].r=r;
	if (l==r){
		tree[node].x1=a[l].x1;
		tree[node].x2=a[l].x2;
		tree[node].x3=a[l].x3;
		tree[node].x4=a[l].x4;
		tree[node].x5=a[l].x5;
		tree[node].sum=1;
		return;
	}
	int mid=(l+r)/2;
	build(node*2,l,mid);
	build(node*2+1,mid+1,r);
	PushUp(node);
}
int query(int node,Node tmp){
	if (tmp.x1>=tree[node].x1 && tmp.x2>=tree[node].x2 && tmp.x3>=tree[node].x3 && tmp.x4>=tree[node].x4 && tmp.x5>=tree[node].x5){
		return tree[node].sum;
	}
	if (tree[node].l==tree[node].r){
		return 0;
	}
	return query(node*2,tmp)+query(node*2+1,tmp);
}
bool cmp(Node x,Node y){
	if (x.x1!=y.x1)
		return x.x1<y.x1;
	else if (x.x2!=y.x2)
		return x.x2<y.x2;
	else if (x.x3!=y.x3)
		return x.x3<y.x3;
	else if (x.x4!=y.x4)
		return x.x4<y.x4;
	else
		return x.x5<y.x5;
}
int main(){
	int t,n,m,q;
	cin>>t;
	while (t--){
		cin>>n>>m;
		for (int i=1;i<=n;i++){
			cin>>a[i].x1>>a[i].x2>>a[i].x3>>a[i].x4>>a[i].x5;
		}
		sort(a+1,a+n,cmp);
		build(1,1,n);
		cin>>q;
		Node tmp;
		int ans=0;
		for (int i=0;i<q;i++){
			cin>>tmp.x1>>tmp.x2>>tmp.x3>>tmp.x4>>tmp.x5;
			if (i){
				tmp.x1=tmp.x1^ans;
				tmp.x2=tmp.x2^ans;
				tmp.x3=tmp.x3^ans;
				tmp.x4=tmp.x4^ans;
				tmp.x5=tmp.x5^ans;
			}
			ans=query(1,tmp);
			cout<<ans<<endl;
		}
	}

	return 0;
}