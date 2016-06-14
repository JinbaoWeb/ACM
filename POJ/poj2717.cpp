//Accepted    164K    47MS    C++    413B
#include <stdio.h>
#include <string.h>

int solve(char s[])
{
    int ans = 0;
    int t = 1;
    for(int i = strlen(s) - 1; i >= 0 ;i--)
    {
        ans += (s[i] - '0') * t;
        t *= 9;
    }
    return ans;
}
int main(void)
{
    char s[20];
    while(scanf("%s",s)!=EOF && strcmp(s,"0") != 0)
    {
        printf("%s",s);
        for(int i=0;i<strlen(s);i++)
            if(s[i] > '4') s[i]--;
        printf(": %d\n",solve(s));
    }
    return 0;
}
