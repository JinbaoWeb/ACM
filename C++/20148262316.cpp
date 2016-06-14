#include <iostream>
#include <algorithm>
#define M 300005
using namespace std;
int main()
{
	int n,a[M];
	while (cin>>n)
	{
		long long sum=0,maxsum=0;
		for (int i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}	
		sort(a,a+n);
		for (int i=0;i<n;i++)
		{
			maxsum+=sum;
			if (sum!=a[n-1])
				maxsum+=a[i]; 
			sum-=a[i];
		}
		
		cout<<maxsum<<endl;
	}
	return 0;
}
