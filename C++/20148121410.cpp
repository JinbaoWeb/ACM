#include <iostream>
using namespace std;
int main()
{
	int t;
	long long n;
	cin>>t;
	for (int c=1;c<=t;c++)
	{
		cin>>n;
		int count=0;
		for (int i=4;i<n/3+7;i++)
		{
			int flag=0;
			int m=n;
			while (m>0)
			{
				int s=m%i;
				m/=i;
				if (s<3||s>6)
				{
					flag=1;
					break;
				}		
			}
			if (flag==0)
			{
				count++;
				cout<<i<<"-"<<endl;
			}
			
		}
		cout<<"Case #"<<c<<": "<<count<<endl;
	}
	return 0;
}
