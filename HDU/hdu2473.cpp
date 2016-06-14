#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1000000+10;
const int MAXM = 1000000+10;
int father[2*MAXN];
bool used[2*MAXN+MAXM];
void Init(int n,int m){
	memset(used,false,sizeof(used));
	for (int i=0;i<n;i++)
		father[i]=i+n;
	for (int i=n;i<2*n+m;i++)
		father[i]=i;
}
int find(int x){
	if (x==father[x]) return x;
	father[x]=find(father[x]);
	return father[x];
}
void Union(int a,int b){
	int x=find(a),y=find(b);
	//printf("%d %d ----\n",x,y );
	if (x==y) return;
	if (x>y)
		father[x]=y;
	else
		father[y]=x;
}
void Debug(int n){
	for (int i=0;i<n;i++)
		printf("%d ",find(i) );
	printf("\n");
}
int main(){
	int n,m,a,b;
	int cas=1;
	while (scanf("%d%d",&n,&m)){
		if (n==0 && m==0) break;
		Init(n,m);
		int cnt=2*n;
		char str[2];
		//Debug(n);
		while (m--){
			scanf("%s",str);
			if (str[0]!='S'){
				scanf("%d%d",&a,&b);
				//printf("-----\n");
				Union(a,b);
			}
			else{
				scanf("%d",&a);
				//printf("----------\n");
				father[a]=cnt++;
			}
			//Debug(n);
		}
		//Debug(n);
		int ans=0;
		for (int i=0;i<n;i++){
			int temp=find(i);
			if (used[temp]==false){
				used[temp]=true;
				ans++;
			}
		}
		printf("Case #%d: %d\n",cas++,ans );
	}
	return 0;
}