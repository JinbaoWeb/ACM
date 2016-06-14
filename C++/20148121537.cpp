#include <iostream>
using namespace std;
int main()
{
	int T;
	long long n, x, y, z, t;
	cin>>T;
	for (int c=1;c<=T;c++)
	{
		cin>>n>>x>>y>>z>>t;
		long long max=0,damage=0;
		for (int i=0;i<=n;i++)	//blue
		{
			for (int j=0;j<=n;j++)	//green
			{
				int k=n-i-j;		//red
				damage=k*(t+i*z)*x;
				damage+=y*((j-1)*j/2+j*k)*(t+i*z);
				if (max<damage)
					max=damage;
			}
		}
		cout<<"Case #"<<c<<": "<<max<<endl;
	}
	return 0;
}
