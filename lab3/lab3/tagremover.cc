#include <iostream>
#include <string>

#include "tagremover.h"

TagRemover::TagRemover(std::istream& in): is(in) {

}

void TagRemover::print(std::ostream& os) const {
	std::string str;
    std::string line;
	while (std::getline(is, line))
	{
	    str += line;
	    str += "\n";
	}
   	int a = str.find("<");
   	int b = str.find(">");

    while(str.find("<") != std::string::npos) {
    	str.erase(a, b-a+1);
    	a = str.find("<");
    	b = str.find(">");
    }
    str.replace(str.find("&lt;"), 4, "<");
    str.replace(str.find("&gt;"), 4, ">");
    str.replace(str.find("&nbsp;"), 6, " ");
    str.replace(str.find("&amp;"), 5, "&");
    os << str;
}


int main() {
    TagRemover tr(std::cin);	// read from cin
    tr.print(std::cout);	// print on cout
}
