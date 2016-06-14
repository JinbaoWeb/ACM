#include<stdio.h>
#include<string.h>
#define MAX 200
char s1[MAX],s2[MAX],temp[MAX];
int a[MAX],b[MAX];
int len1,len2,i,j;
 
void add(char *s1,char *s2)  //�������ӷ�
{
    for(i=len1-1,j=0;i>=0;--i)
        a[j++]=s1[i]-'0';
    for(i=len2-1,j=0;i>=0;--i)
        b[j++]=s2[i]-'0';
    for(i=0;i<MAX;++i)
    {
        a[i]+=b[i];
        if(a[i]>=10)
        {
            a[i]-=10;
            ++a[i+1];
        }
    }
}
 
int judge(char *s1,char *s2)//�ж�s1�ľ���ֵ�Ƿ����s2����������򷵻�1��С���򷵻�0
{
    len1=strlen(s1);
    len2=strlen(s2);
    if(len1>len2)
        return 1;
    else if(len1==len2)
    {
        for(i=0;i<len1;++i)
        {
            if(s1[i]>s2[i])
                return 1;
            else
                return 0;
        }
    }
    else
        return 0;
}
 
void sub(char *s1,char *s2)
{
    len1=strlen(s1);//��ֹ�任��len1��len2����
    len2=strlen(s2);
    for(i=len1-1,j=0;i>=0;--i)
            a[j++]=s1[i]-'0';
    for(i=len2-1,j=0;i>=0;--i)
        b[j++]=s2[i]-'0';
    for(i=0;i<MAX;++i)
    {
        a[i]-=b[i];
        if(a[i]<0)
        {
            a[i]+=10;
            --a[i+1];
        }
    }
}
 
int main()
{
    int flag;
    while(scanf("%s%s",s1,s2)!=EOF)
    {
        if(strcmp(s1,s2)==0)//��ʼ���ų�0 ��������Ժ����ж�
        {
            printf("0\n");
            continue;
        }
        flag=0;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        len1=strlen(s1);
        len2=strlen(s2);
        if(s1[0]!='-'&&s2[0]=='-'||s1[0]=='-'&&s2[0]!='-')    //���һ��A-(-B)���ȼ���A+B  ����  �������-A-B���ȼ���-(A+B)
        {
            if(s1[0]=='-')
            {
                s1[0]='0';
                flag=1;
            }
            if(s2[0]=='-')
                s2[0]='0';//��ȥ����
            add(s1,s2);
            if(flag)
                printf("-");
        }
        else                    //�������A-B  ����ģ�-A-(-B)�ȼ���B-A
        {
            if(s1[0]=='-') //�������ת��Ϊ�����
            {
                s1[0]='0';
                s2[0]='0';
                strcpy(temp,s1);
                strcpy(s1,s2);
                strcpy(s2,temp);
            }
            if(judge(s1,s2))
                sub(s1,s2);
            else
            {
                printf("-");
                sub(s2,s1);
            }
        }
        for(i=MAX-1;i>=0&&a[i]==0;--i);
    //  if(i>=0)                      //���εĴ�����Կ�¯0-(-0)�����
    //  {
            for(;i>=0;--i)
                printf("%d",a[i]);
            printf("\n");
    //  }
    //  else
    //      printf("0\n");
    }
    return 0;
}
