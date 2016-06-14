#include <iostream>
#include <string.h>
using namespace std;
bool used[27][27];
int chess[27][27];
int str[8][2]={-1,-2,1,-2,-2,-1,2,1,-2,1,2,1,-1,2,1,2};
struct point
{
	char x,y;
}path[700];
int t,p,q,flag,a,b;
void dfs(int a,int b,int flag)
{
	chess[a][b]=flag;
	path[flag].x=a-1+'A';
	path[flag].y=b-1+'0';
	used[a][b]=true;
	for (int i=0;i<8;i++)
	{
		int m,n;
		m=a+str[i][0];
		n=b+str[i][1];
		if (1<=m&&m<=p&&1<=n&&n<=q&&used[m][n]==false)
			dfs(m,n,++flag);
	}
	if (flag!=p*q)
	{
		flag--;
		used[a][b]=false;
		return;
	}
}
int main()
{
	cin>>t;
	for (int c=1;c<=t;c++)
	{
		memset(used,false,sizeof(used));
		memset(chess,0,sizeof(chess));
		cin>>p>>q;
		a=b=flag=1;
		dfs(a,b,flag);
		for (int i=1;i<=p;i++)
		{
			for (int j=1;j<=q;j++)
				cout<<used[i][j]<<","<<chess[i][j]<<"    ";
			cout<<endl;
		}
		if (flag==p*q)
			for(int i=0;i<=flag;i++)
				cout<<path[flag].x<<path[flag].y;
		else
			cout<<"impossible";
		cout<<endl<<endl; 
	} 
	return 0;
}
