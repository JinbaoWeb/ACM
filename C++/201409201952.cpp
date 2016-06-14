#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	char s[35];
	int sum=0,i=0;
	cin.getline(s,35);
	int mul=pow(2,7);
	while (i<32){
		sum+=(s[i]-'0')*mul;
		mul/=2;
		if ((i+1)%8==0){
			mul=pow(2,7) ;
			cout<<sum;
			sum=0;
			if (i!=31)
				cout<<'.';
		}
		i++;
	}
	cout<<endl;/*
	while(i<32)
	{
		for(int j=0;j<8;j++)
		{
			int a=0;
			a=s[i]-'0';
			for(int h=1;h<=8-(i+1)%8;h++)
				a*=2;
			sum+=a;
		}
		i++;
		cout<<sum<<".";
	}
	cout<<endl;*/ 
	return 0;
}

