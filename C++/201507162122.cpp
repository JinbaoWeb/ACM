#include <iostream>
using namespace std;
long long f[1000000+5];
void init(){
        f[0]=7%3,f[1]=11%3;
        for (int i=2;i<=1000000;i++)
             f[i]=(f[i-1]+f[i-2])%3;
}
int main(){
     int n;
     init();
     while (cin>>n){
             if (f[n]%3==0)
                 cout<<"yes"<<endl;
             else
                cout<<"no"<<endl;
    }
     return 0;
}