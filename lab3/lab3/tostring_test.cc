#include <iostream>
#include <iomanip> // for setw and setfill
#include <sstream>
#include "date.h"


template <typename T>
std::string toString(T& obj) {
	std::ostringstream oss;
	oss << obj;
	return oss.str();
}


int main()
{
	double d = 1.234;
	Date today;
	std::string sd = toString(d);
	std::cout << sd << std::endl;
	std::string st = toString(today);
	std::cout << st << std::endl;
}
