#include <iostream>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <stdio.h>
using namespace std;
#define M 100005
int main()
{
	int n,m,a[M],b[M];
	while (cin>>n)
	{
		int sum=0;
		if (n%2==0)
		{
			for (int i=0;i<=n;i++)
			{
				cin>>a[i];
				if (a[i]==0)
					b[i]=0;
				else
				{
					if (a[i]%2==0)
						b[i]=a[i]-1;
					else
						b[i]=a[i]+1;
				}
				sum+=a[i]^b[i];
			}
		}
		else
		{
			for (int i=0;i<=n;i++)
			{
				cin>>a[i];
				if (a[i]==0)
					b[i]=n;
				else
				{
					if (a[i]==n)
						b[i]=0;
					else
					{
						if (a[i]%2==0)
							b[i]=a[i]-1;
						else
							b[i]=a[i]+1;
					}
				}
				sum+=a[i]^b[i];
			}
			
		}
		cout<<sum<<endl;
		for (int i=0;i<n;i++)
			cout<<b[i]<<" ";
		cout<<b[n]<<endl;
	}
	return 0;
} 
