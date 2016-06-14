#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
int main(){
	int n,x;
	while (cin>>n){
		int flag=0;
		for (int i=0;i<n;i++){
			cin>>x;
			if (x==1)
				flag=1;
		}
		if (flag==0)
			cout<<1<<endl;
		else
			cout<<-1<<endl;
	}

	return 0;
}