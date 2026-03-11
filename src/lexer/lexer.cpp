#include <lexer/lexer.h>

namespace lexer {

bool Lexer::isAtEnd() const { return current_ >= source_.length(); }

char Lexer::peek() const {
  if (isAtEnd())
    return '\0';
  return source_[current_];
}

char Lexer::advance() {
  if (source_[current_] == '\n') {
    line_++;
  }
  return source_[current_++];
}

} // namespace lexer
