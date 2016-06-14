#include <stdio.h>
int main(int argc, char const *argv[])
{
	printf("10\n");
	for (int i=0;i<10;i++)
	{
		printf("1000 1000\n");
		for (int j=1;j<1000;j++) printf("%d %d\n",j,j+1 );
	}
	return 0;
}