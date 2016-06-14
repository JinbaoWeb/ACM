#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int t,n,x,y,z,num[1005];
	while (cin>>t)
	{
		cin>>n;
		memset(num,1,sizeof(num));
		for (int i=0;i<t;i++)
		{
			cin>>x;
			if (x==1)
			{
				cin>>y>>z;
				num[y]=0;
				num[z]+=num[y];
			}
			else
			{
				cin>>y;
				cout<<num[y]-1<<endl;
			}
		}
	}
	return 0;
}
