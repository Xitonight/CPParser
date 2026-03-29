#include <cstddef>
#include <string>
#include <token.h>

namespace lexer {

class Lexer {
public:
  Lexer(std::string source) : source_{source} {};

  Token nextToken();
  bool isAtEnd() const;
  char peek() const;
  char advance();
  bool match(char expected);

private:
  std::string source_;
  std::size_t current_ = 0;
  std::size_t line_ = 1;
};

} // namespace lexer
