#include <iostream>
using namespace std;
int min(int a,int b,int c,int d)
{
	return d<(c<(a<b?a:b) ? c:(a<b?a:b)) ? d:(c<(a<b?a:b) ? c:(a<b?a:b));
}
int f(int a)
{
	a%=10;
	return a;
}
int main()
{
	int a[5843],i2,i3,i5,i7;
	i2=i3=i5=i7=1;
	a[1]=1;
	for (int i=2;i<5843;i++)
	{
		a[i]=min(a[i2]*2,a[i3]*3,a[i5]*5,a[i7]*7);
		if (a[i]==a[i2]*2)
			i2++;
		if (a[i]==a[i3]*3)
			i3++;
		if (a[i]==a[i5]*5)
			i5++;
		if (a[i]==a[i7]*7)
			i7++;
	}
	int n;
	while (cin>>n&&n)
	{
		if (f(n)==1&&n!=11&&n%100!=11)
			cout<<"The "<<n<<"st humble number is "<<a[n]<<"."<<endl;
		else
		{
			if (f(n)==2&&n!=12&&n%100!=12)
				cout<<"The "<<n<<"nd humble number is "<<a[n]<<"."<<endl;
			else
			{
				if (f(n)==3&&n!=13&&n%100!=13)
					cout<<"The "<<n<<"rd humble number is "<<a[n]<<"."<<endl;
				else
					cout<<"The "<<n<<"th humble number is "<<a[n]<<"."<<endl;
			}
		}
	}
	return 0;
}
