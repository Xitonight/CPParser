#include "../include/token.h"
#include <iomanip>
#include <ios>
#include <ostream>
#include <unordered_map>

namespace lexer {

TokenTypeInfo tokenTypeInfo[] = {
    // Single char tokens
    {"LEFT_PAREN", "("},
    {"RIGHT_PAREN", ")"},
    {"LEFT_SQUARE_BRACKET", "["},
    {"RIGHT_SQUARE_BRACKET", "]"},
    {"LEFT_CURLY_BRACKET", "{"},
    {"RIGHT_CURLY_BRACKET", "}"},

    {"SLASH", "/"},
    {"STAR", "*"},
    {"SEMICOLON", ";"},

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
    {"STRING", "string_literal"},
    {"IDENTIFIER", "identifier"},

    // Keywords
    {"IF", "if"},
    {"WHILE", "while"},
    {"FOR", "for"},

    {"END_OF_FILE", ""}};

const std::unordered_map<std::string, TokenType> KeywordMap = {
    {"if", TokenType::IF},
    {"while", TokenType::WHILE},
    {"for", TokenType::FOR},
};

std::ostream &operator<<(std::ostream &out, TokenType const &type) {
  return out << tokenTypeInfo[(int)type].name;
}

std::ostream &operator<<(std::ostream &out, Token const &token) {
  out << "Token(type: " << std::left << std::setw(12) << token.type()
      << ", lexeme: " << token.lexeme() << ", line: " << token.line()
      << ", column: " << token.column() << ")";
  return out;
}

std::string lexemeForType(TokenType type) {
  return tokenTypeInfo[(int)type].lexeme;
}
} // namespace lexer
