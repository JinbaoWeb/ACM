#include <iostream>
#include <cmath>
using namespace std;
int x[16][3];
int main()
{
	int x[16][3],index;
	double a,b,c,d,sum;
	for (int i=0;i<16;i++)
		cin>>x[i][0]>>x[i][1]>>x[i][2];
	while (cin>>a>>b>>c)
	{
		if (a==-1&&b==-1&&c==-1)
			break;
		sum=(a-x[0][0])*(a-x[0][0])+(b-x[0][1])*(b-x[0][1])+(c-x[0][2])*(c-x[0][2]);;
		index=0;
		for (int i=1;i<16;i++)
		{
			d=(a-x[i][0])*(a-x[i][0])+(b-x[i][1])*(b-x[i][1])+(c-x[i][2])*(c-x[i][2]);
			if (d<sum)
			{
				sum=d;
				index=i;
			}
		}
		cout<<"("<<a<<","<<b<<","<<c<<") maps to ("<<x[index][0]<<","<<x[index][1]<<","<<x[index][2]<<")"<<endl;
	}
	return 0;
}
