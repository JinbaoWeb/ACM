#include <iostream>
using namespace std;
int main()
{
	int t,n,h[1002];
	cin>>t;
	while (cin>>n)
	{
		int minhigh=10000;
		for (int i=1;i<=n;i++)
			cin>>h[i];	
		int maxarea=0,area;	
		for (int i=1;i<=n;i++)
		{
			for (int k=i;k<=n;k++)
				if (h[k]<minhigh) 
					minhigh=h[k];
			for (int x=1;x<=n-i+1;x++)
			{
				int min=h[i];
				for (int s=i;s<=i+x-1;s++)
					if (h[s]<min)
						min=h[s];
				area=min*x;
				if (area>maxarea)
					maxarea=area;
				if (h[i+x-1]==minhigh)
					x=n-i-2;
			}
		}
		cout<<maxarea<<endl;
	}
	return 0;
} 
