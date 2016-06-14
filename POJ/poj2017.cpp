#include <iostream>
using namespace std;
int main()
{
	int n,speed[20],time[20];
	while (cin>>n&&n>=0)
	{
		for (int i=0;i<n;i++)
			cin>>speed[i]>>time[i];
		int distance=speed[0]*time[0];
		for (int i=1;i<n;i++)
			distance+=speed[i]*(time[i]-time[i-1]);
		cout<<distance<<" miles"<<endl;
	}
	return 0;
}
