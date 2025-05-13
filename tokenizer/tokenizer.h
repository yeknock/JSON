#pragma once


enum class TokenType {
	OpenBrace,      // {										+
	CloseBrace,     // }										+
	OpenBracket,    // [										+
	CloseBracket,   // ]										+
	Colon,          // :										+
	Comma,          // ,										+
	True,           // true										+
	False,          // false									+
	Null,           // null										+
	String,         // "..."									+
	Number,         // 123, -3.14, 1e10							+
	EndOfFile,      // End of input								-
	Invalid         // For unexpected characters or tokens		-
};


class Token
{
	TokenType	type;
	std::string value;

public:
	Token	(): type(TokenType::Invalid), value("") {  }
	Token	(TokenType type_, std::string value_ = ""): type(type_), value(value_) {  }

	void	set(TokenType type_, std::string value_)
	{
		type = type_;
		value = value_;
	}
	TokenType	get_type() { return type; }
	std::string get_value() { return value; }
};



void				tokenization(std::vector<Token>& t_list,std::string& raw_str);
void				print(std::vector<Token> t_list);
void				open_brace_tokenization(std::vector<Token>& t_list, const std::string& raw_str, int *index);
void				close_brace_tokenization(std::vector<Token>& t_list, const std::string& raw_str, int *index);
void				open_bracket_tokenization(std::vector<Token>& t_list, const std::string& raw_str, int *index);
void				close_bracket_tokenization(std::vector<Token>& t_list, const std::string& raw_str, int *index);
void				comma_tokenization(std::vector<Token>& t_list, const std::string& raw_str, int *index);
void				colon_tokenization(std::vector<Token>& t_list, const std::string& raw_str, int *index);
void				string_tokenization(std::vector<Token>& t_list, const std::string& raw_str, int *index);
void				number_tokenization(std::vector<Token>& t_list, const std::string& raw_str, int *index);
void				tr_fls_null_tokenization(std::vector<Token>& t_list, const std::string& raw_str, int *index);
void				eof_tokenization(std::vector<Token>& t_list);