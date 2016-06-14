/*******************************************************************************
 * Author :          jinbao
 * Email :           dongjinbao913106840144@gmail.com
 * Last modified :   2015-04-28 09:29
 * Filename :        hdu1166.cpp
 * Description :     
 * *****************************************************************************/
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int MAX = 50000+5;
int a[MAX];	
int tree[MAX*4];	//线段树
void build(int node,int begin,int end){	//构造线段树
	if (begin==end)
		tree[node]=a[begin];
	else{
		build(node*2,begin,(begin+end)/2);
		build(node*2+1,(begin+end)/2+1,end);
		tree[node]=tree[node*2]+tree[node*2+1];
	}
}
int query(int node,int begin,int end,int left,int right){	//查询线段树
	if (end<left || right<begin)
		return 0;
	if (left<=begin && end<=right)
		return tree[node];
	return query(2*node,begin,(begin+end)/2,left,right)+query(2*node+1,(begin+end)/2+1,end,left,right);
}
void update(int node,int begin,int end,int index,int value){
	if (begin==end){
		tree[node]+=value;
		return;
	}
	int m=(begin+end)/2;
	if (index<=m)
		update(node*2,begin,m,index,value);
	else
		update(node*2+1,m+1,end,index,value);
	tree[node]=tree[node*2]+tree[node*2+1];
}
int main(){
	int t,n,x,y;
	char s[10];
	scanf("%d",&t);
	for (int cas=1;cas<=t;cas++){
		printf("Case %d:\n",cas);
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		build(1,1,n);
		while (~scanf("%s",&s)){
			if (strcmp(s,"End")==0)
				break;
			if (strcmp(s,"Query")==0){
				scanf("%d%d",&x,&y);
				printf("%d\n",query(1,1,n,x,y));
			}
			if (strcmp(s,"Add")==0){	
				scanf("%d%d",&x,&y);
				update(1,1,n,x,y);
			}
			if (strcmp(s,"Sub")==0){	
				scanf("%d%d",&x,&y);
				update(1,1,n,x,-y);
			}
		}
	}
	return 0;
}
