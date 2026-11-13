# JSON Parser in C++

A JSON parser written from scratch in **C++17**, with no external libraries.
It reads a JSON file and turns it into a list of typed **tokens**, the first stage of
any parser or compiler. The parsing stage, which builds objects and arrays from those
tokens, is in progress.

## Status

| Stage | State |
|---|---|
| Lexer (tokenizer) | ✅ Done |
| Parser (building objects and arrays from tokens) | 🚧 In progress |

## Features

- **Single pass, character by character.** The lexer looks at each character once
  and decides which kind of token starts there.
- **13 token types:**

  | Token | Example |
  |---|---|
  | `OpenBrace` / `CloseBrace` | `{` `}` |
  | `OpenBracket` / `CloseBracket` | `[` `]` |
  | `Colon` / `Comma` | `:` `,` |
  | `String` | `"name"` |
  | `Number` | `25`, `-3.14`, `1e10` |
  | `True` / `False` / `Null` | `true` `false` `null` |
  | `EndOfFile` | added after the last token |
  | `Invalid` | anything that is not valid JSON |

- **Numbers follow the JSON specification:**
  - an optional minus sign
  - no leading zeros (`012` is rejected, `0` and `0.5` are fine)
  - an optional fraction, which must have digits after the dot (`1.` is rejected)
  - an optional exponent, `e` or `E` with an optional sign, which must have digits (`1e` is rejected)
  - no letters straight after a number (`12abc` is rejected)
- **Errors are tokens, not crashes.** Malformed input becomes an `Invalid` token
  holding the bad text, so the parser can report exactly what went wrong.

## Example

Input (`data.json`):

```json
{
  "name": "Yenok",
  "age": 25,
  "pi": -3.14e2,
  "skills": ["C++", "Python"],
  "active": true,
  "manager": null,
  "bad": 012
}
```

Output (shortened):

```
1) Value: {, TokenType: 0
2) Value: name, TokenType: 9
3) Value: :, TokenType: 4
4) Value: Yenok, TokenType: 9
...
12) Value: -3.14e2, TokenType: 10
...
16) Value: [, TokenType: 2
17) Value: C++, TokenType: 9
...
24) Value: true, TokenType: 6
...
28) Value: null, TokenType: 8
...
32) Value: 012, TokenType: 12
33) Value: }, TokenType: 1
34) Value: , TokenType: 11
```

`TokenType` is printed as the number of the token type in the `TokenType` enum in
[`tokenizer/tokenizer.h`](tokenizer/tokenizer.h): `9` is `String`, `10` is `Number`,
`12` is `Invalid` and `11` is `EndOfFile`. Note that `012` became an `Invalid` token
because of its leading zero.

## Build and run

You need CMake 3.10 or newer and a C++17 compiler (GCC or Clang).

```bash
git clone https://github.com/yeknock/JSON.git
cd JSON
mkdir -p build && cd build
cmake ..
make
./json_parser
```

The program reads `../data.json`, relative to where you run it, so run it from the
`build` folder. Edit `data.json` to try your own input.

## Project structure

```
.
├── main.cpp                  # reads data.json line by line, runs the lexer, prints tokens
├── main.h                    # shared includes
├── data.json                 # sample input
├── CMakeLists.txt
├── tokenizer/
│   ├── tokenizer.h           # TokenType enum, Token class, function declarations
│   ├── tokenizer.cpp         # main loop: picks the right function for each character
│   ├── brace_bracket_tokenization.cpp
│   ├── comma_colon_tokenization.cpp
│   ├── string_tokenization.cpp
│   ├── number_tokenization.cpp
│   ├── tr_fls_null_tokenization.cpp   # true / false / null
│   └── eof_invalid_tokenization.cpp
└── parser/                   # in progress
```

## How it works

1. `main.cpp` reads `data.json` one line at a time.
2. For each line, `tokenization()` walks through the characters. The first character
   of each token decides which function handles it: `{` goes to the brace function,
   `"` to the string function, a digit or `-` to the number function, `t`, `f` or `n`
   to the literal function, and so on. Whitespace is skipped.
3. Each function reads the whole token, adds it to the token list, and moves the
   position past it.
4. After the last line, an `EndOfFile` token is added so the parser knows where the
   input ends.

## Roadmap

- [ ] Recursive-descent parser that builds objects and arrays from the token list
- [ ] Escape sequences in strings (`\"`, `\\`, `\n`, `\uXXXX`)
- [ ] A clear error for strings with no closing quote
- [ ] Error messages with line and column numbers
- [ ] Print token type names instead of numbers
- [ ] Tests against [JSONTestSuite](https://github.com/nst/JSONTestSuite)

## Author

**Yenok Martirosyan**, [GitHub](https://github.com/yeknock) ·
[LinkedIn](https://www.linkedin.com/in/yenokmartirosyan)
