#include <string>
#include <iostream>
#include <fstream>
#include "coding.h"

using namespace std;

int main(int argc, char** argv) {
	if(argc < 2) return 1;
	string filename = argv[1];
	ifstream in(filename);
	ofstream out(filename + ".dec");
	unsigned char c;
	while(true) {
		in.get(c);
		if(!in.good()) {
			break;
		}
		out << Coding::decode(c);
	}
	in.close();
	out.close();
	return 0;
}