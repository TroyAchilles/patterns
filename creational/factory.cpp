#include <iostream>
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

class AbstractFactory {
public:
    virtual std::shared_ptr<AbstractProduct> CreateProduct() = 0;
};

class ConcreteFactoryA : public AbstractFactory {
public:
    virtual std::shared_ptr<AbstractProduct> CreateProduct() override {
        return std::make_shared<ConcreteProductA>();
    }
};

class ConcreteFactoryB : public AbstractFactory {
public:
    virtual std::shared_ptr<AbstractProduct> CreateProduct() override {
        return std::make_shared<ConcreteProductB>();
    }
};

int main() {
    std::shared_ptr<AbstractFactory> factorya = std::make_shared<ConcreteFactoryA>();
    std::shared_ptr<AbstractFactory> factoryb = std::make_shared<ConcreteFactoryB>();
    auto producta = factorya->CreateProduct();
    auto productb = factoryb->CreateProduct();
    producta->Opteration();
    productb->Opteration();
}
