#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAX = 8000+5;
struct Node{
	int l,r;
	int color;
}tree[3*MAX];
int ans[MAX];
void build(int node,int left,int right){
	//cout<<left<<" "<<right<<endl;
	tree[node].l=left;
	tree[node].r=right;
	tree[node].color=-1;
	if (left==right)
		return;
	build(node*2,left,(left+right)/2);
	build(node*2+1,(left+right)/2+1,right);
}
void PushDown(int node){
	tree[2*node].color=tree[2*node+1].color=tree[node].color;
	tree[node].color=-1;
}
void update(int node,int left,int right,int color){
	//cout<<tree[node].l<<" "<<left<<" "<<tree[node].r<<" "<<right<<endl;
	if (tree[node].color==color)
		return;
	if (tree[node].l>=left&&tree[node].r<=right){
		tree[node].color=color;
		return;
	}
	if (tree[node].color!=-1){
		PushDown(node);
	}
	int mid=(tree[node].l+tree[node].r)/2;
	if (mid>=right)
		update(node*2,left,right,color);
	else if (mid<left){
		update(node*2+1,left,right,color);
	}
	else{
		update(node*2,left,right,color);
		update(node*2+1,left,right,color);
	}
	if (tree[node*2].color==tree[node*2+1].color&&tree[node*2].color!=-1)
		tree[node].color=tree[node*2].color;
}
void query(int node){
	if (tree[node].color!=-1){
		for (int i=tree[node].l;i<=tree[node].r;i++){
			ans[i]=tree[node].color;
		}
		return;
	}
	if (tree[node].l==tree[node].r)
		return;
	query(2*node);
	query(2*node+1);
}
void print(){
	int res[MAX];
	memset(res,0,sizeof(res));
	int pre=-1;
	for (int i=0;i<MAX;i++){
		if (pre!=ans[i]){
			pre=ans[i];
			res[pre]++;
		}
	}
	for (int i=0;i<MAX;i++){
		if (res[i]!=0)
			printf("%d %d\n",i,res[i]);
	}
	cout<<endl;
}
int main(){
	int n,a,b,c;
	while (~scanf("%d",&n)){
		memset(ans,-1,sizeof(ans));
		build(1,0,8000);
		while (n--){
			scanf("%d%d%d",&a,&b,&c);
			if (a==b)
				continue;
			update(1,a,b-1,c);
		}
		query(1);
		print();
	}
	return 0;
}