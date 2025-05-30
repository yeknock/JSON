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


void		check_invalid_tokens(const std::vector<Token>& t_list);
JsonValue	parser(const std::vector<Token>& t_list);
JsonValue	parseValue(const std::vector<Token>& t_list, int *index);
JsonValue	parseObject(const std::vector<Token>& t_list, int *index);
JsonValue	parseArray(const std::vector<Token>& t_list, int *index);
JsonValue	parseString(const std::vector<Token>& t_list, int *index);
JsonValue	parseNumber(const std::vector<Token>& t_list, int *index);
JsonValue	parseLiterals(const std::vector<Token>& t_list, int *index);