#include <cli.h>
#include <lexer.h>

int main(int argc, char *argv[]) {
  cli::CliHelper cliHelper{argc, argv};
  auto options = cliHelper.parse();

  lexer::Lexer lexer{options.source()};

  lexer::Token t;

  do {
    t = lexer.nextToken();
    std::cout << t << std::endl;
  } while (t.type() != lexer::TokenType::END_OF_FILE);

  return 0;
}
