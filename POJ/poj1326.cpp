#include <iostream>
#include <string.h>
using namespace std;
int f(int a,char b)
{
	if (b=='F')
		return 2*a;
	if (b=='B')
	{
		double s=1.5*a;
		if (s-(int)s>=0.5)
			return (int)s+1;
		return (int)s;
	}
	if (b=='Y')
	{
		if (a<=500)
			return 500;
		return a;
	}
}
int main()
{
	char x[100],y[100],b;
	int a,sum=0;
	while (cin>>x)
	{
		if (strcmp(x,"0")==0)
		{
			cout<<sum<<endl;
			sum=0;
			continue;
		}	
		if (strcmp(x,"#")==0)
			break;
		cin>>y>>a>>b;
		sum+=f(a,b);
	}
	return 0;
} 
