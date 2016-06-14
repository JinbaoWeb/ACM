#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	char c;
	int a,b;
	int t;
	cin>>t;
	while (t--)
	{
		cin>>c>>a>>b;
		if (c=='+')
			cout<<a+b<<endl;
		if (c=='-')
			cout<<a-b<<endl;
		if (c=='*')
			cout<<a*b<<endl;
		if (c=='/')
		{
			if (a%b==0)
				cout<<a/b<<endl;
			else
				cout<<fixed<<setprecision(2)<<1.0*a/b<<endl;
		}
			
	}
	return 0;
} 
