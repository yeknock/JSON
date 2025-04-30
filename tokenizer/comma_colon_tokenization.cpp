#include "../main.h"

void	comma_tokenization(std::vector<Token>& t_list, const std::string& raw_str, int *index)
{
    if (raw_str[*index] == ',')
	{
		Token new_token;
		new_token.set(TokenType::Comma, ",");
		t_list.push_back(new_token);
		(*index)++;
	}
}


void	colon_tokenization(std::vector<Token>& t_list, const std::string& raw_str, int *index)
{
    if (raw_str[*index] == ':')
	{
		Token new_token;
		new_token.set(TokenType::Colon, ":");
		t_list.push_back(new_token);
		(*index)++;
	}
}