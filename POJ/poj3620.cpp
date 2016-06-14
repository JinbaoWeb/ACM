#include <iostream>
#include <string.h>
using namespace std;
int m,n,k,a,b;
bool map[100][100];
int dfs(int a,int b)
{
	if (a<0 || a>m ||b<0 ||b>n ||map[a][b]==false)
		return 0;
	map[a][b]=false;
	return dfs(a,b-1)+dfs(a-1,b)+dfs(a+1,b)+dfs(a,b+1)+1;
}
int main()
{
	memset(map,false,sizeof(map));
	while (cin>>m>>n>>k)
	{
		memset(map,false,sizeof(map));
		for (int i=1;i<=k;i++)
		{
			cin>>a>>b;
			map[a-1][b-1]=true;
		}	
		int count=0,maxcount=0;
		for (int i=0;i<m;i++)
			for (int j=0;j<n;j++)
			{
				if (map[i][j]==true)
					count=dfs(i,j);
				if (count>maxcount)
					maxcount=count;
			}
		cout<<maxcount<<endl;	
	}
	return 0;
}
