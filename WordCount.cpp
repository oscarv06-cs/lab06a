// WordCount.cpp

#include "WordCount.h"

using namespace std;

// Default constructor
WordCount::WordCount() {}

// Simple hash function. Do not modify.
size_t WordCount::hash(std::string word) const {
	size_t accumulator = 0;
	for (size_t i = 0; i < word.size(); i++) {
		accumulator += word.at(i);
	}
	return accumulator % CAPACITY;
}

int WordCount::getTotalWords() const {
	total = 0; 
	for (size_t i = 0; i < CAPACITY; i++){
		for (size_t j = 0; j < table[i].size(); j++){
			total = total + table[i][j].second;
		}
	}
	return total;
}

int WordCount::getNumUniqueWords() const {
	int getTotalWords = 0;
    for (size_t i = 0; i < CAPACITY; i++) {
        total = table + table[i].size();
    }
	return total;
}

int WordCount::getWordCount(std::string word) const {
	string val = makeValidWord(word);
    if (val == "") {
        return 0;
    }
    size_t index = hash(val);
    const vector<pair<string,int>> &bucket = table[index];
    for (size_t i = 0; i < bucket.size(); i++) {
        if (bucket[i].first == val) {
            return bucket[i].second;
        }
    }
    return 0;
}
	
int WordCount::incrWordCount(std::string word) {
	string val = makeValidWord(word);
    if (val == "") {
        return 0;
    }

    size_t index = hash(val);
    vector<pair<string,int>> &bucket = table[index];
    for (size_t i = 0; i < bucket.size(); ++i) {
        if (bucket[i].first == val) {
            bucket[i].second += 1;
            return bucket[i].second;
        }
    }
	bucket.push_back(make_pair(val, 1));
	return 1;
}

int WordCount::decrWordCount(std::string word) {
	// STUB
	return -2;
}

bool WordCount::isWordChar(char c) {
	// STUB
	return false;
}

std::string WordCount::makeValidWord(std::string word) {
	// STUB
	return "";
}
