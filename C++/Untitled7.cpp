#include <iostream>
#include <string.h>
using namespace std;
struct style
{
	char name[20];
	int number;
	double price;
}s[20];
int mian()
{
	s[0].name={"9500"};				s[0].price=23;
	s[1].name={"619"};				s[1].price=27;
	s[2].name={"8089"};				s[2].price=42;
	s[3].name={"636"};				s[3].price=30;
	s[4].name={"620"};				s[4].price=26;
	s[5].name={"2028"};				s[5].price=24;
	s[6].name={"2188"};				s[6].price=33;
	s[7].name={"902"};				s[7].price=28;
	s[8].name={"18"};				s[8].price=7;
	s[9].name={"床边17公分"};		s[9].price=2.3;
	for (int i=0;i<10;i++)
		s[i].number=0;
	char a[20];
	int b;
	while (cin>>a&&strcmp(a,"0")!=0)
	{
		cin>>b;
		for (int i=0;i<10;i++)
			if (strcmp(a,s[i].name)==0)
			{
				s[i].number+=b;
				break;
			}
	}
	cout<<'\t'<<"款型"<<'\t'<<"单价"<<'\t'<<"数量"<<'\t'<<"计件工资"<<endl;
	for (int i=0;i<10;i++)
		cout<<'\t'<<s[i].name<<'\t'<<s[i].price<<'\t'<<s[i].number<<'\t'<<s[i].price*s[i].number<<endl;
	return 0;
}
