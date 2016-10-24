#include <iostream>
#include <memory>

class Context {};

class AbstractExpression {
public:
    virtual void Eval(std::shared_ptr<Context> ctx) = 0;
};

class TerminalExpression : public AbstractExpression {};
class NoneTerminalExpression : public AbstractExpression {};

class Int : TerminalExpression {
private:
    int v;
public:
    Int(int v) : v(v) {}

    virtual void Eval(std::shared_ptr<Context>) override {
        std::cout << "Int Eval: " << v << std::endl;
    }
};

class Multiply : public TerminalExpression {
private:
    Int left;
    Int right;
public:
    Multiply(Int left, Int right) 
        : left(left), right(right)
    {}

    virtual void Eval(std::shared_ptr<Context> ctx) override {
        left.Eval(ctx);
        right.Eval(ctx);
        std::cout << "Multiply Eval" << std::endl;
    }
};

int main() {
    auto ctx = std::make_shared<Context>();
    std::shared_ptr<AbstractExpression> expr = std::make_shared<Multiply>(Int(5), Int(8));
    expr->Eval(ctx);
}
