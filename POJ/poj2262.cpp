#include <iostream>
using namespace std;
bool isprime(int n)
{
	if (n<2)
		return false;
	if (n==2||n==3||n==5||n==7)
		return true;
	for (int i=2;i*i<=n;i++)
		if (n%i==0)
			return false;
	return true;
}
int main()
{
	int n;
	while (cin>>n)
	{
		for (int i=2;i<=n/2;i++)
			if (isprime(i)==true&&isprime(n-i)==true)
			{
				cout<<n<<" = "<<i<<" + "<<n-i<<endl;
				break;
			}		
	}
	return 0;
}
