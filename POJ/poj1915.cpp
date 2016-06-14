#include <iostream>
#include <fstream> 
#include <queue>
#include <string.h> 
using namespace std;
int dir[8][2]={{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2}};
bool used[305][305];
struct point
{
	int x,y,step;
};
bool isvivld(point a,int n)
{
	if (a.x<n&&a.x>=0&&a.y>=0&&a.y<n&&used[a.x][a.y]==false)
		return true;
	return false;
}
int bfs(point start,point end,int n)
{
	queue<point> q;
	point a,b;
	a=start;
	used[a.x][a.y]=true;
	q.push(a);
	while (!q.empty())
	{
		a=q.front();
		q.pop();
		a.step++;
		if (a.x==end.x&&a.y==end.y)
		{
			return a.step;
		}	
		for (int i=0;i<8;i++)
		{
			b=a;
			b.x+=dir[i][0];
			b.y+=dir[i][1];
			if (isvivld(b,n)==true)
			{
				used[b.x][b.y]=true;
				q.push(b);
			}
		}
	}
	return 1;
}
int main()
{
	//ifstream cin("1915.txt");
	int t,n;
	cin>>t;
	point start,end;
	for (int i=1;i<=t;i++)
	{
		cin>>n;
		cin>>start.x>>start.y>>end.x>>end.y;
		start.step=0;
		memset(used,false,sizeof(used));
		cout<<bfs(start,end,n)-1<<endl;
	}
	return 0;
}
