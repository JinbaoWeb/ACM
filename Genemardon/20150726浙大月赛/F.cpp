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
		if (tree[node*2].l==tree[node*2].r){
			a[tree[node*2].l]%=tree[node*2].p;
			if (check(a[tree[node*2].l])==true)
				tree[node].num=1;
			else
				tree[node].num=0;
		}
		if (tree[node*2+1].l==tree[node*2+1].r){
			a[tree[node*2+1].l]%=tree[node*2+1].p;
			if (check(a[tree[node*2+1].l])==true)
				tree[node].num=1;
			else
				tree[node].num=0;
		}
		tree[node].num=tree[node*2].num+tree[node*2+1].num;
		tree[node].p=0;
	}
}
void update(int node,int l,int r,int v){
	if (l<=tree[node].l && tree[node].r<=r){
		tree[node].p=v;
		return;
	}
	PushDown(node);
	int mid=(tree[node].l+tree[node].r)/2;
	if (r<=mid)
		update(node*2,l,r,v);
	else if (mid<l)
		update(node*2+1,l,r,v);
	else{
		update(node*2,l,mid,v);
		update(node*2+1,mid+1,r,v);
	}
	tree[node].num=tree[node*2].num+tree[node*2+1].num;
}
void Set(int node,int x,int v){
	if (tree[node].l==tree[node].r && tree[node].l==x){
		a[x]=v;
		if (check(a[x])==true)
			tree[node].num=1;
		else
			tree[node].num=0;
		return;
	}
	PushDown(node);
	int mid=(tree[node].l+tree[node].r)/2;
	if (x<=mid)
		Set(node*2,x,v);
	else
		Set(node*2+1,x,v);
	tree[node].num=tree[node*2].num+tree[node*2+1].num;

}
void PushUp(int node){
	if (tree[node].l==tree[node].r){
		a[tree[node].l]%=tree[node].p;
		if (check(a[tree[node].l])==true)
			tree[node].num=1;
		else
			tree[node].num=0;
		return;
	}
	PushUp(node*2);
	PushUp(node*2+1);
	tree[node].num=tree[node*2+1].num+tree[node*2+1].num;
}
int query(int node,int l,int r){
	if (l<=tree[node].l && tree[node].r<=r){
		if (tree[node].p){
			PushUp(node);
			tree[node].p=0;
		}
		return tree[node].num;
	}
	PushDown(node);
	int mid=(tree[node].l+tree[node].r)/2;
	if (r<=mid)
		return query(node*2,l,r);
	else if (mid<l)
		return query(node*2+1,l,r);
	else
		return query(node*2,l,mid)+query(node*2+1,mid+1,r);
}
void Debug(int n){
	cout<<"---------------debug--------------\n";
	for (int i=0;i<4*n;i++)
		cout<<tree[i].num<<" ";
	cout<<endl;
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
				update(1,b,c,d);
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
				Set(1,b,c);
			}
			Debug(n);
		}
	}

	return 0;
}