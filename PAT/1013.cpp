#include <iostream>
using namespace std;
int a[10];
int main()
{
	for (int i=0;i<10;i++)
	{
		cin>>a[i];
	}
	for (int i=1;i<10;i++)
	{
		if (a[i])
		{
			cout<<i;
			a[i]--;
			break;
		}
	}
	for (int i=0;i<10;i++)
	{
		if (a[i])
		{
			for (int j=0;j<a[i];j++)
			{
				cout<<i;
			}
		}
	}
	cout<<endl;
	return 0;
}