#include <iostream>
using namespace std;
int f(long long a)
{
	int odd=0,even=0,flag=0;
	while (a>0)
	{
		if (flag==0)
		{
			even+=a%10;
			flag=1;
		}
		else
		{
			odd+=a%10;
			flag=0;
		}	
		a/=10;	
	}
	return even-odd;
}
int main()
{
	long long l,r,t;
	cin>>t;
	for (int c=1;c<=t;c++)
	{
		cin>>l>>r;
		long long k=(l-3)/11;
		long long R=k*11+14;
		while (f(R)==3)
		{
			k++;
			R=k*11+3;
		}
		cout<<R<<endl;
		if (R>r||R<l)
			cout<<-1<<endl;
		else
			cout<<R<<endl;
	}
	return 0;
} 
