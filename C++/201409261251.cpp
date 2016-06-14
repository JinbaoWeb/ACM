# include<iostream>
#include<iomanip>
using namespace std;
 float f (int a0,int a1,int a2,int a3,float x)
{
	int a=a0*x*x*x+a1*x*x+a2*x+a3;
	return a;
} 
int main ()
{
	int a0,a1,a2,a3;
	float a,b;
	cin>>a0>>a1>>a2>>a3;
	cin>>a>>b;
	for(;;)
	{
		cout<<"---"<<endl;
		if((b-a)<0.001)
		{
			cout<<fixed<<setprecision(2)<<(b+a)/2.0<<endl;
			break;
		}
		if(f(a0,a1,a2,a3,a)*f(a0,a1,a2,a3,b)<0)
		{
			int t;
			t=(b+a)/2.0;
			if(f(a0,a1,a2,a3,t)==0)
			{
				cout<<fixed<<setprecision(2)<<t<<endl;
			}
			else
			{	
				if(f(a0,a1,a2,a3,a)*f(a0,a1,a2,a3,t)<0)
				{
					b=t;continue;
				}
				if(f(a0,a1,a2,a3,t)*f(a0,a1,a2,a3,b)<0)
				{
					a=t;continue;
				}
			}
		}
	}
	return 0;
}

