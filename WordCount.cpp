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
    std::vector<int> counts;
	for (size_t i = 0; i < CAPACITY; i++){
		for (size_t i = 0; j < table[i].size(); j++){
			counts.push_back(table[i][j].second);
		}  
	}
    int todal = 0;
	for (size_t k = 0; k < counts.size(); k++){
		total += counts[k];
	}
}

int WordCount::getNumUniqueWords() const {
    // STUB
    return -1;
}

int WordCount::getWordCount(std::string word) const {
    // STUB
    return -1;
}

int WordCount::incrWordCount(std::string word) {
    // STUB
    return -1;
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
