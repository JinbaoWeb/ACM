#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ifstream cin("Rectangle.in");
    ofstream cout("Rectangle.out");
    int n,m;
    while (cin>>n>>m){
        int ans=0;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                ans+=(n-i)*(m-j);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}