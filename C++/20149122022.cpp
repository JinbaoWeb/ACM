#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	long long t,n,m,k,a[100005];
	cin>>t;
	while (cin>>n>>m>>k)
	{
		long long s,ss,value=0;
		memset(a,0,sizeof(a));
		for (int i=0;i<n;i++)
		{
			cin>>s>>ss;
			a[s]=ss;
		}
		for (int i=0;i<m;i++)
		{
			
	 		cin>>s;
	 		long long v=0;
	 		long long ii=s,jj=s;
	 		int cou1=0,cou2=0;
	 		while (ii--&&cou1<=k/2)
	 		{
	 			if (a[ii]==0)
	 				continue;
	 			v+=a[ii];
	 			cou1++;
	 		}
	 		cou2=k-cou1;
	 		while (jj++<100005&&cou2)
	 		{
	 			if (a[jj]==0)
	 				continue;
	 			v+=a[jj];
	 			cou2--;
	 		}
	 		a[s]=v/k;
	 		cout<<a[s]<<endl;
	 		value+=a[s];
		}
		cout<<value<<endl;
	}
	return 0;
}
