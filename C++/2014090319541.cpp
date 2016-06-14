#include <iostream>
#include <iomanip> 
using namespace std;
int main()
{
	int t;
	cin>>t;
	double x1,y1,x2,y2,x3,y3,x4,y4;
	while (cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4)
	{
		if (x1-x2==0||x3-x4==0)
		{
			if (x1-x2==0&&x3-x4==0)
			{
				if (x1==x3)
					cout<<"no"<<endl;
				else
					cout<<"line"<<endl;		
			}
			else
			{
				if (x1-x2==0)
				{
					double b=(y3-y4)*1.0/(x3-x4);
					double y=b*(x1-x3)+y3;
					cout<<fixed<<setprecision(3)<<x1<<" "<<y<<endl;		
				}
				else
				{
					double a=(y1-y2)*1.0/(x1-x2);
					double y=a*(x3-x1)+y1;
					cout<<fixed<<setprecision(3)<<x3<<" "<<y<<endl;	
				}
			}
			
		}
		else
		{
			double a=(y1-y2)*1.0/(x1-x2),b=(y3-y4)*1.0/(x3-x4);
			if (a==b)
			{
				if ((y1-y2)*1.0/(x1-x2)==(y1-y3)*1.0/(x1-x3))
					cout<<"no"<<endl;
				else
					cout<<"line"<<endl;
			}
			else
			{
				double x=(y3-x3*b+a*x1-y1)*1.0/(a-b);
				double y=a*(x-x1)+y1;
				cout<<fixed<<setprecision(3)<<x<<" "<<y<<endl;
			}
		}
		
	}
	return 0;
} 
