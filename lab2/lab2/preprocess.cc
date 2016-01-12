#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using std::vector;

int main(int argc, char** argv) {
	string filename = argv[1];
	ifstream in(filename);
	ofstream out("words.txt");
	if(argc == 0) return 1;

	vector<string> v;
	string word;
	string trigram;
	while(true) {
		v.clear();
		getline(in, word);
		transform(word.begin(), word.end(), word.begin(), ::tolower);
		if(!in.good()) {
			break;
		}

		if(word.length() <= 3) {
			// do nothing
		} else {		
			for(unsigned int i = 0; i < word.length() - 2; i++) {
				trigram = word.substr(i, 3);
				v.push_back(trigram);
			}
		}

		sort( v.begin(), v.end());

		out << word << " ";
		out << v.size();

		for(unsigned int i = 0; i < v.size(); i++) {
			out << " "<< v[i];
		}
		out << endl;


	//	std::cout << word << endl;
	}
	in.close();
	out.close();
	return 0;
}