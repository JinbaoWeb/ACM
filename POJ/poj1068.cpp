#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int t,n,a[22],b[44],result[22];
	bool used[44];
	cin>>t;
	for (int c=1;c<=t;c++)
	{
		memset(used,false,sizeof(used));
		cin>>n;
		for (int i=0;i<n;i++)
			cin>>a[i];
		int j;
		for (j=0;j<a[0];j++)
			b[j]=0;
		b[j++]=1;
		for (int i=0;i<n-1;i++)
		{
			for (int k=0;k<a[i+1]-a[i];k++)
				b[j++]=0;
			b[j++]=1;
		}
		int count=0;
		for (int p=0;p<j;p++)
		{
			if (b[p]==1)
			{
				int num=0;
				for (int q=p-1;q>=0;q--)
				{
					if (b[q]==0&&used[q]==false)
					{
						num++;
						result[count++]=num;
						used[q]=true;
						break;
					}
					else
					{
						if (b[q]==0&&used[q]==true)
							num++;
					}
				}
			}
		}
		for (int s=0;s<count;s++)
		{
			cout<<result[s];
			if (s!=count-1)
				cout<<" ";
		}	
		cout<<endl;
	}
	return 0;
}
