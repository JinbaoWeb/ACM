#include <bits/stdc++.h>
using namespace std;
struct Node{
    int h,k;
}P[100000+10];
int a[100000+10];
int ans[100000+10];
int lowbit(int x)
{
    return x & (-x);
}
void modify(int x,int add)//һά
{  
    while(x<=100000+10)  
    {      
        a[x]+=add;    
        x+=lowbit(x); 
    }
}
int get_sum(int x)
{  
    int ret=0; 
    while(x!=0)  
    {       
        ret+=a[x];   
        x-=lowbit(x);   
    }  
    return ret;
}
bool cmp(Node a,Node b){
    return a.h<=b.h;
}
int main(){
    int t,n;
    scanf("%d",&t);
    for (int cas=1;cas<=t;cas++){
    	memset(a,0,sizeof(a));
        scanf("%d",&n);
        for (int i=0;i<n;i++)
            scanf("%d%d",&P[i].h,&P[i].k);
        sort(P,P+n,cmp);
        for (int i=0;i<n;i++){
        	modify(i+1,1);
        }
        int flag=1;
        for (int i=0;i<n;i++){
            int k=min(P[i].k+1,n-i-P[i].k);
            if (k<=0) 
            {
                flag=0;
                break;
            }
            //cout<<k<<"k="<<endl;
            int l=0,r=n;
            int x;
            while (l<r-1){
                x=(l+r)/2;
                int q=get_sum(x);
                //cout<<q<<"---------"<<endl;
                if (q<k)
                    l=x;
                else if (q>=k)
                    r=x;
            }
            //cout<<r<<endl;
            modify(r,-1);
            //cout<<"---------"<<endl;
            ans[r]=P[i].h;
        }
        if (flag==0)
        {
            printf("Case #%d: impossible\n",cas );
            continue;
        }
        printf("Case #%d: ",cas );
        for (int i=1;i<n;i++)
            cout<<ans[i]<<" ";
        cout<<ans[n]<<endl;
    }

    return 0;
}