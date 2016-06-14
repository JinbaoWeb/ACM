#include <iostream>
#include <queue>
using namespace std;
struct Node{
	int x,y,z;
	int cnt;
};
char map[35][35][35];
bool used[35][35][35];
int dir[6][3]={1,0,0,-1,0,0,0,1,0,0,-1,0,0,0,1,0,0,-1};
Node s,e,temp,temp2;
int l,r,c;
int bfs(){
	queue<Node> q;
	q.push(s);
	while (!q.empty()){
		temp=q.front();
		for (int i=0;i<6;i++){
			temp2.x=temp.x+dir[i][0];
			temp2.y=temp.y+dir[i][1];
			temp2.z=temp.z+dir[i][2];
			temp2.cnt=temp.cnt+1;
			if (temp2.x>=0 && temp2.x<l && 
			temp2.y>=0 && temp2.y<r && 
			temp2.z>=0 && temp2.z<c && 
			used[temp2.x][temp2.y][temp2.z]==true){
				q.push(temp2);
				used[temp2.x][temp2.y][temp2.z]=false;
				if (temp2.x==e.x && temp2.y==e.y && temp2.z==e.z){
					return temp2.cnt;
				}
			}
		}
		q.pop();
	}
	return -1;
}
int main(){
	while (cin>>l>>r>>c){
		if (l==0 && r==0 && c==0)
			break;
		for (int i=0;i<l;i++){
			for (int j=0;j<r;j++)
				for (int k=0;k<c;k++){
					cin>>map[i][j][k];
					if (map[i][j][k]=='#')
						used[i][j][k]=false;
					else
						used[i][j][k]=true;
					if (map[i][j][k]=='S')
						s.x=i,s.y=j,s.z=k,s.cnt=0;
					if (map[i][j][k]=='E')
						e.x=i,e.y=j,e.z=k;
				}
		}
		int ans=bfs();
		if (ans>0)
			cout<<"Escaped in "<<ans<<" minute(s)."<<endl;
		else
			cout<<"Trapped!"<<endl;
	}
	
	return 0;
}


