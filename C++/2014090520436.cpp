#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int n,a[205][205],dp[205][205];
	while (cin>>n)
	{
		memset(dp,0,sizeof(dp));
		for (int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>a[i][j];
		for (int i=0;i<n;i++)
			dp[0][i]=a[0][i];
		for (int i=1;i<n;i++)
		{
			for (int j=0;j<n;j++)
			{
				if (i==j)
				{
					dp[i][j]=0;
					continue;
				}
				int min=0xffffff;
				for (int k=0;k<n;k++)
				{
					if (i-1==k)
						continue;
					if (min>dp[i-1][k])
						min=dp[i-1][k];
				}
				dp[i][j]=a[i][j]+min;
			}
		}
		cout<<endl;
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
				cout<<dp[i][j]<<" ";
			cout<<endl;
		}	
	}
	return 0;
}
