#include<stdio.h>//�������࣬����n(���������Ǵ��� 
char a[100000];
int main()
{
	int i,j,k,m,n;
	while(scanf("%s%d",a,&n)!=EOF)
	{
		m=0;
		for(i=0;a[i]!='\0';i++)
			m=((m*10)%n+(a[i]-'0')%n)%n;
		printf("%d\n",m);
 	}
	return 0;
}
