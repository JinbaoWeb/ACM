#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int MAXN = 25;
int map[MAXN][MAXN];
int main(){
	int n,t;
	int v,a,b;
	scanf("%d",&t);
	while (t--){
		scanf("%d",&n);
		memset(map,0,sizeof(map));
		for (int i=0;i<n;i++){
			scanf("%d%d%d",&v,&a,&b);
			map[a][b]=v;
		}
	}

	return 0;
}