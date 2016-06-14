#include <iostream>
using namespace std;
int main()
{
	//x-xxx-xxxxx-x
	//0123456789012
	char a[100];
	while (cin>>a)
	{
		int sum=0;
		sum+=(a[0]-'0')*1+(a[2]-'0')*2+(a[3]-'0')*3+(a[4]-'0')*4;
		for (int i=6;i<11;i++)
			sum+=(a[i]-'0')*(i-1);
		sum%=11;
		if ((sum==a[12]-'0')||(sum==10&&a[12]=='X'))
			cout<<"Right"<<endl;
		else
		{
			if (sum==10)
				a[12]='X';
			else
				a[12]=sum+'0';
			cout<<a<<endl;
		}
	}
	return 0;
}
