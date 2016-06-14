#include <iostream>
#include <iomanip>
using namespace std;
double mul(int a)
{
	double s=1;
	while (a>0)
		s*=a--;
	return s;
}
int main()
{
	double a[10];
	a[0]=1;
	for (int i=1;i<10;i++)
		a[i]=mul(i);
	double answer=0;
	cout<<"n e"<<endl;
	cout<<"- -----------"<<endl;
	for (int i=0;i<10;i++)
	{
		cout<<i<<" ";
		answer+=1.0/a[i];
		cout<<setprecision(10)<<answer<<endl;
	}
	return 0;
}
