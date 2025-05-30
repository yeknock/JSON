#include "../main.h"

void	eof_tokenization(std::vector<Token>& t_list)
{
	t_list.push_back(Token(TokenType::EndOfFile, ""));
}
