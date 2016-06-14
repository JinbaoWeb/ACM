#include <iostream>
#include <string.h>
using namespace std;
#define M 10005
int main()
{
	int n,a,num[M];
	while (cin>>n)
	{
		memset(num,0,sizeof(num));
		for (int i=0;i<n;i++)
		{
			cin>>a;
			num[a]++;
		}
		int max=0,index=0;
		for (int i=0;i<10005;i++)
			if (num[i]>max)
			{
				max=num[i];
				index=i;
			}	
		cout<<index<<endl;
	}
	return 0;
} 
