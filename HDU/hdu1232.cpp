#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int MAXN = 1000+10;
int father[MAXN];
bool used[MAXN];
void init(int n){
	for (int i=0;i<=n;i++){
		father[i]=i;
	}
}
int find(int x){
	if (x==father[x])	return x;
	return father[x]=find(father[x]);
}
void Union(int x,int y){
	x=find(x),y=find(y);
	if (x==y)	return;
	father[x]=y;
}
int main(){
	int n,m,x,y;
	while (~scanf("%d",&n)&n){
		scanf("%d",&m);
		init(n);
		memset(used,false,sizeof(used));
		while (m--){
			scanf("%d%d",&x,&y);
			Union(x,y);
		}
		for (int i=1;i<=n;i++){
			used[find(i)]=true;
		}
		int ans=0;
		for (int i=1;i<=n;i++){
			if (used[i]==true)
				ans++;
		}
		printf("%d\n",ans-1);
	}
	return 0;
}