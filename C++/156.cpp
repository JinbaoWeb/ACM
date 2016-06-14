#include <iostream>
using namespace std;
int main()
{
	int n,a[201],t;
	cin>>t;
	while (cin>>n)
	{
		for (int i=0;i<n;i++)
			cin>>a[i];
		int sum=0,count=0;
		for (int i=0;i<n-3;i++)
			for (int j=i+1;j<n-2;j++)
				for (int k=j+1;k<n-1;k++)
					for (int s=k+1;s<n;s++)
					{
						sum+=a[i]+a[j]+a[k]+a[s];
						if (sum==0)
							count++;
						sum=0;
					}
		cout<<count<<endl;
	}
	return 0;
}
