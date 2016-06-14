#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAXN = 200+5;
const int MAXM = 1000+5;
int father[MAXN];
struct Edge{
	int s,e;
	int v;
}E[MAXM];
bool cmp(Edge a,Edge b){
	return a.v<b.v;
}
void init(int n){
	for (int i=1;i<=n;i++)
		father[i]=i;
}
int find(int x){
	if (x==father[x])	return x;
	return father[x]=find(father[x]);
}
void Union(int x,int y){
	x=find(x),y=find(y);
	if (x==y) return;
	father[x]=y;
}
int main(){
	int n,m,q,a,b;
	while (~scanf("%d%d",&n,&m)){
		for (int i=0;i<m;i++)
			scanf("%d%d%d",&E[i].s,&E[i].e,&E[i].v);
		sort(E,E+m,cmp);
		scanf("%d",&q);
		while (q--){
			scanf("%d%d",&a,&b);
			int ans=0xffffff;
			for (int i=0;i<m;i++){	//枚举最小边
				init(n);
				for (int j=i;j<m;j++){
					Union(E[j].s,E[j].e);
					if (find(a)==find(b)){
						int temp=E[j].v-E[i].v;
						if (temp<ans)
							ans=temp;
						break;
					}
				}
			}
			if (ans==0xffffff)
				printf("-1\n");
			else
				printf("%d\n",ans);
		}
	}

	return 0;
}