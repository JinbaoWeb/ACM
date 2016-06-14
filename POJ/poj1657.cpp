#include <iostream>
using namespace std;
int min(int a,int b)
{
	if (a>b)
		return b;
	return a;
}
int max(int a,int b)
{
	if (a<b)
		return a;
	return b;
}
int main()
{
	int t;
	cin>>t;
	char start[3],end[3];
	for (int c=1;c<=t;c++)
	{
		cin>>start>>end;
		int x=(start[0]-end[0])>0?(start[0]-end[0]):(end[0]-start[0]);
		int y=(start[1]-end[1])>0?(start[1]-end[1]):(end[1]-start[1]);
		if (x==y&&y==0)
			cout<<0<<" "<<0<<" "<<0<<" "<<0<<endl;
		else
		{
			cout<<min(x,y)+(x>y?x-y:y-x)<<" ";
			if (x==0||y==0||x==y)
				cout<<1<<" ";
			else
				cout<<2<<" ";
			if (x==0||y==0)
				cout<<1<<" ";
			else
				cout<<2<<" ";
			if ((x+y)%2==0)
			{
				if (x==y)
					cout<<1<<endl;
				else
					cout<<2<<endl;
			}
			else
				cout<<"Inf"<<endl;		
		}
		
		
	}
	return 0;
}
