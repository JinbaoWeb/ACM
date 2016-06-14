#include <iostream>
using namespace std;
#define M 101
void input(char a[M][M],int m,int n)
{
    int i,j;
    for (i=0;i<m;i++)
    {
        for (j=0;j<m;j++)
            cin>>a[i][j];
        a[i][j]=0;
    }
}
void f(int *a,char x[M][M],int m,int n)
{
    for (int i=0;i<m;i++)
    {
        int count=0;
        for (int j=0;j<n;j++)
            for (int s=j+1;s<n;s++)
                if (x[j]<x[s])
                    count++;
        a[i]=count;
    }
}
void output(int *x,char y[M][M],int m,int n)
{
    int value,index,z[M];
    for (int i=0;i<m;i++)
    {
        if (x[i]==-1)
            continue;
        value=x[i];
        index=i;
        for (int j=i+1;j<m;j++)
            if (value>x[j])
            {
                value=x[j];
                index=j;
            }
        z[i]=index;
        x[index]=-1;
    }
    for (int s=0;s<m;s++)
        cout<<y[s]<<endl;
}
int main()
{
    char x[M][M];
    int m,n,y[M];
    while (cin>>m>>n)
    {
        input(x,m,n);
        f(y,x,m,n);
        output(y,x,m,n);
    }
    return 0;
}
