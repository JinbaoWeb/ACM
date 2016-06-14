#include<stdio.h>
#include<math.h>
#include<string.h>
char s1[22][22]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax",
                 "zac","ceh","mac","kankin","muan","pax","koyab","cumhu"};
char s2[23][23]={"imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk",
                 "ok","chuen","eb", "ben","ix","mem","cib","caban","eznab","canac","ahau"};
int main()
{
   int n,m,k,l,i,j,h,q,w;
   while(~scanf("%d",&m))
   {
        printf("%d\n",m);
        while(m--)
        {
            char mon[44];
            int day,year;
            scanf("%d. %s %d",&day,mon,&year);
            n=year*365;
            for(i=0;i<19;i++)
            {
                if(strcmp(mon,s1[i])==0) break;
            }         
            if(i!=19) n+=(i)*20+day; 
            if(i==19) n+=(18*20)+day;
            q=n%20;
            w=n%13;
            printf("%d",w+1);
            printf(" %s ",s2[q]);
            printf("%d\n",n/260);
         
        }
    } 
}
