#include <iostream>
using namespace std;
int main()
{
	int min=0xffffff,max=0;
	int n,t,s;
	cin>>t;
	while (cin>>n)
	{
		min=0xffffff,max=0;
		for (int i=0;i<n;i++)
		{
			cin>>s;
			if (s>max)
				max=s;
			if (s<min)
				min=s;
		}
		cout<<2*(max-min)<<endl;
	}
	return 0;
}
