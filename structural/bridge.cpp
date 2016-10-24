#include <iostream>
#include <memory>

class Implementor {
public:
    virtual void OperationImpl() = 0;
};

class ConcreateImplementor : public Implementor {
public:
    virtual void OperationImpl() override {
        std::cout << "OperationImpl" << std::endl;
    }
};

class Abstraction {
protected:
    std::shared_ptr<Implementor> impl;

public:
    void setImplementor(std::shared_ptr<Implementor> impl) {
        this->impl = impl;
    }

    virtual void Operation() = 0;
};

class RedefinedAbstraction : public Abstraction {
public:
    virtual void Operation() override{
        std::cout << "Operation" << std::endl;
        impl->OperationImpl();
    }
};

int main() {
    std::shared_ptr<Implementor> i = std::make_shared<ConcreateImplementor>();
    std::shared_ptr<Abstraction> a = std::make_shared<RedefinedAbstraction>();
    a->setImplementor(i);
    a->Operation();
}
