#include "../main.h"

void	tr_fls_tokenization(std::vector<Token>& t_list, const std::string& raw_str, int *index)
{
	std::string cut_true = raw_str.substr(*index, 4);   // cut "true" from the raw_str
	std::string cut_false = raw_str.substr(*index, 5);  // cut "false" from the raw_str
	Token		new_token;

	if (cut_false == "false")
	{
		new_token.set(TokenType::False, cut_false);
		t_list.push_back(new_token);
		(*index) += 5;
	}
	if (cut_true == "true")
	{
		new_token.set(TokenType::True, cut_true);
		t_list.push_back(new_token);
		(*index) += 4;
	}
}