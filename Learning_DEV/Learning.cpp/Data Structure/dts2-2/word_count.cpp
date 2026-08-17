#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include "tokenizer.h"

using namespace std;

void printWord(string filename);
void printUniqueWords1(string filename);
void printUniqueWords2(string filename);
void printUniqueWords3(string filename);
void printUniqueWords4(string filename);


int main() {
    string filename = "test.txt";

    printWord(filename);
    printUniqueWords1(filename);  // 2 faster than 1
    printUniqueWords2(filename);
    printUniqueWords3(filename);
    printUniqueWords4(filename);  // The Fastest

    return 0;
}


bool search(string words[], int n, string w) {
    for (int i = 0; i < n; i++) {
        if (words[i] == w) return true;
    }
    return false;
}


void printWord(string filename) {
    
    int n = 0;

    Tokenizer tokenizer(filename);
    while (tokenizer.hasNext()) {
        string token = tokenizer.next();
        n++;
    }
    tokenizer.close();
    cout << "A total of " << n << " words" << endl;
}


void printUniqueWords1(string filename) {
    
    string words[10000];
    int n = 0;

    Tokenizer tokenizer(filename);
        while(tokenizer.hasNext()) {
            string token = tokenizer.next();
            if (!search(words,n,token)) words[n++] = token;
        }
        tokenizer.close();
        cout << "A total of " << n << " words" << endl;
    }


void printUniqueWords2(string filename) {
    
    int cap = 1;
    string *words;
    words = new string[cap];  // * = declared
    int n = 0;
    
    Tokenizer tokenizer(filename);
    while(tokenizer.hasNext()) {
        string token = tokenizer.next();
        if (!search(words,n,token)) {
            if (n == cap) {
                string *a = new string[2*cap];
                for (int i = 0; i < n; i++) a[i] =  words[i];
                delete[] words;
                words = a;
                cap *= 2;
            }
            words[n++] = token;
        }
    }
    tokenizer.close();
    cout << "A total of " << n << " words" << endl;
}


void printUniqueWords3(string filename) {
    
    vector<string> words;       // vary according to n(data)
    
    Tokenizer tokenizer(filename);
    while (tokenizer.hasNext()) {
        string token = tokenizer.next();
        if (words.end() == find(words.begin(), words.end(), token))
        words.push_back(token);
    }
    tokenizer.close();
    cout << "A total of " << words.size() << " words" << endl;
}


void printUniqueWords4(string filename) {
    
    set<string> words;      // vary according to log(data)
    
    Tokenizer tokenizer(filename);
    while (tokenizer.hasNext()) {
        string token = tokenizer.next();
        if (words.end() == words.find(token))
            words.insert(token);
    }
    tokenizer.close();
    cout << "A total of " << words.size() << " words" << endl;
}