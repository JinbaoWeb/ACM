#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;
#define M 100005
int main()
{
	int n,a[M],b[M];
	bool used[M];
	while (cin>>n)
	{
		int sum=0;
		memset(used,false,sizeof(used));
		for (int i=0;i<=n;i++)
		{
			cin>>a[i];
			int k=0,s=a[i],flag=0;
			while (s)
			{
				int p=s%2;
				if (p==0)
					p=1;
				else
					p=0;
				int q=p*pow(2,flag++)+k;
				if (q>n)
					break;
				else
					k=q;
				s/=2;
			}
			if (k==0&&a[i]!=0)
				k=k+pow(2,flag++);
			if (used[k]==true)
				k=k+pow(2,flag-1);
			b[i]=k;
			used[k]=true;
			sum+=a[i]^b[i];
		}
		cout<<sum<<endl;
		for (int i=0;i<n;i++)
			cout<<b[i]<<" ";
		cout<<b[n]<<endl;	
	}
	return 0;
} 
