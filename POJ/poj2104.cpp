/*******************************************************************************
 * Author :          jinbao
 * Email :           dongjinbao913106840144@gmail.com
 * Last modified :   2015-06-08 20:30
 * Filename :        poj2104.cpp
 * Description :     
 * *****************************************************************************/
#include <bits/stdc++.h>
using namespace std;
int n,m;
int tree[20][100005],sum[20][100005];	//sum[i][j]：在第i层前j个数中有多少个数进入了左子区间
int a[100005];
void build(int level,int left,int right){
	if (left==right) return;	//只有一个节点
	int mid=(left+right)>>1;	//在a[left-right]之间的中位数a[mid]
	int count=0;	//统计跟a[mid]相等的值的个数
	for (int i=left;i<=right;i++)
		if (tree[level][i]==a[mid])
			count++;
	int l=left,r=mid+1;	// l:在左子区间的开始位置， r：在右子区间的开始位置
	for (int i=left;i<=right;i++){	//遍历left-right之间的点
		if (i==left)	//初始化
			sum[level][i]=0;
		else
			sum[level][i]=sum[level][i-1];
		if (l<=mid && ((tree[level][i]<a[mid])||(tree[level][i]==a[mid]&&count-->0)))	//进入左子区间
			sum[level][i]++,tree[level+1][l++]=tree[level][i];	//由于这个数要进入左子区间，所以sum需要加一
		else	//进入右子区间
			tree[level+1][r++]=tree[level][i];
	}
	build(level+1,left,mid);
	build(level+1,mid+1,right);
}
int query(int level,int left,int right,int l,int r,int k){
	cout<<l<<" "<<r<<endl;
	if (l==r) return tree[level][l];
	int mid=(l+r)>>1;
	int lsum=0;
	if (left>l) lsum=sum[level][left-1];
	int t=sum[level][right]-lsum;
	if (t>=k) return query(level+1,l+lsum,l+sum[level][right]-1,l,mid,k);
	return query(level+1,mid+1+left-l-lsum,mid+1+right-l-sum[level][right],mid+1,r,k);

}
int main(){
	while(~scanf("%d%d",&n,&m)){
		for (int i=1;i=n;i++){
			scanf("%d",&tree[0][i]);
			a[i]=tree[0][i];
		}
		for (int i=0; i<20; i++) sum[i][0]=0;
		sort(a+1,a+n+1);
		build();
	}
    return 0;
}
