#include <bits/stdc++.h>
using namespace std;
int a[1000],b[1000];
int main(){
	int t,n,i,j,k,temp,a[102],max_p,max_1,max_2;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
         scanf("%d",&n);
         for(j=1;j<=n;j++) 
              scanf("%ld",&a[j]);
         max_p=1;
         max_1=a[1];
         max_2=0;
         for(j=1;j<n;j++)
         {
              if(max_1<a[j+1])
              {
                   max_2=max_1;
                   max_1=a[j+1];
                   max_p=j+1;
              }
              else
              {
                   if(max_2<a[j+1])
                   {
                       max_2=a[j+1];
                   }
              }
         }
         printf("%ld %ld\n",max_p,max_2);
     }
	return 0;
}