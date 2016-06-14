#include <iostream>
using namespace std;
int main(){
    int t,cas,n,x;
    int a[10000];
    cin>>t;
    while (t--){
        cin>>cas>>n;
        int sum=0;  //记录总和
        int k=0;    //记录个数
        for (int i=1;i<=n;i++){
            cin>>x;
            sum+=x;
            if (i%2==1)
              a[k++]=sum/i;
        }
        cout<<"--------"<<endl;
        cout<<cas<<" "<<k<<endl;
        for (int i=0;i<k;i++){
            if (i%10==0&&i!=0)
              cout<<endl;
            if (i==0)
              cout<<a[i];
            else
              cout<<" "<<a[i];
        }
        if (k%10)
          cout<<endl;
    }
    return 0;
}
