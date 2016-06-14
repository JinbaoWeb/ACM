#include <cstdio>
#include <queue>
#include <string.h>
using namespace std;
int vis[300010];
struct Node{
	int loc;
	int step;
};
queue<Node> q;
int bfs(int start,int end){
	Node a,b;
	a.loc=start;
	a.step=0;
	q.push(a);
	while(!q.empty()){
		a=q.front();
		q.pop();
		if(a.loc==end)
			return a.step;
		a.step++;
		if(a.loc<end && !vis[a.loc]){	
			b=a;
			b.loc*=2;
			q.push(b);
		}
		if(a.loc>0 && !vis[a.loc]){
			b=a;
			b.loc-=1;
			q.push(b);
		}
		if(!vis[a.loc]){
			b=a;
			b.loc+=1;
			q.push(b);
			vis[a.loc]=1;
		}
	}
}

int main(){
	int i,j;
	int n,k;
	while(scanf("%d%d",&n,&k)!=EOF){
		memset(vis,0,sizeof(vis));
		printf("%d\n",bfs(n,k));
		while(!q.empty())//Çå¿Õ¶ÓÁÐ
            q.pop();

	}
	return 0;
}

