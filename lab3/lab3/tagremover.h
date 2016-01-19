#ifndef TAGREMOVER_H
#define TAGREMOVER_H 

#include <string>
#include <iostream>
#include <unordered_map>

class TagRemover {
public:
	TagRemover(std::istream& is);
	void print(std::ostream& os) const;
private:
	std::istream& is;
	std::unordered_map <std::string, char> specialChars;
};

#endif
