#include <iostream>
using namespace std;

int father[MAX],rank[MAX];
void init(int n){
	for (int i=1;i<=n;i++){
		father[i]=i;
		rank[i]=1;
	}
}
int find(int x){
	if (x!=father[x])
		father[x] = find(father[x]);	//路径压缩
	return father[x];
}
void Union(int x,int y){
	int i=find(x);
	int j=find(y);
	if (i==j)
		return;
	if (rank[i]<rank[j])
		father[i]=j;
	else{
		father[j]=i;
		if (rank[i]==rank[j])	//两棵树同高
			rank[i]++;
	}
}
bool same(int x,int y){
        return find(x)==find(y);
}
int main(){
	int n,m,l,r;
	while (cin>>n>>m){
		
		if (flag==1)
			cout<<"NO\n";
		else
			cout<<"YES\n";
	}
	return 0;
}