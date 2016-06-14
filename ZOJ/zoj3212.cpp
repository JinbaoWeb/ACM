#include <bits/stdc++.h>
using namespace std;
int a[20][20];
int main(){
    int t,n,m,k;
    cin>>t;
    while (t--){
        cin>>n>>m>>k;
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                a[i][j]=1;
        for (int i=1;i<n-1;i++){
            for (int j=1;j<m-1;j++){
                if (k){
                    a[i][j]=a[i-1][j]=a[i+1][j]=a[i][j-1]=a[i][j+1]=0;
                    k--;
                }
            }
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<m-1;j++)
                cout<<a[i][j]<<" ";
            cout<<a[i][m-1]<<endl;
        }
    }
    return 0;
}