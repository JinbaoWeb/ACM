#include<bits/stdc++.h>
using namespace std;
#define Maxn 330
struct Node{ 
	int s,e;
}P[Maxn];
bool cmp(struct Node a,struct Node b){ 
	if(a.e!=b.e) 
		return a.e<b.e; 
	return a.s<b.s;
}
bool vis[Maxn];
int main(){ 
	int n; 
	while(scanf("%d",&n)&&n){ 
	for(int i=1;i<=n;i++) 
		scanf("%d%d",&P[i].s,&P[i].e); 
		sort(P+1,P+n+1,cmp); 
		int ans=0; 
		for(int i=0;i<5;i++) { 
			int res=0,pos=1; 
			memset(vis,false,sizeof(vis)); 
			for(int j=i;j<P[n].e;j+=5) { 
				for(int k=1;k<=n;k++) { 
					if(vis[k]) continue; 
					if(P[k].s<=j&&P[k].e>j) {
						vis[k]=true,res++; 
						break; 
					} 
				} 
			} 
			ans=max(ans,res); 
		} 
		printf("%d\n",ans); 
	} 
	return 0;
}