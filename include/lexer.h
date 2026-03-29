#include <cstddef>
#include <string>
#include <token.h>

namespace lexer {

class Lexer {
public:
  Lexer() = default;
  Lexer(std::string_view source) : source_{source} {}

  Token nextToken();

private:
  [[nodiscard]] bool isAtEnd() const;
  char advance();
  [[nodiscard]] char peek() const;
  [[nodiscard]] char peekNext() const;
  [[nodiscard]] bool match(char expected);

  [[nodiscard]] Token handleNumberToken();

  [[nodiscard]] Token createToken(TokenType type,
                                  std::string_view lexeme) const;
  [[nodiscard]] Token createToken(TokenType type) const;

  void throwLexingError(std::string_view msg) const;

  std::string source_;
  size_t line_ = 1;
  size_t column_ = 1;
  size_t start_ = 0;
  size_t current_ = 0;
};

} // namespace lexer
