#include <iostream>
using namespace std;
int main()
{
	int n,sum;
	while (cin>>n&&n)
	{
		sum=0;
		while (n>=3)
		{
			int num=n/3;
			sum+=num;
			n=n%3+num;
		}
		if (n==2)
			sum++;
		cout<<sum<<endl;
	}
	return 0;
} 
