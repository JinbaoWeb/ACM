#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int a[1000],t,n;
	cin>>t;
	while (cin>>n)
	{
		memset(a,0,sizeof(a));
		a[0]+=1;
		for (int i=1;i<=n;i++)
		{
			for (int j=0;j<1000;j++)
				a[j]*=i;
			for (int k=0;k<1000;k++)
				if(a[k]>=10)
				{
					a[k+1]+=a[k]/10;
					a[k]%=10; 
				} 
			int index;
			for (int i=1000;i>=0;i--)
				if (a[i]!=0)
				{
					index=i;
					break;
				}
			for (int i=index;i>=0;i--)
				cout<<a[i];
			cout<<endl;
		}
		int index;
		for (int i=1000;i>=0;i--)
			if (a[i]!=0)
			{
				index=i;
				break;
			}
		cout<<index<<endl;
		for (int i=index;i>=0;i--)
			cout<<a[i];
		cout<<endl;
	}
	
	
	return 0;
}
