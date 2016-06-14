#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAXN = 1000+5;
struct Node{
	int x,y;
}P[MAXN];
int father[MAXN];
bool used[MAXN];
void Init(int n){
	for (int i=0;i<=n;i++){
		father[i]=i;
		used[i]=false;
	}
}
int Find(int x){
	if (x==father[x]) return x;
	return father[x]=Find(father[x]);
}
void Union(int x,int y){
	x=Find(x),y=Find(y);
	if (x==y) return ;
	father[y]=x;
}
bool dis(int x,int y,int d){
	if ((P[x].y-P[y].y)*(P[x].y-P[y].y)+(P[x].x-P[y].x)*(P[x].x-P[y].x)<=d*d)
		return true;
	return false;
}
int main(){
	int n,m,d,a,b;
	char s[2];
	while (~scanf("%d%d",&n,&d)){
		Init(n);

		for (int i=1;i<=n;i++){
			scanf("%d%d",&P[i].x,&P[i].y);
		}
		while (cin>>s){
			if (s[0]=='O'){
				scanf("%d",&a);
				used[a]=true;
				for (int i=1;i<=n;i++){
					if (i!=a && used[i] && dis(i,a,d)){
						Union(i,a);
					}
				}
			}
			else{
				scanf("%d%d",&a,&b);
				a=Find(a),b=Find(b);
				if (a==b)
					printf("SUCCESS\n");
				else
					printf("FAIL\n");
			}
		}
	}

	return 0;
}