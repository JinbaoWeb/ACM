#include <iostream>
#include <queue>
using namespace std;
bool used[5][5];
int map[5][5];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
struct point
{
	int x,y;
};
point v[25];
bool isvivld(point s)
{
	if (map[s.x][s.y]==0&&s.x>=0&&s.x<5&&s.y>=0&&s.y<5)
		return true;
	return false;
}
int flag;
bool bfs(point a,point b)
{
	flag=0;
	queue<point> q;
	point m,n;
	v[flag].x=a.x;
	v[flag].y=a.y;
	flag++;
	q.push(a);
	used[a.x][a.y]=true;
	while (!q.empty())
	{
		m=q.front();
		q.pop();
		for (int i=0;i<4;i++)
		{
			n.x=m.x+dir[i][0];
			n.y=m.y+dir[i][1];
			if (isvivld(n)==true&&used[n.x][n.y]==false)
			{
				if (n.x==b.x&&n.y==b.y)	//find
				{
					v[flag].x=n.x;
					v[flag].y=n.y;
					return true;
				}
				else
				{
					v[flag].x=n.x;
					v[flag].y=n.y;
					flag++;
					q.push(n);
					used[n.x][n.y]=true;
				}	
			}
		}
	}
	return false;
}
int main()
{
	point visit[25];
	int index=0;
	for (int i=0;i<5;i++)
		for (int j=0;j<5;j++)
			cin>>map[i][j];
	point a,b;
	a.x=0;
	a.y=0;
	b.x=4;
	b.y=4;
	if (bfs(a,b)==true)
	{
		visit[index].x=v[flag].x;
		visit[index].y=v[flag].y;
		index++;
		for (int k=flag-1;k>=0;k--)
		{
			for (int i=0;i<4;i++)
			{
				if (v[k].x+dir[i][0]==visit[index-1].x&&v[k].y+dir[i][1]==visit[index-1].y)
				{
					visit[index].x=v[k].x;
					visit[index].y=v[k].y;
					index++;
					break;
				}
			}
		}
		for (int i=index-1;i>=0;i--)
			cout<<"("<<visit[i].x<<", "<<visit[i].y<<")"<<endl;
	}
	return 0;
}
