#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

int a[100][100],s[100],e[100];
int n;

void swap(int &a,int &b)
{
     int tmp=a;
     a=b;
     b=tmp;
}

int gauss()
{
    int i,j,k,l;
    for (i=0,j=0;i<n,j<n;i++,j++)
    {
        int row=i;
        for (k=i+1;k<n;k++)
            if (a[k][j]>a[row][j]) row=k;
        if (row!=i)
        {
                   for (k=j;k<=n;k++) swap(a[i][k],a[row][k]);
        }
        if (a[i][j]==0)
        {
                       i--;
                       continue;
        }        
        for (k=i+1;k<n;k++)
        {
            if (a[k][j]==0) continue;
            for (l=j;l<=n;l++) a[k][l]=(a[k][l]-a[i][l]+2)%2;
        }
    }
    for (k=i;k<n;k++)
        if (a[k][n]!=0) return -1;
    if (i==n) return 1;
    else return pow(2.0,n-i); 
}

int main()
{
    int T,i,k,j,r;
    cin>>T;
    while (T>0)
    {
          cin>>n;
          memset(a,0,sizeof(a));
          for (i=0;i<n;i++) cin>>s[i];
          for (i=0;i<n;i++) 
          {
              cin>>e[i];
              a[i][n]=(e[i]-s[i]+2)%2;
              a[i][i]=1;
          }
          do
          {
              int x,y;
              cin>>x>>y;
              if (x+y==0) break;
              a[y-1][x-1]=1;
          }
          while (true);
          if ((r=gauss())<0)
             cout<<"Oh,it's impossible~!!"<<endl;
          else cout<<r<<endl;
          T--;          
    }
    return 0;
}
