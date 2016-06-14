#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <queue>
#include <stack>
using namespace std;
void f1(int n){
	/***************/
	for (int i=0;i<n;i++)
		cout<<"*";
	/***************/
}
void f2(int n){
	/***************/
	int k=n/8-1;
	for (int i=0;i<k;i++){
		cout<<"*";
		for (int j=1;j<n-1;j++)
			cout<<" ";
		cout<<"*";
	}
	/***************/
}
void f3(int n){
	/***************/
	int k=n/8-1;
	cout<<"*";
	for (int i=0;i<k;i++)
		cout<<" ";
	for (int i=0;i<n/2;i++)
		cout<<"*";
	for (int i=0;i<n/2;i++)
		cout<<" ";
	for (int i=0;i<n/2;i++)
		cout<<"*";
	for (int i=0;i<k;i++)
		cout<<" ";
	cout<<"*";
	/***************/
}
void f4(int n){
	/***************/
	int k=n/8-1;
	int p=n/4-1;
	for (int i=0;i<p;i++){
		cout<<"*";
		for (int i=0;i<k;i++)
			cout<<" ";
		cout<<"*";
		for (int i=0;i<p-1;i++)
			cout<<" ";
		cout<<"*";
		for (int i=0;i<n/2;i++)
			cout<<" ";
		cout<<"*";
		for (int i=0;i<p-1;i++)
			cout<<" ";
		cout<<"*";
		for (int i=0;i<k;i++)
			cout<<" ";
		cout<<"*";
	}
	/***************/
}
void show(int n,int flag){
	if (n==0)
		return;
	if (flag==1){
		for (int i=0;i<n/2;i++){
			cout<<"*";
			for (int i=0;i<n/4-1;i++)
				cout<<" ";
			show(n/2,1-flag);
			for (int i=0;i<n/4-1;i++)
				cout<<" ";
			cout<<"*"<<endl;
		}
		/*******************/
		
	}
	

	if (flag==0){
		f1(n);cout<<endl;
		f2(n);cout<<enld;
		f3(n);cout<<endl;
		f4(n);cout<<endl;
		f3(n);cout<<endl;
		f2(n);cout<<endl;
	}
	else{
		f2(n);cout<<endl;
		f3(n);cout<<endl;
		f4(n);cout<<endl;
		f3(n);cout<<endl;
		f2(n);cout<<endl;
		f1(n);cout<<endl;
	}
	flag=1-flag;
	for (int i=0;i<n/2;i++){
		cout<<"*";
		for (int j=0;j<n/4-1;j++)
			cout<<" ";
		if (flag==0)
			f1(n/2);
		else
			f2(n/2);
		for (int j=0;j<n/4-1;j++)
			cout<<" ";
		cout<<"*"<<endl;
	}



	for (int i=1;i<7;i++){
		switch (i){
			case 1:{
				if (flag==0)
					f1(n);
				else
					f2(n);
				//show(n/2,1-flag);
				cout<<endl;
				break;
			}
			case 2:{
				if (flag==0)
					f2(n);
				else
					f3(n);
				//show(n/2,1-flag);
				cout<<endl;
				break;
			}
			case 3:{
				if (flag==0)
					f3(n);
				else
					f4(n);
				//show(n/2,1-flag);
				cout<<endl;
				break;
			}
			case 4:{
				if (flag==0)
					f4(n);
				else
					f3(n);
				//show(n/2,1-flag);
				cout<<endl;
				break;
			}
			case 5:{
				if (flag==0)
					f3(n);
				else
					f2(n);
				//show(n/2,1-flag);
				cout<<endl;
				break;
			}
			case 6:{
				if (flag==0)
					f2(n);
				else
					f1(n);
				//show(n/2,1-flag);
				cout<<endl;
				break;
			}

		}
	}
	show(n/2,1-flag);
}
int main(){
	int n;
	while (cin>>n&&n){
		show(n,0);
	}
	return 0;
}