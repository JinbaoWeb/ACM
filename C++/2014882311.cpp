#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int a[3],b[3],n;
	while (cin>>a[0]>>a[1]>>a[2]>>b[0]>>b[1]>>b[2]>>n)
	{
		int sum_a=0,sum_b=0;
		for (int i=0;i<3;i++)
		{
			sum_a+=a[i];
			sum_b+=b[i];
		}	
		int num_a=sum_a/5,num_b=sum_b/10;
		if (sum_a>num_a*5)
		{
			num_a++;
		}	
		if (sum_b>num_b*10)
		{
			num_b++;
		}	
		if (n>=num_a+num_b)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
