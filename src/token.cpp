#include <ostream>
#include <token.h>

namespace lexer {

TokenTypeInfo tokenTypeInfo[] = {
    // Single char tokens
    {"LEFT_PAREN", "("},
    {"RIGHT_PAREN", ")"},
    {"SLASH", "/"},
    {"STAR", "*"},

    // One or two char tokens
    {"EQUAL", "="},
    {"EQUAL_EQUAL", "=="},
    {"BANG", "!"},
    {"NOT_EQUAL", "!="},
    {"GREATER_THAN", ">"},
    {"GREATER_EQUAL", ">="},
    {"LESS_THAN", "<"},
    {"LESS_EQUAL", "<="},
    {"PLUS", "+"},
    {"INCREMENT", "++"},
    {"MINUS", "-"},
    {"DECREMENT", "--"},

    // Literals
    {"NUMBER", "number_literal"},

    {"END_OF_FILE", ""}};

std::ostream &operator<<(std::ostream &out, TokenType const &type) {
  return out << tokenTypeInfo[(int)type].name;
}

std::ostream &operator<<(std::ostream &out, Token const &token) {
  out << "Token(type: " << token.type() << ", lexeme: " << token.lexeme()
      << ", line: " << token.line() << ", column: " << token.column() << ")";
  return out;
}

std::string lexemeForType(TokenType type) {
  return tokenTypeInfo[(int)type].lexeme;
}
} // namespace lexer
