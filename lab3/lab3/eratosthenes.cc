#include <iostream>
#include <string>



int main() {
	std::string str = std::string(100000, 'P');
	str.replace(0, 1, "C");
	str.replace(1, 1, "C");

	int lastprime = 2;
	while(lastprime*lastprime < 100000) {
		for(int i = 2; lastprime*i < 100000; i++) {
			str.replace(lastprime*i, 1, "C");
		}
		lastprime = str.find("P", lastprime + 1);
	}

	for(int i = 0; i < 200; i++) {
		std::string temp = str.substr(i, 1);
		if(temp == "P") {
			std::cout << i << " ";
		}
	}

	std::cout << "Largest prime found is: "<< str.find_last_of("P") << std::endl;

}


