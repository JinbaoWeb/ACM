#include <iostream>
#include <stdio.h>
using namespace std;
const int MAXN = 100000+10;
const int MAXM = 1000000+10;
struct Node{
	int l,r;
	int p;
	int num;
}tree[4*MAXN];
int a[MAXN];
bool isprime(int x){
	if (x<2)
		return false;
	if (x==3 || x==2 || x==5 || x==7)
		return true;
	for (int i=2;i*i<=x;i++){
		if (x%i==0)
			return false;
	}
	return true;
}
inline void read(int &x){
    char c=0;
    for(;c<'0'||c>'9';c=getchar());
    for(x=0;c>='0'&&c<='9';c=getchar())x=x*10+(c-'0');
}
bool check(int x){
	if (x==1 || x==6)
		return true;
	int y=x;
	while (y%2==0)
		y/=2;
	if (y==1)
		return true;
	if (isprime(x)==true)
		return true;
	return false;
}
void build(int node,int l ,int r){
	tree[node].l=l,tree[node].r=r,tree[node].p=0;
	if (l==r){
		if (check(a[l])==true)
			tree[node].num=1;
		else
			tree[node].num=0;
		return;
	}
	build(node*2,l,(l+r)/2);
	build(node*2+1,(l+r)/2+1,r);
	tree[node].num=tree[node*2].num+tree[node*2+1].num;
}
void PushDown(int node){
	if (tree[node].p){
		tree[node*2].p=tree[node*2+1].p=tree[node].p;
		tree[node].p=0;
	}
}
void update(int node,int x,int v){
	if (tree[node].l==tree[node].r && tree[node].l==x){
		tree[node].num=v;
		return;
	}
	PushDown(node);
	int mid=(tree[node].l+tree[node].r)/2;
	if (x<=mid)
		update(node*2,x,v);
	else
		update(node*2+1,x,v);
}
void update2(int node,int l,int r,int v){
	if (tree[node].l==tree[node].r){
		a[tree[node].l]%=v;
		if (check(a[tree[node].l])==true)
			tree[node].num=1;
		else
			tree[node].num=0;
		return;
	}
	int mid=(tree[node].l+tree[node].r)/2;
	if (r<=mid)
		update2(node*2,l,r,v);
	else if (mid<l)
		update2(node*2+1,l,r,v);
	else{
		update2(node*2,l,mid,v);
		update2(node*2+1,mid+1,r,v);
	}
}
int query(int node,int l,int r){
	if (l<=tree[node].l && tree[node].r<=r){
		return tree[node].num;
	}
	int mid=(tree[node].l+tree[node].r)/2;
	if (r<=mid)
		return query(node*2,l,r);
	else if (mid<l)
		return query(node*2+1,l,r);
	else
		return query(node*2,l,mid)+query(node*2+1,mid+1,r);
}
int main(){
	int n,t;
	int op,b,c,d;
	while (~scanf("%d",&n)){
		for (int i=1;i<=n;i++){
			read(a[i]);
			//scanf("%d",&a[i]);
		}
		build(1,1,n);
		read(t);
		//scanf("%d",&t);
		while (t--){
			read(op);
			read(b);
			read(c);
			//scanf("%d%d%d",&op,&b,&c);
			if (op==1){
				printf("%d\n",query(1,b,c));
			}
			if (op==2){
				read(d);
				//scanf("%d",&d);
				update2(1,b,c,d);
				/*
				for (int i=b;i<=c;i++){
					bool first = check(a[i]);
					a[i]%=d;
					bool second = check(a[i]);
					if (first == second)
						continue;
					update(1,i,second);
				}
				*/
			}
			if (op==3){
				bool first = check(a[b]);
				bool second = check(c);
				if (first == second)
					continue;
				update(1,b,second);
			}
		}
	}

	return 0;
}