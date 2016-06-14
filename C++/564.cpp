#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n;
	while (cin>>n)
	{
		if (n<0)
			n=-n;
		int i=0;
		long long sum=0;
		for (i=1;;i++)
		{
			sum+=i;
			if (sum<=n&&sum+i+1>n)
				break;
		}
		int a=n-sum,b=sum+i+1-n;
		if (a>b)
		{
			i++;
			i+=b*2;
		}
		else
			i+=a*2;
		cout<<i<<endl;
	}
	return 0;
}
