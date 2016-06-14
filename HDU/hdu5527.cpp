#include <bits/stdc++.h>
using namespace std;
int v[]={1,5,10,20,50,100,200,500,1000,2000};
int c[20];
int main(){
    int t,p;
    scanf("%d",&t);
    while (t--){
        scanf("%d",&p);
        for (int i=0;i<10;i++)
            scanf("%d",&c[i]);
        int left=p;
        int ans=0;
        int money=0;
        int i,j;
        for (i=0;i<10;i++){
            if (left>=v[i]*c[i]){
                left-=v[i]*c[i];
                ans+=c[i];
            }
            else{
                int temp=left/v[i];
                money=(temp+1)*v[i]-left;
                ans+=(temp+1);
                left=0;
                break;
            }
        }
        cout<<left<<" "<<money<<" "<<ans<<" "<<i<<endl;
        if (left){
            cout<<-1<<endl;
            continue;
        }
        while (money){
            if (i==0 || j==0)
                break;
            for (j=i-1;j>=0;j--){
                if (money>=v[j]*c[j]){
                    money-=v[j]*c[j];
                    ans-=c[j];
                }
                else{
                    int temp=money/v[j];
                    money-=temp*v[j];
                    ans-=temp;
                    i=j;
                    break;
                }
            }
            //cout<<i<<" "<<j<<" "<<money<<" "<<ans<<endl;
        }
        if (money<=c[0]){
            ans-=money;
            money=0;
        }
        if (money){
            left=p;
            int answer=0;
            for (int i=9;i>=0;i--){
                if (left>v[i]){
                    int temp=left/v[i];
                    answer+=temp;
                    left-=v[i]*temp;
                }
            }
            cout<<-1<<endl;
        }
        else
            cout<<ans<<endl;
    }
    return 0;
}