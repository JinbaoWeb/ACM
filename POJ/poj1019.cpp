#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
int main()
{
	long long a[32001],b[32001];	//用a记录第i个串中数字的个数，用b记录前i个串中数字的个数
	a[0]=0,b[0]=0;
	for (int i=1;i<32001;i++) 
	{
		a[i]=a[i-1]+(int)log10((double)i)+1;
		b[i]=a[i]+b[i-1];
	}
	int t;
	long long i;
	while (cin>>t)
	{
		for (int c=1;c<=t;c++)
		{
			cin>>i;
			int k;
			for (k=0;k<32001;k++)
				if (i>b[k]&&i<=b[k+1])
					break;
			i-=b[k];
			int s;
			for (s=0;s<32001;s++)
				if (i>a[s]&&i<=a[s+1])
					break;
			i-=a[s];
			s++;
			/*char string[13];
			itoa(s,string,10);
			cout<<string[i-1]<<endl;*/
			int count[11];
			memset(count,0,sizeof(count));
			if (s<10)
				count[0]=s;
			else
			{
				if (s<100)
				{
					count[0]=s/10;
					s=s-s/10*10;
					count[1]=s;
				}
				else
				{
					if (s<1000)
					{
						count[0]=s/100;
						s=s-s/100*100;
						count[1]=s/10;
						s=s-s/10*10;
						count[2]=s;
					}
					else
					{
						if (s<10000)
						{
							count[0]=s/1000;
							s=s-s/1000*1000;
							count[1]=s/100;
							s=s-s/100*100;
							count[2]=s/10;
							s=s-s/10*10;
							count[3]=s;
						}
						else
						{
							if (s<100000)
							{
								count[0]=s/10000;
								s=s-s/10000*10000;
								count[1]=s/1000;
								s=s-s/1000*1000;
								count[2]=s/100;
								s=s-s/100*100;
								count[3]=s/10;
								s=s-s/10*s*10;
								count[4]=s;
							}
						}
					}
				}
			}
			cout<<count[i-1]<<endl;
		}
	}
	return 0;
} 
