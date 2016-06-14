#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
#define M 10000
#define INF 0xffffff
struct point
{
	double l,r;
}; 
bool cmp(point a,point b)
{
	if  (a.l!=b.l)
		return a.l<b.l;
	return a.r<b.r;
}
int main()
{
	int n,d,count=0,flag=1,t=0;
	double x,y,temp;
	point p[M];
	while (cin>>n>>d)
	{
		if (n==0&&d==0)
			break;
		for (int i=0;i<n;i++)
		{
			cin>>x>>y;
			if (y>d)
				t=-1;
			else
			{
				p[i].l=x-sqrt(d*d-y*y);
				p[i].r=x+sqrt(d*d-y*y);
			}
			
		}
		sort(p,p+n,cmp);
		cout<<"----------"<<endl;
		for (int i=0;i<n;i++)
			cout<<p[i].l<<"     "<<p[i].r<<endl;
		cout<<"----------"<<endl;
		count=1;
		temp=p[0].r;
		for (int i=1;i<n;i++)
		{
			if (p[i].l>temp)
			{
				count++;
				temp=p[i].r;
			}
			else
			{
				if (p[i].r<temp)
					temp=p[i].r;
			}
			
		}
		if (t!=0)
			count=t;
		cout<<"Case "<<flag++<<": "<<count<<endl;	
	}
	return 0;
}
