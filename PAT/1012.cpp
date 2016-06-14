#include <iostream>
using namespace std;
int main()
{
	int a,b,d;
	int ans[40];
	while (cin>>a>>b>>d)
	{
		int c=a+b;
		int k=0;
		while (c>=d)
		{
			ans[k++]=c%d;
			c/=d;
		}
		if (c!=0)
			ans[k++]=c;
		while (k--)
		{
			cout<<ans[k];
		}
		cout<<endl;
	}
	return 0;
}