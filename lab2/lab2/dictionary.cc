#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "word.h"
#include "dictionary.h"

using namespace std;

Dictionary::Dictionary() {
	ifstream in("words.txt");
	string word;
	string trig;
	int number_of_words = 0;
	vector<string> trigrams;
	while(in >> word) {
		trigrams.clear();
		in >> number_of_words;
		for(int i = 0; i < number_of_words; i++) {
			in >> trig;
			trigrams.push_back(trig);
		}
		if(word.length() < word_max_length) {
			words[word.size() - 1].push_back(Word(word, trigrams));
		}
	}
}

bool Dictionary::contains(const string& word) const {
	if(word.size() > word_max_length) {
		return false;
	}
	vector<Word> temp = words[word.size() - 1];

	for(unsigned int i = 0; i < temp.size(); i++) {
		if(temp[i].get_word() == word){
			return true;
		}
	}
	return false;
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<std::string> suggestions;
	if(word.size() <= word_max_length) {
		add_trigram_suggestions(suggestions, word);
		rank_suggestions(suggestions, word);
		trim_suggestions(suggestions);
	}
		return suggestions;
}

void Dictionary::add_trigram_suggestions(vector<std::string>& suggestions, const string& word) const {
	vector<string> v;
	string trigram;
	if(word.length() <= 3) {
		// do nothing
	} else {		
		for(unsigned int i = 0; i < word.length() - 2; i++) {
			trigram = word.substr(i, 3);
			v.push_back(trigram);
		}
	}
	sort( v.begin(), v.end());

	int length = word.size();
	unsigned int matches = 0;

	for(int i = length - 2; i <= length; i++) {
		if(word.size() == 1) {
			i++;
		}
		if(word.size() == word_max_length && i == length - 1) {
			break;
		}
		for(unsigned int j = 0; j < words[i].size(); j++) {
				matches = words[i][j].get_matches(v);
				if(matches >= v.size()/2) {
					suggestions.push_back(words[i][j].get_word());
				}
		}
	}
}

void Dictionary::rank_suggestions(vector<std::string>& suggestions, const string& word) const {
	vector<pair<int, string>> pairs;
	int dist;
	for(unsigned int i= 0; i<suggestions.size(); i++){
		dist = distance(suggestions[i], word);
		pairs.push_back(make_pair(dist, suggestions[i]));
	}
	sort(pairs.begin(), pairs.end());
	for(unsigned int i = 0; i< pairs.size(); i++){
		suggestions[i] = pairs[i].second;
	}
}


int Dictionary::distance(const string& w1, const string& w2) const {
	int d[26][26];

	for(unsigned int i= 0; i<=w1.size(); i++){
		for(unsigned int j=0; j<=w2.size(); j++){
			if(i == 0){
				d[i][j] = j;
			}else if(j== 0){
				d[i][j] = i;
			} else{
				int a;
				if (w1[i-1] == w2[j-1]) {
					a = 0;
				} else {
					a = 1;
				}
				d[i][j] = min(d[i-1][j-1]+a, min(d[i-1][j]+1 , d[i][j-1]+1));
			}
		}
	}
	return d[w1.length()][ w2.length()];
}

void Dictionary::trim_suggestions(std::vector<std::string>& suggestions) const {
	suggestions.resize(5);
}
