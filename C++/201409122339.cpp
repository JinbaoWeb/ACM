#include <iostream>
using namespace std;
int main()
{
	int n,m,a,b;
	while (cin>>n>>m>>a>>b)
	{
		double s=1.0*b/m;
		if (a<=s)
			cout<<n*a<<endl;
		else
		{
			int k=n/m;
			int money=k*b;
			int left=n-k*m;
			if (left*a<=b)
				money+=left*a;
			else
				money+=b;
			cout<<money<<endl;
		}
	}
	return 0;
}
