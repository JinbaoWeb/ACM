#include <iostream>
#include <stdio.h>
using namespace std;
#define M 100
int main(){
    long long n;
    short a[M];
    long long k=1;
    for (int i=1;i<M;i++){
        k=(k*k*i)%(1000000007);
        a[i]=k;
    }
    while (cin>>n){
        cout<<((a[n]+1000000007)%1000000007)<<endl;
    }
    return 0;
}