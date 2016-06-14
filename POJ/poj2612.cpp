#include <iostream>
using namespace std;
#define MAX 12
int n;
char map[MAX][MAX],ans[MAX][MAX];
int count(int i,int j,int n){
	int ans=0;
	if (map[i-1][j-1]=='*' && i-1>=0 && j-1>=0)
		ans++;
	if (map[i-1][j]=='*' && i-1>=0)
		ans++;
	if (map[i-1][j+1]=='*' && i-1>=0 && j+1<n)
		ans++;

	if (map[i][j-1]=='*' && j-1>=0)
		ans++;	
	if (map[i][j]=='*')
		ans++;
	if (map[i][j+1]=='*' && j+1<n)
		ans++;

	if (map[i+1][j-1]=='*' && i+1<n && j-1>=0)
		ans++;
	if (map[i+1][j]=='*' && i+1<n)
		ans++;
	if (map[i+1][j+1]=='*' && i+1<n && j+1<n)
		ans++;
	return ans;
}
int main(){
	
	while (cin>>n){
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
				cin>>map[i][j];
		int flag=0;
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				cin>>ans[i][j];
				if (map[i][j]=='*' && ans[i][j]=='x')
					flag=1;
				if (ans[i][j]=='x'){
					int k=count(i,j,n);
					ans[i][j]=k+'0';
				}
			}
		}
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				if (flag==1 && map[i][j]=='*')
					cout<<map[i][j];
				else
					cout<<ans[i][j];
			}
			cout<<endl;
		}
	}
	return 0;
}