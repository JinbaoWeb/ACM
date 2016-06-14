#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
int a[1005];
int main(){
	int t,n,x;
	cin>>t;
	while (t--){
		cin>>n;
		int count=0;
		while (n--){
			cin>>x;
			if (x>6000)
				count++;
		}
		cout<<count<<endl;
	}

	return 0;
}
