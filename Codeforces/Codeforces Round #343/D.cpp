#include <bits/stdc++.h>
using namespace std;
#define M_PI 3.1415926535
typedef long long ll;
struct Node{
	ll num;
	int l,r;
}tree[4*100001];
ll a[100000+1],b[100000+1];
void build(int node,int l,int r){
	//cout<<l<<" "<<r<<endl;
	tree[node].l=l,tree[node].r=r,tree[node].num=0;
	if (l==r)
		return;
	int mid=(l+r)/2;
	build(node*2,l,mid);
	build(node*2+1,mid+1,r);
}
void update(int node,int x,ll v){
	if (tree[node].l==x && x==tree[node].r){
		tree[node].num=v;
		return;
	}
	int mid=(tree[node].l+tree[node].r)/2;
	if (x<=mid)
		update(node*2,x,v);
	else
		update(node*2+1,x,v);
	tree[node].num=max(tree[node*2].num,tree[node*2+1].num);
}
ll query(int node,int l,int r){
	//cout<<node<<" "<<tree[node].l<<" "<<tree[node].r<<" "<<endl;
	if (l<=tree[node].l && tree[node].r<=r){
		return tree[node].num;
	}
	int mid=(tree[node].l+tree[node].r)/2;
	if (r<=mid)
		return query(node*2,l,r);
	else if (mid<l)
		return query(node*2+1,l,r);
	else{
		return max(query(node*2,l,mid),query(node*2+1,mid+1,r));
	}
}
int main(){
	int n,r,h;
	ll one=1;
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%d%d",&r,&h);
		a[i]=one*r*r*h;
		b[i]=a[i];
	}
	sort(b,b+n);
	build(1,1,n);
	for (int i=0;i<n;i++){
		int x=lower_bound(b,b+n,a[i])-b+1;
		ll temp=query(1,1,x);
		update(1,x,a[i]+temp);
	}
	double ans=query(1,1,n)*M_PI;
	printf("%.9f\n",ans );
	//cout<<query(1,1,100000)*M_PI<<endl;
	return 0;
}