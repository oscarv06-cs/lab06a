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
    for (size_t i = 0; i < CAPACITY; i++) {
        total += table[i].size();
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
	 string cleaned = makeValidWord(word);
    if (cleaned == ""){
        return -1;
	}
    size_t index = hash(cleaned);
    auto &bucket = table[index];
  	for (size_t i = 0; i < bucket.size(); i++) {
        if (bucket[i].first == cleaned) {
            if (bucket[i].second > 1) {
                bucket[i].second--;
                return bucket[i].second;
            } 
			else {
                bucket.erase(bucket.begin() + i);
                return 0;
            }
        }
    }
    return -1;
}

bool WordCount::isWordChar(char c) {
	// STUB
	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

std::string WordCount::makeValidWord(std::string word) {
	if (word.empty()){
        return "";
	}

    size_t left = 0, right = word.size() - 1;

    while (left < word.size() && !isWordChar(word[left])){
        left++;
}
    if (left == word.size()){
        return "";
	}
    while (right > left && !isWordChar(word[right])){
        right--;
	}
    string out;
    out.reserve(right - left + 1);

    for (size_t i = left; i <= right; i++) {
        char c = word[i];

        if (isWordChar(c)) {
            if (c >= 'A' && c <= 'Z')
                c = c - 'A' + 'a';
            out = out + c;
        } else if (c == '-' || c == '\'') {
            out = out + c;
        }
    }
    return out;
}
