#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
const int MAX = 30005;
struct Node{
	int l,r;
	ll sum;
	bool flag;
}tree[MAX*4];
int array[MAX];
void build(int node,int left,int right){
	tree[node].l=left,tree[node].r=right;
	tree[node].flag=false;
	if (left==right){
		tree[node].sum=array[left];
		return;
	}
	build(node*2,left,(left+right)/2);
	build(node*2+1,(left+right)/2+1,right);
	tree[node].sum=tree[2*node].sum+tree[node*2+1].sum;
}
ll query(int node,int left,int right){
	//cout<<left<<" "<<right<<endl;
	if (tree[node].l>=left && tree[node].r<=right)
		return tree[node].sum;
	if (tree[node].flag){
		ll average=tree[node].sum/(tree[node].r-tree[node].l+1);
		tree[node*2].sum=average*(tree[node*2].r-tree[node*2].l+1);
		tree[node*2+1].sum=tree[node].sum-tree[node*2].sum;
		tree[node*2].flag=tree[node*2+1].flag=true;
		tree[node].flag=false;
	}
	int mid=(tree[node].l+tree[node].r)/2;
	if (mid>=right)
		return query(node*2,left,right);
	else if (mid<left)
		return query(node*2+1,left,right);
	else
		return query(node*2,left,mid)+query(node*2+1,mid+1,right);
}
void update(int node,int left,int right,ll value){
	//cout<<node<<" "<<left<<" "<<right<<" "<<value<<endl;
	if (tree[node].l==left&&tree[node].r==right){
		tree[node].sum=value*(tree[node].r-tree[node].l+1);
		tree[node].flag=true;
		return;
	}
	if (tree[node].flag){
		ll average=tree[node].sum/(tree[node].r-tree[node].l+1);
		tree[node*2].sum=average*(tree[node*2].r-tree[node*2].l+1);
		tree[node*2+1].sum=tree[node].sum-tree[node*2].sum;
		tree[node*2].flag=tree[node*2+1].flag=true;
		tree[node].flag=false;
	}
	int mid=(tree[node].l+tree[node].r)/2;
	if (mid>=right)
		update(node*2,left,right,value);
	else if (mid<left)
		update(node*2+1,left,right,value);
	else{
		update(node*2,left,mid,value);
		update(node*2+1,mid+1,right,value);
	}
	tree[node].sum=tree[node*2].sum+tree[node*2+1].sum;
}
void print(int node){
	if (tree[node].l==tree[node].r){
		if (tree[node].l!=1)
			cout<<" ";
		cout<<tree[node].sum;
		return;
	}
	if (tree[node].flag){
		ll average=tree[node].sum/(tree[node].r-tree[node].l+1);
		tree[node*2].sum=average*(tree[node*2].r-tree[node*2].l+1);
		tree[node*2+1].sum=tree[node].sum-tree[node*2].sum;
		tree[node*2].flag=tree[node*2+1].flag=true;
		tree[node].flag=false;
	}
	print(node*2);
	print(node*2+1);
}
ll myceil(ll sum,int n){
    if(sum>=0)
        return sum/n+(sum%n!=0);
    else
        return sum/n;
}

ll myfloor(ll sum,int n){
    if(sum>=0)
        return sum/n;
    else
        return sum/n-(sum%n!=0);
}
int main(){
	int n,m,a,b;
	while (~scanf("%d%d",&n,&m)){
		ll oldSum=0,curSum=0,segSum,average;
		for (int i=1;i<=n;i++){
			scanf("%lld",&array[i]);
			oldSum+=array[i];
		}
		build(1,1,n);
		while (m--){
			scanf("%d%d",&a,&b);
			curSum=query(1,1,n);
            segSum=query(1,a,b);
            if(curSum<=oldSum)
                average=myceil(segSum,b-a+1);
            else
                average=myfloor(segSum,b-a+1);
            //cout<<average<<endl;
			update(1,a,b,average);
			//print(1);
			//cout<<endl;
		}
		print(1);
		cout<<endl<<endl;
	}
	return 0;
}