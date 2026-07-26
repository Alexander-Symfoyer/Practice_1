#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <fstream>
#include <cctype>

class Tokenizer {
private:
    std::ifstream file;
    std::string currentLine;
    size_t linePos;
    std::string currentToken;
    bool hasToken;
    
    bool isWordChar(char c);
    void readNextToken();

public:
    // Constructor - เปิดไฟล์
    Tokenizer(const std::string& filename);
    
    // Destructor - ปิดไฟล์
    ~Tokenizer();
    
    // ตรวจสอบว่ามี token ถัดไปหรือไม่
    bool hasNext();
    
    // อ่าน token ถัดไป
    std::string next();
    
    // ปิดไฟล์
    void close();
};

#endif // TOKENIZER_H