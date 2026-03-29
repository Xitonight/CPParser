#include <ostream>
#include <string>
#include <string_view>

namespace lexer {

enum class TokenType {
  // Single char tokens
  LEFT_PAREN,
  RIGHT_PAREN,
  LEFT_SQUARE_BRACKET,
  RIGHT_SQUARE_BRACKET,
  LEFT_CURLY_BRACKET,
  RIGHT_CURLY_BRACKET,
  SLASH,
  STAR,
  SEMICOLON,

  // One or two char tokens
  EQUAL,
  EQUAL_EQUAL,
  BANG,
  NOT_EQUAL,
  GREATER_THAN,
  GREATER_EQUAL,
  LESS_THAN,
  LESS_EQUAL,
  PLUS,
  INCREMENT,
  MINUS,
  DECREMENT,

  // Literals
  NUMBER,
  STRING,

  END_OF_FILE
};

struct TokenTypeInfo {
  std::string name;
  std::string lexeme;
};

extern TokenTypeInfo tokenTypeInfo[];

std::ostream &operator<<(std::ostream &out, TokenType const &type);

class Token {
public:
  Token() = default;
  Token(TokenType type, std::string_view lexeme, size_t line, size_t column)
      : type_{type}, lexeme_{lexeme}, line_{line}, column_{column} {}

  TokenType type() const { return type_; }
  std::string const &lexeme() const { return lexeme_; }
  size_t line() const { return line_; }
  size_t column() const { return column_; }

private:
  TokenType type_;
  std::string lexeme_;
  size_t line_;
  size_t column_;
};

std::ostream &operator<<(std::ostream &out, Token const &token);
std::string lexemeForType(TokenType type);
} // namespace lexer
