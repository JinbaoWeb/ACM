#include <iostream>
#include <cmath>
#include <stdio.h> 
using namespace std;
int main()
{
	char b[40],n;
	int a[32];
	int map[8]={1,2,4,8,16,32,64,128};
	cin>>n;
	getchar();
	for (int j=1;j<=n;j++)
	{
		int ip1=0,ip2=0,ip3=0,ip4=0;
		gets(b);
		for (int i=0;i<32;i++)	
			a[i]=b[i]-'0';
		for (int i=0;i<8;i++)
			if (a[i]==1) 
				ip1+=a[i]*map[7-i];
		for (int j=8;j<16;j++)
			if (a[j]==1)
				ip2+=a[j]*map[15-j];
		for (int k=16;k<24;k++)
			if (a[k]==1)
				ip3+=a[k]*map[23-k];
		for (int s=24;s<32;s++)
			if (a[s]==1)
				ip4+=a[s]*map[31-s];
		cout<<ip1<<"."<<ip2<<"."<<ip3<<"."<<ip4<<endl;
	}
	return 0;
}
