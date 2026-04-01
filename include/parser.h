#pragma once

#include <memory>
#include <node.h>
#include <stdexcept>
#include <string>
#include <token.h>
#include <vector>

namespace parser {

class ParseError : public std::runtime_error {
public:
  ParseError(const lexer::Token &token, const std::string &message);

  const lexer::Token &token() const { return token_; }

private:
  lexer::Token token_;
};

class Parser {
public:
  explicit Parser(std::vector<lexer::Token> tokens)
      : tokens_{std::move(tokens)} {};

  std::unique_ptr<Expr> parse();

private:
  [[nodiscard]] const lexer::Token &peek() const;
  [[nodiscard]] const lexer::Token &previous() const;
  [[nodiscard]] bool isAtEnd() const;
  [[nodiscard]] bool check(lexer::TokenType type) const;

  const lexer::Token &advance();
  bool match(lexer::TokenType type);
  const lexer::Token &consume(lexer::TokenType type,
                              const std::string &message);

  std::unique_ptr<Expr> expression();
  std::unique_ptr<Expr> term();
  std::unique_ptr<Expr> factor();
  std::unique_ptr<Expr> primary();

  [[noreturn]] void throwParseError(const std::string &message);

  std::vector<lexer::Token> tokens_;
  size_t current_ = 0;
};

} // namespace parser
