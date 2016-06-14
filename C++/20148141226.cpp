#include <iostream>
using namespace std;
int main()
{
	int h,a,b,k,c=1;
	while (cin>>h>>a>>b>>k)
	{
		if (h==0&&a==0&&b==0&&k==0)
			break;
		if (a>b)
		{
			int s=a-b;
			int flag=h;
			s=k*s;
			h=h-s;
			h+=b;
			if (flag>h)
				cout<<"Case #"<<c<<": YES"<<endl;
			else
				cout<<"Case #"<<c<<": NO"<<endl;
		}
		else
			cout<<"Case #"<<c<<": NO"<<endl;
		c++;
	}
	return 0;
}
