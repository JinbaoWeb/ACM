#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char a[20];
	int flag,c=1;
	while (cin>>a)
	{
		if (strcmp(a,"0")==0)
			break;
		flag=0;
		int n=strlen(a);
		int count1=0;
		for (int i=0;i<n;i++)
			if (a[i]=='1')
				count1++;
		if (count1==n)
			flag=1;
			////
		int count2=0;
		for (int i=0;i<n;i++)
			if (a[i]=='2')
				count2++;
		if (count2==n)
			flag=1;
			////
		int count4=0;
		for (int i=0;i<n;i++)
			if (a[i]=='4')
				count4++;
		if (count4==n)
			flag=1;
		int count8=0;
		//////
		for (int i=0;i<n;i++)
			if (a[i]=='8')
				count8++;
		if (count8==n)
			flag=1;
		if (flag==0)
			cout<<"Case "<<c<<": "<<0<<endl;
		else
			cout<<"Case "<<c<<": "<<n<<endl;
		c++;
	}
	return 0;
}
