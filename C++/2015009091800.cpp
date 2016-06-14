#include <iostream>
#include <string.h>
using namespace std;
int a[10000+10];
int main(){
	int n,x;
	while (cin>>n){
		memset(a,0,sizeof(a));	//初始化为0
		for (int i=0;i<n;i++){	//数据的输入
			cin>>x;
			a[x]++;
		}
		int Max=a[0];
		int ans=0;
		for (int i=0;i<10000+10;i++){	//循环判断
			if (a[i]>Max){
				Max=a[i];
				ans=i;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}