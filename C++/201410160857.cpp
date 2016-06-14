#include<iostream>
#include<string.h>
using namespace std;
int next[1000005];
char s[1000005];
void getnext()
{
    int i=0,j=-1;
    next[0]=-1;
    int len=strlen(s);
    while(i<len)
    {
        if(s[i]==s[j]||j==-1)
        {
            i++;
            j++;
            next[i]=j;
        }
        else
            j=next[j];
    }
}
int main()
{
    while(scanf("%s",s)>0)
    {
        if(s[0]=='.')
            break;
        int len=strlen(s);
        getnext();
        for (int i=0;i<=len;i++)
			cout<<next[i]<<" ";
		cout<<endl; 
        if(len%(len-next[len])==0)
            printf("%d\n",len/(len-next[len]));
        else
            printf("1\n");
    }
    return 0;
}
