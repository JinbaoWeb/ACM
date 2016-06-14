#include <iostream>
using namespace std;
#define M 105
int main()
{
	int n,array[M][M],dp[M][M];
	while (cin>>n)
	{
		for (int i=0;i<n;i++)
			for (int j=0;j<=i;j++)
				cin>>array[i][j];
		for (int i=0;i<n;i++)
			dp[n-1][i]=array[n-1][i];
		for (int i=n-2;i>=0;i--)
		{
			for (int j=n-2;j>=0;j--)
			{
				int max=dp[i+1][j]>dp[i+1][j+1]?dp[i+1][j]:dp[i+1][j+1];
				dp[i][j]=max+array[i][j];
			}
		}
		cout<<dp[0][0]<<endl;
	}
	return 0;
} 
