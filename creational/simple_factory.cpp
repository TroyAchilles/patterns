#include <iostream>
#include <string>
#include <memory>

class AbstractProduct {
public:
    virtual void Opteration() = 0;
};

class ConcreteProductA : public AbstractProduct {
public:
    virtual void Opteration() override {
        std::cout << "ConcreteProductA" << std::endl;
    }
};

class ConcreteProductB : public AbstractProduct {
public:
    virtual void Opteration() override {
        std::cout << "ConcreteProductB" << std::endl;
    }
};


class Factory {
public:
    std::shared_ptr<AbstractProduct> CreateProduct(std::string name) {
        if (name == "A")
            return std::shared_ptr<AbstractProduct>(new ConcreteProductA);
        else if (name == "B")
            return std::shared_ptr<AbstractProduct>(new ConcreteProductB);
        else
            return nullptr;
    }
};

int main() {
    auto factory = std::make_shared<Factory>();
    auto producta = factory->CreateProduct("A");
    auto productb = factory->CreateProduct("B");
    producta->Opteration();
    productb->Opteration();
}
