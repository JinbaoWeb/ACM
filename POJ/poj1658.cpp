#include <iostream>
using namespace std;
bool f(int *a)
{
	if (a[3]-a[2]==a[2]-a[1]&&a[2]-a[1]==a[1]-a[0])
		return true;
	return false;
}
int main()
{
	int t,a[6];
	cin>>t;
	for (int c=1;c<=t;c++)
	{
		for (int i=0;i<4;i++)
			cin>>a[i];
		if (f(a)==true)
		{
			a[4]=a[3]+a[1]-a[0];
		}	
		else
		{
			a[4]=a[1]*1.0/a[0]*a[3];
		}	
		for (int i=0;i<5;i++)
			cout<<a[i]<<" ";
		cout<<endl;	
	}
	return 0;
} 
