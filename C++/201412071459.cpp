#include <stdio.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n); 
	if (n%10==0)
		n/=10;
	while (n>0){
		printf("%d",n%10);
		n/=10;
	}
	return 0;
}
