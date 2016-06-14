#include <bits/stdc++.h>
using namespace std;
int a[100000+10];
int num[100000+10];
bool used[100000+10];
int main(){
    int n;
    scanf("%d",&n);
    memset(used,false,sizeof(used));
    memset(num,0,sizeof(num));
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if (used[a[i]-1]==false)
            num[a[i]]=1;
        else
            num[a[i]]=num[a[i]-1]+1;
        used[a[i]]=true;
    }
    int ans=0;
    for (int i=0;i<=n;i++){
        ans=max(ans,num[i]);
    }
    cout<<n-ans<<endl;
}