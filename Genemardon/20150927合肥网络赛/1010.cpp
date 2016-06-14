#include <bits/stdc++.h>
using namespace std;
struct Node{
	int h,k;
}P[100000+10];
int a[100000+10];
int ans[100000+10];
struct Node2{
	int l,r;
	int sum;
}tree[4*100000+10];
void build(int node,int l,int r){
	tree[node].l=l,tree[node].r=r;
	if (l==r){
		tree[node].sum=1;
		return;
	}
	int mid=(l+r)/2;
	build(node*2,l,mid);
	build(node*2+1,mid+1,r);
	tree[node].sum=tree[node*2].sum+tree[node*2+1].sum;
}
void update(int node,int x){
	if (tree[node].l==tree[node].r && tree[node].l==x){
		tree[node].sum=0;
		return;
	}
	int mid=(tree[node].l+tree[node].r)/2;
	if (x<=mid)
		update(node*2,x);
	else
		update(node*2+1,x);
	tree[node].sum=tree[node*2].sum+tree[node*2+1].sum;
}
int query(int node,int l,int r){
	if (l<=tree[node].l && tree[node].r<=r){
		return tree[node].sum;
	}
	int mid=(tree[node].l+tree[node].r)/2;
	if (r<=mid)
		return query(node*2,l,r);
	else if (mid<l)
		return query(node*2+1,l,r);
	else
		return query(node*2,l,mid)+query(node*2+1,mid+1,r);
}
bool cmp(Node a,Node b){
	return a.h<=b.h;
}
int main(){
	int t,n;
	scanf("%d",&t);
	for (int cas=1;cas<=t;cas++){
		scanf("%d",&n);
		for (int i=0;i<n;i++)
			scanf("%d%d",&P[i].h,&P[i].k);
		sort(P,P+n,cmp);
		build(1,1,n);
		int flag=1;
		for (int i=0;i<n;i++){
			int k=min(P[i].k+1,n-i-P[i].k);
			if (k<=0) 
			{
				flag=0;
				break;
			}
			//cout<<k<<"k="<<endl;
			int l=0,r=n;
			int x;
			while (l<r-1){
				x=(l+r)/2;
				int q=query(1,1,x);
				//cout<<q<<"---------"<<endl;
				if (q<k)
					l=x;
				else if (q>=k)
					r=x;
			}
			//cout<<r<<endl;
			update(1,r);
			//cout<<"---------"<<endl;
			ans[r]=P[i].h;
		}
		if (flag==0)
		{
			printf("Case #%d: impossible\n",cas );
			continue;
		}
		printf("Case #%d: ",cas );
		for (int i=1;i<n;i++)
			cout<<ans[i]<<" ";
		cout<<ans[n]<<endl;
	}

	return 0;
}