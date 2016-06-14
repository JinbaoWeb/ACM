#include <bits/stdc++.h>
using namespace std;
int a[100000+10];
int b[100000+10];
int main(){
    int n;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    cin>>n;
    int ans=0;
    b[0]=1;
    for (int i=0;i<n;i++){
        cin>>a[i];
        if (i){
            if (a[i]>=a[i-1]){
                b[i]=b[i-1]+1;
            }
            else
                b[i]=1;
        }
    }
    int ns=0;
    for (int i=0;i<n;i++){
        if (b[i]>ns)
            ns=b[i];
    }
    cout<<ns<<endl;
    return 0;
}