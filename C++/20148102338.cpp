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
			num+=in/5;  //��һ�μ����ж��ٸ�5���ڶ��μ����ж��ٸ�25�������μ�����ٸ�125��������������
			in=in/5;
  		}
   		printf("%d\n",num);
	}
	return 0;
}
