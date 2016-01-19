#include <iostream>
#include <iomanip> // for setw and setfill
#include <sstream>
#include "date.h"
#include <string>
#include <stdexcept>      // std::invalid_argument

template <typename T>
T string_cast(const std::string& str) {
	std::istringstream iss (str);
	T temp;

	if (!(iss >> temp)) {
		throw std::invalid_argument("Invalid argument");
	}
	return temp;
}


int main()
{
	try {
		int i = string_cast<int>("123");
		std::cout << "här kommer i: " << i << std::endl;
		double d = string_cast<double>("12.34");
		std::cout << "här kommer d: " << d << std::endl;
		Date date = string_cast<Date>("2015-20-10");
		std::cout << "här kommer date: " << date << std::endl;
	} catch (std::invalid_argument& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}
