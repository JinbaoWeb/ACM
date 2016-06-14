#include <iostream>
using namespace std;
int f(long long *a,int n,int i,int j)
{
	if (i==n-1)
		return j;
	if (a[i]!=1)
		return f(a,n,i+1,j);
	else
	{
		if (j==0)
			j=1;
		else
			j=0;
		return f(a,n,i+1,j);
	}	
}
int main()
{
	int t,n;
	long long a[1005];
	cin>>t;
	while (cin>>n)
	{
		for (int i=0;i<n;i++)
			cin>>a[i];
		if (f(a,n,0,0)==0)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
