#include <iostream>
using namespace std;
int main()
{
	int x,y,t;
	cin>>t;
	while (cin>>x>>y)
	{
		if (x>=y&&(x+y)%2==0&&(x-y)%2==0)
			cout<<(x+y)/2<<" "<<(x-y)/2<<endl;
		else
			cout<<"impossible"<<endl;
	}
	return 0;
}
