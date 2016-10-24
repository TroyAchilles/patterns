#include <iostream>
#include <memory>

class Visitor;

class Element {
public:
    virtual void accept(std::shared_ptr<Visitor> visitor) = 0;
};

class ConcreteElement : public Element, public std::enable_shared_from_this<ConcreteElement> {
public:
    virtual void accept(std::shared_ptr<Visitor> visitor) override;
};

class Visitor {
public:
    virtual void visit(std::shared_ptr<ConcreteElement> elm) = 0;
};

class ConcreteVisitor : public Visitor {
public:
    virtual void visit(std::shared_ptr<ConcreteElement> elm) override {
        std::cout << "begin to visit: " << elm.get() << std::endl;
    }
};

void ConcreteElement::accept(std::shared_ptr<Visitor> visitor) {
    std::cout << "accept visitor: " << visitor.get() << std::endl;
    visitor->visit(shared_from_this());
}

int main() {
    auto elm = std::make_shared<ConcreteElement>();
    std::shared_ptr<Visitor> visitor = std::make_shared<ConcreteVisitor>();
    elm->accept(visitor);
}
