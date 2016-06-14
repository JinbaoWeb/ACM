#include <iostream>

#include <time.h>
using namespace std;
class Date{
	int year, month, day;
public:
	Date(int y, int m, int d){ //构造函数1
		year = y;
		month = m;
		day = d;
	}
	Date(){ //构造函数2
		time_t ltime; //说明time_t结构变量ltime
		time(&ltime); //取得当前时间
		tm * today = localtime(&ltime); //转换为本地时间
		year = today->tm_year + 1900; //取得当前年份
		month = today->tm_mon + 1; //取得当前月份,0-11
		day = today->tm_mday; //取得当前日,1-31
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

