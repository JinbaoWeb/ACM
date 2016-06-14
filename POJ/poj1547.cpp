#include <iostream>
using namespace std;
int main()
{
	int n,a,b,c,cube[12];
	char name[12][12];
	while (cin>>n&&n>=0)
	{
		for (int i=0;i<n;i++)
		{
			cin>>a>>b>>c;
			cube[i]=a*b*c;
			cin>>name[i];
		}
		int max=cube[0],min=cube[0],index_max=0,index_min=0;
		for (int i=1;i<n;i++)
		{
			if (max<cube[i])
			{
				max=cube[i];
				index_max=i;
			}	
			if (min>cube[i])
			{
				min=cube[i];
				index_min=i;
			}	
		}
		cout<<name[index_max]<<" took clay from "<<name[index_min]<<"."<<endl;
	}
	return 0;
}
