#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char a[100],b[100];
	while (cin>>a>>b)
		cout<<strcmp(a,b)<<endl;
	return 0;
}
