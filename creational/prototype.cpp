#include <iostream>
#include <memory>

class Prototype {
public:
    virtual std::shared_ptr<Prototype> Clone() = 0;
};

class ConcretePrototype : public Prototype {
public:
    virtual std::shared_ptr<Prototype> Clone() override {
        return std::make_shared<ConcretePrototype>(*this);
    }
};

int main() {
    auto proto1 = std::make_shared<ConcretePrototype>();
    auto proto2 = std::dynamic_pointer_cast<ConcretePrototype>(proto1->Clone());
    (void)proto2;
}
