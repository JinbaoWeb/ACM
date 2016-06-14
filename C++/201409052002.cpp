#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	long long n,i,a[100];
	while (cin>>n>>i)
	{
		memset(a,0,sizeof(a));
		int k=1;
		while (n)
		{
			int s=n%2;
			n/=2;
			a[k++]=s;
		}
		if (a[i]==1)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
