#include <stdio.h>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	printf("1\n");
	printf("%d %d\n",100,200000 );
	for (int i=0;i<200000;i++) printf("%d %d\n",rand()%100+1,rand()%100+1 );
	return 0;
}