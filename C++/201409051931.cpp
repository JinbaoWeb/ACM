#include <iostream>
#include <string.h>
#include <cmath>
#define M 100000
using namespace std; 
int main()
{
	
	double x=(1+sqrt(5))/2,y=(1-sqrt(5))/2;
	int n;
	while (cin>>n)
	{
		int i=1;
		double f;
		while (i)
		{
			f=(pow(x,i)-pow(y,i))/sqrt(5);
			if (f>=n)
				break;
			i++;
		} 
		if ((int)f==n)
			cout<<i<<endl;
		else
			cout<<(pow(x,i-1)-pow(y,i-1))/sqrt(5)<<" "<<(int)f<<endl;
	}
	return 0;
}
