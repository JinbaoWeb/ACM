#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node{
	int x,y;
	int cnt;
};
int bfs(int x,int y){
	queue<Node> q;
	Node s,temp,temp2;
	s.x=x,s.y=y,s.cnt=0;
	q.push(s);
	int ans=0;
	while (!q.empty()){
		temp=q.front();
		if (temp.y-2>0){
			temp2.x=temp.x+1,temp2.y=temp.y-2,temp2.cnt=temp.cnt+1;
			ans=max(ans,temp2.cnt);
			//cout<<temp2.x<<" "<<temp2.y<<" "<<temp2.cnt<<endl;
			q.push(temp2);
		}
		if (temp.x-2>0){
			temp2.x=temp.x-2,temp2.y=temp.y+1,temp2.cnt=temp.cnt+1;
			//cout<<temp2.x<<" "<<temp2.y<<" "<<temp2.cnt<<endl;
			q.push(temp2);
			ans=max(ans,temp2.cnt);
		}
		q.pop();
	}
	return ans;
}
int main(){
	int n,m;
	cin>>n>>m;
	cout<<bfs(n,m)+1<<endl;
	return 0;
}