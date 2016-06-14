#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAXN = 5000+5;
//扫描线
struct ScanLine{	
	int x;		//扫描线的横坐标
	int y1,y2;	//扫描线的上、下纵坐标
	int flag;	//标记为矩阵左右边，0表示右边，1表示左边
}scan[MAXN];
//线段树
struct Node{
	int l,r;	//线段树的范围
	int count;	//被覆盖的次数
	int line;	//所包含区间的数目
	int lbd,rbd;//左右端点是否被覆盖
	int m;		//测度 
}tree[4*MAXN];

int y[MAXN];

void build(int node,int l,int r){
	tree[node].l=l,tree[node].r=r;
	tree[node].count=0;
	tree[node].m=0;
	tree[node].line=0;
	if (r-l==1)
		return;
	build(node*2,l,(l+r)/2);
	build(node*2+1,(l+r)/2,r);
}
void update(int node){
	if (tree[node].count>0){
		tree[node].m=y[tree[node].r]-y[tree[node].l];
		tree[node].line=1;
		tree[node].lbd=tree[node].rbd=1;
	}
	else if (tree[node].r-tree[node].l==1){
		tree[node].line=tree[node].lbd=tree[node].rbd=0;
	}
	else{
		tree[node].lbd=tree[node*2].lbd;
		tree[node].rbd=tree[node*2+1].rbd;
		tree[node].line=tree[node*2].line+node[2*i+1].line-tree[2*i].rbd*tree[2*i+1].lbd;
	}
}
void insert(int node,int l,int r){
	if (r<y[tree[node].l] || y[tree[node].r]<l)
		return;
	if (l<=y[tree[node].l] && y[tree[node].r]<=r){
		tree[node].count++;

		return;
	}
	if (tree[node].r-tree[node].l==1)
		return;
	insert(node*2,l,r);
	insert(node*2+1,l,r);

}
bool cmp(ScanLine a,ScanLine b){
	if (a.x==b.x)
		return a.flag>b.flag;
	return a.x<b.x;
}
int main(){
	int n;
	int x1,y1,x2,y2;
	while (~scanf("%d",&n)){
		int k=0;
		for (int i=0;i<n;i++){
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			scan[k].x=x1;
			scan[k].y1=y1;
			scan[k].y2=y2;
			scan[k].flag=1;
			y[k++]=y1;
			scan[k].x=x1;
			scan[k].y1=y1;
			scan[k].y2=y2;
			scan[k].flag=0;
			y[k++]=y2;
		}
		sort(y,y+k);
		sort(scan,scan+k,cmp);
		int num=unique(y,y+k)-y;
		build(1,1,num);
		for (int i=0;i<k;i++){
			if (scan[i].flag==1){
				insert(1,scan[i].y1,scan[i].y2);
			}
		}
	}

	return 0;
}