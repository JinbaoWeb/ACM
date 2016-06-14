#include <iostream>
using namespace std;
int main()
{
	int t,n,a,b;
	cin>>t;
	for (int c=1;c<=t;c++)
	{
		cin>>n;
		cin>>a;
		long long sum=0;
		int max=a;
		for (int i=1;i<n;i++)
		{
			cin>>b;
			if (b<max)
				sum++;
			else
				max=b;
		}
		cout<<sum<<endl;
	}
	return 0;
}
