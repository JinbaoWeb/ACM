#include <iostream>
using namespace std;
int main()
{
	int n,h;
	while (cin>>n)
	{
		int max=0;
		for (int i=0;i<n;i++)
		{
			cin>>h;
			if (max<h)
				max=h;
		}
		cout<<max<<endl;
	}
	return 0;
} 
