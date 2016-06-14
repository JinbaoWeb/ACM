#include <iostream>
#include <stdio.h>
using namespace std;
int father[50000+1],rank[50000+1];
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
int main(){
	int n,m,x,y,num=1;
	while (cin>>n>>m){
		if (n==0&&m==0)
			break;
		init(n);
		for (int i=0;i<m;i++){
			cin>>x>>y;
			Union(x,y);
		}
		int ans=0;
		for (int i=1;i<=n;i++){
			if (i==father[i])
				ans++;
		}
		cout<<"Case "<<num<<": "<<ans<<endl;
		num++;
	}
	return 0;
}