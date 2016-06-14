#include <iostream>
#include <string.h>
using namespace std;
char Haab[19][10]={"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};
char Tzolkin[20][10]={"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
int main()
{
	int c,day,year;
	char month[10],doc;
	cin>>c;
	cout<<c<<endl;
	for (int ss=0;ss<c;ss++)
	{
		cin>>day>>doc>>month>>year;
		int n_month;
		if (strcmp(month,Haab[18])!=0)
		{
			for (int i=0;i<19;i++)
				if (strcmp(month,Haab[i])==0)
				{
					n_month=i;
					break;
				}
			int sumday=day+1+year*365+n_month*20;
			int cout_year=sumday/260;
			while (sumday>260)
				sumday-=260;
			if (sumday==260)
				cout_year--;
			int month_n=sumday;
			while (month_n>20)
				month_n-=20;
			int day_n=sumday;
			while (day_n>13)
				day_n-=13;
			cout<<day_n<<" "<<Tzolkin[month_n-1]<<" "<<cout_year<<endl;
		}
		else
		{
			int sumday=day+1+year*365+18*20;
			int cout_year=sumday/260;
			while (sumday>260)
				sumday-=260;
			if (sumday==260)
				cout_year--;
			int month_n=sumday;
			while (month_n>20)
				month_n-=20;
			int day_n=sumday;
			while (day_n>13)
				day_n-=13;
			cout<<day_n<<" "<<Tzolkin[month_n-1]<<" "<<cout_year<<endl;
		}
	}
	return 0;
}
