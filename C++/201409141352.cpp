#include <iostream>
using namespace std;
const int M = 1e9+7;
using namespace std;
int k[12][12]={1, 0, 0,  0,  0,  0,  0,  0, 0, 0,0,
			   1, 1, 0,  0,  0,  0,  0,  0, 0, 0,0,
			   1, 2, 1,  0,  0,  0,  0,  0, 0, 0,0,
			   1, 3, 3,  1,  0,  0,  0,  0, 0, 0,0,
			   1, 4, 6,  4,  1,  0,  0,  0, 0, 0,0,
			   1, 5,10, 10,  5,  1,  0,  0, 0, 0,0,
			   1, 6,15, 20, 15,  6,  1,  0, 0, 0,0,
			   1, 7,21, 35, 35, 21,  7,  1, 0, 0,0,
			   1, 8,28, 56, 70, 56, 28,  8, 1, 0,0,
			   1, 9,36, 84,126,126, 84, 36, 9, 1,0,
			   1,10,45,120,210,252,210,120,45,10,1};
int f(int n,int m,int *a)
{
	if (m==0)
		return a[n];
	if (n==0)
	{
		int s=23;
		for (int i=0;i<m;i++)
		{
			s=s*10+3;
			s=s%M;
		}
		return s;
	}
	int s=0;
	for (int i=0;i<n&&m-n>=0;i++)
		s=(s+k[n-1][i]*f(i,m-i,a))%M;
	return s;
}
int main()
{
	int n,m,a[15];
	int k[12][12]={1, 0, 0,  0,  0,  0,  0,  0, 0, 0,0,
				   1, 1, 0,  0,  0,  0,  0,  0, 0, 0,0,
				   1, 2, 1,  0,  0,  0,  0,  0, 0, 0,0,
				   1, 3, 3,  1,  0,  0,  0,  0, 0, 0,0,
				   1, 4, 6,  4,  1,  0,  0,  0, 0, 0,0,
				   1, 5,10, 10,  5,  1,  0,  0, 0, 0,0,
				   1, 6,15, 20, 15,  6,  1,  0, 0, 0,0,
				   1, 7,21, 35, 35, 21,  7,  1, 0, 0,0,
				   1, 8,28, 56, 70, 56, 28,  8, 1, 0,0,
				   1, 9,36, 84,126,126, 84, 36, 9, 1,0,
				   1,10,45,120,210,252,210,120,45,10,1};
	while (cin>>n>>m)
	{
		for (int i=0;i<n;i++)
			cin>>a[i];
		cout<<f(n,m,a)<<endl;
	}
	return 0;
} 
