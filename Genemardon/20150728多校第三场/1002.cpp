#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int MAXN = 1e6+10;
struct Node{
	int l,r;
	short a[8];
}tree[2100000];
int cnt[8];
//快速读入
short arr[MAXN];
inline void read(int &x){
    char c=0;
    for(;c<'0'||c>'9';c=getchar());
    for(x=0;c>='0'&&c<='9';c=getchar())x=x*10+(c-'0');
}
bool isprime(int x){
	if (x<2) return false;
	if (x==2 || x==3 || x==5 || x==7)
		return true;
	for (int i=2;i*i<=x;i++){
		if (x%i==0)
			return false;
	}
	return true;
}
void init(){
	memset(arr,0,sizeof(arr));
	for (int i=2;i<MAXN;i++){
		if (isprime(i)==true){
			for (int j=1;j*i<MAXN;j++){
				arr[i*j]++;
			}
		}
	}
}
void PushUp(int node){
	for (int i=1;i<8;i++){
		tree[node].a[i]=tree[node*2].a[i]+tree[node*2+1].a[i];
		if (tree[node].a[i]>=2)
			tree[node].a[i]=2;
	}
}
//int Max=0;
void build(int node,int l,int r){
	//if (node>Max)
		//Max=node;
	tree[node].l=l,tree[node].r=r;
	memset(tree[node].a,0,sizeof(tree[node].a));
	if (l==r){
		/*
		int k=0;
		int temp=l;
		for (int j=2;j*j<=temp;j++){
			if (temp%j==0){
				k++;
				while (temp%j==0)
					temp/=j;
			}
		}
		if (temp!=1)
			k++;
		tree[node].a[k]++;
		if (tree[node].a[k]>=2)
			tree[node].a[k]=2;
			*/
		tree[node].a[arr[l]]++;
		return;
	}
	build(node*2,l,(l+r)/2);
	build(node*2+1,(l+r)/2+1,r);
	PushUp(node);
}
void query(int node,int l,int r){
	if (l<=tree[node].l&&tree[node].r<=r){
		for (int i=1;i<8;i++){
			cnt[i]+=tree[node].a[i];
		}
		return;
	}
	int mid=(tree[node].l+tree[node].r)/2;
	if (r<=mid)
		query(node*2,l,r);
	else if (mid<l)
		query(node*2+1,l,r);
	else{
		query(node*2,l,mid);
		query(node*2+1,mid+1,r);
	}
}
void Debug(int node){
	for (int i=0;i<4*node;i++){
		for (int j=1;j<8;j++)
			printf("%d ",tree[i].a[j]);
		printf("\n");
	}
}
int main(){
	int t,l,r;
	read(t);
	init();
	build(1,1,1000000);
	//printf("%d\n",Max );
	while (t--){
		read(l),read(r);
		//Debug(r);
		memset(cnt,0,sizeof(cnt));
		query(1,l,r);
		/*for (int i=0;i<8;i++)
			printf("%d ",cnt[i] );
		printf("\n");*/
		for (int i=7;i>=1;i--){
			if (cnt[i]>=2){
				printf("%d\n",i);
				break;
			}
			else{
				if (i==3 && cnt[6]>=1){
					printf("%d\n",i );
					break;
				}
				if (i==2 && cnt[4]>=1){
					printf("%d\n",i );
					break;
				}
			}
		}
	}

	return 0;
}