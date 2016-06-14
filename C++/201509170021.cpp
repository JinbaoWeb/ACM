#include <bits/stdc++.h>
using namespace std;
int n,t[500]={-1};
int a[500][500]={-1};
bool check(){
    for(int i=0;i<2*n;i++) if(t[i]<0) return true;
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=2;i<=2*n;i++)
        for(int j=1;j<=i-1;j++){
            cin>>a[i][j];
            a[j][i]=a[i][j];
        }
    //cout<<"--------"<<endl;
    while(check())
        for(int i=1;i<=2*n;i++)
            if(t[i]==-1){
            int ma=*max_element(a[i]+1,a[i]+2*n+1);
            for(int j=1;j<=2*n;j++)
                if(a[i][j]==ma&&a[i][j]==*max_element(a[j]+1,a[j]+2*n+1)&&t[j]==-1){
                    for(int k=1;k<=2*n;k++){ a[i][k]=-1; a[k][i]=-1; a[j][k]=-1; a[k][j]=-1;}
                    t[i]=j;
                    t[j]=i;
                }
            }
    for(int i=1;i<=2*n;i++) cout<<t[i];
    return 0;
}