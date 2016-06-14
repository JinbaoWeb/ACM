#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	printf("1\n");
	printf("30 30\n");
	for (int i=0;i<30;i++)
	{
		for (int j=0;j<30;j++)
			printf("%d ",rand()%30+1 );
		printf("\n");
	}
	return 0;
}