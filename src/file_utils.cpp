#include "../include/file_utils.h"
#include <fstream>
#include <iterator>
#include <stdexcept>
#include <string>
#include <string_view>

namespace io {
std::string readFile(std::string_view path) {
  std::ifstream source{std::string(path)};
  if (!source.is_open()) {
    throw std::runtime_error("Could not open file");
  }
  return std::string(std::istreambuf_iterator<char>(source),
                     std::istreambuf_iterator<char>());
}
} // namespace io
