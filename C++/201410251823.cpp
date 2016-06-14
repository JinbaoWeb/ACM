#include <iostream>
using namespace std;
#include <algorithm>
#define MAX 2005
int main(){
	int n,a[MAX];
	while (cin>>n){
		for (int i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n);
		int max=0,i,j;
		for (i=0;i<n;i++){
			int sum=0;
			for (j=0;j<n;j++){
				sum+=a[j];
				if (sum>a[i])
					break;
			}
			if (max<j)
				max=j;
			//cout<<max<<endl;
		}
		cout<<max+1<<endl;
	}
	return 0;
}
