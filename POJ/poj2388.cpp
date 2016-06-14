#include <iostream>
#include <algorithm>
using namespace std;
int cmp(int a,int b)
{
	return a>b?0:1;
}
int main()
{
	int n,a[10000];
	while (cin>>n)
	{
		for (int i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n,cmp);
		cout<<a[n/2]<<endl;
	}
	return 0;
}
