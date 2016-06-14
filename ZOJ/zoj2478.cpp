#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char str[110];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        int len=strlen(str),j;
        for(int i=0;i<len;)
        {
            if(str[i]!=str[i+1])
            {
                printf("%c",str[i]);
                i++;
            }
            else
            {
               int count=1;
                for(j=i+1;j<len;j++)
                {
                   if(str[i]==str[j])
                    count++;
                    else
                    break;
                }
                 printf("%d%c",count,str[i]);
                i=j;
 
            }
        }
        printf("\n");
    }
    return 0;
}


