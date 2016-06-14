#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream in("000.txt");
	ofstream out("00000.txt");
	int n;
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
