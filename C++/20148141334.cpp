#include <iostream>
using namespace std;
int main()
{
	int c=1;
	long long x,k;
	while (cin>>x>>k)
	{
		if (x==0&&k==0)
			break;
		for (int i=2;i<=k;i++)
		{
			while (x%i!=0)
				x++;
		}
		cout<<"Case #"<<c<<": "<<x<<endl;
	}
	return 0;
}
