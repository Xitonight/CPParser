#include <cstddef>
#include <string>
#include <vector>

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

class token {
  TokenType type_;
  std::string value_;
  std::size_t position_;

public:
  token(TokenType type) : type_{type} {}
};

class tokenizer {
  std::vector<token> tokens_;

public:
  std::vector<token> tokens() const { return tokens_; }
};

} // namespace lexer
