#pragma once

#include <node.h>
#include <sstream>
#include <string>

namespace parser {

class ASTPrinter : public ExprVisitor {
public:
  std::string result() const { return stream_.str(); }

  void visit(const NumberLiteralExpr &expr) override {
    stream_ << expr.token().lexeme();
  }

  void visit(const StringLiteralExpr &expr) override {
    stream_ << expr.token().lexeme();
  }

  void visit(const IdentifierExpr &expr) override {
    stream_ << expr.token().lexeme();
  }

  void visit(const GroupingExpr &expr) override {
    stream_ << "(group ";
    expr.expression().accept(*this);
    stream_ << ")";
  }

  void visit(const UnaryExpr &expr) override {
    stream_ << "(" << expr.op().lexeme() << " ";
    expr.right().accept(*this);
    stream_ << ")";
  }

  void visit(const BinaryExpr &expr) override {
    stream_ << "(" << expr.op().lexeme() << " ";
    expr.left().accept(*this);
    stream_ << " ";
    expr.right().accept(*this);
    stream_ << ")";
  }

private:
  std::ostringstream stream_;
};

} // namespace parser
