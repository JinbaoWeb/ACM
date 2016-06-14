#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int n;
	char a[1000],b[25],c[1000];
	while (cin>>n)
	{
		if (n==0)
			break;	
		cin>>a;
		int len=strlen(a),num=0,k=0,s=0;
		memset(b,'0',sizeof(b));
		for (int i=0;i<len;i++)
		{
			if (k==0)
				b[k++]=a[i];
			else
			{
				int flag=0;
				for (int j=0;j<k;j++)
				{
					if (b[j]==a[i])
					{
						b[j]='0';
						k--;
						flag=1;
						break;
					}
				}
				if (flag==0)
				{
					if (k>n-1)
						c[s++]=a[i];
					else
						b[k++]=a[i];
				}	
			}
		}
		if (s>0)
		{
			bool ss[26];
			int count=0;
			memset(ss,false,sizeof(ss));
			for (int i=0;i<s;i++)
				ss[c[i]-'A']=true;
			for (int i=0;i<26;i++)
				if (ss[i]==true)
					count++;
			cout<<count<<" customer(s) walked away."<<endl;
		}
		else
		{
			cout<<"All customers tanned successfully."<<endl;
		}
	}
	return 0;
}
