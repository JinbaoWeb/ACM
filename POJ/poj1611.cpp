#include <iostream>
#include <stdio.h>
using namespace std;
int father[30000+1],rank[30000+1];
void init(int n){
	for (int i=0;i<=n;i++){
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
bool same(int i,int j){
	if (find(i)==find(j))
		return true;
	return false;
}
int main(){
	int n,m,k;
	while (cin>>n>>m){
		if (n==0&&m==0)
			break;
		if (m==0){
			cout<<1<<endl;
			continue;
		}
		init(n);
		for (int i=0;i<m;i++){
			cin>>k;
			if (k==0)
				continue;
			int first,second;
			cin>>first;
			if (k==1){
				Union(first,first);
				continue;
			}
			for (int j=1;j<k;j++){
				cin>>second;
				Union(first,second);
			}
		}
		int count=0;
		for (int i=0;i<n;i++)
			if (same(i,0)==true)
				count++;
		cout<<count<<endl;
	}
	return 0;
}