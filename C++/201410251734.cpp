#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 2005
int main(){
	int n;
	int a[MAX];
	while (cin>>n){
		for (int i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n);
		int count=1;
		int sum=0;
		for (int i=0;i<n;i++){
			sum+=a[i];
			if (sum<=a[n-1])
				count++;
			else
				break;
		}
		cout<<count<<endl;
	}
	return 0;
} 
