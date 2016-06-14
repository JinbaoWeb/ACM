#include <iostream>
#include <string.h> 
using namespace std;
int main()
{
	int n,w,s;
	char people[70][20],doc;
	bool used[70];
	while (cin>>n)
	{
		for (int i=0;i<n;i++)
			cin>>people[i];
		cin>>w>>doc>>s;
		memset(used,false,sizeof(used));
		int pos=w-2;	//记录位置 
		int num=0;	//记录人数 
		while (num<n)
		{
			for (int step=0;step<s;step++)
			{
				pos++;
				if (pos>=n)
					pos%=n;
				if (used[pos]==true)
					step--;
			}
			cout<<people[pos]<<endl;
			used[pos]=true;
			num++;
		}
		
	}
	return 0;
}
