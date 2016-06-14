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
    }//p判断第n个数是多少位(这个位将两个合在了一起，比如1和2，算成一起）

    ans+=(n%s==0?s:n%s)-1;//判断第n个数是在奇数位（例如1位）还是偶数位（例如2位）
    printf("%d",ans);//回文数的构成规则，将一个数分成两部分，后边的和前边的相同，这是输出前半部分。
    if(n-s<=0)//第n个数在奇数位上
        ans/=10;//奇数位上的回文数，如111.是由11和1组成的故ans需要除10，先输出11后在输出1。
    while(ans)
    {
        printf("%d",ans%10);//输出后半部分
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