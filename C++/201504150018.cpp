#include <stdio.h>
#include <string.h>
void slove(int n)
{
    int s=9,ans=1;
    while(n>s*2)
    {
        n-=s*2;
        s*=10;
        ans*=10;
    }//p�жϵ�n�����Ƕ���λ(���λ������������һ�𣬱���1��2�����һ��

    ans+=(n%s==0?s:n%s)-1;//�жϵ�n������������λ������1λ������ż��λ������2λ��
    printf("%d",ans);//�������Ĺ��ɹ��򣬽�һ�����ֳ������֣���ߵĺ�ǰ�ߵ���ͬ���������ǰ�벿�֡�
    if(n-s<=0)//��n����������λ��
        ans/=10;//����λ�ϵĻ���������111.����11��1��ɵĹ�ans��Ҫ��10�������11�������1��
    while(ans)
    {
        printf("%d",ans%10);//�����벿��
        ans/=10;
    }
    printf("\n");
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF&&n)
    {
        slove(n);
    }
    return 0;
}