#include <string>
#include <vector>
#include "word.h"

using namespace std;

Word::Word(const string& w, const vector<string>& t): word(w), v(t) {}

string Word::get_word() const {
	return word;
}

unsigned int Word::get_matches(const vector<string>& t) const {
	unsigned int matches = 0;
	unsigned int v_count = 0;
	unsigned int t_count = 0;
	while(v_count < v.size() && t_count < t.size()) {
		if(v[v_count] == t[t_count]) {
			matches++;
			v_count++;
			t_count++;
		} else if(v[v_count] > t[t_count]) {
			t_count++;
		} else {
			v_count++;
		}
	}
	return matches;
}
