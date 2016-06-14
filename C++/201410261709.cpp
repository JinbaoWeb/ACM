#include <iostream>
using namespace std;
struct node{
	int l,r,value;
}tree[100002];
void bulid(int v,int l,int r){
	tree[v].l=l;
	tree[v].r=r;
	if (l==r){
		tree[v].value=0;
		return;
	}
	int mid=(l+r)/2;
	bulid(v*2,l,mid);
	bulid(v*2,mid+1,r);
	tree[v].value=tree[v*2].value+tree[v*2+1].value;
}
void update(int v,int l,int r){
	cout<<tree[v].l<<" "<<tree[v].r<<endl;
	if (tree[v].l==l && tree[v].r==r){
		tree[v].value=r-l+1-tree[v].value;
		return;
	}
	int mid=(tree[v].l+tree[v].r)/2;
	if (r<=mid){
		update(v*2,l,r);
	}
	else{
		if (l>mid){
			update(v*2+1,l,r);
		}
		else{
			cout<<"--"<<endl;
			cout<<l<<" "<<mid<<endl;
			update(v*2,l,mid);
			update(v*2+1,mid+1,r);
		}
	}
}
void query(int v,int l,int r){
	if (tree[v].l==l && tree[v].r==r){
		cout<<tree[v].value<<endl;
		return;
	}
	int mid=(tree[v].l+tree[v].r)/2;
	if (r<=mid){
		query(v*2,l,r);
	}
	else{
		if (l>mid){
			query(v*2+1,l,r);
		}
		else{
			query(v*2,l,mid);
			query(v*2+1,mid+1,r);
		}
	}
}
int main(){
	int t,n,q,a,b,c;
	cin>>t;
	while (cin>>n>>q){
		bulid(1,0,n-1);
		for (int i=0;i<q;i++){
			cin>>a>>b>>c;
			if (a==0){
				update(1,b,c);
			}
			else{
				query(1,b,c);
			}
		}
	}
	return 0;
} 
