#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>

class Tokenizer {
public:
    Tokenizer(const std::string& filename) {
        inputFile.open(filename);
        if (inputFile.is_open()) {
            std::string word;
            while (inputFile >> word) {
                // Simple tokenization: remove punctuation and convert to lowercase
                std::string cleaned_word;
                for (char c : word) {
                    if (std::isalnum(c)) { // Keep only alphanumeric characters
                        cleaned_word += std::tolower(c);
                    }
                }
                if (!cleaned_word.empty()) {
                    tokens.push_back(cleaned_word);
                }
            }
        }
        current_token_index = 0;
    }

    bool hasNext() {
        return current_token_index < tokens.size();
    }

    std::string next() {
        if (hasNext()) {
            return tokens[current_token_index++];
        }
        return ""; // Or throw an exception
    }

    void close() {
        if (inputFile.is_open()) {
            inputFile.close();
        }
    }

private:
    std::ifstream inputFile;
    std::vector<std::string> tokens;
    size_t current_token_index;
};


#endif // TOKENIZER_H
