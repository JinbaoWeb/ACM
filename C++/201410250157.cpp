#include <iostream>
#include <string.h>
using namespace std;
#define MAX 100005
int main(){
	int s,n,a[MAX];
	while (cin>>n>>s){
		
		for (int i=0;i<n-1;i++)
			cout<<a[i]<<" ";
		cout<<a[n-1]<<endl;
	}
	return 0;
}
