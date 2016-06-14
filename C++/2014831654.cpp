#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char r[9];
	int s[33];
	int x,y;
	while (cin>>r>>x>>y)
	{
		reverse(r);
		cout<<r<<endl;
	}
	return 0;
}
