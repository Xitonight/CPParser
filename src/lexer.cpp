#include "../include/lexer.h"
#include "../include/cli.h"
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

namespace lexer {

std::vector<Token> Lexer::tokenize() {
  Token t;
  do {
    t = nextToken();
    tokens_.push_back(t);
  } while (t.type() != lexer::TokenType::END_OF_FILE);
  return tokens_;
}

Token Lexer::nextToken() {
  start_ = current_;
  char c = advance();

  switch (c) {
  case '(':
    return createToken(TokenType::LEFT_PAREN);
  case ')':
    return createToken(TokenType::RIGHT_PAREN);
  case '[':
    return createToken(TokenType::LEFT_SQUARE_BRACKET);
  case ']':
    return createToken(TokenType::RIGHT_SQUARE_BRACKET);
  case '{':
    return createToken(TokenType::LEFT_CURLY_BRACKET);
  case '}':
    return createToken(TokenType::RIGHT_CURLY_BRACKET);
  case '=':
    if (match('='))
      return createToken(TokenType::EQUAL_EQUAL);
    return createToken(TokenType::EQUAL);
  case '!':
    if (match('='))
      return createToken(TokenType::NOT_EQUAL);
    return createToken(TokenType::BANG);
  case '>':
    if (match('='))
      return createToken(TokenType::GREATER_EQUAL);
    return createToken(TokenType::GREATER_THAN);
  case '<':
    if (match('='))
      return createToken(TokenType::LESS_EQUAL);
    return createToken(TokenType::LESS_THAN);
  case '+':
    if (match('+'))
      return createToken(TokenType::INCREMENT);
    return createToken(TokenType::PLUS);
  case '-':
    if (match('-'))
      return createToken(TokenType::DECREMENT);
    return createToken(TokenType::MINUS);
  case ';':
    return createToken(TokenType::SEMICOLON);
  case '/':
    if (match('/')) {
      while (peek() != '\n' && !isAtEnd())
        advance();
    } else
      return createToken(TokenType::SLASH);
    break;
  case '*':
    return createToken(TokenType::STAR);
  case '"':
    return handleStringToken();
  case '\0':
    column_--;
    return createToken(TokenType::END_OF_FILE);
  case ' ':
  case '\t':
  case '\r':
    break;
  case '\n':
    line_++;
    column_ = 1;
    break;
  default:
    if (std::isdigit(c))
      return handleNumberToken();
    else if (std::isalpha(c) || c == '_')
      return handleIdentifierToken();
    throwLexingError(std::string("Unexpected char: ") + c);
  }
  return nextToken();
}

Token Lexer::createToken(TokenType type, std::string_view lexeme) const {
  return Token{type, lexeme, line_, column_ - lexeme.size()};
}

Token Lexer::createToken(TokenType type) const {
  return createToken(type, lexemeForType(type));
}

Token Lexer::handleNumberToken() {
  while (std::isdigit(peek()))
    advance();

  if (peek() == '.' && std::isdigit(peekNext())) {
    advance();
    while (std::isdigit(peek()))
      advance();
  }
  return createToken(TokenType::NUMBER,
                     source_.substr(start_, current_ - start_));
}

Token Lexer::handleStringToken() {
  while (peek() != '"' && !isAtEnd() && peek() != '\n') {
    advance();
  }

  if (isAtEnd() || peek() == '\n') {
    throwLexingError("Unterminated string.", start_);
    // throwLexingError("Unterminated string.");
  }

  advance();

  return createToken(TokenType::STRING,
                     source_.substr(start_, current_ - start_));
}

Token Lexer::handleIdentifierToken() {
  while (std::isalnum(peek()) || peek() == '_')
    advance();
  std::string text = source_.substr(start_, current_ - start_);
  auto type = KeywordMap.find(text);
  if (type != KeywordMap.end()) {
    return createToken(type->second);
  }
  return createToken(TokenType::IDENTIFIER, text);
}

char Lexer::advance() {
  column_++;
  return source_[current_++];
}

char Lexer::peek() const {
  if (isAtEnd())
    return '\0';
  return source_[current_];
}

char Lexer::peekNext() const {
  if (isAtEnd())
    return '\0';
  return source_[current_ + 1];
}

bool Lexer::match(char expected) {
  if (isAtEnd())
    return false;
  if (peek() != expected)
    return false;
  column_++;
  current_++;
  return true;
}

bool Lexer::isAtEnd() const { return current_ >= source_.length(); }

void Lexer::throwLexingError(std::string_view msg) const {
  throwLexingError(msg, current_ - 1);
}

void Lexer::throwLexingError(std::string_view msg, size_t errorPos) const {
  size_t lineStart = current_;

  while (lineStart > 0 && source_[lineStart - 1] != '\n')
    lineStart--;

  size_t lineEnd = current_;

  while (lineEnd < source_.size() && source_[lineEnd] != '\n')
    lineEnd++;

  std::string errorLine = source_.substr(lineStart, lineEnd - lineStart);

  std::cerr << std::endl
            << Color::RED << "[line " << line_ << "] Error: " << msg
            << Color::RESET << std::endl
            << " " << line_ << " | " << errorLine << std::endl
            << " " << std::string(std::to_string(line_).size(), ' ') << "  "
            << std::string(errorPos - lineStart + 1, ' ') << Color::RED << "^"
            << Color::RESET << std::endl;

  exit(1);
}
} // namespace lexer
