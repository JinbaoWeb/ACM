#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	float t,n,a[1001];
	cin>>t;
	while (cin>>n)
	{
		float sum=0;
		for (int i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}
		float dv=sum*1.0/n;
		float count=0;
		for (int i=0;i<n;i++)
			if (a[i]>dv)
				count++;
		cout<<fixed<<setprecision(3)<<count*100/n<<"%"<<endl;	
	}
	return 0;
} 
