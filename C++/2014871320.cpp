#include <iostream>
#include <algorithm>
using namespace std;
struct point
{
	int x,y;
}p[1005];
int cmp(point a,point b)
{
	if (a.x<b.x)
		return 1;
	else
	{
		if (a.x==b.x)
			if (a.y<b.y)
				return 1;
		return 0;
	}
}
int main()
{
	int t,n;
	cin>>t;
	for (int c=1;c<=t;c++)
	{
		cin>>n;
		for (int i=0;i<n;i++)
			cin>>p[i].x>>p[i].y;
		sort(p,p+n,cmp);
		int count=0;
		for (int i=0;i<n;i++)
		{
			for (int j=i+1;j<n;j++)
			{
				if (p[i].x!=p[j].x)
					continue;
				for (int k=j+1;k<n;k++)
				{
					if (p[i].y!=p[k].y)
						continue;
					for (int s=k+1;s<n;s++)
					{
						if (p[k].x==p[s].x&&p[s].y==p[j].y)
							count++;
					}
				}
			}
		}
		cout<<count<<endl;
	}
	return 0;
}
