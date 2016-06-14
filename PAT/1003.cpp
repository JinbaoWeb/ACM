#include <iostream>
#include <stdio.h>
using namespace std;
int a,b;
int ans[10000];
bool isprime(int x){
    if (x==2 || x==3 || x==5 || x==7) return true;
    for (int i=2;i*i<=x;i++){
        if (x%i==0) return false;
    }
    return true;
}
int main()
{
    int k=0;
    for (int i=2;;i++){
        if (k>10000) break;
        if (isprime(i)==true){
            ans[k++]=i;
        }
    }
    while (~scanf("%d%d",&a,&b)){
        for (int i=a;i<b;i++){
            if ((i-a)%10==9) cout<<ans[i-1]<<endl;
            else cout<<ans[i-1]<<" ";
        }
        cout<<ans[b-1]<<endl;
        
    }
    return 0;
}