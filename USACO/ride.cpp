/*
ID: dongjin3
PROG: ride
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    char a[10],b[10];
    while (fin >> a >> b){
    	long long x=1,y=1;
    	int len_a=strlen(a);
    	for (int i=0;i<len_a;i++){
    		x=x*(a[i]-'A'+1);
    	}
    	int len_b=strlen(b);
    	for (int i=0;i<len_b;i++){
    		y=y*(b[i]-'A'+1);
    	}
    	if (x%47 == y%47){
    		fout<<"GO\n";
    	}
    	else
    		fout<<"STAY\n";
    }
    
    return 0;
}