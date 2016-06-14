#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
const long long M=1e9+7;
int main()
{
	int t,n;
	long long a[2001];
	cin>>t;
	while (t--)
	{
		cin>>n;
		for (int i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n);
		if (n==1)
			cout<<1<<endl;
		else
		{
			if (n==2)
				cout<<a[0]+1<<endl;
			else
			{
				if (n%2==0)
				{
					long long sum=1;
					for (int i=0;i<n;i++,i++)
					{
						sum=(sum%M)*(a[i]+1);
					}
					cout<<sum%M<<endl;
				}
				else
				{
					long long sum=1;
					for (int i=1;i<n;i++,i++)
					{
						sum=(sum%M)*(a[i]+1);
					}
					cout<<sum%M<<endl;
				}
			}
		}
	}
	return 0;
} 
