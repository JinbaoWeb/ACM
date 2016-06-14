#include <iostream>
#include <algorithm>
using namespace std;
struct point
{
	int x,y;
}p[81];
int cmp(point a,point b)
{
	if (a.x<b.x)
		return 1;
	else
	{
		if (a.x>b.x)
			return 0;
		else
		{
			if (a.y<b.y)
				return 1;
			else
				return 0;
		}
	}
}
int main()
{
	int t,n;
	cin>>t;
	for (int c=0;c<t;c++)
	{
		cin>>n;
		for (int i=0;i<n;i++)
			cin>>p[i].x>>p[i].y;
		sort(p,p+n,cmp);
		int max=0,count=0;
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
			{
				count=0;
				if (p[i].x==p[j].x)
				{
					for (int k=0;k<n;k++)
					{
						if (p[k].x==p[i].x)
						{
							count++;
						}	
					}
				}
				else
				{
					if (p[i].y==p[j].y)
					{
						for (int k=0;k<n;k++)
							if (p[k].y==p[i].y)
								count++;
					}
					else
					{
						double a=(p[i].y-p[i].y)*1.0/(p[i].x-p[i].x);
						for (int k=0;k<n;k++)
							if (a*(p[k].x-p[i].x)==p[k].y-p[i].y)
								count++;
					}
				}
				if (max<count)
				{
					max=count;
				}	
			}
		}
		cout<<max<<endl;
	}
	return 0;
}
