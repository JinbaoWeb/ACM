#include <iostream>
using namespace std;
#define MAX 50005
int main()
{
	int t,n,a[MAX],dp[MAX];
	cin>>t;
	for (int cases=1;cases<=t;cases++)
	{
		cin>>n;
		for (int i=0;i<n;i++)
			cin>>a[i];
		dp[0]=1;
		int answer=dp[0];
		for (int i=1;i<n;i++)
		{
			int temp=1,max=0;
			for (int j=0;j<i;j++)
			{
				if (a[i]>a[j])
					temp=dp[j]+1;
				if (temp>max)
					max=temp;
			}
			dp[i]=max;
			if (dp[i]>answer)
				answer=dp[i];
		}
		cout<<answer<<endl;
	}
	return 0;
}
