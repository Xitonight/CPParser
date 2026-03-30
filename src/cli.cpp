#include <cli.h>
#include <file_utils.h>
#include <string>
#include <string_view>

namespace cli {

const std::unordered_map<std::string_view, FlagType> FlagMap = {
    {"-s", FlagType::SOURCE},   {"--source", FlagType::SOURCE},
    {"-p", FlagType::PATH},     {"--path", FlagType::PATH},
    {"--file", FlagType::PATH}, {"-h", FlagType::HELP},
    {"--help", FlagType::HELP}};

Options CliHelper::parse() {
  check();
  switch (FlagMap.at(argv_[1])) {
  case cli::FlagType::SOURCE:
    return Options{argv_[2]};
  case cli::FlagType::PATH:
    return Options{io::readFile(argv_[2])};
  default:
    showError("Unhandled flag.");
    exit(1);
  }
  return Options{};
}

void CliHelper::check() {
  bool hasError = false;

  if (argc_ == 1) {
    showError("No arguments passed.");
    hasError = true;
  }

  if (argc_ >= 2 && !FlagMap.contains(argv_[1])) {
    showError("Invalid argument(s).");
    hasError = true;
  }

  if (argc_ == 2) {
    showError("Missing argument for " + std::string(argv_[1]) + ".");
    hasError = true;
  }

  if (argc_ > 3) {
    showError("Invalid argument(s).");
    hasError = true;
  }

  if (hasError) {
    showUsage(std::cout);
    exit(1);
  }
}

void CliHelper::showError(std::string_view msg) {
  std::cerr << Color::RED << "Error: " << msg << Color::RESET << std::endl
            << std::endl;
}

void CliHelper::showUsage(std::ostream &out) {
  out << "Usage" << std::endl << std::endl;
  out << "  parser [-h/--help]" << std::endl;
  out << "  parser [-s/--source] <source-string>" << std::endl;
  out << "  parser [-p/--path/--file] <path-to-source>" << std::endl;
}

} // namespace cli
