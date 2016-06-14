#include <stdio.h>
#include <iostream>
#include <stdlib.h> 
#include <time.h> 
using namespace std;
#define N 1000 
int Max=0,Min=0xffff;    
void MaxAndMin(int array[], int left, int right)  
{ 
	int mid; 
	if (left==right)
	{
		if (Max < array[right])
			Max = array[right];
		if (Min > array[right])
			Min = array[right];
	}   
	else if ( (left + 1) == right)     
	{
	 	if ( array[left] < array[right] && Max < array[right] ) 
			Max = array[right];
	 	if ( array[left] > array[right] && Max < array[left] )
			Max = array[left];
	 	if ( array[left] < array[right] && Min > array[left]) 
		 	Min = array[left]; 
	 	if ( array[left] > array[right] && Min > array[right])
		 	Min = array[right];	 	
	 }
	 else 
	 {
	 	mid = (left + right) / 2;    
	 	MaxAndMin(array, left, mid);    
	 	MaxAndMin(array, mid + 1, right);  
	 }
}
int main()                 
{	
	int A[1000];
	int num;
	cin>>num;
	for(int n=0;n<num;n++)
		cin>>A[n]; 
	MaxAndMin(A, 0, num-1); 
	printf("����������ֵΪ��%d����СֵΪ��%d\n",Max,Min);
	return 0;
}	