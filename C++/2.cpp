#include <iostream>
#include <string.h>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int maxn=70;
int n,sum,aim,num,a[maxn];
bool used[maxn];
int cmp(int x,int y)
{
	if (x<y)
		return 1;
	return 0;
}
bool dfs(int stick,int len,int pos)
{
	int i;
	bool sign=(len==0?true:false);
	if (stick==num)
		return true;
	for (i=pos+1;i<n;i++)
	{
		if (used[i])
			continue;
		if (len+a[i]==aim)
		{
			used[i]=true;
			if (dfs(stick+1,0,-1))
				return true;
			used[i]=false;
			return false;
			
		}
		else
			if (len+a[i]<aim)
			{
				used[i]=true;
				if (dfs(stick,len+a[i],i))
					return true;
				used[i]=false;
				if (sign)
					return false;
				while (a[i]==a[i+1])
					i++;
			}
	}
	return false;
}
int main()
{
	while (cin>>n&&n)
	{
		sum=0;
		for (int i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}
		sort(a,a+n,cmp);
		for (aim=a[0];aim<=sum;aim++)
		{
			if (sum%aim==0)
			{
				num=sum/aim;
				memset(used,false,sizeof(used));
				if (dfs(1,0,-1))
				{
					cout<<aim<<endl;
					break; 
				}
			}
		}
	}
	return 0;	
}

