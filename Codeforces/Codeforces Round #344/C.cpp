#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node{
    ll t,r;
    bool used;
}OP[200020];
ll a[200020];
bool cmp1(int x,int y){
    return x<y;
}
bool cmp2(int x,int y){
    return x>y;
}

int main(){
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++)
        cin>>a[i];
    for (int i=0;i<m;i++){
        
        cin>>OP[i].t>>OP[i].r;

        OP[i].used=false;
    }
    int T=0,R=0;
    for (int i=m-1;i>=0;i--){
        if (OP[i].t==1){
            if (OP[i].r>T){
                T=OP[i].r;
            }
            else{
                OP[i].used=true;
            }
        }
        else{
            if (OP[i].r>R){
                R=OP[i].r;
            }
            else{
                OP[i].used=true;
            }
        }
    }
    int TT=0,RR=0;
    int cnt=0;
    for (int i=0;i<m;i++){
        if ()
        if (OP[i].used==false){
            if (OP[i].t==1){
                sort(a,a+OP[i].r,cmp1);
            }
            else
                sort(a,a+OP[i].r,cmp2);
        }
    }
    for (int i=0;i<n-1;i++)
        cout<<a[i]<<" ";
    cout<<a[n-1]<<endl;
    return 0;
}