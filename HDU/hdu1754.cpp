/*******************************************************************************
 * Author :          jinbao
 * Email :           dongjinbao913106840144@gmail.com
 * Last modified :   2015-04-27 21:00
 * Filename :        hdu1754.cpp
 * Description :     
 * *****************************************************************************/
#include <iostream>
#include <stdio.h>
using namespace std;
#define max(a,b)	a>b?a:b
#define inf -1
const int MAX = 200000+5;
int a[MAX];
int tree[MAX*4];
void build(int node,int begin,int end){
	if (begin==end)
		tree[node]=a[begin];
	else{
		build(2*node,begin,(begin+end)/2);
		build(2*node+1,(begin+end)/2+1,end);
		tree[node]=max(tree[2*node],tree[2*node+1]);
	}
}
int query(int node,int begin,int end,int left,int right){
	if (end<left || right<begin)
		return -1;
	if (begin>=left && end<=right)
		return tree[node];
	int p=query(2*node,begin,(begin+end)/2,left,right);
	int q=query(2*node+1,(begin+end)/2+1,end,left,right);
	if (q>p)
		return q;
	return p;
}
void update(int node,int begin,int end,int index,int value){
	if (begin==end){
		tree[node]=value;
		return;
	}
	int m=(begin+end)/2;
	if (index<=m)
		update(node*2,begin,m,index,value);
	else
		update(node*2+1,m+1,end,index,value);
	tree[node]=max(tree[2*node],tree[2*node+1]);
}
int main(){
	int n,m;
	char s;
	int x,y;
	while (~scanf("%d%d",&n,&m)){
		for (int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		build(1,1,n);
		for (int i=0;i<m;i++){
			scanf("\n%c%d%d",&s,&x,&y);
			if (s=='Q')
				printf("%d\n",query(1,1,n,x,y));
			else{
 				update(1,1,n,x,y);
			}
		}
	}

	return 0;
}
