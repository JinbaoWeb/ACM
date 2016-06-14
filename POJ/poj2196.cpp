#include <iostream>
using namespace std;
int sum(int n,int d)
{
	if(n/d)
		return n%d+sum(n/d,d);
	else
		return n;
}
int main()
{
	for (int i=2992;i<9999;i++)
		if (sum(i,10)==sum(i,12)&&sum(i,12)==sum(i,16))
			cout<<i<<endl;
	return 0;
}
