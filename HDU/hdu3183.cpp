#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char b[1010];//输入
    int a[1010],i,j,k,n,m;//转化为整数
    int c[1010];//保存结果
    while(cin>>b>>n)
    {
        if(b[0]=='0'&&n==0)
            break;
        for(i=0;b[i]!='\0';i++)
            a[i]=b[i]-'0';//转化为整数
        m=i;k=0;
        for(i=0;i<m-1&&n>0;i++)
        {
            if(a[i]<=a[i+1])
            {
                c[k++]=a[i];
            }
            else
            {
                n--;
                while(c[k-1]>a[i+1]&&n>0)//处理相等情况,如 5553444 3，处理第三个5时，往回消除数字
                {
                    k--;n--;
                }
            }
        }
        for(;i<m;i++)
            c[k++]=a[i];
        for(i=0;i<k-n;i++)//去除前导0
            if(c[i]!=0)
                break;
        if(i==k-n)//答案为0时
            cout<<"0";
        for(;i<k-n;i++)
            cout<<c[i];
        cout<<endl;
    }
}