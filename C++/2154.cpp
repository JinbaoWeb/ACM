#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char a[202],b[202],c[200];
	int n;
	while (cin.getline(a,202))
	{
		cin.getline(b,202);
		cin.getline(c,202);
		cin>>n;
		int len_a=strlen(a);
		int len_b=strlen(b);
		int sum_a=0,sum_b=0;
		for (int i=0;i<len_a;i++)
		{
			if (a[i]==' ')
				continue;
			else
				sum_a+=a[i]-'0';
		}
		for (int i=0;i<len_b;i++)
		{
			if (b[i]==' ')
				continue;
			else
				sum_b+=b[i]-'0';
		}
		//cout<<sum_a<<"-"<<sum_b<<endl; 
		int num_a=sum_a/5;
		if (num_a*5<sum_a)
			num_a++;
		int num_b=sum_b/10;
		if (num_b*10<sum_b)
			num_b++;
		if (num_a+num_b<n)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}



