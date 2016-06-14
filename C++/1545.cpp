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
		//cout<<year_a<<":"<<month_a<<":"<<day_a<<endl;
	//	cout<<year_b<<":"<<month_b<<":"<<day_b<<endl;
		int s=0;
		for (int i=year_a;i<=year_b;i++)
			if (isyear(i)==true)
				s++;
		//cout<<s<<endl;
		int days=(year_b-year_a-1)*365+s;
		int months=0,months_b=0;
		if (isyear(year_a)==true)
		{
			for (int k=0;k<month_a;k++)
				months+=amonth[k];
			if (month_a>2)
				months++;
			months+=day_a;
			months=366-months;
		}
		else
		{
			for (int k=0;k<month_a;k++)
				months+=amonth[k];
			months+=day_a;
			months=365-months;
		}
		
		if (month_b>2)
		{
			for (int k=0;k<month_b;k++)
				months_b+=amonth[k];
			months_b++;
		}
		else
			for (int k=0;k<month_b;k++)
				months_b+=amonth[k];
		months_b+=day_b;
		cout<<"months"<<months<<"months_b"<<months_b<<endl;
		cout<<days+months+months_b<<endl;
	}
	return 0;
}
