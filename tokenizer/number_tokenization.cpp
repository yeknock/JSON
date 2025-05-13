#include "../main.h"


void	number_tokenization(std::vector<Token>& t_list, const std::string& raw_str, int* index)
{
	std::size_t i = *index;
	std::size_t length = raw_str.length();
	std::string number;

	std::size_t start = i;

	// Optional minus sign
	if (i < length && raw_str[i] == '-')
		number += raw_str[i++];

	// Check for at least one digit
	if (i < length && isdigit(raw_str[i])) {
		if (raw_str[i] == '0') {
			number += raw_str[i++];
			// leading 0 must not be followed by more digits
			if (i < length && isdigit(raw_str[i])) {
				// Invalid number: leading 0 followed by digit
				while (i < length && isalnum(raw_str[i])) number += raw_str[i++];
				t_list.push_back(Token(TokenType::Invalid, number));
				*index = i;
				return;
			}
		} else {
			while (i < length && isdigit(raw_str[i])) {
				number += raw_str[i++];
			}
		}
	} else {
		// Invalid number: does not start with a digit
		number += raw_str[i];
		t_list.push_back(Token(TokenType::Invalid, number));
		*index = ++i;
		return;
	}

	// Optional fractional part
	if (i < length && raw_str[i] == '.') {
		number += raw_str[i++];
		if (i >= length || !isdigit(raw_str[i])) {
			// Invalid number: dot not followed by digits
			t_list.push_back(Token(TokenType::Invalid, number));
			*index = i;
			return;
		}
		while (i < length && isdigit(raw_str[i])) {
			number += raw_str[i++];
		}
	}

	// Optional exponent
	if (i < length && (raw_str[i] == 'e' || raw_str[i] == 'E')) {
		number += raw_str[i++];
		if (i < length && (raw_str[i] == '+' || raw_str[i] == '-')) {
			number += raw_str[i++];
		}
		if (i >= length || !isdigit(raw_str[i])) {
			// Invalid number: 'e' not followed by digits
			t_list.push_back(Token(TokenType::Invalid, number));
			*index = i;
			return;
		}
		while (i < length && isdigit(raw_str[i])) {
			number += raw_str[i++];
		}
	}

	// Check if number is immediately followed by invalid alphanumeric characters
	if (i < length && (isalpha(raw_str[i]) || raw_str[i] == '_')) {
		while (i < length && (isalnum(raw_str[i]) || raw_str[i] == '_')) {
			number += raw_str[i++];
		}
		t_list.push_back(Token(TokenType::Invalid, number));
		*index = i;
		return;
	}

	// Valid number
	t_list.push_back(Token(TokenType::Number, number));
	*index = i;
}

