#include "../main.h"

void	check_invalid_tokens(const std::vector<Token>& t_list)
{
	for (size_t i = 0; i < t_list.size(); i++)
	{
		if (t_list[i].get_type() == TokenType::Invalid)
			throw JsonParseException("Found an Invalid Token!");
	}
}


JsonValue	parseObject(const std::vector<Token>& t_list, int *index)
{
	JsonValue obj;
	obj.type = JsonType::Object;
	(*index)++;
	
	while (t_list[*index].get_type() != TokenType::CloseBrace) // waiting until close brace
	{
		
	}
}





JsonValue	parseValue(const std::vector<Token>& t_list, int *index)
{
	if (*index >= t_list.size())
		throw JsonParseException("Index >= Size of token's list!");

	if (t_list[*index].get_type() == TokenType::OpenBrace)
		return parseObject(t_list, index);
	else if (t_list[*index].get_type() == TokenType::OpenBracket)
		return parseArray(t_list, index);
	else if (t_list[*index].get_type() == TokenType::String)
		return parseString(t_list, index);
	else if (t_list[*index].get_type() == TokenType::Number)
		return parseNumber(t_list, index);
	else if (t_list[*index].get_type() == TokenType::True || \
				t_list[*index].get_type() == TokenType::False || \
					t_list[*index].get_type() == TokenType::Null)
		return parseLiterals(t_list, index);
	else
		throw JsonParseException("Invalid case occured during parsing!");
}




JsonValue parser(const std::vector<Token>& t_list)
{
	int 		index = 0;
	JsonValue   root;
	root = parseValue(t_list, &index);

	if (index != t_list.size())
		throw JsonParseException("Extra tokens after valid JSON");

	return root;
}
