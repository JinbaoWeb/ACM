#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 30000+10;
int a[MAXN],b[MAXN],rt[MAXN];
int mp[MAXN];
struct Node{
	int l,r;
	ll sum;
}tree[20*MAXN];
int cur=0;
void PushUp(int k){
	tree[k].sum=tree[tree[k].l].sum+tree[tree[k].r].sum;
}
int build(int l,int r){
	int k=cur++;
	tree[k].sum=0;
	if (l==r) 
		return k;
	int mid=(l+r)/2;
	tree[k].l=build(l,mid);
	tree[k].r=build(mid+1,r);
	PushUp(k);
	return k;
}
int update(int node,int l,int r,int pos,int v){
	int k=cur++;
	tree[k]=tree[node];
	if (l==pos && r==pos){
		tree[k].sum+=v;
		return k;
	}
	int mid=(l+r)/2;
	if (pos<=mid)
		tree[k].l=update(tree[node].l,l,mid,pos,v);
	else
		tree[k].r=update(tree[node].r,mid+1,r,pos,v);
	PushUp(k);
	return k;
}
ll query(int node,int l,int r,int pos){
	if (l==r)
		return tree[node].sum;
	int mid=(l+r)/2;
	if (mid<=pos)
		return query(tree[node].l,l,mid,pos);
	else
		return tree[tree[node].l].sum+query(tree[node].r,mid+1,r,pos);
}
int main(){
	map<int,int> mp;
	int t,n,m;
	scanf("%d",&t);
	while (t--){
		mp.clear();
		scanf("%d",&n);
		for (int i=0;i<n;i++)
			scanf("%d",&a[i]);
		rt[0]=build(1,30000);
		for (int i=1;i<=n;i++){
			if (mp.find(a[i])==mp.end()){
				mp[a[i]]=i;
				rt[i]=update(rt[i-1],1,n,i,a[i]);
			}
			else{
				int temp=update(rt[i-1],1,n,mp[a[i]],-a[i]);
				rt[i]=update(temp,1,n,i,a[i]);
			}
			mp[a[i]]=i;
		}
		scanf("%d",&m);
		while (m--){
			int aa,bb;
			scanf("%d%d",&aa,&bb);
			ll ans=query(rt[bb],1,n,aa);
			cout<<ans<<endl;
		}
	}
	return 0;
}