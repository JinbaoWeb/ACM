#include <bits/stdc++.h>
using namespace std;
int parent[105];
int key[105];
bool mstSet[105];
int n;
int graph[105][105];
struct Node{
	int x,y;
}ans[105];
int minKey(){
	int Min=INT_MAX,min_index=-1;
	for (int v=0;v<n;v++){
		if (mstSet[v]==false && key[v]<Min)
			Min=key[v],min_index=v;
	}
	return min_index;
}
void primMST(){
	for (int i=0;i<n;i++)
		key[i]=INT_MAX,mstSet[i]=false;
	key[0]=0;
	parent[0]=-1;
	for (int count=0;count<n-1;count++){
		int u=minKey();
		mstSet[u]=true;
		for (int v=0;v<n;v++){
			if (graph[u][v] && mstSet[v]==false && graph[u][v]<key[v]){
				parent[v]=u,key[v]=graph[u][v];
			}
		}
	}
}
bool cmp(Node s1,Node s2){
	if (s1.x!=s2.y)
		return s1.x<s2.x;
	return s1.y<s2.y;
}
void print(){
	for (int i=1;i<n;i++){
		ans[i].x=i,ans[i].y=parent[i];
		if (graph[i][parent[i]]==0){
			cout<<-1<<endl;
			return;
		}
		if (i>parent[i])
			swap(ans[i].x,ans[i].y);
		//cout<<ans[i].x<<" "<<ans[i].y<<" "<<graph[i][parent[i]]<<endl;
	}
	sort(ans,ans+n-1,cmp);
	for (int i=1;i<n-1;i++){
		cout<<ans[i].x+1<<" "<<ans[i].y+1<<" ";
	}
	cout<<ans[n-1].x+1<<" "<<ans[n-1].y+1<<endl;
}
int main(){
	int t;
	cin>>t;
	while (t--){
		cin>>n;
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++)
				cin>>graph[i][j];
		}
		primMST();
		print();
	}
	return 0;
}