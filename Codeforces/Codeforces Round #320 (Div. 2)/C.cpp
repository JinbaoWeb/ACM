#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
int main(){
	int a,b;
	while (cin>>a>>b){
		if (a<b){
			cout<<-1<<endl;
			continue;
		}
		int t=a/b+1;
		if (t%2==1)
			t--;
		double ans=(a+b)*1.0/t;
		printf("%.10f\n",ans);
	}
	return 0;
}