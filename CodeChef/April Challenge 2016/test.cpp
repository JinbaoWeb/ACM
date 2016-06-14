#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool used[15][15];
ll n,m;
int dx[]={ 1,-1, 0, 0};
int dy[]={ 0, 0, 1,-1};
bool f(int x,int y){
	if (0<=x && x<n && 0<=y && y<m && used[x][y]==false)
		return true;
	return false;
}
int ii,jj;
bool DFS(int x,int y,int step){
	//cout<<x<<" "<<y<<" "<<step<<endl;
	used[x][y]=true;
	if (step==n*m && (abs(ii-x)+abs(jj-y)==1))
		return true;
	for (int i=0;i<4;i++){
		if (f(x+dx[i],y+dy[i])==true){
			if (DFS(x+dx[i],y+dy[i],step+1)==true)
				return true;
			used[x+dx[i]][y+dy[i]]=false;
		}
	}
	return false;
}
int main(){
	int t=1;
	while (t--){
		for (n=1;n<11;n++){
			for (m=1;m<11;m++){
				int flag=0;
				for (ii=0;ii<n;ii++){
					for (jj=0;jj<m;jj++){
						memset(used,false,sizeof(used));
						if (DFS(ii,jj,1)==true){
							flag=1;
						}
					}
					if (flag) break;
				}
				if (flag==0)
					cout<<n<<" "<<m<<endl;
			}
		}
	}
	return 0;
}