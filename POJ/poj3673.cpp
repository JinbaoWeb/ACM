#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char a[12],b[12];
	while (cin>>a>>b)
	{
		int mul=0;
		int len_a=strlen(a),len_b=strlen(b);
		for (int i=0;i<len_a;i++)
			for (int j=0;j<len_b;j++)
				mul+=(a[i]-'0')*(b[j]-'0');
		cout<<mul<<endl;
	}
	return 0;
}
