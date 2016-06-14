#include <iostream>
#include <fstream>
using namespace std;
int main(){
	ofstream cout("D.txt");
	int n=200000,m=5000;
	cout<<n<<" "<<m<<endl;
	for (int i=0;i<m;i++){
		cout<<2<<" "<<1<<" "<<n<<endl;
	}
	cout<<3<<" "<<1<<" "<<n<<endl;
	return 0;
}