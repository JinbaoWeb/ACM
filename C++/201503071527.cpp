#include <stdio.h>
#define MAX 100000+1
int Max_x,Max_y,x,y;
int MaxSubseqSum(int n,int a[]){
    int ThisSum=0 , MaxSum=0 ;
    x=y=0;
    for (int i=0;i<n;i++){
        ThisSum+=a[i];
        y=i;
        if (ThisSum>MaxSum){
            Max_x=x;
            Max_y=y;
            MaxSum=ThisSum;
        }   
        else if (ThisSum<0){
            ThisSum=0;
            x=y=i+1;
        }             
    }
    return MaxSum;
}
int main(){
    int n,a[MAX];
    while (~scanf("%d",&n)){
        for (int i=0;i<n;i++)    
            scanf("%d",&a[i]);
        x=y=Max_x=Max_y=0;
        int ans=MaxSubseqSum(n,a);
        printf("%d %d %d\n",ans,Max_x,Max_y);
    }
    return 0;
}