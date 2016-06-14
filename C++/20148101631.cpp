#include <iostream>
using namespace std;
int main()
{
	int t,s,n,q,p;
	cin>>t;
	for (int c=1;c<=t;c++)
	{
		cin>>s>>n;
		for (int i=0;i<n;i++)
		{
			cin>>q>>p;
			//cout<<q<<"-"<<p<<endl;
			s+=q*p;
		}
		cout<<s<<endl;
	}
	return 0;
}
