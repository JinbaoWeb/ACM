#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int MAXN = 50+5;
int array[11][4]={
	1,0,0,1,
	1,1,0,0,
	0,0,1,1,
	0,1,1,0,
	1,0,1,0,
	0,1,0,1,
	1,1,0,1,
	1,0,1,1,
	0,1,1,1,
	1,1,1,0,
	1,1,1,1
};
char map[MAXN][MAXN];
int father[MAXN*MAXN];
bool used[MAXN*MAXN];
void init(int n){
	for (int i=0;i<=n;i++){
		father[i]=i;
	}
}
int find(int x){
	if (x==father[x]) return x;
	return father[x]=find(father[x]);
}
void Union(int x,int y){
	x=find(x),y=find(y);
	if (x==y) return;
	father[x]=y;
}
bool check(int x,int y,int m,int n){
	if (m==0){
		if (array[map[x][y]-'A'][1]==1 && array[map[x][y+1]-'A'][3]==1)
			return true;
		return false;
	}
	if (m==1){
		if (array[map[x][y]-'A'][2]==1 && array[map[x+1][y]-'A'][0]==1)
			return true;
		return false;
	}
}
int main(){
	int n,m;
	while (~scanf("%d%d",&n,&m)){
		if (n<0 && m<0)
			break;
		memset(used,false,sizeof(used));
		init(n*m);
		for (int i=0;i<n;i++)
			scanf("%s",map[i]);
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				if (j+1<m){
					if (check(i,j,0,1)==true){
						//cout<<i*m+j+1<<" "<<i*m+j+2<<endl;
						Union(i*m+j+1,i*m+j+2);
					}
				}
				if (i+1<n){
					if (check(i,j,1,0)==true){
						//cout<<i*m+j+1<<" "<<(i+1)*m+j+1<<endl;
						Union(i*m+j+1,(i+1)*m+j+1);
					}
				}
			}
		}
		//for (int i=1;i<=n*m;i++)
			//cout<<find(i)<<" ";
		//cout<<endl;
		for (int i=1;i<=n*m;i++){
			used[find(i)]=true;
		}
		int ans=0;
		for (int i=1;i<=n*m;i++){
			if (used[i]==true)
				ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}