#include <iostream>
using namespace std;
struct rectangle
{
	int xmin,ymin;
	int xmax,ymax;
}r[5002];
int main()
{
	int n;
	while (cin>>n)
	{
		for (int i=0;i<n;i++)
			cin>>r[i].xmin>>r[i].xmax>>r[i].ymin>>r[i].ymax;
		int count=0;
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
			{
				if (i!=j&&r[i].xmin>=r[j].xmin&&r[i].ymin>=r[j].ymin&&r[i].xmax<=r[j].xmax&&r[i].ymax<=r[j].ymax)
				{
					count++;
					break;
				}
			}
		cout<<count<<endl;
	}
	return 0;
}
