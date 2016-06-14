#include <iostream>
using namespace std;
#define M 10000
int f(int a)
{
	int odd=0,even=0,flag=0;
	while (a>0)
	{
		if (flag==0)
		{
			even+=a%10;
			flag=1;
		}
		else
		{
			odd+=a%10;
			flag=0;
		}	
		a/=10;	
	}
	return even-odd;
}
int main()
{
	int t,l,r;
	int a[M];
	int k=1,s=0;
	while (k++)
	{
		if (f(11*k+3)!=3)
			a[s++]=11*k+3;
		if (k>=1000)
			break;
	}
	for (int i=0;i<s;i++)
		cout<<a[i]<<" ";
	/*cin>>t;
	for (int c=1;c<=t;c++)
	{
		cin>>l>>r;
		int answer=(r+8)/11-(l+7)/11;
	}*/
	return 0;
}
