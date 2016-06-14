#include <iostream>
#include <algorithm>
#include <iostream>
using namespace std;
#define M 710
struct point
{
	int x;
	int y;	
};
int cmp(point a,point b)
{
	if (a.x<b.x)
		return 1;
	else
	{
		if (a.x==b.x)
		{
			if(a.y<b.y)
				return 1;
			else
				return 0;
		}
		else
			return 0;
	}
}
int main()
{
	int n;
	point p[M];
	while (cin>>n&&n)
	{
		for (int i=0;i<n;i++)
			cin>>p[i].x>>p[i].y;
		sort(p,p+n,cmp);
		int maxcount=0,count=0;
		for (int i=0;i<n;i++)
			for (int j=i+1;j<n;j++)
			{
				count=0;
				for (int s=j+1;s<n;s++)
				{
					
					if((p[i].x-p[j].x)*(p[i].y-p[s].y) == (p[i].x-p[s].x)*(p[i].y-p[j].y))
						count++;
						/*double k=(p[j].y-p[i].y)*1.0/(p[j].x-p[i].x);
						if ((k*(p[s].x-p[i].x)+p[i].y-p[s].y)==0)
							count++;
						if ((k*(p[s].x-p[i].x)+p[i].y-p[s].y)>0)
							break;*/
				}
				if (maxcount<count)
					maxcount=count;
			}
		cout<<maxcount+2<<endl;
	}
	return 0;
} 