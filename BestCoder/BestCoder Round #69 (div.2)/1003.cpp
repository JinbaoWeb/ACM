#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
char map[100][100];
bool used[100][100];
int t,n,m;
double sum;
bool f(int x,int y){
	if (0<=x && x<n && 0<=y && y<m)
		return true;
	return false;
}
bool bfs(int x,int y,double k){
	//cout<<x<<" "<<y<<" "<<k<<endl;
	//cout<<fabs(k-sum)<<endl;
	if (fabs(k-sum)<=1e-8)
		return true;
	//0
		if (f(x-2,y)==true && used[x-2][y]==false){
			used[x-2][y]=true;
			if (map[x-1][y]=='+')
				if (bfs(x-2,y,k+(map[x-2][y]-'0'))==false){
					used[x-2][y]=false;
				}
			if (map[x-1][y]=='-')
				if (bfs(x-2,y,k-(map[x-2][y]-'0'))==false){
					used[x-2][y]=false;
				}
			if (map[x-1][y]=='*')
				if (bfs(x-2,y,k*(map[x-2][y]-'0'))==false){
					used[x-2][y]=false;
				}
			if (map[x-1][y]=='/'){
				if (map[x-2][y]-'0'==0){
					used[x-2][y]=false;
				}
				else if (bfs(x-2,y,k/(map[x-2][y]-'0'))==false){
					used[x-2][y]=false;
				}

			}	
		}
	
	//1
		if (f(x,y+2)==true && used[x][y+2]==false){
			used[x][y+2]=true;
			if (map[x][y+1]=='+')
				if (bfs(x,y+2,k+(map[x][y+2]-'0'))==false){
					used[x][y+2]=false;
				}
			if (map[x][y+1]=='-')
				if (bfs(x,y+2,k-(map[x][y+2]-'0'))==false){
					used[x][y+2]=false;
				}
			if (map[x][y+1]=='*')
				if (bfs(x,y+2,k*(map[x][y+2]-'0'))==false){
					used[x][y+2]=false;
				}
			if (map[x][y+1]=='/'){
				if (map[x][y+2]-'0'==0){
					used[x][y+2]=false;
					
				}
				else if (bfs(x,y+2,k/(map[x][y+2]-'0'))==false){
					used[x][y+2]=false;
				}

			}
		}	
	//2
		if (f(x,y-2)==true && used[x][y-2]==false){
			used[x][y-2]=true;
			if (map[x][y-1]=='+')
				if (bfs(x,y-2,k+(map[x][y-2]-'0'))==false){
					used[x][y-2]=false;
				}
			if (map[x][y-1]=='-')
				if (bfs(x,y-2,k-(map[x][y-2]-'0'))==false){
					used[x][y-2]=false;
				}
			if (map[x][y-1]=='*')
				if (bfs(x,y-2,k*(map[x][y-2]-'0'))==false){
					used[x][y-2]=false;
				}
			if (map[x][y-1]=='/'){
				if (map[x][y-2]-'0'==0){
					used[x][y-2]=false;
					
				}
				else if (bfs(x,y-2,k/(map[x][y-2]-'0'))==false){
					used[x][y-2]=false;
				}

			}	
		}
		if (f(x+2,y)==true && used[x+2][y]==false){
			used[x+2][y]=true;
			if (map[x+1][y]=='+')
				if (bfs(x+2,y,k+(map[x+2][y]-'0'))==false){
					used[x+2][y]=false;
				}
			if (map[x+1][y]=='-')
				if (bfs(x+2,y,k-(map[x+2][y]-'0'))==false){
					used[x+2][y]=false;
				}
			if (map[x+1][y]=='*')
				if (bfs(x+2,y,k*(map[x+2][y]-'0'))==false){
					used[x+2][y]=false;
				}
			if (map[x+1][y]=='/'){
				if (map[x+2][y]-'0'==0){
					used[x+2][y]=false;
					
				}
				else if (bfs(x+2,y,k/(map[x+2][y]-'0'))==false){
					used[x+2][y]=false;
				}

			}	
		}
	return false;
}
int main(){
	cin>>t;
	while (t--){
		cin>>n>>m>>sum;
		memset(used,false,sizeof(used));
		for (int i=0;i<n;i++)
			cin>>map[i];
		int flag=0;
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				if (i%2==0 && j%2==0){
					if (bfs(i,j,map[i][j]-'0')==true){
						flag=1;
						cout<<"Possible"<<endl;
						break;
					}	
				}
			}
			if (flag==1)
				break;
		}
		if (flag==0)
			cout<<"Impossible"<<endl;
	}
	return 0;
}
