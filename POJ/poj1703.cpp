#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int father[2*100000+1],rank[2*100000+1];
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
	int t,n,m,a,b;
	char s;
	cin>>t;
	while (t--){
		//cin>>n>>m;
		scanf("%d%d",&n,&m);
		//getchar();
		init(2*n);
		for (int i=0;i<m;i++){
			//scanf("%c%d%d",&s,&a,&b);
			cin>>s;
			cin>>a>>b;
			if (s=='A'){
				if (same(a, b))
                   cout << "In the same gang." << endl;
               else{
               		if (same(a, b + n))
	                   cout << "In different gangs." << endl;
	               else
	                   cout << "Not sure yet." << endl;	
               } 
               
			}
			else{
				Union(a,b+n);
				Union(a+n,b);
			}
		}
	}
	return 0;
}