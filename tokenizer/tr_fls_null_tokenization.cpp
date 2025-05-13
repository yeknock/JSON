#include "../main.h"

void	tr_fls_null_tokenization(std::vector<Token>& t_list, const std::string& raw_str, int *index)
{
	std::string cut_true_null = raw_str.substr(*index, 4);   // cut "true" or "null"(because they have the same length, so we don't have to have another variable for "null") from the raw_str
	std::string cut_false = raw_str.substr(*index, 5);  // cut "false" from the raw_str
	Token		new_token;

	if (cut_false == "false")
	{
		new_token.set(TokenType::False, cut_false);
		t_list.push_back(new_token);
		(*index) += 5;
		return;
	}
	if (cut_true_null == "true")
	{
		new_token.set(TokenType::True, cut_true_null);
		t_list.push_back(new_token);
		(*index) += 4;
		return;
	}
	if (cut_true_null == "null")
	{
		new_token.set(TokenType::Null, cut_true_null);
		t_list.push_back(new_token);
		(*index) += 4;
		return;
	}

	std::string invalid_char(1, raw_str[*index]);
	t_list.push_back(Token(TokenType::Invalid, invalid_char));
	(*index)++;
}