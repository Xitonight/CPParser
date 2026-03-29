# Testing

This directory contains tests for the parser project using the Catch2 testing framework.

## Running Tests

From the project root directory:

```bash
mkdir -p build && cd build
cmake ..
make
ctest
```

Or run the test executable directly:

```bash
./tests
```

## Test Files

- `lexer_tests.cpp` - Tests for the Lexer class including:
  - Single character tokens
  - Multi-character tokens
  - Number literals (integers and decimals)
  - String literals
  - Identifiers and keywords
  - Token positions and line tracking
  - Complex expressions

## Adding New Tests

To add a new test:

1. Create a new `.cpp` file in this directory (e.g., `my_feature_tests.cpp`)
2. Include Catch2 headers: `#include <catch2/catch_test_macros.hpp>`
3. Write test cases using the `TEST_CASE` macro
4. Rebuild the project - CMake will automatically discover and include new tests

Example test:

```cpp
#include <catch2/catch_test_macros.hpp>
#include <your_header.h>

TEST_CASE("Feature: Basic functionality", "[feature]") {
    // Setup
    YourClass obj;
    
    // Test
    REQUIRE(obj.doSomething() == expected_value);
    
    // More assertions
    CHECK(obj.state() == "ready");
}
```

## Catch2 Resources

- [Catch2 Documentation](https://github.com/catchorg/Catch2/tree/devel/docs)
- [Tutorial](https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md#top)