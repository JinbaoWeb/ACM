#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int b,n,a;
	while (cin>>b>>n)
	{
		if (b==0&&n==0)
			break;
		a=pow(b,1.0/n);
		if (b-pow(a,n)>pow(a+1,n)-b)
			a++;
		cout<<a<<endl;
	}
	return 0;
}
