#include <iostream>
#include <string.h>
using namespace std;
struct people
{
	int x,y,v;
}p[501];
int main()
{
	int n,max=-1,a[501],c=1;
	while (cin>>n)
	{
		if (n==0)
			break;
		memset(a,0,sizeof(a));
		int num=0;
		for (int i=0;i<n;i++)
		{
			cin>>p[i].x>>p[i].y>>p[i].v;
			if (p[i].v==0)
				num++;
			if (p[i].v>max)
				max=p[i].v;
		}	
		for (int i=0;i<n;i++)
			if (p[i].v==max)
				a[i]=1;
		
		if (num==0)
			memset(a,0,sizeof(a));
		cout<<"Case #"<<c<<": ";
		for (int i=0;i<n;i++)
			cout<<a[i];
		cout<<endl;
		c++;
	}
	return 0;
}
