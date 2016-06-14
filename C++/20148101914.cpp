#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int t,a[6];
	cin>>t;
	for (int c=1;c<=t;c++)
	{
		for (int i=0;i<6;i++)
			cin>>a[i];
		sort(a,a+6);
		int sum1=a[4]+a[5];
		int sum2=a[1]+a[2]+a[3];
		if (sum1>sum2)
			cout<<"Grandpa Shawn is the Winner!"<<endl;
		else
			cout<<"What a sad story!"<<endl;
	}
	return 0;
} 
