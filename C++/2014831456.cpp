#include<stdio.h>
__int64 d[32280];
int main()
{
  //  freopen("out.txt","r",stdin);
   // freopen("out1.txt","w",stdout);
	__int64 n,m,i,j,s,k,l,q,w,e,r,t,y;
	s=0;
	for(i=1;;i++)
	{
		if(i>=1&&i<=9)
		{
			d[i]=i;
			s+=d[i];

		}

		if(i>=10&&i<=99)
		{
			d[i]=(i-9)*2+d[9];
			s+=d[i];
		}

		if(i>=100&&i<=999)
		{
			d[i]=(i-99)*3+d[99];
			s+=d[i];

		}

		if(i>=1000&&i<=9999)

		{
			d[i]=(i-999)*4+d[999];
			s+=d[i];

		}

		if(i>=10000&&i<=99999)

		{

			d[i]=(i-9999)*5+d[9999];
			s+=d[i];
		}
        if(s>2147483647)
			{
				break;
			}


}


scanf("%I64d",&r);
	{


//for(j=1;j<=i;j++)
// printf("%d ",d[j]);
		while(r--)

		{
			scanf("%I64d",&n);
              s=0;
			for(i=1;;i++)
			{
            s+=d[i];
	        if(s>=n) break;
			}
           s-=d[i];
		__int64 cnt=0;
		   for(j=1;;j++)
		   {
			   if(j<10)              cnt+=1;
			   if(j>=10&&j<=99)      cnt+=2;
			   if(j>=100&&j<=999)     cnt+=3;
			   if(j>=1000&&j<=9999)   cnt+=4;
			   if(j>=10000&&j<=99999) cnt+=5;
			   if(cnt+s>=n) break;
		   }
          cnt+=s;
				if(j<10)
				{
                   printf("%I64d\n",j);
				}
					else if(j>=10&&j<=99)
				{
					if(cnt-n==0)

						printf("%I64d\n",j%10);

					if(cnt-n==1)
						printf("%I64d\n",(j/10)%10);
				}
				else	if(j>=100&&j<999)
				{
					if(cnt-n==0)
						printf("%I64d\n",j%10);
					if(cnt-n==1)
					   	printf("%I64d\n",(j/10)%10);
					if(cnt-n==2)
					    printf("%I64d\n",(j/100));
				}
				else	if(j>=1000&&j<9999)
                  {
					if(cnt-n==0)
						printf("%I64d\n",j%10);
					if(cnt-n==1)
						printf("%I64d\n",(j/10)%10);
					if(cnt-n==2)
					    printf("%I64d\n",(j/100)%10);
					if(cnt-n==3)
						printf("%I64d\n",(j/1000));
				}
			else	if(j>=10000&&j<99999)
       {
					if(cnt-n==0)
						printf("%I64d\n",j%10);
					if(cnt-n==1)
						printf("%I64d\n",(j/10)%10);
					if(cnt-n==2)
					    printf("%I64d\n",(j/100)%10);
					if(cnt-n==3)
						printf("%I64d\n",(j/1000)%10);
					if(cnt-n==4)
						printf("%I64d\n",(j/1000)/10);

				}



		}
	}
}
