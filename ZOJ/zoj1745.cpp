#include <iostream>
#include <stdio.h>
using namespace std;
int abs(int a){
	if (a>0)
		return a;
	return -a;
}
int main(){
	int first,second,flag=0,last,location;
	while (~scanf("%d",&location)){
		
		if (location==5280){
			while (~scanf("%d",&second));
			break;
		}
		if (flag++)
			printf("\n");
		first=0;
		while (~scanf("%d",&second)){
			if (second==location){
				printf("Moving from %d to %d: found it!\n",first,second);
				break;
			}
			else{
				int l=abs(second-location),r=abs(first-location);
				if (l>r)
					printf("Moving from %d to %d: colder.\n",first,second);
				if (l==r)
					printf("Moving from %d to %d: same.\n",first,second);
				if (l<r)
					printf("Moving from %d to %d: warmer.\n",first,second);
			}
			first=second;
		}
	
	}
	return 0;
}
