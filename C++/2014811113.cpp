#include <iostream>
#include <string.h>
#include <math.h>
#include <iomanip>
using namespace std;
#define m 100005
#define q (sqrt(5)+1)/2
int main()
{
	char a[m],b[m];
	double x=0,y=0;
	while (cin>>a>>b)
	{
		x=0;
		y=0;
		int len=strlen(a);
		for (int i=0;i<len;i++)
			x+=(a[i]-'0')*pow(q,len-i-1);
		len=strlen(b);
		for (int i=0;i<len;i++)
			y+=(b[i]-'0')*pow(q,len-i-1);
		cout<<fixed<<setprecision(39)<<x<<"-"<<y<<endl;
		if (x<y)
			cout<<"<"<<endl;
		if (x>y)
			cout<<">"<<endl;
		if (x==y)
			cout<<"="<<endl;
		
	}
	return 0;
}
