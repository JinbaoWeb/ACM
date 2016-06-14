/*******************************************************************************
 * Author :          jinbao
 * Email :           dongjinbao913106840144@gmail.com
 * Last modified :   2015-06-10 00:42
 * Filename :        poj2761.cpp
 * Description :     
 * *****************************************************************************/
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
int n,m;
int a[100001];
int tree[20][100001],sum[20][100001];
void build(int level,int left,int right){
	if (left==right) return;
	int mid=(left+right)>>1;
	int count=0;
	for (int i=left;i<=right;i++)
		if (tree[level][i]==a[mid])
			count++;
	sum[level][left]=0;
	int l=left,r=mid+1;
	for (int i=left;i<=right;i++){
		if (i>left)
			sum[level][i]=sum[level][i-1];
		if (l<=mid && ((tree[level][i]<a[mid])||(tree[level][i]==a[mid] && count-->0)))
			tree[level+1][l++]=tree[level][i],sum[level][i]++;
		else
			tree[level+1][r++]=tree[level][i];
	}
	build(level+1,left,mid);
	build(level+1,mid+1,right);
}
int query(int level,int left,int right,int L,int R,int k){
	cout<<left<<" "<<right<<endl;
	if (left==right) return tree[level][right];
	int mid=(left+right)>>1;
	int lsum=0;
	if (L>left)
		lsum=sum[level][L-1];
	int t=sum[level][R]-lsum;
	if (t>=k)
		return query(level+1,left,mid,left+lsum,left+sum[level][R]-1,k);
	return query(level+1,mid+1,right,mid+1+L-left-lsum,mid+1+R-left-sum[level][R],k-t);
}
void debug(){
	for (int i=0;i<4;i++){
		for (int j=1;j<=n;j++)
			cout<<tree[i][j]<<" ";
		cout<<endl;
	}
	for (int i=0;i<4;i++){
		for (int j=1;j<=n;j++)
			cout<<sum[i][j]<<" ";
		cout<<endl;
	}
}
void solve(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%d",&tree[0][i]);
		a[i]=tree[0][i];
	}
	sort(a+1,a+n+1);
	for (int i=0;i<20;i++)
		sum[i][0]=0;
	build(0,1,n);
	int l,r,k;
	debug();
	for (int j=0;j<m;j++){
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",query(1,1,n,l,r,k));
	}
}
int main(){
	solve();
    return 0;
}

