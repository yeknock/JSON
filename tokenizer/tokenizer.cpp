#include "../main.h"

void tokenization(const std::string raw_line)
{
    std::size_t length_of_raw_line = raw_line.length();
    unsigned int count = 0;
    for (std::size_t i = 0 ; i < length_of_raw_line ; i++)
    {
        if (raw_line[i] == ' ')
            count++;
    }

    std::cout << count << std::endl;
}