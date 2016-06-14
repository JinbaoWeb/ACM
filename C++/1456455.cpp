#include <iostream>
using namespace std;
int main()
{
	int t,n;
	cin>>n;
	while (cin>>t)
	{
		int mul=1;
		for (int i=1;i<=t;i++)
			mul*=i;
		cout<<mul<<endl;
	}
	return 0;
}
