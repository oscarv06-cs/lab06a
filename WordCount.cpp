// WordCount.cpp

#include "WordCount.h"
#include <cctype> //include for iswordchar func
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
    int total = 0;
	for (size_t i = 0; i < CAPACITY; i++){
		for (size_t j = 0; j < table[i].size(); j++){
			total += table[i][j].second;
		}  
	}
	return total;
}

int WordCount::getNumUniqueWords() const {
    int total = 0;
	for (size_t i = 0; i < CAPACITY; i++){
		total += table[i].size();  
	}
	return total;
}

int WordCount::getWordCount(std::string word) const {
    std::string validWord = makeValidWord(word); //making word valid for the test cases

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
    return isalpha(c);
}

std::string WordCount::makeValidWord(std::string word) {
    // STUB
    return "";
}
