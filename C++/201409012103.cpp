#include <iostream>
using namespace std;
struct ff
{
	int x,y,z;
}f[1000];
int main()
{
	int a=123,b,c,num[9],kk=0;
	for (;a<300;a++)
	{
		for (b=a+1;b<999;b++)
		{
			c=a+b;
			if (c>1000)
				break;
			int x=a,y=b,z=c;
			int k=0;
			while (x)
			{
				num[k]=x%10;
				x/=10;
				k++;
			}
			while (y)
			{
				num[k]=y%10;
				y/=10;
				k++;
			}
			while (z)
			{
				num[k]=z%10;
				z/=10;
				k++;
			}
			int flag=0;
			
			for (int i=0;i<9;i++)
			{
				for (int j=1;j<9;j++)
				{
					if (i==j)
						continue;
					if (num[i]==num[j]||num[i]==0)
					{
						flag=1;
						break;
					}
				}
				if (flag==1)
					break;
			}
			if (flag==0)
			{
				//cout<<a<<"-"<<b<<"-"<<c<<endl;
				f[kk].x=a;
				f[kk].y=b;
				f[kk].z=c;
				kk++;
			}
			
		}
	}
	int n,t;
	cin>>t;
	while (cin>>n)
	{
		cout<<f[n-1].x<<" + "<<f[n-1].y<<" = "<<f[n-1].z<<endl;
	}
	return 0;
}
