#include <iostream>
using namespace std;
int amonth[12]={31,28,31,30,31,30,31,31,30,31,30,31};
bool isyear(int a)
{
	if (a%4==0&&a%100!=0)
		return true;
	return false;
}
int main()
{
	int t;
	char a[20],b[20];
	cin>>t;
	for (int c=1;c<=t;c++)
	{
		cin>>a>>b;
		int year_a=(a[0]-'0')*1000+(a[1]-'0')*100+(a[2]-'0')*10+a[3]-'0';
		int year_b=(b[0]-'0')*1000+(b[1]-'0')*100+(b[2]-'0')*10+b[3]-'0';
		int month_a=(a[5]-'0')*10+a[6]-'0';
		int month_b=(b[5]-'0')*10+b[6]-'0';
		int day_a=(a[8]-'0')*10+a[9]-'0';
		int day_b=(b[8]-'0')*10+b[9]-'0';
		if (year_a>year_b)
		{
			swap(year_a,year_b);
			swap(month_a,month_b);
			swap(day_a,day_b);
		}
		/*if (year_a==year_b)
		{
			for (int k=0;k<month_a;k++)
				day_a+=amonth[k];
			for (int k=0;k<month_b;k++)
				day_b+=amonth[k];
			if (isyear(year_a)==true)
			{
				if (month_a>2)
					day_a++;
				if (month_b>2)
					day_b++;
			}
			int r=day_a-day_b;
			if (r<0)
				r=-r;
			cout<<r<<endl;
		}
		else
		{*/
			int s=0;
			for (int i=year_a;i<year_b;i++)
				if (isyear(i)==true)
					s++;
			int r=(year_b-year_a-1)*365+s;
			//cout<<s<<" "<<r<<endl;
			day_a=amonth[month_a-1]-day_a;
			for (int k=month_a;k<12;k++)
				day_a+=amonth[k];
			if (isyear(year_a)==true)
			{
				if (month_a>1)
					day_a++;
			}
			//cout<<day_a<<endl;
			for (int k=0;k<month_b-1;k++)
				day_b+=amonth[k];
			if (isyear(year_b)==true)
			{
				if (month_b>2)
					day_b++;
			}
			//cout<<day_b<<endl;
			cout<<r+day_a+day_b<<endl;
		
	}
	return 0;
}
