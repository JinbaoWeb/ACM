#include <iostream>
using namespace std;
int main(){
	int t,n,a,max=0;
	cin>>t;
	for (int i=1;i<=t;i++){
		cin>>n;
		max=0;
		for (int j=0;j<n;j++)
		{
			cin>>a;
			if (a>max)
				max=a;
		}
		cout<<"Case #"<<i<<": "<<max<<endl;
	}
	return 0;
} 
