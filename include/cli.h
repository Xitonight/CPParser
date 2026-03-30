#include <iostream>
#include <string>
#include <string_view>
#include <unordered_map>

namespace cli {

enum class FlagType { SOURCE, PATH, HELP };

extern const std::unordered_map<std::string_view, FlagType> FlagMap;

class Options {
public:
  Options() = default;
  Options(std::string_view source) : source_{source} {};
  std::string const &source() const { return source_; }

private:
  std::string source_;
};

class CliHelper {
public:
  CliHelper(int argc, char **argv) : argc_{argc}, argv_{argv} {}

  Options parse();

private:
  void check();
  void showError(std::string_view msg);
  void showUsage(std::ostream &out);

  int argc_;
  char **argv_;
};
} // namespace cli

namespace Color {
const std::string RED = "\033[31m";
const std::string RESET = "\033[0m";
} // namespace Color
