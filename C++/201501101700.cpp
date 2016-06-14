#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <math.h>
typedef long long ll;
using namespace std;
int main(){
	int n,m;
	while (cin>>n>>m){
		if (m==1)
			cout<<0<<endl;
		else{
			
			cout<<(m-1)%n<<endl;
		}
	}
	return 0;
}