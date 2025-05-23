#include "main.h"

int main()
{
	std::ifstream file("../data.json");

	if (!file.is_open())
	{
		std::cerr << "Failed to open file!" << std::endl;
		return 1;
	}

	std::string raw_text;
	std::vector<Token> tokens_list;

	while (std::getline(file, raw_text))
		tokenization(tokens_list, raw_text);

	eof_tokenization(tokens_list); // at the last part of the Token list we add EOF token
	print(tokens_list);

	// Here we are starting to parse the token list
	parser(tokens_list);

	file.close();
	return 0;
}