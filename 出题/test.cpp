
#include<math.h>
#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int a,b;
		cin>>a>>b;
		int c;
		double num,sum;
		num=sqrt(a*a+b*b);
		a=b?sum=sqrt(a*a+b*b):a>b?sum=sqrt(a*a-b*b):sum=sqrt(b*b-a*a);
		int x,y;
		x=num;
		y=sum;
		if(num-x==0)
		{
			c=num;
			cout<<c<<endl;
		}
		else
		{
			if(sum-y==0)
			{
				c=sum;
				cout<<c<<endl;
			}
			else
				cout<<"NO"<<endl;
		}
	}
	cin.get();	
	return 0;
}