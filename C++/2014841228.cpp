#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int t,a;
	double d,v1,v2,v3;
	cin>>t;
	while (cin>>a>>d>>v1>>v2>>v3)
	{
		cout<<a<<" ";
		cout<<fixed<<setprecision(2)<<(d/(v1+v2))*v3<<endl;
	}
	return 0;
} 
