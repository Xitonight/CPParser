#pragma once

#include <memory>
#include <token.h>

namespace parser {

class NumberLiteralExpr;
class StringLiteralExpr;
class IdentifierExpr;
class GroupingExpr;
class UnaryExpr;
class BinaryExpr;

class ExprVisitor {
public:
  virtual ~ExprVisitor() = default;

  virtual void visit(const NumberLiteralExpr &expr) = 0;
  virtual void visit(const StringLiteralExpr &expr) = 0;
  virtual void visit(const IdentifierExpr &expr) = 0;
  virtual void visit(const GroupingExpr &expr) = 0;
  virtual void visit(const UnaryExpr &expr) = 0;
  virtual void visit(const BinaryExpr &expr) = 0;
};

class Expr {
public:
  virtual ~Expr() = default;
  virtual void accept(ExprVisitor &visitor) const = 0;
};

class NumberLiteralExpr : public Expr {
public:
  explicit NumberLiteralExpr(lexer::Token token)
      : token_{std::move(token)} {}

  const lexer::Token &token() const { return token_; }

  void accept(ExprVisitor &visitor) const override {
    visitor.visit(*this);
  }

private:
  lexer::Token token_;
};

class StringLiteralExpr : public Expr {
public:
  explicit StringLiteralExpr(lexer::Token token)
      : token_{std::move(token)} {}

  const lexer::Token &token() const { return token_; }

  void accept(ExprVisitor &visitor) const override {
    visitor.visit(*this);
  }

private:
  lexer::Token token_;
};

class IdentifierExpr : public Expr {
public:
  explicit IdentifierExpr(lexer::Token token)
      : token_{std::move(token)} {}

  const lexer::Token &token() const { return token_; }

  void accept(ExprVisitor &visitor) const override {
    visitor.visit(*this);
  }

private:
  lexer::Token token_;
};

class GroupingExpr : public Expr {
public:
  explicit GroupingExpr(std::unique_ptr<Expr> expression)
      : expression_{std::move(expression)} {}

  const Expr &expression() const { return *expression_; }

  void accept(ExprVisitor &visitor) const override {
    visitor.visit(*this);
  }

private:
  std::unique_ptr<Expr> expression_;
};

class UnaryExpr : public Expr {
public:
  UnaryExpr(lexer::Token op, std::unique_ptr<Expr> right)
      : op_{std::move(op)}, right_{std::move(right)} {}

  const lexer::Token &op() const { return op_; }
  const Expr &right() const { return *right_; }

  void accept(ExprVisitor &visitor) const override {
    visitor.visit(*this);
  }

private:
  lexer::Token op_;
  std::unique_ptr<Expr> right_;
};

class BinaryExpr : public Expr {
public:
  BinaryExpr(std::unique_ptr<Expr> left, lexer::Token op,
             std::unique_ptr<Expr> right)
      : left_{std::move(left)}, op_{std::move(op)},
        right_{std::move(right)} {}

  const Expr &left() const { return *left_; }
  const lexer::Token &op() const { return op_; }
  const Expr &right() const { return *right_; }

  void accept(ExprVisitor &visitor) const override {
    visitor.visit(*this);
  }

private:
  std::unique_ptr<Expr> left_;
  lexer::Token op_;
  std::unique_ptr<Expr> right_;
};

} // namespace parser
