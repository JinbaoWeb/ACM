#include <iostream>
#include <string.h>
using namespace std;
#define M 25000001
short hash[M];
int main()
{
	int a1,a2,a3,a4,a5,x1,x2,x3,x4,x5;
	while (cin>>a1>>a2>>a3>>a4>>a5)
	{
		memset(hash,0,sizeof(hash));
		for (x1=-50;x1<=50;x1++)
		{
			if (x1==0)
				continue;
			for (x2=-50;x2<=50;x2++)
			{
				if (x2==0)
					continue;
				int sum=(x1*x1*x1*a1+x2*x2*x2*a2)*(-1);
				if (sum<0)
					sum+=25000000;
				hash[sum]++;
			}
		}
		int count=0;
		for (x3=-50;x3<=50;x3++)
		{
			if (x3==0)
				continue;
			for (x4=-50;x4<=50;x4++)
			{
				if (x4==0)
					continue;
				for (x5=-50;x5<=50;x5++)
				{
					if (x5==0)
						continue;
					int sum=x3*x3*x3*a3+x4*x4*x4*a4+x5*x5*x5*a5;
					if (sum<0)
						sum+=25000000;
					if (hash[sum])
						count+=hash[sum];
				}
			}
		}
		cout<<count<<endl;
	}
	return 0;
}
