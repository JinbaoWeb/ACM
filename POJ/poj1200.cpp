#include<stdio.h>
#include<string.h>
#define mem(a) memset(a,0,sizeof(a))

unsigned int hash[16000000+5];
unsigned int c[128];
char str[1000000];

int main()
{
    int len,base;
    while(~scanf("%d%d",&len,&base))
    {
        mem(str);
        mem(c);
        mem(hash);
        scanf("%s",str);
        int num =0;
        int i,j=0,length=strlen(str),tp=1;
        for(i=0;i<length;i++)
        {
            if(c[str[i]]==0)
				c[str[i]]=++j;
            if(j==base)
				break;
        }
        for(i=0;i<len;i++)
        {
            num=num*base+c[str[i]]-1;
            tp*=base;
        }
        tp/=base;
        hash[num]=1;
        int count=1;
        for(i=1;i<=length-len;i++)
        {
            num = ( num-(c[str[i-1]]-1)*tp )* base+ c[str[i+len-1]] - 1;
            if(!hash[num])
            {
                hash[num]=1;
                count++;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
