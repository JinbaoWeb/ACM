#include <iostream>
#include <string.h>
using namespace std;
int a[100000+5];
int m[100000+5];
int main(){
	int n,k,mm;
	while (cin>>n>>k){
		memset(a,0,sizeof(a));
		while (k--){
			cin>>mm;
			for (int i=0;i<mm;i++)
				cin>>m[i];
			if (mm==1)
				continue;
			for (int i=0;i<mm-1;i++){
				a[m[i]]=m[i+1];
				
			}
		}
		int ans=0;
		for (int i=1;i<n;i++){
			int k=-1;
			if (a[i]==i+1)
				k=0;
			if (a[i]==0)
				k=1;
			if (k==-1)
				k=2;
			//cout<<"a[i]="<<a[i]<<" "<<k<<endl;
			ans+=k;
		}
		cout<<ans<<endl;
	}
	return 0;
}