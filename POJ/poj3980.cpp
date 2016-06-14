#include <cstdio>
int main()
{
	int a,b;
	while (scanf("%d%d",&a,&b)!=EOF)
	{
		printf("%d\n",a-a/b*b);
	}
	return 0;
} 
