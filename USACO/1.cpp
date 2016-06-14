/*
ID: dongjin3
PROG: 
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("test.out");
    ifstream fin ("test.in");
    char a[10],b[10];
    while (fin >> a >> b){
    	long long x=1,y=1;
    	int len_a=strlen(a);
    	for (int i=0;i<len_a;i++){
    		x=x*(a[i]-'A')%47;
    	}
    	int len_b=strlen(b);
    	for (int i=0;i<len_b;i++){
    		y=y*(a[i]-'A')%47;
    	}
    	if (x%47 == y%47){
    		fout<<"GO\n";
    	}
    	else
    		fout<<"STAY\n";
    }
    
    return 0;
}