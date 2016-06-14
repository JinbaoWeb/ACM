#include <iostream>
#include <algorithm>
#include <iomanip> 
using namespace std;
int main()
{
	int t,n;
	long long a[52];
	long long d[52];
	cin>>t;
	for (int c=1;c<=t;c++)
	{
		cin>>n;
		int max=-0xffffff;
		for (int i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n);
		for (int i=1;i<n;i++)
			d[i-1]=a[i]-a[i-1];
		sort(d,d+n-1);
		/*for (int i=0;i<n;i++)
			cout<<a[i]<<" ";
		cout<<endl;
		for (int i=0;i<n-1;i++)
			cout<<d[i]<<"-";
		cout<<endl;*/
		a[n]=0xffffff;
		int i;
		for (i=n-2;i>=0;i--)
		{
			for (int j=0;j<n;j++)
			{
				
			}
		}
		cout<<fixed<<setprecision(3)<<(double)d[i]<<endl;
	}
	return 0;
}
