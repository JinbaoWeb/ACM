#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream cin("Feach.in");
	ofstream cout("Feach.out");
	int n;
	while (cin>>n){
		int half=1;
		for (int i=0;i<n-1;i++)
			half=(half+1)*2;
		cout<<half<<endl;
	}
	return 0;
}