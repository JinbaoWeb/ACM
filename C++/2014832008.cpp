#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int n,m,a[40002];
	while (cin>>n>>m)
	{
		int index;
		for (int i=0;i<n;i++)
		{
			cin>>a[i];
			if (a[i]==m)
				index=i;
		}	
		int count=0;
		/*int  left[40002],right[40002];
		memset(left,0,sizeof (left));
		memset(right,0,sizeof(right));
		for (int i=index-1;i>=0;i--)
		{
			if (a[i]>m)
				left[index-i]=left[index-i-1]+1;
			else
				left[index-i]=left[index-i-1]-1; 
		}	
		for (int i=index+1;i<n;i++)
		{
			if (a[i]>m)
				right[i-index]=right[index-i-1]+1;
			else
				right[i-index-i]=right[index-i-1]-1; 
		}
		for (int k=0;k<=index;k++)
		{
			for (int s=0;s<=n-1-index;s++)
			{
				if (left[k]+right[s]==0)
					count++;
			}
		}*/
		int leftcount=0,rightcount=0;
		for (int k=0;k+index<n;k++)	//¿ØÖÆÓÒ±ß 
		{
			if (a[k+index]>m)
				rightcount++;
			if (a[k+index]<m)
				leftcount++;
			int left=leftcount,right=rightcount;
			for (int s=0;index-s>=0;s++)	//¿ØÖÆ×ó±ß 
			{
				if (a[index-s]>m)
					rightcount++;
				if (a[index-s]<m)
					leftcount++;
				if (rightcount==leftcount)
					count++;
			}
			leftcount=left;
			rightcount=right;
		}
		cout<<count<<endl;
	}
	return 0;
}
