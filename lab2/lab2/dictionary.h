#ifndef DICTIONARY_H
#define DICTIONARY_H

#define word_max_length 25

#include <string>
#include <vector>
#include <unordered_set>
#include "word.h"

class Dictionary {
public:
	Dictionary();
	bool contains(const std::string& word) const;
	std::vector<std::string> get_suggestions(const std::string& word) const;

private:
	std::vector<Word> words[word_max_length];
	void add_trigram_suggestions(std::vector<std::string>& suggestions, const std::string& word) const;
	void rank_suggestions(std::vector<std::string>& suggestions, const std::string& word) const;
	void trim_suggestions(std::vector<std::string>& suggestions) const;
	int distance(const std::string& w1, const std::string& w2) const;
};

#endif
