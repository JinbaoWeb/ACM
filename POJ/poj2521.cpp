#include <iostream>
using namespace std;
int main()
{
	int n,m,p,c;
	while (cin>>n>>m>>p>>c)
	{
		if (n==0&&m==0&&p==0&&c==0)
			break;
		cout<<n-m+p<<endl;
	}
	return 0;
}
