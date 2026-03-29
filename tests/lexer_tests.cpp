#include <catch2/catch_test_macros.hpp>
#include <lexer.h>

using namespace lexer;

TEST_CASE("Lexer: Single char token - LEFT_PAREN", "[lexer]") {
  Lexer lexer("(");
  Token token = lexer.nextToken();
  REQUIRE(token.type() == TokenType::LEFT_PAREN);
  REQUIRE(token.lexeme() == "(");
}

TEST_CASE("Lexer: Single char token - RIGHT_PAREN", "[lexer]") {
  Lexer lexer(")");
  Token token = lexer.nextToken();
  REQUIRE(token.type() == TokenType::RIGHT_PAREN);
  REQUIRE(token.lexeme() == ")");
}

TEST_CASE("Lexer: Single char token - LEFT_SQUARE_BRACKET", "[lexer]") {
  Lexer lexer("[");
  Token token = lexer.nextToken();
  REQUIRE(token.type() == TokenType::LEFT_SQUARE_BRACKET);
  REQUIRE(token.lexeme() == "[");
}

TEST_CASE("Lexer: Single char token - RIGHT_SQUARE_BRACKET", "[lexer]") {
  Lexer lexer("]");
  Token token = lexer.nextToken();
  REQUIRE(token.type() == TokenType::RIGHT_SQUARE_BRACKET);
  REQUIRE(token.lexeme() == "]");
}

TEST_CASE("Lexer: Single char token - LEFT_CURLY_BRACKET", "[lexer]") {
  Lexer lexer("{");
  Token token = lexer.nextToken();
  REQUIRE(token.type() == TokenType::LEFT_CURLY_BRACKET);
  REQUIRE(token.lexeme() == "{");
}

TEST_CASE("Lexer: Single char token - RIGHT_CURLY_BRACKET", "[lexer]") {
  Lexer lexer("}");
  Token token = lexer.nextToken();
  REQUIRE(token.type() == TokenType::RIGHT_CURLY_BRACKET);
  REQUIRE(token.lexeme() == "}");
}

TEST_CASE("Lexer: Single char token - SEMICOLON", "[lexer]") {
  Lexer lexer(";");
  Token token = lexer.nextToken();
  REQUIRE(token.type() == TokenType::SEMICOLON);
  REQUIRE(token.lexeme() == ";");
}

TEST_CASE("Lexer: Single char token - SLASH", "[lexer]") {
  Lexer lexer("/");
  Token token = lexer.nextToken();
  REQUIRE(token.type() == TokenType::SLASH);
  REQUIRE(token.lexeme() == "/");
}

TEST_CASE("Lexer: Single char token - STAR", "[lexer]") {
  Lexer lexer("*");
  Token token = lexer.nextToken();
  REQUIRE(token.type() == TokenType::STAR);
  REQUIRE(token.lexeme() == "*");
}

TEST_CASE("Lexer: EQUAL_EQUAL", "[lexer]") {
  Lexer lexer("==");
  Token token = lexer.nextToken();
  REQUIRE(token.type() == TokenType::EQUAL_EQUAL);
  REQUIRE(token.lexeme() == "==");
}

TEST_CASE("Lexer: NOT_EQUAL", "[lexer]") {
  Lexer lexer("!=");
  Token token = lexer.nextToken();
  REQUIRE(token.type() == TokenType::NOT_EQUAL);
  REQUIRE(token.lexeme() == "!=");
}

TEST_CASE("Lexer: GREATER_EQUAL", "[lexer]") {
  Lexer lexer(">=");
  Token token = lexer.nextToken();
  REQUIRE(token.type() == TokenType::GREATER_EQUAL);
  REQUIRE(token.lexeme() == ">=");
}

TEST_CASE("Lexer: LESS_EQUAL", "[lexer]") {
  Lexer lexer("<=");
  Token token = lexer.nextToken();
  REQUIRE(token.type() == TokenType::LESS_EQUAL);
  REQUIRE(token.lexeme() == "<=");
}

TEST_CASE("Lexer: EQUAL", "[lexer]") {
  Lexer lexer("=");
  Token token = lexer.nextToken();
  REQUIRE(token.type() == TokenType::EQUAL);
  REQUIRE(token.lexeme() == "=");
}

TEST_CASE("Lexer: BANG", "[lexer]") {
  Lexer lexer("!");
  Token token = lexer.nextToken();
  REQUIRE(token.type() == TokenType::BANG);
  REQUIRE(token.lexeme() == "!");
}

TEST_CASE("Lexer: GREATER_THAN", "[lexer]") {
  Lexer lexer(">");
  Token token = lexer.nextToken();
  REQUIRE(token.type() == TokenType::GREATER_THAN);
  REQUIRE(token.lexeme() == ">");
}

TEST_CASE("Lexer: LESS_THAN", "[lexer]") {
  Lexer lexer("<");
  Token token = lexer.nextToken();
  REQUIRE(token.type() == TokenType::LESS_THAN);
  REQUIRE(token.lexeme() == "<");
}

TEST_CASE("Lexer: INCREMENT", "[lexer]") {
  Lexer lexer("++");
  Token token = lexer.nextToken();
  REQUIRE(token.type() == TokenType::INCREMENT);
  REQUIRE(token.lexeme() == "++");
}

TEST_CASE("Lexer: DECREMENT", "[lexer]") {
  Lexer lexer("--");
  Token token = lexer.nextToken();
  REQUIRE(token.type() == TokenType::DECREMENT);
  REQUIRE(token.lexeme() == "--");
}

TEST_CASE("Lexer: PLUS", "[lexer]") {
  Lexer lexer("+");
  Token token = lexer.nextToken();
  REQUIRE(token.type() == TokenType::PLUS);
  REQUIRE(token.lexeme() == "+");
}

TEST_CASE("Lexer: MINUS", "[lexer]") {
  Lexer lexer("-");
  Token token = lexer.nextToken();
  REQUIRE(token.type() == TokenType::MINUS);
  REQUIRE(token.lexeme() == "-");
}

TEST_CASE("Lexer: Integer number - 0", "[lexer]") {
  Lexer lexer("0");
  Token token = lexer.nextToken();
  REQUIRE(token.type() == TokenType::NUMBER);
  REQUIRE(token.lexeme() == "0");
}

TEST_CASE("Lexer: Integer number - 42", "[lexer]") {
  Lexer lexer("42");
  Token token = lexer.nextToken();
  REQUIRE(token.type() == TokenType::NUMBER);
  REQUIRE(token.lexeme() == "42");
}

TEST_CASE("Lexer: Decimal number - 0.5", "[lexer]") {
  Lexer lexer("0.5");
  Token token = lexer.nextToken();
  REQUIRE(token.type() == TokenType::NUMBER);
  REQUIRE(token.lexeme() == "0.5");
}

TEST_CASE("Lexer: Decimal number - 3.14", "[lexer]") {
  Lexer lexer("3.14");
  Token token = lexer.nextToken();
  REQUIRE(token.type() == TokenType::NUMBER);
  REQUIRE(token.lexeme() == "3.14");
}

TEST_CASE("Lexer: String - hello", "[lexer]") {
  Lexer lexer("\"hello\"");
  Token token = lexer.nextToken();
  REQUIRE(token.type() == TokenType::STRING);
  REQUIRE(token.lexeme() == "\"hello\"");
}

TEST_CASE("Lexer: Empty string", "[lexer]") {
  Lexer lexer("\"\"");
  Token token = lexer.nextToken();
  REQUIRE(token.type() == TokenType::STRING);
  REQUIRE(token.lexeme() == "\"\"");
}

TEST_CASE("Lexer: Identifier - variable", "[lexer]") {
  Lexer lexer("variable");
  Token token = lexer.nextToken();
  REQUIRE(token.type() == TokenType::IDENTIFIER);
  REQUIRE(token.lexeme() == "variable");
}

TEST_CASE("Lexer: Identifier - camelCase", "[lexer]") {
  Lexer lexer("camelCase");
  Token token = lexer.nextToken();
  REQUIRE(token.type() == TokenType::IDENTIFIER);
  REQUIRE(token.lexeme() == "camelCase");
}



TEST_CASE("Lexer: Keyword - if", "[lexer]") {
  Lexer lexer("if");
  Token token = lexer.nextToken();
  REQUIRE(token.type() == TokenType::IF);
  REQUIRE(token.lexeme() == "if");
}

TEST_CASE("Lexer: Keyword - while", "[lexer]") {
  Lexer lexer("while");
  Token token = lexer.nextToken();
  REQUIRE(token.type() == TokenType::WHILE);
  REQUIRE(token.lexeme() == "while");
}

TEST_CASE("Lexer: Keyword - for", "[lexer]") {
  Lexer lexer("for");
  Token token = lexer.nextToken();
  REQUIRE(token.type() == TokenType::FOR);
  REQUIRE(token.lexeme() == "for");
}

TEST_CASE("Lexer: Multiple tokens in sequence", "[lexer]") {
  Lexer lexer("if (x == 42)");

  REQUIRE(lexer.nextToken().type() == TokenType::IF);
  REQUIRE(lexer.nextToken().type() == TokenType::LEFT_PAREN);
  REQUIRE(lexer.nextToken().type() == TokenType::IDENTIFIER);
  REQUIRE(lexer.nextToken().type() == TokenType::EQUAL_EQUAL);
  REQUIRE(lexer.nextToken().type() == TokenType::NUMBER);
  REQUIRE(lexer.nextToken().type() == TokenType::RIGHT_PAREN);
}

TEST_CASE("Lexer: Whitespace and newlines", "[lexer]") {
  Lexer lexer("  \t\n  \r  ");

  Token token = lexer.nextToken();
  REQUIRE(token.type() == TokenType::END_OF_FILE);
  REQUIRE(token.line() == 2);
}

TEST_CASE("Lexer: Comments", "[lexer]") {
  Lexer lexer("// this is a comment\nx");

  Token token = lexer.nextToken();
  REQUIRE(token.type() == TokenType::IDENTIFIER);
  REQUIRE(token.lexeme() == "x");
  REQUIRE(token.line() == 2);
}

TEST_CASE("Lexer: Complex expression", "[lexer]") {
  Lexer lexer("if (x >= 10) { x++; }");

  auto token1 = lexer.nextToken();
  auto token2 = lexer.nextToken();
  auto token3 = lexer.nextToken();
  auto token4 = lexer.nextToken();
  auto token5 = lexer.nextToken();
  auto token6 = lexer.nextToken();
  auto token7 = lexer.nextToken();
  auto token8 = lexer.nextToken();
  auto token9 = lexer.nextToken();
  auto token10 = lexer.nextToken();
  auto token11 = lexer.nextToken();

  REQUIRE(token1.type() == TokenType::IF);
  REQUIRE(token2.type() == TokenType::LEFT_PAREN);
  REQUIRE(token3.type() == TokenType::IDENTIFIER);
  REQUIRE(token4.type() == TokenType::GREATER_EQUAL);
  REQUIRE(token5.type() == TokenType::NUMBER);
  REQUIRE(token6.type() == TokenType::RIGHT_PAREN);
  REQUIRE(token7.type() == TokenType::LEFT_CURLY_BRACKET);
  REQUIRE(token8.type() == TokenType::IDENTIFIER);
  REQUIRE(token9.type() == TokenType::INCREMENT);
  REQUIRE(token10.type() == TokenType::SEMICOLON);
  REQUIRE(token11.type() == TokenType::RIGHT_CURLY_BRACKET);
}

TEST_CASE("Lexer: Token positions", "[lexer]") {
  Lexer lexer("x + y");

  auto token1 = lexer.nextToken();
  auto token2 = lexer.nextToken();
  auto token3 = lexer.nextToken();

  REQUIRE(token1.lexeme() == "x");
  REQUIRE(token1.column() == 1);

  REQUIRE(token2.lexeme() == "+");
  REQUIRE(token2.column() == 3);

  REQUIRE(token3.lexeme() == "y");
  REQUIRE(token3.column() == 5);
}

TEST_CASE("Lexer: Multiple lines", "[lexer]") {
  Lexer lexer("x\n+\ny");

  auto token1 = lexer.nextToken();
  auto token2 = lexer.nextToken();
  auto token3 = lexer.nextToken();

  REQUIRE(token1.line() == 1);
  REQUIRE(token2.line() == 2);
  REQUIRE(token3.line() == 3);
}