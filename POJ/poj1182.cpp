#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <iostream>
const int MAXN = 50000+5;
using namespace std;
struct Node{
	int parent;
	int relation;
}tree[MAXN];
void init(int n){
	for (int i=1;i<=n;i++){
		tree[i].parent=i;
		tree[i].relation=0;
	}
}
int find(int x){
	if (x==tree[x].parent)
		return x;
	else{
		int temp=tree[x].parent;
		tree[x].parent=find(tree[x].parent);
		tree[x].relation=(tree[temp].relation+tree[x].relation)%3;
		return tree[x].parent;
	}
}
void Union(int x,int y,int d){
	int p=find(x),q=find(y);
	tree[p].parent=q;
	tree[p].relation=(tree[y].relation-tree[x].relation+3+d)%3;
}
int main(){
	int n,k;
	int d,x,y;
	cin>>n>>k;
		init(n);
		int ans=0;
		for (int i=0;i<k;i++){
			cin>>d>>x>>y;
			if (x>n || y>n){
				ans++;
				continue;
			}
			if (d==2 && x==y){
				ans++;
				continue;
			}
			int p=find(x),q=find(y);
			if (p==q){
				if ((tree[x].relation-tree[y].relation+3)%3!=d-1)
					ans++;
			}
			else
				Union(x,y,d-1);
		}
		cout<<ans<<endl;
	

	return 0;
}