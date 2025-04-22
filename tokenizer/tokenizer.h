#pragma once

#include <string>

enum class TokenType {
    LeftBrace,      // {
    RightBrace,     // }
    LeftBracket,    // [
    RightBracket,   // ]
    Colon,          // :
    Comma,          // ,
    True,           // true
    False,          // false
    Null,           // null
    String,         // "..."
    Number,         // 123, -3.14, 1e10
    EndOfFile,      // End of input
    Invalid         // For unexpected characters or tokens
};


struct Token
{
    TokenType type;
    std::string value;
    Token* next = nullptr;
    Token* prev = nullptr;

    // Constructor
    Token (TokenType type_, const std::string& value_ = ""): type(type_), value(value_), next(nullptr), prev(nullptr) {  }
};



void tokenization(const std::string raw_str);