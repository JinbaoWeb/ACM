#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 200000+10;
const int MAXM = 500000+10;
int father[MAXN];
struct Node{
	int l,r;
	int flag;
}tree[4*MAXM];
void build(int node,int l,int r){
	tree[node].l=l,tree[node].r=r;
	if (l==r){
		tree[node].flag=0;
		return;
	}
	build(node*2,l,(l+r)/2);
	build(node*2+1,(l+r)/2+1,r);
	tree[node].flag=0;
}
void update(int node,int l,int r){
	if (l<=tree[node].l && tree[node].r<=r){
		tree[node].flag=1;
		return;
	}
	int mid=(tree[node].l+tree[node].r)/2;
	if (r<=mid)
		update(node*2,l,r);
	else if (mid<l)
		update(node*2+1,l,r);
	else{
		update(node*2,l,mid);
		update(node*2+1,mid+1,r);
	}
	tree[node].flag=(tree[node*2].flag&&tree[node*2+1].flag);
}
int query(int node,int l,int r){
	if (l<=tree[node].l && r<=tree[node].r){
		return tree[node].flag;
	}
	//if (tree[node].l==tree[node].r)
		//return 1;
	int mid=(tree[node].l+tree[node].r)/2;
	if (r<=mid)
		return query(node*2,l,r);
	else if (mid<l)
		return query(node*2+1,l,r);
	else{
		return query(node*2,l,mid)&&query(node*2+1,mid+1,r);
	}
}
void init(int n){
	for (int i=0;i<=n;i++){
		father[i]=i;
	}
}
int find(int x){
	if (x==father[x])
		return x;
	return father[x]=find(father[x]);
}
void Union(int x,int y){
	x=find(x),y=find(y);
	if (x==y)
		return;
	if (x<y)
		father[y]=x;
	else
		father[x]=y;
}
int main(){
	int n,m,a,b,type;
	while (~scanf("%d%d",&n,&m)){
		init(n);
		build(1,1,n);
		while (m--){
			scanf("%d%d%d",&type,&a,&b);
			if (type==3){
				int ans=query(1,a,b);
				if (ans==1){
					printf("YES\n");
				}
				else{
					if (find(a)==find(b))
						printf("YES\n");
					else
						printf("NO\n");
				}
			}
			if (type==1){
				Union(a,b);
			}
			if (type==2){
				update(1,a,b);
			}
		}
	}
	return 0;
}