#include <iostream>
#include <memory>

class AbstractProductA {
public:
    virtual void Opteration() = 0;
};

class ConcreteProductA1 : public AbstractProductA {
public:
    virtual void Opteration() override {
        std::cout << "ConcreteProductA1" << std::endl;
    }
};

class ConcreteProductA2 : public AbstractProductA {
public:
    virtual void Opteration() override {
        std::cout << "ConcreteProductA2" << std::endl;
    }
};

class AbstractProductB {
public:
    virtual void Opteration() = 0;
};

class ConcreteProductB1 : public AbstractProductB {
public:
    virtual void Opteration() override {
        std::cout << "ConcreteProductB1" << std::endl;
    }
};

class ConcreteProductB2 : public AbstractProductB {
public:
    virtual void Opteration() override {
        std::cout << "ConcreteProductB2" << std::endl;
    }
};


class AbstractFactory {
public:
    virtual std::shared_ptr<AbstractProductA> CreateProductA() = 0;
    virtual std::shared_ptr<AbstractProductB> CreateProductB() = 0;
};

class ConcreteFactoryA : public AbstractFactory {
public:
    virtual std::shared_ptr<AbstractProductA> CreateProductA() override {
        return std::shared_ptr<AbstractProductA>(new ConcreteProductA1);
    }

    virtual std::shared_ptr<AbstractProductB> CreateProductB() override {
        return std::shared_ptr<AbstractProductB>(new ConcreteProductB2);
    }
};

class ConcreteFactoryB : public AbstractFactory {
public:
    virtual std::shared_ptr<AbstractProductA> CreateProductA() override {
        return std::shared_ptr<AbstractProductA>(new ConcreteProductA2);
    }
    virtual std::shared_ptr<AbstractProductB> CreateProductB() override {
        return std::shared_ptr<AbstractProductB>(new ConcreteProductB1);
    }
};

int main() {
    auto factorya = std::shared_ptr<AbstractFactory>(new ConcreteFactoryA);
    auto factoryb = std::shared_ptr<AbstractFactory>(new ConcreteFactoryB);
    auto producta1 = factorya->CreateProductA();
    auto productb1 = factorya->CreateProductB();
    auto producta2 = factoryb->CreateProductA();
    auto productb2 = factoryb->CreateProductB();
    producta1->Opteration();
    productb1->Opteration();
    producta2->Opteration();
    productb2->Opteration();
}
