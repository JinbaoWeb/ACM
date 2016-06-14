#include <iostream>
using namespace std;
void select(int *s,int n)
{
	int temp;
	for (int i=0;i<n;i++)
		for (int j=0;j<n-1-i;j++)
			if (s[j]>s[j+1])
			{
				temp=s[j];
				s[j]=s[j+1];
				s[j+1]=temp;
			}
}
int main()
{
	int k,s[20],x[6];
	while (cin>>k&&(k!=0))
	{
		for (int i=0;i<k;i++)
			cin>>s[i];
		select(s,k);
		int a,b,c,d,e,f;
		for (a=0;a<k-5;++a)
		{
			x[0]=s[a];
			for (b=a+1;b<k-4;++b)
			{
				x[1]=s[b];
				for (c=b+1;c<k-3;++c)
				{
					x[2]=s[c];
					for (d=c+1;d<k-2;++d)
					{
						x[3]=s[d];
						for (e=d+1;e<k-1;++e)
						{
							x[4]=s[e];
							for (f=e+1;f<k;++f)
							{
								x[5]=s[f];
								/*for (int ii=0;ii<5;ii++)
								{
									cout<<x[ii]<<" ";
								}
								cout<<x[5]<<endl;*/
								cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<" "<<x[3]<<" "<<x[4]<<" "<<x[5]<<endl;
							}
						}
					}
				}
			}
		}
		cout<<endl;
	}
	cout<<'\b';
	return 0;
}
