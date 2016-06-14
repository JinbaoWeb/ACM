/*******************************************************************************
 * Author :          jinbao
 * Email :           dongjinbao913106840144@gmail.com
 * Last modified :   2015-04-27 20:01
 * Filename :        201504272001.cpp
 * Description :     线段树 
 * *****************************************************************************/
#include <iostream>
using namespace std;
#define min(a,b)	(a)<(b)?(a):(b)
#define max(a,b)	(a)>(b)?(a):(b)
#define inf 0xffffffff 
const int MAX = 10000;	//数组的大小
int a[MAX];	//区间数组
int tree[4*MAX+10];	//线段树
/********************************************************************************
 * 构造线段树
 *	node:当前在线段树的位置
 * begin:当前结点存储区间的下限
 *	 end:当前结点存储区间的上限
 * *****************************************************************************/
void build(int node,int begin,int end){
	if (begin==end)
		tree[node]=a[begin];	//叶子节点
	else{
		build(2*node,begin,(begin+end)/2);	//递归构造左子树
		build(2*node+1,(begin+end)/2+1,end);	//递归构造右子树
		tree[node]=min(tree[2*node],tree[2*node+1]);	//依据题目而定
	}
}
/********************************************************************************
 * 线段树的查询
 *	node:当前在线段树的位置
 * begin:当前结点存储区间的下限
 *	 end:当前结点存储区间的下限
 *	left:查询区间的下限
 * right:查询区间的上限
 * *****************************************************************************/
int query(int node,int begin,int end,int left,int right){
	if (end<left || right<begin){	//查询区间[left,right]与存储区间[begin,end]不存在交集
		return -1;
	}
	int p=query(2*node,begin,(begin+end)/2,left,right);	//查询左子树
	int q=query(2*node+1,(begin+end)/2+1,end,left,right);	//查询右子树
	//以下依据题目而定
	if (p==-1)
		return q;
	if (q==-1)
		return p;
	if (p<q)
		return p;
	return q;
}

int main(){


	return 0;
}