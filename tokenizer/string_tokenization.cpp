#include "../main.h"

void	string_tokenization(std::vector<Token>& t_list, const std::string& raw_str, int *index)
{
	std::string	appended_string;
	int			lastIndexOfString;
	int			firstIndexOfString = *index + 1;
	int			i = *index + 1;
	Token		new_token;

	while(raw_str[i] != '"') i++;

	lastIndexOfString = i; // getting the last index of the appending string
	appended_string = raw_str.substr(firstIndexOfString, lastIndexOfString - firstIndexOfString); // find appending string in the raw_str

	new_token.set(TokenType::String, appended_string);
	t_list.push_back(new_token);
	*index += lastIndexOfString - firstIndexOfString + 2; // moving index to the next of the second "
}