#include <iostream>
#include <fstream> 
using namespace std;
int main()
{
	int n;
	ifstream cin("1.txt");
	ofstream cout("00000.txt");
	while (cin>>n)
	{
		int begin=2*n*(n+1)-n;
		int end=2*n*(n+1)+n;
		for (int i=begin;i<end;i++)
			cout<<i<<" ";
		cout<<end<<endl;
	}
	return 0;
}

