#include <iostream>
#include <string.h>
using namespace std;
bool x[10001];
int f(int n)
{
	int sum=n;
	while (n)
	{
		sum+=n%10;
		n/=10;
	}
	return sum;
}
int main()
{
	memset(x,true,sizeof (x));
	for (int i=1;i<=10000;i++)
	{
		if (f(i)<=10000)
			x[f(i)]=false;
		else
			break;
	}
	for (int i=1;i<=9993;i++)
		if (x[i]==true)
			cout<<i<<endl;
	return 0;
}
