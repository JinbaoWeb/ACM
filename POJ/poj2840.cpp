#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;
int main()
{
	int t;
	cin>>t;
	char clock[50];
	while (cin>>clock)
	{
		int n=strlen(clock),index;
		for (int i=0;i<n;i++)
			if (clock[i]==':')
			{
				index=i;
				break;
			}
		int sum=0,back=0;
		for (int i=0;i<index;i++)
			sum+=pow(10,index-i-1)*(clock[i]-'0');
		for (int i=index+1;i<n;i++)
			back+=pow(10,i-index-1)*(clock[i]-'0');
		if (back)
		{
			cout<<0<<endl;
			continue;
		}
		if (sum>=1&&sum<=12)
			cout<<sum+12<<endl;
		else
		{
			if (sum>=13&&sum<24)
				cout<<sum-12<<endl;
			else
				cout<<12<<endl;
		}
	}
	return 0;
}
