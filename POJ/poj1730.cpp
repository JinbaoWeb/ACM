#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int p,n,i,t;
    while(cin>>n && n){
    	int flag=1;
    	if (n<0){
    		flag=2;
    		n=-n;
    	}
        for(i=31;i>=1;i=i-flag){
            t=(int)(pow(1.0*n,1.0/i)+0.1);
            p=(int)(pow(1.0*t,1.0*i)+0.1);
            if(n==p){
            	cout<<i<<endl;
                break;
            } 
        }
    }
    return 0;
}
