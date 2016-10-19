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
        return std::shared_ptr<AbstractProduct>(new ConcreteProductA);
    }
};

class ConcreteFactoryB : public AbstractFactory {
public:
    virtual std::shared_ptr<AbstractProduct> CreateProduct() override {
        return std::shared_ptr<AbstractProduct>(new ConcreteProductB);
    }
};

int main() {
    auto factorya = std::shared_ptr<AbstractFactory>(new ConcreteFactoryA);
    auto factoryb = std::shared_ptr<AbstractFactory>(new ConcreteFactoryB);
    auto producta = factorya->CreateProduct();
    auto productb = factoryb->CreateProduct();
    producta->Opteration();
    productb->Opteration();
}
