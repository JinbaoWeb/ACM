#include <stdio.h>
int main(int argc, char const *argv[])
{
	printf("20000\n");
	for (int i=0;i<20000;i++) printf("2 %d\n",i*32%1000000);
	return 0;
}