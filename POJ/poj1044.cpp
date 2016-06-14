#include <iostream>
using namespace std;
struct computer
{
	int year;
	int a,b;
}c[25];
int main()
{
	int t=1;
	int n;
	while (cin>>n)
	{
		if (n==0)
			break;
		int flagflag=0;
		for (int i=1;i<=n;i++)
			cin>>c[i].year>>c[i].a>>c[i].b;
		int y=0;
		for (int i=1;i<=n;i++)
			if (c[i].year>y)
				y=c[i].year;
		while (y<=10000)
		{
			int flag=0;
			for (int i=1;i<=n;i++)
				if (((y-c[i].year)%(c[i].b-c[i].a))==0)
					flag++;	
			if (flag==n)
				break;	
			y++;
		}
		cout<<"Case #"<<t<<":"<<endl;
		if (y>=10000)
			cout<<"Unknown bugs detected."<<endl;
		else
			cout<<"The actual year is "<<y<<"."<<endl;
		cout<<endl;
		t++;
	}
	return 0;
}
