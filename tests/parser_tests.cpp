#include <ast_printer.h>
#include <catch2/catch_test_macros.hpp>
#include <lexer.h>
#include <parser.h>

namespace parser {
namespace {

std::string parseAndPrint(std::string_view source) {
  lexer::Lexer lex{source};
  auto tokens = lex.tokenize();
  Parser parser{std::move(tokens)};
  auto expr = parser.parse();
  if (!expr)
    return "PARSE_ERROR";
  ASTPrinter printer;
  expr->accept(printer);
  return printer.result();
}

} // namespace

TEST_CASE("Parser: number literal", "[Parser]") {
  REQUIRE(parseAndPrint("42") == "42");
}

TEST_CASE("Parser: string literal", "[Parser]") {
  REQUIRE(parseAndPrint("\"hello\"") == "\"hello\"");
}

TEST_CASE("Parser: identifier", "[Parser]") {
  REQUIRE(parseAndPrint("x") == "x");
}

TEST_CASE("Parser: unary negation", "[Parser]") {
  REQUIRE(parseAndPrint("-5") == "(- 5)");
}

TEST_CASE("Parser: unary not", "[Parser]") {
  REQUIRE(parseAndPrint("!x") == "(! x)");
}

TEST_CASE("Parser: double unary", "[Parser]") {
  REQUIRE(parseAndPrint("!!x") == "(! (! x))");
}

TEST_CASE("Parser: binary addition", "[Parser]") {
  REQUIRE(parseAndPrint("1 + 2") == "(+ 1 2)");
}

TEST_CASE("Parser: binary multiplication", "[Parser]") {
  REQUIRE(parseAndPrint("2 * 3") == "(* 2 3)");
}

TEST_CASE("Parser: operator precedence", "[Parser]") {
  REQUIRE(parseAndPrint("2 + 3 * 4") == "(+ 2 (* 3 4))");
}

TEST_CASE("Parser: grouping overrides precedence", "[Parser]") {
  REQUIRE(parseAndPrint("(2 + 3) * 4") == "(* (group (+ 2 3)) 4)");
}

TEST_CASE("Parser: complex expression", "[Parser]") {
  REQUIRE(parseAndPrint("1 + 2 * 3 - 4 / 2") ==
          "(- (+ 1 (* 2 3)) (/ 4 2))");
}

TEST_CASE("Parser: nested grouping", "[Parser]") {
  REQUIRE(parseAndPrint("((1 + 2))") == "(group (group (+ 1 2)))");
}

TEST_CASE("Parser: unary with binary", "[Parser]") {
  REQUIRE(parseAndPrint("-x + 3") == "(+ (- x) 3)");
}

TEST_CASE("Parser: parse error on missing closing paren", "[Parser]") {
  REQUIRE(parseAndPrint("(1 + 2") == "PARSE_ERROR");
}

TEST_CASE("Parser: parse error on empty input", "[Parser]") {
  REQUIRE(parseAndPrint("") == "PARSE_ERROR");
}

} // namespace parser
