#include <iostream>
using namespace std;
#define M 100002
int main()
{
	int n,a[M],b[M];
	while (cin>>n)
	{
		for (int i=0;i<n;i++)
			cin>>a[i]>>b[i];
		int maxa=a[0],maxb=b[0];
		int index_a=0,index_b=0;
		for (int i=1;i<n;i++)
		{
			if (a[i]>maxa)
			{
				maxa=a[i];
				index_a=i;
			}
			if (b[i]>maxb)
			{
				maxb=b[i];
				index_b=i;
			}
		}
		if (index_a!=index_b)
			cout<<"Happy Alex"<<endl;
		else
			cout<<"Poor Alex"<<endl;
	}
	return 0;
}
