#include "../main.h"


void    number_tokenization(std::vector<Token>& t_list, const std::string& raw_str, int* index)
{
	std::size_t i = *index;
	std::size_t length = raw_str.length();
	std::string number;

	// Checking if the number is negative or not, if it is, we're adding - in front of the number
	if (i < length && raw_str[i] == '-')
		number += raw_str[i++];

	// Checking if the number is integer or not
	if (i < length && isdigit(raw_str[i])) {
		if (raw_str[i] == '0') {
			number += raw_str[i++];
			// leading 0 must not be followed by more digits
			if (i < length && isdigit(raw_str[i]))
				return;
		} else {
			while (i < length && isdigit(raw_str[i])) {
				number += raw_str[i++];
			}
		}
	} else {
		return;
	}

	// Checking if the number is fractional or not
	if (i < length && raw_str[i] == '.') {
		number += raw_str[i++];
		if (i >= length || !isdigit(raw_str[i]))
			return; // Invalid number, no digits after '.'
		while (i < length && isdigit(raw_str[i])) {
			number += raw_str[i++];
		}
	}

	// Exponential or not
	if (i < length && (raw_str[i] == 'e' || raw_str[i] == 'E')) {
		number += raw_str[i++];
		if (i < length && (raw_str[i] == '+' || raw_str[i] == '-')) {
			number += raw_str[i++];
		}
		if (i >= length || !isdigit(raw_str[i]))
			return;
		while (i < length && isdigit(raw_str[i])) {
			number += raw_str[i++];
		}
	}

	
	Token token;
	token.set(TokenType::Number, number);
	t_list.push_back(token);
	*index = i;
}
