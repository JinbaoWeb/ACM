#include <iostream>
#include <string.h>
using namespace std;
int main(){
	char s1[20],s2[20];
	while (cin>>s1>>s2){
		int a=((s1[0]-'0')*10+(s1[1]-'0'))*3600+((s1[3]-'0')*10+(s1[4]-'0'))*60+((s1[6]-'0')*10+(s1[7]-'0'));
		int b=((s2[0]-'0')*10+(s2[1]-'0'))*3600+((s2[3]-'0')*10+(s2[4]-'0'))*60+((s2[6]-'0')*10+(s2[7]-'0'));
		cout<<b-a<<endl;
	}
	return 0;
}
