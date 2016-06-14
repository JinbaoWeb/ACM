#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int a[5];
	int b[5];
	int num[5]={500,1000,1500,2000,2500};
	int k[5]={150,300,450,600,750};
	int c[2];
	for (int i=0;i<5;i++)
		cin>>a[i];
	for (int i=0;i<5;i++)
		cin>>b[i];
	for (int i=0;i<2;i++)
		cin>>c[i];
	int sum=0;
	for (int i=0;i<5;i++){
		int temp=(250-a[i])*(num[i]/250)-50*b[i];
		sum+=max(k[i],temp);
	}
	sum+=(c[0]*100-c[1]*50);
	cout<<sum<<endl;
	return 0;
}