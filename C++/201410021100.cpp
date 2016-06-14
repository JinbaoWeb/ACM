#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#include <queue>
#include <set>
#include <vector>
#include <stack>
#include <map>
#include <iomanip>
#define PI acos(-1.0)
#define Max 2005
#define inf 1<<28
using namespace std;

char Map[Max][Max];
int n,m;
int main()
{
    int i,j,k,l,T;
    scanf("%d",&T);
    while(T--)
    {
        int num=0;
        cin>>n>>m;
        for(i=0; i<n; i++)
        {
            scanf("%s",Map[i]);
            for(j=0; j<m; j++)
                if(Map[i][j]!='.')
                {
                    num++;
                    break;
                }
        }
        if(!num)//??num==0,?????????"?"???,?????????
        {
            puts("INCORRECT");
            continue;
        }
        char op='.';
        int numx,numy;
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                if(Map[i][j]!=op)//????????
                {
                    op=Map[i][j];
                    numx=i;//??????????
                    numy=j;
                    break;
                }
            }
            if(op!='.')
                break;
        }
        bool flag=0;
        for(i=0; i<n; i++)//?????????????????????
            for(j=0; j<m; j++)
                if(Map[i][j]!='.')
                    if(Map[i][j]!=op)//?????flag=1;
                    {
                        flag=1;
                    }
        if(flag)//??flag=1,????2???2???????????,?????????
        {
            puts("INCORRECT");
            continue;
        }
        i=numx,j=numy;
        if(Map[i][j]=='\\')//?????????,???
        {
            while(i<n&&j<m)
            {
                if(Map[i][j]!=op)
                {
                    break;
                }
                Map[i][j]='.';//???????"\"??,?????????"?"?
                i++;//???????????
                j++;
            }
        }
        else if(Map[i][j]=='/')
        {
            while(i<n&&j>=0)
            {
                if(Map[i][j]!=op)
                {
                    break;
                }
                Map[i][j]='.';
                i++;
                j--;
            }
        }
        else if(Map[i][j]=='|')
        {
            while(i<n)
            {
                if(Map[i][j]!=op)
                {
                    break;
                }
                Map[i][j]='.';
                i++;
            }
        }
        else if(Map[i][j]=='-')
        {
            while(j<m)
            {
                if(Map[i][j]!=op)
                {
                    break;
                }
                Map[i][j]='.';
                j++;
            }
        }
        bool flag1=0;
        num=0;
        for(i=0; i<n; i++)//??????,????"?",????????
        {
            for(j=0; j<m; j++)
                if(Map[i][j]!='.')
                {
                    flag1=1;
                    break;
                }
            if(flag1)break;
        }
        if(!flag1)
            puts("CORRECT");
        else
            puts("INCORRECT");
    }
    return 0;
}

