#include <iostream>
#include <memory>

class Component {
public:
    virtual void Operation() = 0;
};

class ConcreteComponent : public Component {
public:
    virtual void Operation() override {
        std::cout << "Operation" << std::endl;
    }
};

class Decorator : public Component {
protected:
    std::shared_ptr<Component> target;

public:
    void SetComponent(std::shared_ptr<Component> t) {
        target = t;
    }

    virtual void Operation() = 0;
};

class ConcreteDecorator : public Decorator {

public:
    virtual void Operation() override {
        std::cout << "Decorator Operation begin" << std::endl;
        target->Operation();
        std::cout << "Decorator Operation end" << std::endl;
    };
};

int main() {
    std::shared_ptr<Component> c = std::make_shared<ConcreteComponent>();
    std::shared_ptr<Decorator> d = std::make_shared<ConcreteDecorator>();
    d->SetComponent(c);

    std::shared_ptr<Component> decorated = d;
    decorated->Operation();
}
