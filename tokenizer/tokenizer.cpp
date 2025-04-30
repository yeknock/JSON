#include "../main.h"


void	print(std::vector<Token> t_list)
{
	std::size_t	len = t_list.size();

	for (size_t i = 0; i < len; i++)
	{
		std::cout << t_list[i].get_value() << " -> ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Capacity is: " << t_list.capacity() << std::endl;
}




std::vector<Token>	tokenization(const std::string& raw_line)
{
	std::size_t			length_of_raw_line = raw_line.length();
	int					current_index = 0;
	std::vector<Token>	t_list;

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
		else
			current_index++;
	}

	return t_list;
}