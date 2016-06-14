#include <stdio.h>

int main()
{
    int cas,i;
    int n,t,b;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d%d",&t,&b);
        if(90%b)//b必须能被90整除
        {
            printf("Impossible!\n");
            continue;
        }
        //以下是按结果的最后数字不同进行分类
        if(b == 1 || b == 3 || b == 9)
        {
            for(i = 0;i<t;i++)
            printf("9");
        }
        else if(b == 2)
        {
            for(i = 0;i<t-1;i++)
            printf("9");
            printf("8");
        }
        else if(b == 5)
        {
            for(i = 0;i<t-1;i++)
            printf("9");
            printf("5");
        }
        else if(b == 6)
        {
            for(i = 0;i<t-1;i++)
            printf("9");
            printf("6");
        }
        else
        {
            if(t<2)
            {
                printf("Impossible!\n");
                continue;
            }
            for(i = 0;i<t-1;i++)
            printf("9");
            printf("0");
        }
        printf("\n");
    }

    return 0;
}