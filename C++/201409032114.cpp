#include <iostream>
using namespace std;
int main()
{
	int t,n;
	cin>>t;
	for (int c=0;c<t;c++)
	{
		cin>>n;
		int i=1,num=2;
		if (n==2)
		{
			cout<<1<<endl;
			continue;
		}
		while (i++)
		{
			if (num<n&&n<=num+i)
				break;
			num+=i;
		}
		cout<<i<<endl;
	}
	return 0;
}
