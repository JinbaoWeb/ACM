#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int father[30000+1],rank[30000+1];
bool flag[30000+1];
void init(int n){
	for (int i=0;i<=n;i++){
		father[i]=i;
		rank[i]=1;
		flag[i]=false;
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
	int a,b,t=1;
	while (cin>>a>>b){
		if (a==b&&a==-1)
			break;
		if (a==0&&b==0){
			cout<<"Case "<<t++<<" is a tree."<<endl;
			continue;
		}
		flag[a]=flag[b]=true;
		init(1000);
		bool tree=true;
		if (a==b)
			tree=false;
		else
			Union(a,b);
		int first=a;
		while (cin>>a>>b){
			if (a==0&&b==0)
				break;
			if (find(a)==find(b))
				tree=false;
			flag[a]=flag[b]=true;
			Union(a,b);
		}
		for (int i=1;i<=1000;i++){
			if (flag[i]==true&&find(i)!=find(first)){
				tree=false;
				break;
			}
		}
		if (tree==false)
			cout<<"Case "<<t++<<" is not a tree."<<endl;
		else
			cout<<"Case "<<t++<<" is a tree."<<endl;
	}
	return 0;
}