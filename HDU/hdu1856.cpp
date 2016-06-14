#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN = 10000000+5;
int father[MAXN];
int r[MAXN];
void init(){
	for (int i=0;i<=MAXN;i++){
		father[i]=i;
		r[i]=1;
	}
}
int find(int x){
	if (x==father[x])	return x;
	father[x]=find(father[x]);
}
void Union(int x,int y){
	x=find(x),y=find(y);
	if (x==y) return;
	father[x]=y;
	r[y]+=r[x];
}
void Debug(){
	for (int i=1;i<10;i++)
		cout<<r[i]<<" ";
	cout<<endl;
}
int main(){
	int n,x,y;
	while (~scanf("%d",&n)){
		init();
		while (n--){
			scanf("%d%d",&x,&y);
			if (find(x)==find(y))
				continue;
			Union(x,y);
		}
		int ans=0;
		for (int i=1;i<MAXN;i++){
			if (r[find(i)]>ans)
				ans=r[find(i)];
		}
		//Debug();
		printf("%d\n",ans);
	}

	return 0;
}