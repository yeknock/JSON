#include "../main.h"


void	print(std::vector<Token> t_list)
{
	std::size_t	len = t_list.size();

	for (size_t i = 0; i < len; i++)
	{
		std::cout << i + 1 << ") Value: " << t_list[i].get_value() << ", TokenType: " << int(t_list[i].get_type()) << "\n";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Capacity is: " << t_list.capacity() << std::endl;
}



void	tokenization(std::vector<Token>& t_list, std::string& raw_line)
{
	std::size_t			length_of_raw_line = raw_line.length();
	int					current_index = 0;

	while (current_index < length_of_raw_line)
	{
		if (raw_line[current_index] == '{')
			open_brace_tokenization(t_list, raw_line, &current_index);
		else if (raw_line[current_index] == '}')
			close_brace_tokenization(t_list, raw_line, &current_index);
		else if (raw_line[current_index] == '[')
			open_bracket_tokenization(t_list, raw_line, &current_index);
		else if (raw_line[current_index] == ']')
			close_bracket_tokenization(t_list, raw_line, &current_index);
		else if (raw_line[current_index] == ',')
			comma_tokenization(t_list, raw_line, &current_index);
		else if (raw_line[current_index] == ':')
			colon_tokenization(t_list, raw_line, &current_index);
		else if (raw_line[current_index] == '"')
			string_tokenization(t_list, raw_line, &current_index);
		else if (std::isdigit(raw_line[current_index]) || raw_line[current_index] == '-')
			number_tokenization(t_list, raw_line, &current_index);
		else if (raw_line[current_index] == 'f' || raw_line[current_index] == 't' || raw_line[current_index] == 'n')
			tr_fls_null_tokenization(t_list, raw_line, &current_index);
		else if (std::isspace(raw_line[current_index]))
			current_index++;
		else
		{
			std::string invalid_char(1, raw_line[current_index]);
			t_list.push_back(Token(TokenType::Invalid, invalid_char));
			current_index++;
		}
	}
}