#include <iostream>
#include <iomanip> 
using namespace std;
int main()
{
	int t;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		int m,n;
		cin>>m>>n;
		cout<<"Scenario #"<<i<<":"<<endl;
		if (m%2!=0&&n%2!=0)
			cout<<fixed<<setprecision(2)<<(double)m*n+0.41<<endl;
		else
			cout<<fixed<<setprecision(2)<<(double)m*n<<endl;
		cout<<endl;	
	} 
	return 0;
} 
