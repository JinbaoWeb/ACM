#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int i,j;
	double n,s,q;
	cin>>n>>s>>q;
	double now = 0,nss = s,t;
	int ti=0;
	while(nss < n)
	{
		t = (nss-now)*q;
		nss += t*(q-1)/q;
		ti++;
	}
	cout<<ti<<endl;
	return 0;
}
