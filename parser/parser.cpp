#include "../main.h"

void	check_invalid_tokens(std::vector<Token>& t_list)
{
	for (size_t i = 0; i < t_list.size(); i++)
	{
		if (t_list[i].get_type() == TokenType::Invalid)
			throw JsonParseException("Found an Invalid Token!");
	}
}



void    parser(std::vector<Token>& t_list)
{
	try
	{
		check_invalid_tokens(t_list);
	}
	catch (const JsonParseException& e)
	{
		std::cerr << e.what() << std::endl;
	}
}