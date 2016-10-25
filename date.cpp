// date_starter.cpp
#include <iostream>
#include <sstream>

using namespace std;

class Date{
  private:
	int month;
	int day;
	int year;
	const string monthName[12] = {
		"January", "February", "March", "April", "May", "June",
		"July", "August", "September", "October", "November", "December" };



  public:

    const int monthEnds[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	int	getMonth() const { return month; }
	int	getDay() const { return day; }
	int	getYear() const { return year; }
	void setMonth(int m)
	{
        month = m;
    }
	void setDay(int d)
	{
	    day = d;
    }
	void setYear(int y) { year = y;}

	string getMonthName(int m) const;

	void showDate1();
	void showDate2();
	void showDate3();
	//Constructor : Date();

	class InvalidYear{};
	class InvalidMonth{};
	class InvalidDay{};
};

void Date::showDate1() {
	cout << getMonth() <<"/";
	cout << getDay()	 << "/";
	cout << getYear()	<< endl;
}

string Date::getMonthName(int m) const {
	if(m < 1 || m > 12) return "";
	else  return monthName[m-1];
}

void Date::showDate2() {
	cout << getMonthName(getMonth()) <<" ";
	cout << getDay()	 << ", ";
	cout << getYear()	<< endl;
}

void Date::showDate3() {
	cout << getDay()	 << " ";
	cout << getMonthName(getMonth()) <<" ";
	cout << getYear()	<< endl;
}

int main() {
	 // Create a Date object and initialize it
	 // using the overloaded constructor.
	 Date today;
	 int month = 0;
	 int day = 0;
	 int year = 0;
	 string input = "";

     while(true)
	 {
	     cout << "\nEnter the Date as 6 30 2014: ";
	     getline(cin, input);
	     stringstream ss(input);
	     ss >> month;
	     ss >> day;
	     ss >> year;

	     try
	     {
	         if(month > 12 || month < 1)
                throw month;
             today.setMonth(month);

             if(day > today.monthEnds[month-1] || day < 1)
                throw day;
             today.setDay(day);

             if(year > 9999)
                throw year;
             today.setYear(year);

	     }
	     catch(int err)
	     {
	         cout << err << " an invalid value for the Date.\n";
	         continue;
	     }


	     today.showDate1();

         today.showDate2();

         today.showDate3();
	 }
	 return 0;
}
