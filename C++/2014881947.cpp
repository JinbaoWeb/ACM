#include <iostream>
#include <cmath>
using namespace std;
#include <iomanip>
#define g 9.8
#define pi 3.1415926535897932384626433832
int main()
{
	int n;
	double v,d;
	cin>>n;
	for (int c=1;c<=n;c++)
	{
		cin>>v>>d;
		double ss=asin(d/(v*v)*g)/pi*90;
		if (ss<=0)
			ss=-ss;
		cout<<"Case #"<<c<<": "<<fixed<<setprecision(7)<<ss<<endl;
	}
	return 0;
}
