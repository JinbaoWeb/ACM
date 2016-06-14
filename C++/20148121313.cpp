#include <iostream>
using namespace std;
bool f(int n)
{
	int flag=0,count=0,s;
	while (n>0)
	{
		count++;
		s=n%10;
		cout<<s<<endl;
		if (s>=3&&s<=6)
			flag++;
		n/=10;
	}
	if (flag==count)
		return true;
	return false;
}
int main()
{
	int t,a[]={3,4,5,6};
	long long n;
	cin>>t;
	for (int c=1;c<=t;c++)
	{
		cin>>n;
		/*
		if (f(n)==true)
		{
			cout<<"Case #"<<c<<": -1"<<endl;
			continue;
		}
		*/
		int count=0;
		for (int i=0;i<4;i++)
		{
			long long k=n/a[i];
			
			for (int j=0;j<3;j++)
			{
				long long ss=k;
				ss-=j;
				int flag=0;
				int m=n;
				while (m>0)
				{
					int s=m%ss;
					m/=ss;
					if (s<3||s>6)
					{
						flag=1;
						break;
					}		
				}
				if (flag==0)
				{
					count++;
					cout<<ss<<endl;
				}	
			}
		}
		cout<<"Case #"<<c<<": "<<count<<endl;
	}
	return 0;
}
