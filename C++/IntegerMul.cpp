/*******************************************************************************
 * Author :          jinbao
 * Email :           dongjinbao913106840144@gmail.com
 * Last modified :   2015-06-12 17:40
 * Filename :        IntegerMul.cpp
 * Description :     
 * *****************************************************************************/
#include <iostream>
#include <math.h>
using namespace std;
#define SIGN(A) ((A > 0) ? 1 : -1)
#define abs(x)	x>0?x:-x
int IntegerMultiply(int X, int Y, int N)
{
	int sign = SIGN(X) * SIGN(Y);
	int x = abs(X);
	int y = abs(Y);
	if((0 == x) || (0 == y))
		return 0;
	if (1 == N)
		return x*y;
	else
	{
		int XL = x / (int)pow(10., (int)N/2); 
		int XR = x - XL * (int)pow(10., N/2);
		int YL = y / (int)pow(10., (int)N/2);
		int YR = y - YL * (int)pow(10., N/2);
		
		int XLYL = IntegerMultiply(XL, YL, N/2);
		int XRYR = IntegerMultiply(XR, YR, N/2);
		int XLYRXRYL = IntegerMultiply(XL - XR, YR - YL, N/2) + XLYL + XRYR;
		return sign * (XLYL * (int)pow(10., N) + XLYRXRYL * (int)pow(10., N/2) + XRYR);
	}
}
int main()
{
	int x = 1234;
	int y = 4321;
	cout<<"x * y = "<<IntegerMultiply(x, y, 4)<<endl;
	return 0;
}

