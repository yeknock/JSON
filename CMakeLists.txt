cmake_minimum_required(VERSION 3.10)
project(JsonProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/parser
    ${CMAKE_CURRENT_SOURCE_DIR}/tokenizer
)


set(SOURCES
    main.cpp
    parser/parser.cpp
    tokenizer/tokenizer.cpp
    tokenizer/brace_bracket_tokenization.cpp
    tokenizer/comma_colon_tokenization.cpp
    tokenizer/string_tokenization.cpp
    tokenizer/number_tokenization.cpp
    tokenizer/tr_fls_null_tokenization.cpp
    tokenizer/eof_invalid_tokenization.cpp
    parser/parser.cpp
)

add_executable(json_parser ${SOURCES})
