#include <iostream>
#include <string.h>
using namespace std;
#define M 105
int maxSubarray(int n, int *a)
{
	int b=0,sum=-0xffffff;
	for (int i=0;i<n;i++)
	{
		if (b>0)
			b+=a[i];
		else
			b=a[i];
		if (b>sum)
			sum=b;
	}
	return sum;
}

int main()
{
	int n,dp[M][M],temp[M];
	while (cin>>n)
	{
		
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
				cin>>dp[i][j];
		int max=-0xffffff;
		for (int i=0;i<n;i++)
		{
			for (int j=i;j<n;j++)
			{
				memset(temp,0,sizeof(temp));
				for (int k=0;k<n;k++)
					for (int s=i;s<=j;s++)
						temp[k]+=dp[s][k];
				int maxsubarray=maxSubarray(n,temp);
				if (max<maxsubarray)
					max=maxsubarray;
			}	
		}
		cout<<max<<endl;
	}
	return 0;
}
