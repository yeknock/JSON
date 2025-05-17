#pragma once


enum class JsonType
{
	Null,
	Boolean,
	Number,
	String,
	Array,
	Object
};


struct JsonValue
{
	JsonType type;
	std::string stringValue;
	double numberValue;
	bool boolValue;
	std::vector<JsonValue> arrayValue;
	std::map<std::string, JsonValue> objectValue;
};



class JsonParseException : public std::runtime_error {
public:
    JsonParseException(const std::string& message) 
		: std::runtime_error("JSON Parse Error: " + message) {}
};


void	parser(std::vector<Token>& t_list);
void	check_invalid_tokens(std::vector<Token>& t_list);