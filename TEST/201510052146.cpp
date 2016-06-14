#include <iostream> 
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std; 
struct point
{
	int x;
	int y;
}a[200000+100];
struct point2
{
	int x;
	int y;
}b[200000+100];
struct cmp
{
  bool operator()(const point & aa,const point & bb)
  {
        if(aa.y==bb.y)
             return aa.x>bb.x; 
       	return aa.y<bb.y;
  }  
};
int cmp1(point  x,point  y)
{
	if( x.y ==  y.y)
		return x.x < y.x;
	return x.y > y.y;
}
int cmp2(point2  x,point2  y)
{
	return x.x < y.x;
}

int main() 
{
	ifstream cin("0.in");
	ofstream cout("10.out");
	int n,m,k;
	cin>>n>>m>>k;
	for(int i = 0 ; i < m; i++)
	{
		scanf("%d %d",&a[i].x,&a[i].y);
	}
	sort(a,a+n,cmp1);
	for(int j = 0; j < k; j ++)
	{
		scanf("%d %d",&b[j].x,&b[j].y);
	}
	sort(b,b+k,cmp2);
	priority_queue<point,vector<point>,cmp>que;
	int s = 0;
	for(int i = 0 ; i < m; i++)
	{
		que.push(a[i]);
		while(b[s].x == i+1)
		{ 
			for(int j = 0 ; j < b[s].y; j++)
			{
				point temp = que.top();
				if(j == 0)
					printf("%d",temp.x);
				else
					printf(" %d",temp.x);
				que.pop();
			}
			printf("\n");
			s++;
		}
	}
	return 0;
}
