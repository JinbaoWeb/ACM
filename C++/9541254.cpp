#include <iostream>
#include <string.h>
using namespace std;
int pow(int b)
{
	int a=1;
	if (b==0)
		return 1;
	for (int i=1;i<=b;i++)
		a*=10;
	return a;
}
int main()
{
	char a[202],b[202],c[200];
	char nn[10];
	int n;
	while (cin.getline(a,202))
	{
		cin.getline(b,202);
		cin.getline(nn,10);
		//cin>>n;
		int n=0;
		int len=strlen(nn);
		for (int i=0;i<len;i++)
			n+=(nn[i]-'0')*pow(len-1-i);
		//cout<<n<<endl;
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
	//	cout<<sum_a<<"-"<<sum_b<<endl; 
		int num_a=sum_a/5;
		if (num_a*5<sum_a)
			num_a++;
		int num_b=sum_b/10;
		if (num_b*10<sum_b)
			num_b++;
		if (num_a+num_b<=n)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
