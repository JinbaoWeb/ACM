#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
#define M 100005
int main()
{
	int n,a[M];
	bool used[M];	//��������Ƿ�ʹ�ù� 
	int num[M];		//��¼ÿ�����ֵĸ��� 
	while (cin>>n)
	{
		memset(used,false,sizeof(used));
		memset(num,0,sizeof(num));
		long long sum=0;
		for (int i=0;i<n;i++)
		{
			cin>>a[i];
			num[a[i]]++;
			sum+=a[i];
		}	
		long long max=0;
		//sort(a,a+n);
		long long sumsum;
		for (int i=0;i<n;i++)
		{
			sumsum=sum;
			if (used[a[i]]==true)
				continue;
			used[a[i]]=true;
			sumsum-=(a[i]-1)*num[a[i]-1];
			sumsum-=(a[i]+1)*num[a[i]+1];
			if (max<sumsum)
				max=sumsum;
		}
		cout<<max<<endl;
	}
	return 0;
}
