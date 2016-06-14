#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAXN = 2000+10;
int father[MAXN];
int relation[MAXN];
void init(int n){
	for (int i=0;i<=n;i++){
		father[i]=i;
		relation[i]=0;	//0表示同一性别，1表示不同性别
	}
}
int find(int x){
	if (x==father[x])
		return x;
	int temp=father[x];
	father[x]=find(father[x]);
	relation[x]=(relation[x]+relation[temp])%2;
	return father[x];
}
void Union(int x,int y){
	int fx=find(x),fy=find(y);
	if (fx==fy) return;
	father[fx]=fy;
	relation[fx]=(relation[x]+relation[y]+1)%2;
}
int main(){
	int t,n,m,x,y;
	scanf("%d",&t);
	for (int cas=1;cas<=t;cas++){
		scanf("%d%d",&n,&m);
		init(n);
		int flag=0;
		for (int i=0;i<m;i++){
			scanf("%d%d",&x,&y);
			if (find(x)==find(y)){
				if (relation[x]==relation[y]){
					flag=1;
				}
			}
			else{
				Union(x,y);
			}
		}
		printf("Scenario #%d:\n",cas);
		if (flag==0){
			printf("No suspicious bugs found!\n\n");
		}
		else{
			printf("Suspicious bugs found!\n\n");
		}
	}
	

	return 0;
}