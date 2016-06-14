#include <stdio.h>
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
int A,B,C;
struct Node{
	int x,y;
}P[200][200];
int ans[200][200];
bool used[200][200];
Node st;
bool bfs(){
	queue<Node> q;
	Node s;
	s.x=s.y=0;
	q.push(s);
	while (!q.empty()){
		Node e=q.front(),temp;
		if (e.x==C || e.y==C){
			st.x=e.x,st.y=e.y;
			return true;
		}
		//Fill(i)
		for (int i=0;i<2;i++){
			if (i==0){
				if (used[A][e.y]==true)
					continue;
				used[A][e.y]=true;
				P[A][e.y]=e;
				ans[A][e.y]=1;
				temp.x=A,temp.y=e.y;
			}
			else{
				if (used[e.x][B]==true)
					continue;
				used[e.x][B]=true;
				P[e.x][B]=e;
				ans[e.x][B]=2;
				temp.x=e.x,temp.y=B;
			}
			q.push(temp);
		}
		//Drop(i)
		for (int i=0;i<2;i++){
			if (i==0){
				if (used[0][e.y]==true)
					continue;
				used[0][e.y]=true;
				P[0][e.y]=e;
				ans[0][e.y]=3;
				temp.x=0,temp.y=e.y;
			}
			else{
				if (used[e.x][0]==true)
					continue;
				used[e.x][0]=true;
				P[e.x][0]=e;
				ans[e.x][0]=4;
				temp.x=e.x,temp.y=0;
			}
			q.push(temp);
		}
		//Pour(j,i)
		for (int i=0;i<2;i++){
			if (i==0){
				if (e.x+e.y<=B){
					P[0][e.x+e.y]=e;
					ans[0][e.x+e.y]=5;//Pour(j,i)
					temp.x=0,temp.y=e.x+e.y;
				}
				else{
					P[e.x+e.y-B][B]=e;
					ans[e.x+e.y-B][B]=5;//Pour(j,i)
					temp.x=e.x+e.y-B,temp.y=B;
				}
			}
			else{
				if (e.x+e.y<=A){
					P[e.x+e.y][0]=e;
					ans[e.x+e.y][0]=6;//Pour(i,j)
					temp.x=e.x+e.y,temp.y=0;
				}
				else{
					P[A][e.x+e.y-A]=e;
					ans[A][e.x+e.y-A]=6;//Pour(i,j)
					temp.x=A,temp.y=e.x+e.y-A;
				}
			}
			q.push(temp);
		}
		q.pop();
	}
	return false;
}
int main(){
	int ans2[400];
	Node temp;
	while (~scanf("%d%d%d",&A,&B,&C)){
		memset(used,false,sizeof(used));
		if (bfs()==true){
			int cnt=0;
			while (1){
				if (st.x==0 && st.y==0)
					break;
				temp=P[st.x][st.y];
				ans2[cnt++]=ans[st.x][st.y];
				st.x=temp.x,st.y=temp.y;
			}
			cout<<cnt<<endl;
			while (cnt--){
				if (ans2[cnt]==1)
					cout<<"FILL(1)"<<endl;
				else if (ans2[cnt]==2)
					cout<<"FILL(2)"<<endl;
				else if (ans2[cnt]==3)
					cout<<"DROP(1)"<<endl;
				else if (ans2[cnt]==4)
					cout<<"DROP(2)"<<endl;
				else if (ans2[cnt]==5)
					cout<<"POUR(1,2)"<<endl;
				else
					cout<<"POUR(2,1)"<<endl;
			}
		}
		else{
			cout<<"impossible"<<endl;
		}
	}
	return 0;
}


