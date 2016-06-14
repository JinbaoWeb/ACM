#include <iostream>
#include <string.h>
#include <algorithm>
#define M 100005 
using namespace std;
int main()
{
	long long n,k;
	char card[M];
	long long num[26];
	while (cin>>n>>k)
	{
		memset(num,0,sizeof(num));	
		for (int i=0;i<n;i++)
		{
			cin>>card[i];
			num[card[i]-'A']++;
		}	
		sort(num,num+26);
		long long sum=0;
		for (int i=25;i>=0;i--)
		{
			if (k>=num[i])
			{
				sum+=num[i]*num[i];
				k-=num[i];
			}
			else
			{
				sum+=k*k;
				break;
			}	
		}
		cout<<sum<<endl;
	}
	return 0;
}
