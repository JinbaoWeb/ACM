#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
#define M 100
int n,stick[M],number=0,i;
bool used[M];
bool dfs(int left,int num,int l)
{
	if (l==i)
	{
		num++;
		l=0;
	}
	cout<<num<<"-"<<endl;
	if (num==number)
		return true;	
	for (int k=n-1;k>=0;k--)
	{
		if (used[k]==true)
			continue;
		if (l+stick[k]>i)
			continue;
		if (k!=n-1)
			if (stick[k]==stick[k+1]&&used[k+1]==false)
				continue;
		used[k]=true;
		if (dfs(left-stick[k],num,l+stick[k])==true)
			return true;
		used[k]=false;
	}
	return false;
}
int main()
{
	while (cin>>n)
	{
		if (n==0)
			break;
		memset(used,false,sizeof(used));
		int len=0;
		for (int j=0;j<n;j++)
		{
			cin>>stick[j];
			len+=stick[j];
		}	
		sort(stick,stick+n);
		for (i=stick[n-1];i<=len;i++)
		{
			if (len%i!=0)
				continue;
			number=len/i;
			used[n-1]=true;
			if (dfs(len-stick[n-1],0,stick[n-1])==true)
				break;
		}
		cout<<i<<endl;
	}
	return 0;
} 
