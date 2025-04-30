#include "main.h"

int main()
{
    const std::string raw_text = " {{{ \"name\": \"Yenok\", \"age\": 22 }  ";

    std::vector<Token> tokens_list = tokenization(raw_text);
    print(tokens_list);

    return 0;
}