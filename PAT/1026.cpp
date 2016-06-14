#include <iostream>
using namespace std;
int main()
{
	int n;
	char c;
	cin>>n>>c;
	int k=n/2+(n%2==1?1:0);
	for (int i=0;i<k;i++)
	{
		cout<<c;
		for (int j=1;j<n-1;j++)
		{
			if (i==0 || i==k-1)
				cout<<c;
			else
				cout<<" ";
		}
		cout<<c<<endl;
	}
	return 0;
}