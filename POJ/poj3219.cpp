#include <iostream>
using namespace std;
int main()
{
	int n,k;
	while (cin>>n>>k)
		cout<<(((n-k)&k)>0?0:1)<<endl;
	return 0;
}
