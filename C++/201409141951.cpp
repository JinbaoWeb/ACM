#include <iostream>

#include <time.h>
using namespace std;
class Date{
	int year, month, day;
public:
	Date(int y, int m, int d){ //���캯��1
		year = y;
		month = m;
		day = d;
	}
	Date(){ //���캯��2
		time_t ltime; //˵��time_t�ṹ����ltime
		time(&ltime); //ȡ�õ�ǰʱ��
		tm * today = localtime(&ltime); //ת��Ϊ����ʱ��
		year = today->tm_year + 1900; //ȡ�õ�ǰ���
		month = today->tm_mon + 1; //ȡ�õ�ǰ�·�,0-11
		day = today->tm_mday; //ȡ�õ�ǰ��,1-31
	}
	int getYear(){ return year; }
	int getMonth(){ return month; }
	int getDay(){ return day; }
	bool isLeapYear(){
		return year % 400 == 0 || year % 4 == 0 && year % 100 != 0;
	}
	void print(){
		cout << year << "." << month << "." << day;
	}
};
int main(){
	Date date1(2002, 10, 1), date2; //A
	cout << "date1: ";
	date1.print();
	cout << "\ndate2: ";
	date2.print();
	if (date2.isLeapYear())
		cout << "\ndate2 is a leapyear." << endl;
	else
		cout << "\ndate2 is not a leapyear." << endl;
	return 0;
}

