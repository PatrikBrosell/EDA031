#include <ctime>  // time and localtime
#include <string>
#include <iomanip> // for setw and setfill
#include <iostream>
#include "date.h"

int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date() {
	time_t timer = time(0); // time in seconds since 1970-01-01
	tm* locTime = localtime(&timer); // broken-down time
	year = 1900 + locTime->tm_year;
	month = 1 + locTime->tm_mon;
	day = locTime->tm_mday;
}

Date::Date(int y, int m, int d) {
	year = y;
	month = m;
	day = d;
}

int Date::getYear() const {
	return year;
}

int Date::getMonth() const {
	return month;
}

int Date::getDay() const {
	return day;
}

void Date::next() {
	day++;
	if(day > daysPerMonth[month-1]) {
		day = 1;
		month++;
		if(month > 12) {
			year++;
			month = 1;
			day = 1;
		}
	}
}

std::istream& operator>>(std::istream& is, Date& dt) {
	std::string temp = "";
	is >> temp;

	if(temp.length() != 10) {
		is.setstate(std::ios_base::badbit);
		return is;
	}

	if(temp.back() == EOF) {
		is.setstate(std::ios_base::eofbit);
	} else {
		int year = std::stoi(temp.substr(0, 4));

		int month = std::stoi(temp.substr(5, 2));

		int day = std::stoi(temp.substr(8, 2));

		if(month > 0 && month < 13 
			&& year > 0 
			&& day > 0 && day < Date::daysPerMonth[month-1]) {
				dt = Date(year, month, day);
			} else {
				is.setstate(std::ios_base::badbit);
			}
		}
	return is;
}

std::ostream& operator<<(std::ostream& os, Date& dt) {
	os << std::setw(4) << std::setfill('0') << dt.getYear() << '-';
	os << std::setw(2) << std::setfill('0') << dt.getMonth() << '-';
	os << std::setw(2) << std::setfill('0') << dt.getDay();
	return os;
}

