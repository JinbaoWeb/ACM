/*******************************************************************************
 * Author :          jinbao
 * Email :           dongjinbao913106840144@gmail.com
 * Last modified :   2015-05-21 20:23
 * Filename :        poj2777.cpp
 * Description :     
 * *****************************************************************************/
#include <iostream>
#include <stdio.h>
using namespace std;
const int MAX = 100000+2;
struct Node{
	int l,r;
	int col;	//颜色
	bool cover;//整个区间是否被同一种颜色覆盖
}tree[4*MAX];
void build(int node,int begin,int end){
	tree[node].l=begin;
	tree[node].r=end;
	tree[node].col=1;
	tree[node].cover=true;
	if (begin==end)
		return;
	build(node*2,begin,(begin+end)/2);
	build(node*2+1,(begin+end)/2+1,end);
}
void PushDown(int node){
	int val=tree[node].col;
	tree[node].cover=false;
	tree[node*2].col=val;
	tree[node*2].cover=true;
	tree[node*2+1].col=val;
	tree[node*2+1].cover=true;
}
void update(int node,int left,int right,int value){
	if (left==tree[node].l && tree[node].r==right){
		tree[node].col=1<<(value-1);
		tree[node].cover=true;
		return;
	}
	if  (tree[node].cover){
		PushDown(node);
	}
	int mid=(tree[node].l+tree[node].r)>>1;
	if (right<=mid){
		update(node*2,left,right,value);
	}
	else if (mid<left){
		update(node*2+1,left,right,value);
	}
	else{
		update(node*2,left,mid,value);
		update(node*2+1,mid+1,right,value);
	}
	tree[node].col=tree[node*2].col | tree[node*2+1].col;
}
int query(int node,int left,int right){
	if (tree[node].cover || (tree[node].l==left&&tree[node].r==right)){
		return tree[node].col;
	}
	int mid=(tree[node].l+tree[node].r)>>1;
	if (mid>=right)
		return query(node*2,left,right);
	else if (mid<left){
		return query(node*2+1,left,right);
	}
	else{
		return query(node*2,left,mid) | query(node*2+1,mid+1,right);
	}
}
int main(){
	int l,t,o;
	char s;
	int a,b,c;
	while (~scanf("%d%d%d",&l,&t,&o)){
		build(1,1,l);
		//cout<<"--------------\n";
		while (o--){
			cin>>s;
			if (s=='C'){
		 	scanf("%d%d%d",&a,&b,&c);
				if (a>b){
		 			int temp=a;
					a=b;
					b=temp;
				}
				update(1,a,b,c);
			}
			else{
		 	scanf("%d%d",&a,&b);
				if (a>b){
		 			int temp=a;
					a=b;
					b=temp;
				}
				int k=query(1,a,b);
				int ans=0;
				for (int i=0;i<t;i++){
		 			if ((1<<i) & k)
						ans++;
				}
				cout<<ans<<endl;
			}
		}
	}

	return 0;
}
