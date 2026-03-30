# Parser Project

A modern C++ (C++23) parser implementation demonstrating compiler theory and practice. This project builds a complete parser from scratch, starting with a lexer and progressing through expression parsing, statement parsing, and program analysis.

## Features

### Lexer (Implemented)
- **Single character tokens**: `(` `)` `[` `]` `{` `}` `;` `/` `*`
- **Multi-character operators**: `==` `!=` `>=` `<=` `=` `!` `>` `<` `++` `--` `+` `-`
- **Number literals**: Integers (`42`) and decimals (`3.14`)
- **String literals**: Quoted strings (`"hello"`)
- **Identifiers**: Variable names and function names
- **Keywords**: `if`, `while`, `for`
- **Comments**: Single-line comments starting with `//`
- **Position tracking**: Line and column numbers for error reporting

## Building

### Prerequisites
- CMake 3.10 or higher
- C++23 compatible compiler (GCC 12+, Clang 15+, MSVC 2022)
- (Optional) Catch2 for testing - will be auto-downloaded if not present

### Quick Start

```bash
# Clone and navigate to project
cd parser

# Create build directory
mkdir build && cd build

# Configure and build
cmake ..
make -j$(nproc)

# Run the lexer on a source file
./parser --file path/to/source.txt
```

### Build Options

```bash
# Build only the main executable (faster)
make parser

# Build tests
make tests

# Build everything
make

# Use parallel builds for faster compilation
make -j$(nproc)

# Run tests
./tests
# or via CTest for nicer output
ctest --output-on-failure
```

## Testing

The project uses **Catch2** as the testing framework.

### Running Tests

```bash
cd build
./tests                     # Run all tests
./tests -s                  # Verbose output showing each assertion
ctest                       # Run via CTest
ctest -R "Lexer"            # Run specific test patterns
ctest --output-on-failure   # Show details of failing tests
```

### Test Coverage

Currently includes **more than 30 tests** covering:
- Single character tokens
- Multi-character comparison operators
- Arithmetic operators (`+`, `-`, `++`, `--`)
- Number literals (integers and decimals)
- String literals
- Identifiers and keywords
- Token sequences and complex expressions
- Whitespace, newlines, and comments
- Token position tracking (line/column)

Test files are in `tests/lexer_tests.cpp` - new tests are automatically discovered by CMake.

## Project Structure

```
parser/
├── include/           # Header files
│   ├── lexer.h       # Lexer class definition
│   ├── token.h       # Token and TokenType definitions
│   ├── cli.h         # Command-line interface
│   └── file_utils.h # File I/O utilities
├── src/              # Source files
│   ├── lexer.cpp     # Lexer implementation
│   ├── token.cpp     # Token utilities
│   ├── cli.cpp       # CLI argument parsing
│   ├── file_utils.cpp # File reading
│   └── main.cpp     # Main entry point
├── tests/            # Test suite
│   ├── lexer_tests.cpp
│   └── README.md
├── build/            # Build artifacts (generated)
├── CMakeLists.txt    # CMake build configuration
```

## Usage

### Command Line Interface

```bash
# Lex a source file
./parser --file example.txt

# View CLI help
./parser --help
```

### Example Input

```text
if (x >= 10) {
  x++;
}
```

### Example Output

```text
Token(type: IF, lexeme: if, line: 1, column: 1)
Token(type: LEFT_PAREN, lexeme: (, line: 1, column: 4)
Token(type: IDENTIFIER, lexeme: x, line: 1, column: 5)
Token(type: GREATER_EQUAL, lexeme: >=, line: 1, column: 7)
Token(type: NUMBER, lexeme: 10, line: 1, column: 10)
Token(type: RIGHT_PAREN, lexeme: ), line: 1, column: 12)
Token(type: LEFT_CURLY_BRACKET, lexeme: {, line: 1, column: 14)
Token(type: IDENTIFIER, lexeme: x, line: 2, column: 3)
Token(type: INCREMENT, lexeme: ++, line: 2, column: 4)
Token(type: SEMICOLON, lexeme: ;, line: 2, column: 6)
Token(type: RIGHT_CURLY_BRACKET, lexeme: }, line: 3, column: 1)
Token(type: END_OF_FILE, lexeme: , line: 3, column: 2)
```

### Upcoming Milestones

1. **Expression Parser** - Parse arithmetic, logical, and assignment expressions with proper operator precedence
2. **Statement Parser** - Parse `if`, `while`, `for`, blocks, and declarations
3. **AST Implementation** - Build Abstract Syntax Tree from tokens
4. **Error Recovery** - Continue parsing after syntax errors with helpful messages
5. **Semantic Analysis** - Type checking and scope resolution

## Design Philosophy

- **Modern C++23**: Utilizing latest language features for clean, efficient code
- **Educational Focus**: Clear, readable code with comprehensive documentation
- **Test-Driven Development**: Comprehensive test suite ensuring correctness
- **Error Handling**: Helpful error messages with source location
- **Incremental Development**: Small, testable steps building toward complete parser

## Contributing

This is a learning project. To extend functionality:

1. Add new tokens to `include/token.h`
2. Implement lexer handling in `src/lexer.cpp`
3. Add tests in `tests/lexer_tests.cpp`
4. Follow the existing code style and patterns
