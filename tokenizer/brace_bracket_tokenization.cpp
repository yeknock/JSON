#include "../main.h"

void	open_brace_tokenization(std::vector<Token>& t_list, const std::string& raw_str, int *index)
{
	if (raw_str[*index] == '{')
	{
		Token new_token;
		new_token.set(TokenType::OpenBrace, "{");
		t_list.push_back(new_token);
		(*index)++;
	}
}


void	close_brace_tokenization(std::vector<Token>& t_list, const std::string& raw_str, int *index)
{
	if (raw_str[*index] == '}')
	{
		Token new_token;
		new_token.set(TokenType::CloseBrace, "}");
		t_list.push_back(new_token);
		(*index)++;
	}
}


void	open_bracket_tokenization(std::vector<Token>& t_list, const std::string& raw_str, int *index)
{
	if (raw_str[*index] == '[')
	{
		Token new_token;
		new_token.set(TokenType::OpenBracket, "[");
		t_list.push_back(new_token);
		(*index)++;
	}
}


void	close_bracket_tokenization(std::vector<Token>& t_list, const std::string& raw_str, int *index)
{
	if (raw_str[*index] == ']')
	{
		Token new_token;
		new_token.set(TokenType::CloseBracket, "]");
		t_list.push_back(new_token);
		(*index)++;
	}
}