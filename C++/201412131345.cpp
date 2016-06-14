#include <iostream>
#include <stdio.h>
using namespace std;
int t,n,a[100002];
int main(){
    scanf("%d",&t);
    //cin>>t;
    while (t--){
        scanf("%d",&n);
        //cin>>n;
        for (int i=0;i<n;i++){
            scanf("%d",&a[i]);
            //cin>>a[i];
        }
        int max=0;
        for (int i=0;i<n;i++){
            if (a[i]>max)
                max=a[i];
            int ans=a[i];
            for (int j=i+1;j<n;j++){
                ans = ans ^ a[j];
                if (ans>max)
                    max=ans;
            }
        }
        printf("%d\n",max);
    }
    return 0;
}