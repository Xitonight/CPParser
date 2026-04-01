#include <cli.h>
#include <iostream>
#include <parser.h>

namespace parser {

ParseError::ParseError(const lexer::Token &token, const std::string &message)
    : std::runtime_error("[line " + std::to_string(token.line()) + "] at '" +
                         token.lexeme() + "': " + message),
      token_{token} {}

std::unique_ptr<Expr> Parser::parse() {
  try {
    return expression();
  } catch (const ParseError &error) {
    std::cerr << Color::RED << error.what() << Color::RESET << std::endl;
    return nullptr;
  }
}

const lexer::Token &Parser::peek() const { return tokens_[current_]; }

const lexer::Token &Parser::previous() const { return tokens_[current_ - 1]; }

bool Parser::isAtEnd() const {
  return peek().type() == lexer::TokenType::END_OF_FILE;
}

bool Parser::check(lexer::TokenType type) const {
  if (isAtEnd())
    return false;
  return peek().type() == type;
}

const lexer::Token &Parser::advance() {
  if (!isAtEnd())
    current_++;
  return previous();
}

bool Parser::match(lexer::TokenType type) {
  if (check(type)) {
    advance();
    return true;
  }
  return false;
}

const lexer::Token &Parser::consume(lexer::TokenType type,
                                    const std::string &message) {
  if (check(type))
    return advance();
  throwParseError(message);
}

std::unique_ptr<Expr> Parser::expression() {
  auto expr = term();

  while (match(lexer::TokenType::PLUS) || match(lexer::TokenType::MINUS)) {
    lexer::Token op = previous();
    auto right = term();
    expr = std::make_unique<BinaryExpr>(std::move(expr), op, std::move(right));
  }

  return expr;
}

std::unique_ptr<Expr> Parser::term() {
  auto expr = factor();

  while (match(lexer::TokenType::STAR) || match(lexer::TokenType::SLASH)) {
    lexer::Token op = previous();
    auto right = factor();
    expr = std::make_unique<BinaryExpr>(std::move(expr), op, std::move(right));
  }

  return expr;
}

std::unique_ptr<Expr> Parser::factor() {
  if (match(lexer::TokenType::MINUS) || match(lexer::TokenType::BANG)) {
    lexer::Token op = previous();
    auto right = factor();
    return std::make_unique<UnaryExpr>(op, std::move(right));
  }
  return primary();
}

std::unique_ptr<Expr> Parser::primary() {
  if (match(lexer::TokenType::NUMBER))
    return std::make_unique<NumberLiteralExpr>(previous());

  if (match(lexer::TokenType::STRING))
    return std::make_unique<StringLiteralExpr>(previous());

  if (match(lexer::TokenType::IDENTIFIER))
    return std::make_unique<IdentifierExpr>(previous());

  if (match(lexer::TokenType::LEFT_PAREN)) {
    auto expr = expression();
    consume(lexer::TokenType::RIGHT_PAREN, "Expected ')' after expression.");
    return std::make_unique<GroupingExpr>(std::move(expr));
  }

  throwParseError("Expected expression.");
}

[[noreturn]] void Parser::throwParseError(const std::string &message) {
  throw ParseError(peek(), message);
}

} // namespace parser
