#include <iostream>
using namespace std;
int a[100+10];
int b[100+10];
int c[100+10];
int f(int x){
	int sum=0;
	for (int i=1;i*2<=x;i++){
		if (x%i==0)
			sum+=i;
	}
	if (sum==x)
		return 0;	//perfect
	if (sum<x)
		return -1;	//deficient
	if (sum>x)
		return 1;	//abundant
}
int main(){
	int k=0,x;
	int MaxNum=0;
	while (1){
		cin>>x;
		if (x==0)
			break;
		a[k]=x;
		c[k]=f(x);
		int num=0;
		while (x){
			x/=10;
			num++;
		}
		b[k++]=num;
		if (num>MaxNum)
			MaxNum=num;
	}
	cout<<"PERFECTION OUTPUT"<<endl;
	for (int i=0;i<k;i++){
		for (int j=0;j<MaxNum-b[i];j++)
			cout<<" ";
		cout<<a[i]<<"  ";
		if (c[i]==0)
			cout<<"PERFECT"<<endl;
		if (c[i]==1)
			cout<<"ABUNDANT"<<endl;
		if (c[i]==-1)
			cout<<"DEFICIENT"<<endl;
	}
	cout<<"END OF OUTPUT"<<endl;
	return 0;
}