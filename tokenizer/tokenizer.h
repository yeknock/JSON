#pragma once

enum class TokenType {
    // Structural
    LeftBrace,      // {
    RightBrace,     // }
    LeftBracket,    // [
    RightBracket,   // ]
    Colon,          // :
    Comma,          // ,

    // Literals
    True,           // true
    False,          // false
    Null,           // null

    // Values
    String,         // "..."
    Number,         // 123, -3.14, 1e10

    // Control
    EndOfFile,      // End of input
    Invalid         // For unexpected characters or tokens
};