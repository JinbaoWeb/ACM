#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;
typedef long long ll;
int n,k;
double len[10005];
int f(double a,int b){
	int aa=a*100;
	return aa/b;
}
int cal_num(int l){
	int num=0;
	for (int i=0;i<n;i++){
		num+=f(len[i],l);
	}
	return num;
}
int main(){
	while (cin>>n>>k){
		double sum=0,max=0;
		int left,right,mid;
		for (int i=0;i<n;i++){
			cin>>len[i];
			if (max<len[i])
				max=len[i];
			sum+=len[i];
		}
		if (sum*100<k){
			cout<<"0.00"<<endl;
			continue;
		}
		left=0;
		right=max*100;
		//right=sum*100/k;
		while (left<=right){
			mid=(left+right)/2;
			if (cal_num(mid)<k)
				right=mid-1;
			else
				left=mid+1;
			//cout<<fixed<<setprecision(2)<<left/100.00<<" "<<right/100.00<<" "<<mid/100.00<<endl;
		}
		cout<<fixed<<setprecision(2)<<right/100.00<<endl;
	}
	return 0;
}