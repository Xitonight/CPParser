expression  ::= term { ('+' | '-') term }
term        ::= factor { ('*' | '/') factor }
factor      ::= [ '-' | '!' ] primary
primary     ::= NUMBER | '(' expression ')'
