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
	{
		tokenization(tokens_list, raw_text);
	}

	print(tokens_list);

	file.close();
	return 0;
}