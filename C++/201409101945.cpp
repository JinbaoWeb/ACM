#include <iostream>
#include <algorithm>
using namespace std;
#define M 200005
int main()
{
	int t,n,a[M];
	cin>>t;
	while (t)
	{
		cin>>n;
		if (n==1)
		{
			int s;
			cin>>s;
			cout<<s%123456<<endl;
			t--;
			continue;
		}
		long long sum=0,time=0;
		for (int i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n);
		for (int i=0;i<n;i++)
		{
			sum+=a[i];
			if (i)
			{
				time+=sum;
				time%123456;
			}
		}
		cout<<time%123456<<endl;
		t--;
	}
	return 0;
}
