#include <iostream>
using namespace std;
int main()
{
	int a,b,c,d;
	while (cin>>a>>b>>c>>d)
	{
		if (a==0&&b==0&&c==0&&d==0)
			break;
		if (a<=c&&b<=d)
			cout<<"100%"<<endl;
		else
		{
			int x1=c*100/a,x2=d*100/b;
			int x=x1<x2?x1:x2;
			int y1=c*100/b,y2=d*100/a;
			int y=y1<y2?y1:y2;
			if (x>y)
				cout<<x<<"%"<<endl;
			else
				cout<<y<<"%"<<endl;
		}
		
	}
	return 0;
} 
