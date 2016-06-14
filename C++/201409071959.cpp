#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	long long a[105],b[5000];
	bool used[5000];
	while (cin>>n)
	{
		for (int i=0;i<n;i++)
			cin>>a[i];
		memset(used,false,sizeof(used));
		int k=0;
		for (int i=0;i<n;i++)
			for (int j=i+1;j<n;j++)
				b[k++]=a[i]+a[j];
		for (int i=0;i<k;i++)
		{
			if (used[i]==true)
				continue;
			for (int j=i+1;j<k;j++)
			{
				if (b[i]==b[j])
					used[j]=true;
			}
		}
		long long sum=0;
		for (int i=0;i<k;i++)
			if (used[i]!=true)
				sum+=b[i];
		cout<<sum<<endl;
	}
	return 0;
} 
