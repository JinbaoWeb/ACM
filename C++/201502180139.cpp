#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
bool cmp(int a,int b){
	if (a>b)
		return true;
	return false;
}
int main(){
	int n,a[10000];
	char str;
	while (cin>>n){
		int k=0;
		while (n--){
			cin>>str;
			if (str=='2')	
				a[k++]=2;
			if (str=='3')	
				a[k++]=3;
			if (str=='4'){
				a[k++]=3;a[k++]=2;a[k++]=2;
			}
			if (str=='5')	
				a[k++]=5;
			if (str=='6'){
				a[k++]=5;a[k++]=3;
			}
			if (str=='7')	
				a[k++]=7;
			if (str=='8'){
				a[k++]=7;a[k++]=2;a[k++]=2;a[k++]=2;
			}
			if (str=='9'){
				a[k++]=7;a[k++]=3;a[k++]=3;a[k++]=3;
			}
		}
		sort(a,a+k,cmp);
		for (int i=0;i<k;i++)
			cout<<a[i];
		cout<<endl;
	}
	return 0;
}