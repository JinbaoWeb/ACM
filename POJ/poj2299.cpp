/*******************************************************************************
 * Author :          jinbao
 * Email :           dongjinbao913106840144@gmail.com
 * Last modified :   2015-05-04 00:19
 * Filename :        poj2299.cpp
 * Description :     
 * *****************************************************************************/
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX = 500000+5;
int tree[4*MAX];
struct array{
	int index;
	int value;
}a[MAX];
int n;
bool cmp(array x,array y){
	if (x.value<y.value)
		return true;
	return false;
}
void build(int node,int begin,int end){
	if (begin==end)
		tree[node]=1;
	else{
		build(node*2,begin,(begin+end)/2);
		build(node*2+1,(begin+end)/2+1,end);
		tree[node]=tree[node*2]+tree[node*2+1];
	}
}
int query(int node,int begin,int end,int left,int right){
	if (left>right)
		return 0;
	if (end<left || right<begin)
		return 0;
	if (begin>=left && right>=end)
		return tree[node];
	return query(node*2,begin,(begin+end)/2,left,right)+query(node*2+1,(begin+end)/2+1,end,left,right);
}
void update(int node,int begin,int end,int index,int value){
	if (begin==end){
		tree[node]=value;
		return;
	}
	int mid=(begin+end)/2;
	if (mid>=index)
		update(node*2,begin,mid,index,value);
	else
		update(node*2+1,mid+1,end,index,value);
	tree[node]=tree[node*2]+tree[node*2+1];
}
int main(){
	while (~scanf("%d",&n)){
		if (n==0)
			break;
		for (int i=1;i<=n;i++){
			scanf("%d",&a[i].value);
			a[i].index=i;
		}
		sort(a+1,a+n+1,cmp);
		build(1,1,n);;
		ll ans=0;
		for (int i=1;i<=n;i++){
			ans+=query(1,1,n,1,a[i].index-1);
			update(1,1,n,a[i].index,0);
		}
		printf("%lld\n",ans);
	}

	return 0;
}