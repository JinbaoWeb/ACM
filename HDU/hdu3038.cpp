#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int MAXN = 200000+5;
int father[MAXN];
int sum[MAXN];
void Init(int n){
	for (int i=0;i<=n;i++){
		father[i]=i;
		sum[i]=0;
	}
}
int Find(int x){
	if (x==father[x]) return x;
	int temp=father[x];
	father[x]=Find(father[x]);
	sum[x]+=sum[temp];
	return father[x];
}
void Union(int x,int y,int v){
	father[x]=y;
	sum[x]=v;
}
int main(){
	int n,m,x,y,v;
	while (~scanf("%d%d",&n,&m)){
		Init(n);
		int ans=0;
		while (m--){
			scanf("%d%d%d",&x,&y,&v);
			x--;
			int fx=Find(x),fy=Find(y);
			if (fx==fy){
				if (sum[x]-sum[y]!=v)
					ans++;
			}
			else{
				if (x==fx && y==fy)
					Union(x,y,v);
				if (x==fx && y!=fy)
					Union(x,fy,v+sum[y]);
				if (x!=fx && y==fy){
					if (fx>y)
						Union(y,fx,sum[x]-v);
					else
						Union(fx,y,v-sum[x]);
				}
				if (x!=fx && y!=fy){
					if (fx<fy)
						Union(fx,fy,v+sum[y]-sum[x]);
					else
						Union(fy,fx,sum[x]-sum[y]-v);
				}

			}
		}
		printf("%d\n",ans);
	}
	return 0;
}