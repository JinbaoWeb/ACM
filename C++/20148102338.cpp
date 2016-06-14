#include <stdio.h>
int main()
{
	int in,n,num;
	scanf("%d",&n);
	while(n--)
	{
		num=0;
		scanf("%d",&in);
		while(in>0)
		{
			num+=in/5;  //第一次计算有多少个5，第二次计算有多少个25，第三次计算多少个125。。。。。。。
			in=in/5;
  		}
   		printf("%d\n",num);
	}
	return 0;
}
