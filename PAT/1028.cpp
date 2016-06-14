#include <iostream>
#include <string.h>
using namespace std;
int a[200];
int main()
{
	memset(a,0,sizeof(a));
	int n,x,k;
	cin>>n;
	for (int i=0;i<n;i++)
	{
		cin>>x;
		a[x]++;
	}
	cin>>k;
	for (int i=0;i<k-1;i++)
	{
		cin>>x;
		cout<<a[x]<<" ";
	}
	cin>>x;
	cout<<a[x]<<endl;
	return 0;
}