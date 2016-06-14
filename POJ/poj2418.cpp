#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string>
#include <string.h>
#include <map>
using namespace std;
int main(){
	char str[50];
	int count=0;
	map<string,int> counter;
	map<string,int> ::iterator it;
	while (gets(str)!=NULL){
		counter[str]++;
		count++;
	}
	for (it=counter.begin();it!=counter.end();it++){
		cout<<(it->first)<<" "<<fixed<<setprecision(4)<<(it->second)*1.0/count*100<<endl;
	}
	return 0;
}