#include <iostream>
#include <fstream>
using namespace std;
int main(){
	//ifstream cin("e.in");
	//ofstream cout("e.out");
	int a,b;
	int t;
	cin>>t;
	while (t--){
		cin>>a>>b;
		if (a>b)
			swap(a,b);
		int flag=0;
		for (int i=b-a;i<=a+b;i++){
			if (i==0)
				continue;
			if (a*a+i*i==b*b || a*a+b*b==i*i)
			{
				flag=1;
				cout<<i<<endl;
				break;
			}
		}
		if (flag==0)
			cout<<"NO"<<endl;
	}
	return 0;
}