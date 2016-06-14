/*******************************************************************************
 * Author :          jinbao
 * Email :           dongjinbao913106840144@gmail.com
 * Last modified :   2015-05-08 11:04
 * Filename :        zoj2191.cpp
 * Description :     
 * *****************************************************************************/
#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	int f0,f1,f2;
	while (cin>>f0>>f1>>f2){
		int a=(f2-2*f1+f0)/2;
		int b=(4*f1-3*f0-f2)/2;
		int c=f0;
		int f3=9*a+3*b+c;
		int f4=16*a+4*b+c;
		int f5=25*a+5*b+c;
		cout<<f3<<" "<<f4<<" "<<f5<<endl;
	}
	return 0;
}
