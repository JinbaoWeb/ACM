#include <iostream>
using namespace std;
int main()
{
	int t,n,k;
	cin>>t;
	while (cin>>n>>k)
	{
		long long mul=1;
		if (n<=k)
		{
			for (int i=0;i<n;i++)
			{
				mul*=(k-i);
				mul%=10000;
			}	
		}
		else
		{
			mul=1;
			for (int i=0;i<n-3;i++)
			{
				mul*=k-1;
				mul%=10000;
			}
			cout<<mul<<endl;
			mul=mul*k*(k-1+(k-2)*(k-2));
		}
		cout<<mul%10000<<endl;
	}
	return 0;
}
