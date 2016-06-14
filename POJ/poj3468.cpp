/*******************************************************************************
 * Author :          jinbao
 * Email :           dongjinbao913106840144@gmail.com
 * Last modified :   2015-05-02 09:54
 * Filename :        poj3468.cpp
 * Description :     
 * *****************************************************************************/
#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long ll;
const int MAX = 100001;
struct Node{
	int l,r;//
	ll sum;	//存储每个节点的子节点数值的总和
	ll add;	//记录结点增加的值
}tree[4*MAX];	//线段树
void build(int node,int begin,int end){	//构造线段树
	tree[node].l=begin;
	tree[node].r=end;
	tree[node].add=0;
	//cout<<node<<endl;
	if (begin==end){
		scanf("%lld",&tree[node].sum);
	}
	else{
		build(node*2,begin,(begin+end)/2);	//递归构造左子树
		build(node*2+1,(begin+end)/2+1,end);	//递归构造右子树
		tree[node].sum=tree[node*2].sum+tree[node*2+1].sum;
	}
}
void PushDown(int node){
	if (tree[node].add){
		int m=tree[node].r-tree[node].l+1;
		tree[node*2].add+=tree[node].add;
		tree[node*2+1].add+=tree[node].add;
		tree[node*2].sum+=tree[node].add*(m-m/2);
		tree[node*2+1].sum+=tree[node].add*m/2;
		tree[node].add=0;
	}
}
ll query(int node,int left,int right){

	if (tree[node].l==left && tree[node].r==right)
		return tree[node].sum;
	PushDown(node);
	int m=(tree[node].l+tree[node].r)/2;
	ll ans=0;
	if (m>=right)
		ans+=query(node*2,left,right);
	else if (m<left)
		ans+=query(node*2+1,left,right);
	else{
		ans+=query(node*2,left,m);
		ans+=query(node*2+1,m+1,right);
	}
	return ans;
}
void update(int node,int left,int right,int value){
	if (tree[node].l==left && tree[node].r==right){
		tree[node].add+=value;
		tree[node].sum+=(ll)value*(right-left+1);
		return;
	}
	if (tree[node].l==tree[node].r)
		return;
	PushDown(node);
	int m=(tree[node].l+tree[node].r)/2;
	if (m>=right)
		update(node*2,left,right,value);
	else if (m<left)
		update(node*2+1,left,right,value);
	else{
		update(node*2,left,m,value);
		update(node*2+1,m+1,right,value);
	}
	tree[node].sum=tree[node*2].sum+tree[node*2+1].sum;
}
int main(){
	int n,m,l,r,v;
	char s;
	while (~scanf("%d%d",&n,&m)){
	//	cout<<"--------";
		build(1,1,n);
		for (int i=0;i<m;i++){
			scanf("\n%c",&s);
			if (s=='Q'){
				scanf("%d%d",&l,&r);
				printf("%lld\n",query(1,l,r));
			}
			else{
 				scanf("%d%d%d",&l,&r,&v);
				update(1,l,r,v);
			}
		}
	}

	return 0;
}
