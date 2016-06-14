#include <iostream>
using namespace std;
int main()
{
	int n,a[11000],i=1,j=1,s;
	while (i<=10000)
	{
		for (s=i;s<i+j;s++)
			a[s]=j;
		i=i+j++;
	}
	while (cin>>n&&n)
	{
		int sum=0;
		for (int k=1;k<=n;k++)
			sum+=a[k];
		cout<<n<<" "<<sum<<endl;
	}
	return 0;
} 
