#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n,a[1005];
	while (cin>>n)
	{
		int sum=0;
		for (int i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}
		int av=sum/n;
		sort(a,a+n);
		int me=a[(n+1)/2];
		if (av>=me)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
	return 0;
}
