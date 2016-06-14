/*******************************************************************************
 * Author :          jinbao
 * Email :           dongjinbao913106840144@gmail.com
 * Last modified :   2015-05-01 09:50
 * Filename :        301A.cpp
 * Description :    
 * Tutorial：For every symbol we should determine how to rotate the disk. This can be done either by formula: min(abs(a[i]-b[i]),10-abs(a[i]-b[i])) or even by the two for cycles: in both directions.
 * *****************************************************************************/
#include <stdio.h>
#include <iostream>
using namespace std;
int f(char x,char y){
    int a=x-'0',b=y-'0';
    if (a>b){
        return (a-b)<(b-a+10)?(a-b):(b-a+10);
    }
    else
        return (b-a)<(a-b+10)?(b-a):(a-b+10);
}
int main(){
    int n;
    char a[1005],b[1005];
    while (~scanf("%d",&n)){
        scanf("%s%s",&a,&b);
        int sum=0;
        for (int i=0;i<n;i++){
        //  cout<<f(a[i],b[i])<<endl;
            sum+=f(a[i],b[i]);
        }
        printf("%d\n",sum);
    }
    return 0;
}
