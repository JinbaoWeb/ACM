#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 100005
int main(){
	int n,k,a[MAX];
	bool used[MAX];
	while (cin>>n>>k){
		for (int i=0;i<n;i++)
			a[i]=n-i;
		for (int i=0;i<n-1;i++)
			cout<<a[i]<<" ";
		cout<<a[n-1]<<endl;
		int flag=0;
		memset(used,false,sizeof(used));
		do{
			int count=0;
			for (int i=1;i<n;i++,i++){
				if (a[i]>a[i-1]){
					if (used[a[i]-a[i-1]]==false)
						count++;
					used[a[i]-a[i-1]]=true;
				}
				else{
					if (used[a[i-1]-a[i]]==false)
						count++;
					used[a[i-1]-a[i]]=true;
				}
			}
			if (n%2){
				if (used[a[n-1]]==false)
					count++;
				used[a[n-1]]=true;
			}
			if (count==k)
				break;
		}while(next_permutation(a,a+n));
		for (int i=0;i<n-1;i++)
			cout<<a[i]<<" ";
		cout<<a[n-1]<<endl;
	}
	return 0;
}
