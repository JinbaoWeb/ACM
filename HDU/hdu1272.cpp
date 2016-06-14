#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int MAXN = 100000+5;
int father[MAXN];
int used[MAXN];
void init(){
	for (int i=0;i<MAXN-1;i++)
		father[i]=i;
}
int find(int x){
	if (x==father[x]) return x;
	return father[x]=find(father[x]);
}
void Union(int x,int y){
	x=find(x),y=find(y);
	father[x]=y;
}
int main(){
	int x,y;
	while (~scanf("%d%d",&x,&y)){
		if (x==-1 && y==-1) break;
		init();
		memset(used,false,sizeof(used));
		used[x]=true;
		used[y]=true;
		if (find(x)!=find(y))
			Union(x,y);
		int flag=0;
		while (1){
			scanf("%d%d",&x,&y);
			if (x==0 && y==0)
				break;
			if (find(x)!=find(y))
				Union(x,y);
			else{
				flag=1;
			}
		}
		int temp=0;
		for (int i=1;i<MAXN;i++){
			if (used[i]==true)
				temp=find(i);
		}
		for (int i=1;i<MAXN;i++){
			if (used[i]==true && find(i)!=temp){
				flag=1;
			}
		}
		if (flag==0)
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}