#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int a[10000+10];
int main(){
	int n,x;
	while (cin>>n){
		memset(a,0,sizeof(a));
		for (int i=0;i<n;i++){
			cin>>x;
			a[x]++;
		}
		int Max=0;
		int ans=-1;
		int num=0;
		for (int i=0;i<10000+10;i++){
			if (a[i]>=Max){
				Max=a[i];
				ans=i;
				num++;
			}
		}
		//cout<<num<<endl;
		if (num==n+1||Max*2<=n)
			cout<<-1<<endl;
		else
			cout<<ans<<endl;
	}

	return 0;
}