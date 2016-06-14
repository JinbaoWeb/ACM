#include <iostream>
using namespace std;
int main()
{
	int a[6],t;
	char x[10],y[10];
	cin>>t;
	while (cin>>x)
	{
		a[0]=0;
		for (int i=1;i<6;i++)
			a[i]=x[i]-x[i-1];
		for (int i=0;i<6;i++)
			cout<<a[i]<<" ";
		cout<<endl;
		for (int i=5;i>=0;i--)
			cout<<char('a'+a[5-i]);
		cout<<endl;
	}
	return 0;
}
