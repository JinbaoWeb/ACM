#include <iostream>
using namespace std;
int main()
{
	int t,a,b,c;
	cin>>t;
	int sum=0;
	while (cin>>a>>b>>c)
	{
		if (a>b-c)
			cout<<"do not advertise"<<endl;
		if (a<b-c)
			cout<<"advertise"<<endl;
		if (a==b-c)
			cout<<"does not matter"<<endl;
	}
	return 0;
}
