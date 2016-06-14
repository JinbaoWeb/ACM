#include <iostream>
using namespace std;
int main()
{
	int t,n;
	long long a[1002];
	cin>>t;
	while (t--)
	{
		cin>>n;
		int k=0;
		for (int i=0;i<n;i++)
			cin>>a[i];
		if (n==1&&a[0]==1)
		{
			cout<<"Yes"<<endl;
			continue;
		}	
		for (int i=0;i<n-1;i++)
		{
			if (a[i]>1)
				continue;
			if (k==0)
				k=1;
			else
				k=0;
		}
		if (k==0)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
} 
