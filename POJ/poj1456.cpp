#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAXN = 10000+10;
struct Node{
	int v,t;
}P[MAXN];
int parent[MAXN];
bool cmp(Node x,Node y){
	return x.v>y.v;
}
int find(int x){
	if (parent[x]==-1)
		return x;
	return parent[x]=find(parent[x]);
}
int main(){
	int n;
	while (cin>>n){
		memset(parent,-1,sizeof(parent));
		for (int i=0;i<n;i++)
			cin>>P[i].v>>P[i].t;
		sort(P,P+n,cmp);
		int ans=0;
		for (int i=0;i<n;i++){
			int d = find(P[i].t);
			if (d>0){
				ans+=P[i].v;
				parent[d]=d-1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}