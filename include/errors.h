#include <cstddef>
#include <stdexcept>
#include <string>

namespace cp {

class Error : public std::runtime_error {
  std::size_t line_;
  std::size_t column_;

  static std::string build_message(std::size_t line, std::size_t column,
                                   const std::string &message) {
    return "[Line " + std::to_string(line) + ":" + std::to_string(column) +
           "] " + message;
  }

public:
  Error(const std::string &message) : std::runtime_error(message), line_(0), column_(0) {}
  Error(std::size_t line, std::size_t column, const std::string &message)
      : std::runtime_error(build_message(line, column, message)), line_(line), column_(column) {}

  virtual ~Error() = default;

  std::size_t getLine() const { return line_; }

  std::size_t getColumn() const { return column_; }
};

class LexingError : public Error {
public:
  using Error::Error;
  LexingError(const std::string &message) : Error(message) {}
  LexingError(std::size_t line, std::size_t column, const std::string &message)
      : Error(line, column, message) {}
};

class ParsingError : public Error {
public:
  using Error::Error;
  ParsingError(const std::string &message) : Error(message) {}
  ParsingError(std::size_t line, std::size_t column, const std::string &message)
      : Error(line, column, message) {}
};

} // namespace cp
