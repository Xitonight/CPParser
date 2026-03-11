#include <cstddef>
#include <string>

namespace lexer {

enum class TokenType {
  Number,
  Plus,
  Minus,
  Star,
  Slash,
  LParenthesis,
  RParenthesis,
  End
};

class Token {
  TokenType type_;
  std::string lexeme_;
  std::size_t position_;

public:
  Token(TokenType type) : type_{type} {}
};

class Lexer {
  std::string source_;
  std::size_t current_ = 0;
  std::size_t line_ = 1;

  bool isAtEnd() const;
  char peek() const;
  char advance();
  bool match(char expected);

public:
  Lexer(std::string source) : source_{source} {};

  Token nextToken();
};

} // namespace lexer
