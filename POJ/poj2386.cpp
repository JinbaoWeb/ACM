#include <iostream>
#include <string.h>
using namespace std;
char map[100][100];
int used[100][100],m,n;
void dfs(int i,int j)
{
	
	if (i<0 ||i>m ||j<0 ||j>n)
		return;
	if (map[i][j]=='W'&&used[i][j]==0)
	{
		used[i][j]=1;
		dfs(i-1,j-1);dfs(i-1,j);dfs(i-1,j+1);
		dfs(i,j-1);  			dfs(i,j+1);
		dfs(i+1,j-1);dfs(i+1,j);dfs(i+1,j+1);
	}
	else
		return;
}
int main()
{
	while (cin>>m>>n)
	{
		int count=0;
		memset(used,0,sizeof(used));
		for (int i=0;i<m;i++)
			for (int j=0;j<n;j++)
				cin>>map[i][j];
		for (int i=0;i<m;i++)
			for (int j=0;j<n;j++)
				if (map[i][j]=='W'&&used[i][j]==0)
				{
					count++;
					dfs(i,j);
				}
		cout<<count<<endl;
	}	
	return 0;
} 
